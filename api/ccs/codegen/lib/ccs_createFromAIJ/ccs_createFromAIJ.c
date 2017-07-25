#include "ccs_createFromAIJ.h"
#include "m2c.h"

static void ccs_sort(const emxArray_int32_T *col_ptr, emxArray_int32_T *row_ind,
                     emxArray_real_T *val);
static void ccs_sort(const emxArray_int32_T *col_ptr, emxArray_int32_T *row_ind,
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
  i2 = col_ptr->size[0] - 1;
  i = 1;
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  while (i <= i2) {
    ascend = true;
    j = col_ptr->data[i - 1];
    exitg1 = false;
    while ((!exitg1) && (j + 1 <= col_ptr->data[i] - 1)) {
      if (row_ind->data[j] < row_ind->data[j - 1]) {
        ascend = false;
        exitg1 = true;
      } else {
        j++;
      }
    }

    if (!ascend) {
      j = buf_indx->size[0];
      buf_indx->size[0] = col_ptr->data[i] - col_ptr->data[i - 1];
      emxEnsureCapacity_int32_T(buf_indx, j);
      n = col_ptr->data[i] - col_ptr->data[i - 1];
      for (j = 0; j < n; j++) {
        buf_indx->data[j] = 0;
      }

      j = buf_val->size[0];
      buf_val->size[0] = col_ptr->data[i] - col_ptr->data[i - 1];
      emxEnsureCapacity_real_T(buf_val, j);
      n = col_ptr->data[i] - col_ptr->data[i - 1];
      for (j = 0; j < n; j++) {
        buf_val->data[j] = 0.0;
      }

      ind = 1U;
      for (j = col_ptr->data[i - 1]; j < col_ptr->data[i]; j++) {
        buf_indx->data[(int)ind - 1] = row_ind->data[j - 1];
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
      for (j = col_ptr->data[i - 1]; j < col_ptr->data[i]; j++) {
        row_ind->data[j - 1] = buf_indx->data[(int)ind - 1];
        val->data[j - 1] = buf_val->data[(int)ind - 1];
        ind++;
      }
    }

    i++;
  }

  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
}

void ccs_create1(const emxArray_int32_T *is, const emxArray_int32_T *js, const
                 emxArray_real_T *vs, int ni, int nj, struct0_T *A)
{
  unsigned int unnamed_idx_0;
  unsigned int b_unnamed_idx_0;
  int i1;
  int j;
  int i;
  boolean_T ascend;
  boolean_T exitg1;
  emxArray_int32_T *b_A;
  int b_i;
  unnamed_idx_0 = (unsigned int)is->size[0];
  b_unnamed_idx_0 = (unsigned int)is->size[0];
  i1 = A->col_ptr->size[0];
  A->col_ptr->size[0] = nj + 1;
  emxEnsureCapacity_int32_T(A->col_ptr, i1);
  for (i1 = 0; i1 <= nj; i1++) {
    A->col_ptr->data[i1] = 0;
  }

  i1 = A->row_ind->size[0];
  A->row_ind->size[0] = (int)unnamed_idx_0;
  emxEnsureCapacity_int32_T(A->row_ind, i1);
  j = (int)unnamed_idx_0;
  for (i1 = 0; i1 < j; i1++) {
    A->row_ind->data[i1] = 0;
  }

  i1 = A->val->size[0];
  A->val->size[0] = (int)b_unnamed_idx_0;
  emxEnsureCapacity_real_T(A->val, i1);
  j = (int)b_unnamed_idx_0;
  for (i1 = 0; i1 < j; i1++) {
    A->val->data[i1] = 0.0;
  }

  A->nrows = ni;
  A->ncols = nj;
  i1 = js->size[0];
  for (i = 0; i + 1 <= i1; i++) {
    A->col_ptr->data[js->data[i]]++;
  }

  A->col_ptr->data[0] = 1;
  for (i = 1; i <= nj; i++) {
    A->col_ptr->data[i] += A->col_ptr->data[i - 1];
  }

  ascend = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= js->size[0] - 2)) {
    if (js->data[1 + i] < js->data[i]) {
      ascend = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (ascend) {
    i1 = A->row_ind->size[0];
    A->row_ind->size[0] = is->size[0];
    emxEnsureCapacity_int32_T(A->row_ind, i1);
    j = is->size[0];
    for (i1 = 0; i1 < j; i1++) {
      A->row_ind->data[i1] = is->data[i1];
    }

    i1 = A->val->size[0];
    A->val->size[0] = vs->size[0];
    emxEnsureCapacity_real_T(A->val, i1);
    j = vs->size[0];
    for (i1 = 0; i1 < j; i1++) {
      A->val->data[i1] = vs->data[i1];
    }
  } else {
    i1 = A->row_ind->size[0];
    A->row_ind->size[0] = is->size[0];
    emxEnsureCapacity_int32_T(A->row_ind, i1);
    i1 = A->val->size[0];
    A->val->size[0] = is->size[0];
    emxEnsureCapacity_real_T(A->val, i1);
    for (i = 0; i < js->size[0]; i++) {
      j = A->col_ptr->data[js->data[i] - 1];
      A->val->data[A->col_ptr->data[js->data[i] - 1] - 1] = vs->data[i];
      A->row_ind->data[j - 1] = is->data[i];
      A->col_ptr->data[js->data[i] - 1]++;
    }

    j = A->col_ptr->size[0];
    i1 = (int)((2.0 + (-1.0 - (double)A->col_ptr->size[0])) / -1.0);
    for (i = 1; i - 1 < i1; i++) {
      b_i = j - i;
      A->col_ptr->data[b_i] = A->col_ptr->data[b_i - 1];
    }

    A->col_ptr->data[0] = 1;
  }

  emxInit_int32_T(&b_A, 1);
  i1 = b_A->size[0];
  b_A->size[0] = A->col_ptr->size[0];
  emxEnsureCapacity_int32_T(b_A, i1);
  j = A->col_ptr->size[0];
  for (i1 = 0; i1 < j; i1++) {
    b_A->data[i1] = A->col_ptr->data[i1];
  }

  ccs_sort(b_A, A->row_ind, A->val);
  emxFree_int32_T(&b_A);
}

void ccs_createFromAIJ(const emxArray_int32_T *rows, const emxArray_int32_T
  *cols, const emxArray_real_T *vs, struct0_T *A)
{
  int mtmp;
  int j;
  int b_mtmp;
  int unnamed_idx_0;
  int i0;
  boolean_T ascend;
  boolean_T exitg1;
  emxArray_int32_T *b_A;
  mtmp = rows->data[0];
  if (rows->size[0] > 1) {
    for (j = 1; j + 1 <= rows->size[0]; j++) {
      if (rows->data[j] > mtmp) {
        mtmp = rows->data[j];
      }
    }
  }

  b_mtmp = cols->data[0];
  if (cols->size[0] > 1) {
    for (j = 1; j + 1 <= cols->size[0]; j++) {
      if (cols->data[j] > b_mtmp) {
        b_mtmp = cols->data[j];
      }
    }
  }

  j = rows->size[0];
  unnamed_idx_0 = rows->size[0];
  i0 = A->col_ptr->size[0];
  A->col_ptr->size[0] = b_mtmp + 1;
  emxEnsureCapacity_int32_T(A->col_ptr, i0);
  for (i0 = 0; i0 <= b_mtmp; i0++) {
    A->col_ptr->data[i0] = 0;
  }

  i0 = A->row_ind->size[0];
  A->row_ind->size[0] = j;
  emxEnsureCapacity_int32_T(A->row_ind, i0);
  for (i0 = 0; i0 < j; i0++) {
    A->row_ind->data[i0] = 0;
  }

  i0 = A->val->size[0];
  A->val->size[0] = unnamed_idx_0;
  emxEnsureCapacity_real_T(A->val, i0);
  for (i0 = 0; i0 < unnamed_idx_0; i0++) {
    A->val->data[i0] = 0.0;
  }

  A->nrows = mtmp;
  A->ncols = b_mtmp;
  i0 = cols->size[0];
  for (mtmp = 0; mtmp + 1 <= i0; mtmp++) {
    A->col_ptr->data[cols->data[mtmp]]++;
  }

  A->col_ptr->data[0] = 1;
  for (mtmp = 1; mtmp <= b_mtmp; mtmp++) {
    A->col_ptr->data[mtmp] += A->col_ptr->data[mtmp - 1];
  }

  ascend = true;
  mtmp = 0;
  exitg1 = false;
  while ((!exitg1) && (mtmp <= cols->size[0] - 2)) {
    if (cols->data[1 + mtmp] < cols->data[mtmp]) {
      ascend = false;
      exitg1 = true;
    } else {
      mtmp++;
    }
  }

  if (ascend) {
    i0 = A->row_ind->size[0];
    A->row_ind->size[0] = rows->size[0];
    emxEnsureCapacity_int32_T(A->row_ind, i0);
    j = rows->size[0];
    for (i0 = 0; i0 < j; i0++) {
      A->row_ind->data[i0] = rows->data[i0];
    }

    i0 = A->val->size[0];
    A->val->size[0] = vs->size[0];
    emxEnsureCapacity_real_T(A->val, i0);
    j = vs->size[0];
    for (i0 = 0; i0 < j; i0++) {
      A->val->data[i0] = vs->data[i0];
    }
  } else {
    i0 = A->row_ind->size[0];
    A->row_ind->size[0] = rows->size[0];
    emxEnsureCapacity_int32_T(A->row_ind, i0);
    i0 = A->val->size[0];
    A->val->size[0] = rows->size[0];
    emxEnsureCapacity_real_T(A->val, i0);
    for (mtmp = 0; mtmp < cols->size[0]; mtmp++) {
      j = A->col_ptr->data[cols->data[mtmp] - 1];
      A->val->data[A->col_ptr->data[cols->data[mtmp] - 1] - 1] = vs->data[mtmp];
      A->row_ind->data[j - 1] = rows->data[mtmp];
      A->col_ptr->data[cols->data[mtmp] - 1]++;
    }

    j = A->col_ptr->size[0] - 2;
    i0 = (int)((2.0 + (-1.0 - (double)A->col_ptr->size[0])) / -1.0);
    for (mtmp = 0; mtmp < i0; mtmp++) {
      unnamed_idx_0 = j - mtmp;
      A->col_ptr->data[unnamed_idx_0 + 1] = A->col_ptr->data[unnamed_idx_0];
    }

    A->col_ptr->data[0] = 1;
  }

  emxInit_int32_T(&b_A, 1);
  i0 = b_A->size[0];
  b_A->size[0] = A->col_ptr->size[0];
  emxEnsureCapacity_int32_T(b_A, i0);
  j = A->col_ptr->size[0];
  for (i0 = 0; i0 < j; i0++) {
    b_A->data[i0] = A->col_ptr->data[i0];
  }

  ccs_sort(b_A, A->row_ind, A->val);
  emxFree_int32_T(&b_A);
}

void ccs_createFromAIJ_initialize(void)
{
}

void ccs_createFromAIJ_terminate(void)
{
}
