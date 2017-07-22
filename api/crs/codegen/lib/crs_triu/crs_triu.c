#include "crs_triu.h"
#include "m2c.h"
#include "crs_triu_emxutil.h"

static void crs_sort(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind,
                     emxArray_real_T *val);
static void crs_sort(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind,
                     emxArray_real_T *val)
{
  int i2;
  int i;
  emxArray_real_T *buf_val;
  emxArray_int32_T *buf_indx;
  boolean_T ascend;
  int j;
  boolean_T exitg1;
  int n;
  unsigned int ind;
  int l;
  int exitg2;
  boolean_T guard1 = false;
  int r0;
  double t0;
  int exitg3;
  int b_i;
  boolean_T guard2 = false;
  i2 = row_ptr->size[0] - 1;
  i = 1;
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  while (i <= i2) {
    ascend = true;
    j = row_ptr->data[i - 1];
    exitg1 = false;
    while ((!exitg1) && (j + 1 <= row_ptr->data[i] - 1)) {
      if (col_ind->data[j] < col_ind->data[j - 1]) {
        ascend = false;
        exitg1 = true;
      } else {
        j++;
      }
    }

    if (!ascend) {
      j = buf_indx->size[0];
      buf_indx->size[0] = row_ptr->data[i] - row_ptr->data[i - 1];
      emxEnsureCapacity_int32_T(buf_indx, j);
      n = row_ptr->data[i] - row_ptr->data[i - 1];
      for (j = 0; j < n; j++) {
        buf_indx->data[j] = 0;
      }

      j = buf_val->size[0];
      buf_val->size[0] = row_ptr->data[i] - row_ptr->data[i - 1];
      emxEnsureCapacity_real_T(buf_val, j);
      n = row_ptr->data[i] - row_ptr->data[i - 1];
      for (j = 0; j < n; j++) {
        buf_val->data[j] = 0.0;
      }

      ind = 1U;
      for (j = row_ptr->data[i - 1]; j < row_ptr->data[i]; j++) {
        buf_indx->data[(int)ind - 1] = col_ind->data[j - 1];
        buf_val->data[(int)ind - 1] = val->data[j - 1];
        ind++;
      }

      n = buf_indx->size[0];
      if (!(n <= 1)) {
        l = (int)((unsigned int)n >> 1U);
        do {
          exitg2 = 0;
          guard1 = false;
          if (l + 1 <= 1) {
            r0 = buf_indx->data[n - 1];
            t0 = buf_val->data[n - 1];
            buf_indx->data[n - 1] = buf_indx->data[0];
            buf_val->data[n - 1] = buf_val->data[0];
            n--;
            if (n == 1) {
              exitg2 = 1;
            } else {
              guard1 = true;
            }
          } else {
            l--;
            r0 = buf_indx->data[l];
            t0 = buf_val->data[l];
            guard1 = true;
          }

          if (guard1) {
            j = l;
            do {
              exitg3 = 0;
              b_i = j;
              j = ((j + 1) << 1) - 1;
              ascend = false;
              guard2 = false;
              if (j + 1 >= n) {
                if (j + 1 == n) {
                  ascend = true;
                  guard2 = true;
                } else if (j + 1 > n) {
                  exitg3 = 1;
                } else {
                  guard2 = true;
                }
              } else {
                guard2 = true;
              }

              if (guard2) {
                if ((!ascend) && (buf_indx->data[j] < buf_indx->data[j + 1])) {
                  j++;
                }

                if (r0 >= buf_indx->data[j]) {
                  exitg3 = 1;
                } else {
                  buf_indx->data[b_i] = buf_indx->data[j];
                  buf_val->data[b_i] = buf_val->data[j];
                }
              }
            } while (exitg3 == 0);

            buf_indx->data[b_i] = r0;
            buf_val->data[b_i] = t0;
          }
        } while (exitg2 == 0);

        buf_indx->data[0] = r0;
        buf_val->data[0] = t0;
      }

      ind = 1U;
      for (j = row_ptr->data[i - 1]; j < row_ptr->data[i]; j++) {
        col_ind->data[j - 1] = buf_indx->data[(int)ind - 1];
        val->data[j - 1] = buf_val->data[(int)ind - 1];
        ind++;
      }
    }

    i++;
  }

  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
}

