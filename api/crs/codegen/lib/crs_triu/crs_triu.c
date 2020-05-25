#include "crs_triu.h"
#include "m2c.h"
#include "crs_triu_emxutil.h"

static void crs_sort(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind,
                     emxArray_real_T *val);
static void crs_sort(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind,
                     emxArray_real_T *val)
{
  int i;
  emxArray_real_T *buf_val;
  emxArray_int32_T *buf_indx;
  int b_i;
  boolean_T ascend;
  int j;
  int exitg1;
  int ir;
  int i1;
  int l;
  unsigned int ind;
  boolean_T guard1 = false;
  int r0;
  double t0;
  int exitg2;
  int c_i;
  boolean_T guard2 = false;
  i = row_ptr->size[0];
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  for (b_i = 0; b_i <= i - 2; b_i++) {
    ascend = true;
    j = row_ptr->data[b_i];
    do {
      exitg1 = 0;
      ir = row_ptr->data[b_i + 1];
      i1 = ir - 1;
      if (j + 1 <= i1) {
        if (col_ind->data[j] < col_ind->data[j - 1]) {
          ascend = false;
          exitg1 = 1;
        } else {
          j++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (!ascend) {
      l = ir - row_ptr->data[b_i];
      ir = buf_indx->size[0];
      buf_indx->size[0] = l;
      emxEnsureCapacity_int32_T(buf_indx, ir);
      for (ir = 0; ir < l; ir++) {
        buf_indx->data[ir] = 0;
      }

      ir = buf_val->size[0];
      buf_val->size[0] = l;
      emxEnsureCapacity_real_T(buf_val, ir);
      for (ir = 0; ir < l; ir++) {
        buf_val->data[ir] = 0.0;
      }

      ind = 1U;
      ir = row_ptr->data[b_i];
      for (j = ir; j <= i1; j++) {
        l = (int)ind - 1;
        buf_indx->data[l] = col_ind->data[j - 1];
        buf_val->data[l] = val->data[j - 1];
        ind++;
      }

      if (buf_indx->size[0] > 1) {
        l = (int)((unsigned int)buf_indx->size[0] >> 1U);
        ir = buf_indx->size[0];
        do {
          exitg1 = 0;
          guard1 = false;
          if (l + 1 <= 1) {
            r0 = buf_indx->data[ir - 1];
            t0 = buf_val->data[ir - 1];
            buf_indx->data[ir - 1] = buf_indx->data[0];
            buf_val->data[ir - 1] = buf_val->data[0];
            ir--;
            if (ir == 1) {
              exitg1 = 1;
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
              exitg2 = 0;
              c_i = j;
              j = ((j + 1) << 1) - 1;
              ascend = false;
              guard2 = false;
              if (j + 1 >= ir) {
                if (j + 1 == ir) {
                  ascend = true;
                  guard2 = true;
                } else if (j + 1 > ir) {
                  exitg2 = 1;
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
                  exitg2 = 1;
                } else {
                  buf_indx->data[c_i] = buf_indx->data[j];
                  buf_val->data[c_i] = buf_val->data[j];
                }
              }
            } while (exitg2 == 0);

            buf_indx->data[c_i] = r0;
            buf_val->data[c_i] = t0;
          }
        } while (exitg1 == 0);

        buf_indx->data[0] = r0;
        buf_val->data[0] = t0;
      }

      ind = 1U;
      ir = row_ptr->data[b_i];
      for (j = ir; j <= i1; j++) {
        l = (int)ind - 1;
        col_ind->data[j - 1] = buf_indx->data[l];
        val->data[j - 1] = buf_val->data[l];
        ind++;
      }
    }
  }

  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
}

void crs_triu(const struct0_T *A, struct0_T *U)
{
  int offset;
  int start;
  int i;
  int b_i;
  int c_i;
  emxArray_int32_T *b_A;
  int i1;
  int j;
  int i2;
  int i3;
  emxArray_real_T *c_A;
  emxCopyStruct_struct0_T(U, A);
  crs_sort(U->row_ptr, U->col_ind, U->val);
  offset = 0;
  start = 1;
  i = U->nrows;
  for (b_i = 0; b_i < i; b_i++) {
    c_i = b_i + 1;
    i1 = U->row_ptr->data[c_i] - 1;
    for (j = start; j <= i1; j++) {
      i2 = U->col_ind->data[j - 1];
      if (i2 < c_i) {
        offset++;
      } else {
        if (offset != 0) {
          i3 = (j - offset) - 1;
          U->col_ind->data[i3] = i2;
          U->val->data[i3] = U->val->data[j - 1];
        }
      }
    }

    start = U->row_ptr->data[c_i];
    U->row_ptr->data[c_i] -= offset;
  }

  if (offset != 0) {
    emxInit_int32_T(&b_A, 1);
    start = U->col_ind->size[0] - offset;
    i = b_A->size[0];
    b_A->size[0] = U->col_ind->size[0];
    emxEnsureCapacity_int32_T(b_A, i);
    offset = U->col_ind->size[0];
    for (i = 0; i < offset; i++) {
      b_A->data[i] = U->col_ind->data[i];
    }

    if (start < 1) {
      U->col_ind->size[0] = 0;
    } else {
      i = U->col_ind->size[0];
      U->col_ind->size[0] = start;
      emxEnsureCapacity_int32_T(U->col_ind, i);
      i = start - 1;
      for (b_i = 0; b_i <= i; b_i++) {
        U->col_ind->data[b_i] = b_A->data[b_i];
      }
    }

    emxFree_int32_T(&b_A);
    emxInit_real_T(&c_A, 1);
    i = c_A->size[0];
    c_A->size[0] = U->val->size[0];
    emxEnsureCapacity_real_T(c_A, i);
    offset = U->val->size[0];
    for (i = 0; i < offset; i++) {
      c_A->data[i] = U->val->data[i];
    }

    if (start < 1) {
      U->val->size[0] = 0;
    } else {
      i = U->val->size[0];
      U->val->size[0] = start;
      emxEnsureCapacity_real_T(U->val, i);
      i = start - 1;
      for (b_i = 0; b_i <= i; b_i++) {
        U->val->data[b_i] = c_A->data[b_i];
      }
    }

    emxFree_real_T(&c_A);
  }
}

void crs_triu1(const struct0_T *A, int k, struct0_T *U)
{
  int offset;
  int start;
  int i;
  int b_i;
  int c_i;
  emxArray_int32_T *b_A;
  int i1;
  int j;
  int i2;
  int i3;
  emxArray_real_T *c_A;
  emxCopyStruct_struct0_T(U, A);
  crs_sort(U->row_ptr, U->col_ind, U->val);
  offset = 0;
  start = 1;
  i = U->nrows;
  for (b_i = 0; b_i < i; b_i++) {
    c_i = b_i + 1;
    i1 = U->row_ptr->data[c_i] - 1;
    for (j = start; j <= i1; j++) {
      i2 = U->col_ind->data[j - 1];
      if (i2 < c_i + k) {
        offset++;
      } else {
        if (offset != 0) {
          i3 = (j - offset) - 1;
          U->col_ind->data[i3] = i2;
          U->val->data[i3] = U->val->data[j - 1];
        }
      }
    }

    start = U->row_ptr->data[c_i];
    U->row_ptr->data[c_i] -= offset;
  }

  if (offset != 0) {
    emxInit_int32_T(&b_A, 1);
    start = U->col_ind->size[0] - offset;
    i = b_A->size[0];
    b_A->size[0] = U->col_ind->size[0];
    emxEnsureCapacity_int32_T(b_A, i);
    offset = U->col_ind->size[0];
    for (i = 0; i < offset; i++) {
      b_A->data[i] = U->col_ind->data[i];
    }

    if (start < 1) {
      U->col_ind->size[0] = 0;
    } else {
      i = U->col_ind->size[0];
      U->col_ind->size[0] = start;
      emxEnsureCapacity_int32_T(U->col_ind, i);
      i = start - 1;
      for (b_i = 0; b_i <= i; b_i++) {
        U->col_ind->data[b_i] = b_A->data[b_i];
      }
    }

    emxFree_int32_T(&b_A);
    emxInit_real_T(&c_A, 1);
    i = c_A->size[0];
    c_A->size[0] = U->val->size[0];
    emxEnsureCapacity_real_T(c_A, i);
    offset = U->val->size[0];
    for (i = 0; i < offset; i++) {
      c_A->data[i] = U->val->data[i];
    }

    if (start < 1) {
      U->val->size[0] = 0;
    } else {
      i = U->val->size[0];
      U->val->size[0] = start;
      emxEnsureCapacity_real_T(U->val, i);
      i = start - 1;
      for (b_i = 0; b_i <= i; b_i++) {
        U->val->data[b_i] = c_A->data[b_i];
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
