#include "crs_transp.h"
#include "m2c.h"

static void crs_createFromAIJ(const emxArray_int32_T *rows, const
  emxArray_int32_T *cols, const emxArray_real_T *vs, emxArray_int32_T *A_row_ptr,
  emxArray_int32_T *A_col_ind, emxArray_real_T *A_val, int *A_nrows, int
  *A_ncols);
static void crs_createFromAIJ(const emxArray_int32_T *rows, const
  emxArray_int32_T *cols, const emxArray_real_T *vs, emxArray_int32_T *A_row_ptr,
  emxArray_int32_T *A_col_ind, emxArray_real_T *A_val, int *A_nrows, int
  *A_ncols)
{
  int mtmp;
  int j;
  int b_mtmp;
  int n;
  int i0;
  int i;
  boolean_T ascend;
  boolean_T exitg1;
  emxArray_int32_T *col_ind;
  int b_i;
  emxArray_real_T *val;
  emxArray_real_T *buf_val;
  emxArray_int32_T *buf_indx;
  unsigned int ind;
  int l;
  int exitg2;
  boolean_T guard1 = false;
  int r0;
  double t0;
  int exitg3;
  boolean_T guard2 = false;
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

  j = cols->size[0];
  n = cols->size[0];
  i0 = A_row_ptr->size[0];
  A_row_ptr->size[0] = mtmp + 1;
  emxEnsureCapacity_int32_T(A_row_ptr, i0);
  for (i0 = 0; i0 <= mtmp; i0++) {
    A_row_ptr->data[i0] = 0;
  }

  i0 = A_col_ind->size[0];
  A_col_ind->size[0] = j;
  emxEnsureCapacity_int32_T(A_col_ind, i0);
  for (i0 = 0; i0 < j; i0++) {
    A_col_ind->data[i0] = 0;
  }

  i0 = A_val->size[0];
  A_val->size[0] = n;
  emxEnsureCapacity_real_T(A_val, i0);
  for (i0 = 0; i0 < n; i0++) {
    A_val->data[i0] = 0.0;
  }

  i0 = rows->size[0];
  for (i = 0; i + 1 <= i0; i++) {
    A_row_ptr->data[rows->data[i]]++;
  }

  A_row_ptr->data[0] = 1;
  for (i = 1; i <= mtmp; i++) {
    A_row_ptr->data[i] += A_row_ptr->data[i - 1];
  }

  ascend = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= rows->size[0] - 2)) {
    if (rows->data[1 + i] < rows->data[i]) {
      ascend = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (ascend) {
    i0 = A_col_ind->size[0];
    A_col_ind->size[0] = cols->size[0];
    emxEnsureCapacity_int32_T(A_col_ind, i0);
    j = cols->size[0];
    for (i0 = 0; i0 < j; i0++) {
      A_col_ind->data[i0] = cols->data[i0];
    }

    i0 = A_val->size[0];
    A_val->size[0] = vs->size[0];
    emxEnsureCapacity_real_T(A_val, i0);
    j = vs->size[0];
    for (i0 = 0; i0 < j; i0++) {
      A_val->data[i0] = vs->data[i0];
    }
  } else {
    i0 = A_col_ind->size[0];
    A_col_ind->size[0] = cols->size[0];
    emxEnsureCapacity_int32_T(A_col_ind, i0);
    i0 = A_val->size[0];
    A_val->size[0] = cols->size[0];
    emxEnsureCapacity_real_T(A_val, i0);
    for (i = 0; i < rows->size[0]; i++) {
      j = A_row_ptr->data[rows->data[i] - 1];
      A_val->data[A_row_ptr->data[rows->data[i] - 1] - 1] = vs->data[i];
      A_col_ind->data[j - 1] = cols->data[i];
      A_row_ptr->data[rows->data[i] - 1]++;
    }

    j = A_row_ptr->size[0] - 2;
    i0 = (int)((2.0 + (-1.0 - (double)A_row_ptr->size[0])) / -1.0);
    for (i = 0; i < i0; i++) {
      b_i = j - i;
      A_row_ptr->data[b_i + 1] = A_row_ptr->data[b_i];
    }

    A_row_ptr->data[0] = 1;
  }

  emxInit_int32_T(&col_ind, 1);
  i0 = col_ind->size[0];
  col_ind->size[0] = A_col_ind->size[0];
  emxEnsureCapacity_int32_T(col_ind, i0);
  j = A_col_ind->size[0];
  for (i0 = 0; i0 < j; i0++) {
    col_ind->data[i0] = A_col_ind->data[i0];
  }

  emxInit_real_T(&val, 1);
  i0 = val->size[0];
  val->size[0] = A_val->size[0];
  emxEnsureCapacity_real_T(val, i0);
  j = A_val->size[0];
  for (i0 = 0; i0 < j; i0++) {
    val->data[i0] = A_val->data[i0];
  }

  i0 = A_row_ptr->size[0] - 1;
  i = 1;
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  while (i <= i0) {
    ascend = true;
    j = A_row_ptr->data[i - 1];
    exitg1 = false;
    while ((!exitg1) && (j + 1 <= A_row_ptr->data[i] - 1)) {
      if (col_ind->data[j] < col_ind->data[j - 1]) {
        ascend = false;
        exitg1 = true;
      } else {
        j++;
      }
    }

    if (!ascend) {
      n = buf_indx->size[0];
      buf_indx->size[0] = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
      emxEnsureCapacity_int32_T(buf_indx, n);
      j = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
      for (n = 0; n < j; n++) {
        buf_indx->data[n] = 0;
      }

      n = buf_val->size[0];
      buf_val->size[0] = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
      emxEnsureCapacity_real_T(buf_val, n);
      j = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
      for (n = 0; n < j; n++) {
        buf_val->data[n] = 0.0;
      }

      ind = 1U;
      for (j = A_row_ptr->data[i - 1]; j < A_row_ptr->data[i]; j++) {
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
      for (j = A_row_ptr->data[i - 1]; j < A_row_ptr->data[i]; j++) {
        col_ind->data[j - 1] = buf_indx->data[(int)ind - 1];
        val->data[j - 1] = buf_val->data[(int)ind - 1];
        ind++;
      }
    }

    i++;
  }

  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
  i0 = A_col_ind->size[0];
  A_col_ind->size[0] = col_ind->size[0];
  emxEnsureCapacity_int32_T(A_col_ind, i0);
  j = col_ind->size[0];
  for (i0 = 0; i0 < j; i0++) {
    A_col_ind->data[i0] = col_ind->data[i0];
  }

  emxFree_int32_T(&col_ind);
  i0 = A_val->size[0];
  A_val->size[0] = val->size[0];
  emxEnsureCapacity_real_T(A_val, i0);
  j = val->size[0];
  for (i0 = 0; i0 < j; i0++) {
    A_val->data[i0] = val->data[i0];
  }

  emxFree_real_T(&val);
  *A_nrows = mtmp;
  *A_ncols = b_mtmp;
}

void crs_transp(const struct0_T *A, struct0_T *At)
{
  emxArray_int32_T *js;
  unsigned int unnamed_idx_0;
  int nrows;
  int i;
  int j;
  emxInit_int32_T(&js, 1);
  unnamed_idx_0 = (unsigned int)A->col_ind->size[0];
  nrows = js->size[0];
  js->size[0] = (int)unnamed_idx_0;
  emxEnsureCapacity_int32_T(js, nrows);
  nrows = A->row_ptr->size[0] - 1;
  for (i = 1; i <= nrows; i++) {
    for (j = A->row_ptr->data[i - 1]; j < A->row_ptr->data[i]; j++) {
      js->data[j - 1] = i;
    }
  }

  crs_createFromAIJ(A->col_ind, js, A->val, At->row_ptr, At->col_ind, At->val,
                    &At->nrows, &At->ncols);
  emxFree_int32_T(&js);
}

void crs_transp_initialize(void)
{
}

void crs_transp_terminate(void)
{
}