void crs_triu(const struct0_T *A, struct0_T *U)
{
  emxArray_int32_T *b_U;
  int i0;
  int offset;
  int start;
  int i;
  emxArray_int32_T *b_A;
  emxArray_real_T *c_A;
  emxInit_int32_T(&b_U, 1);
  emxCopyStruct_struct0_T(U, A);
  i0 = b_U->size[0];
  b_U->size[0] = U->row_ptr->size[0];
  emxEnsureCapacity_int32_T(b_U, i0);
  offset = U->row_ptr->size[0];
  for (i0 = 0; i0 < offset; i0++) {
    b_U->data[i0] = U->row_ptr->data[i0];
  }

  crs_sort(b_U, U->col_ind, U->val);
  offset = 0;
  start = 0;
  i = 1;
  emxFree_int32_T(&b_U);
  while (i <= U->nrows) {
    i0 = U->row_ptr->data[i] - 1;
    while (start + 1 <= i0) {
      if (U->col_ind->data[start] < i) {
        offset++;
      } else {
        if (offset != 0) {
          U->col_ind->data[start - offset] = U->col_ind->data[start];
          U->val->data[start - offset] = U->val->data[start];
        }
      }

      start++;
    }

    start = U->row_ptr->data[i] - 1;
    U->row_ptr->data[i] -= offset;
    i++;
  }

  if (offset != 0) {
    emxInit_int32_T(&b_A, 1);
    start = U->col_ind->size[0] - offset;
    i0 = b_A->size[0];
    b_A->size[0] = U->col_ind->size[0];
    emxEnsureCapacity_int32_T(b_A, i0);
    offset = U->col_ind->size[0];
    for (i0 = 0; i0 < offset; i0++) {
      b_A->data[i0] = U->col_ind->data[i0];
    }

    if (start < 1) {
      i0 = U->col_ind->size[0];
      U->col_ind->size[0] = 0;
      emxEnsureCapacity_int32_T(U->col_ind, i0);
    } else {
      i0 = U->col_ind->size[0];
      U->col_ind->size[0] = start;
      emxEnsureCapacity_int32_T(U->col_ind, i0);
      for (i = 0; i < start; i++) {
        U->col_ind->data[i] = b_A->data[i];
      }
    }

    emxFree_int32_T(&b_A);
    emxInit_real_T(&c_A, 1);
    i0 = c_A->size[0];
    c_A->size[0] = U->val->size[0];
    emxEnsureCapacity_real_T(c_A, i0);
    offset = U->val->size[0];
    for (i0 = 0; i0 < offset; i0++) {
      c_A->data[i0] = U->val->data[i0];
    }

    if (start < 1) {
      i0 = U->val->size[0];
      U->val->size[0] = 0;
      emxEnsureCapacity_real_T(U->val, i0);
    } else {
      i0 = U->val->size[0];
      U->val->size[0] = start;
      emxEnsureCapacity_real_T(U->val, i0);
      for (i = 0; i < start; i++) {
        U->val->data[i] = c_A->data[i];
      }
    }

    emxFree_real_T(&c_A);
  }
}

void crs_triu1(const struct0_T *A, int k, struct0_T *U)
{
  emxArray_int32_T *b_U;
  int i1;
  int offset;
  int start;
  int i;
  emxArray_int32_T *b_A;
  emxArray_real_T *c_A;
  emxInit_int32_T(&b_U, 1);
  emxCopyStruct_struct0_T(U, A);
  i1 = b_U->size[0];
  b_U->size[0] = U->row_ptr->size[0];
  emxEnsureCapacity_int32_T(b_U, i1);
  offset = U->row_ptr->size[0];
  for (i1 = 0; i1 < offset; i1++) {
    b_U->data[i1] = U->row_ptr->data[i1];
  }

  crs_sort(b_U, U->col_ind, U->val);
  offset = 0;
  start = 0;
  i = 1;
  emxFree_int32_T(&b_U);
  while (i <= U->nrows) {
    i1 = U->row_ptr->data[i] - 1;
    while (start + 1 <= i1) {
      if (U->col_ind->data[start] < i + k) {
        offset++;
      } else {
        if (offset != 0) {
          U->col_ind->data[start - offset] = U->col_ind->data[start];
          U->val->data[start - offset] = U->val->data[start];
        }
      }

      start++;
    }

    start = U->row_ptr->data[i] - 1;
    U->row_ptr->data[i] -= offset;
    i++;
  }

  if (offset != 0) {
    emxInit_int32_T(&b_A, 1);
    start = U->col_ind->size[0] - offset;
    i1 = b_A->size[0];
    b_A->size[0] = U->col_ind->size[0];
    emxEnsureCapacity_int32_T(b_A, i1);
    offset = U->col_ind->size[0];
    for (i1 = 0; i1 < offset; i1++) {
      b_A->data[i1] = U->col_ind->data[i1];
    }

    if (start < 1) {
      i1 = U->col_ind->size[0];
      U->col_ind->size[0] = 0;
      emxEnsureCapacity_int32_T(U->col_ind, i1);
    } else {
      i1 = U->col_ind->size[0];
      U->col_ind->size[0] = start;
      emxEnsureCapacity_int32_T(U->col_ind, i1);
      for (i = 0; i < start; i++) {
        U->col_ind->data[i] = b_A->data[i];
      }
    }

    emxFree_int32_T(&b_A);
    emxInit_real_T(&c_A, 1);
    i1 = c_A->size[0];
    c_A->size[0] = U->val->size[0];
    emxEnsureCapacity_real_T(c_A, i1);
    offset = U->val->size[0];
    for (i1 = 0; i1 < offset; i1++) {
      c_A->data[i1] = U->val->data[i1];
    }

    if (start < 1) {
      i1 = U->val->size[0];
      U->val->size[0] = 0;
      emxEnsureCapacity_real_T(U->val, i1);
    } else {
      i1 = U->val->size[0];
      U->val->size[0] = start;
      emxEnsureCapacity_real_T(U->val, i1);
      for (i = 0; i < start; i++) {
        U->val->data[i] = c_A->data[i];
      }
    }

    emxFree_real_T(&c_A);
  }
}

void crs_triu_initialize(void)
{
}

void crs_triu_terminate(void)
{
}
