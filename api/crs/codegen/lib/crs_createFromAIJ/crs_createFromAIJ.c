#include "crs_createFromAIJ.h"
#include "m2c.h"

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

void crs_create1(const emxArray_int32_T *is, const emxArray_int32_T *js, const
                 emxArray_real_T *vs, int ni, int nj, struct0_T *A)
{
  int i;
  int n;
  int b_i;
  boolean_T ascend;
  boolean_T exitg1;
  int c_i;
  A->ncols = nj;
  i = A->row_ptr->size[0];
  A->row_ptr->size[0] = ni + 1;
  emxEnsureCapacity_int32_T(A->row_ptr, i);
  for (i = 0; i <= ni; i++) {
    A->row_ptr->data[i] = 0;
  }

  i = A->col_ind->size[0];
  A->col_ind->size[0] = js->size[0];
  emxEnsureCapacity_int32_T(A->col_ind, i);
  n = js->size[0];
  for (i = 0; i < n; i++) {
    A->col_ind->data[i] = 0;
  }

  i = A->val->size[0];
  A->val->size[0] = js->size[0];
  emxEnsureCapacity_real_T(A->val, i);
  n = js->size[0];
  for (i = 0; i < n; i++) {
    A->val->data[i] = 0.0;
  }

  A->nrows = ni;
  i = is->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    A->row_ptr->data[is->data[b_i]]++;
  }

  A->row_ptr->data[0] = 1;
  for (b_i = 0; b_i < ni; b_i++) {
    A->row_ptr->data[b_i + 1] += A->row_ptr->data[b_i];
  }

  ascend = true;
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= is->size[0] - 2)) {
    if (is->data[b_i + 1] < is->data[b_i]) {
      ascend = false;
      exitg1 = true;
    } else {
      b_i++;
    }
  }

  if (ascend) {
    i = A->col_ind->size[0];
    A->col_ind->size[0] = js->size[0];
    emxEnsureCapacity_int32_T(A->col_ind, i);
    n = js->size[0];
    for (i = 0; i < n; i++) {
      A->col_ind->data[i] = js->data[i];
    }

    i = A->val->size[0];
    A->val->size[0] = vs->size[0];
    emxEnsureCapacity_real_T(A->val, i);
    n = vs->size[0];
    for (i = 0; i < n; i++) {
      A->val->data[i] = vs->data[i];
    }
  } else {
    i = A->col_ind->size[0];
    A->col_ind->size[0] = js->size[0];
    emxEnsureCapacity_int32_T(A->col_ind, i);
    i = A->val->size[0];
    A->val->size[0] = js->size[0];
    emxEnsureCapacity_real_T(A->val, i);
    i = is->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      n = A->row_ptr->data[is->data[b_i] - 1];
      c_i = n - 1;
      A->val->data[c_i] = vs->data[b_i];
      A->col_ind->data[c_i] = js->data[b_i];
      A->row_ptr->data[is->data[b_i] - 1] = n + 1;
    }

    n = A->row_ptr->size[0] - 2;
    i = (int)(((-1.0 - (double)A->row_ptr->size[0]) + 2.0) / -1.0);
    for (b_i = 0; b_i < i; b_i++) {
      c_i = n - b_i;
      A->row_ptr->data[c_i + 1] = A->row_ptr->data[c_i];
    }

    A->row_ptr->data[0] = 1;
  }

  crs_sort(A->row_ptr, A->col_ind, A->val);
}

void crs_createFromAIJ(const emxArray_int32_T *rows, const emxArray_int32_T
  *cols, const emxArray_real_T *vs, struct0_T *A)
{
  int n;
  int nrows;
  int k;
  int ncols;
  int i;
  boolean_T ascend;
  boolean_T exitg1;
  n = rows->size[0];
  nrows = 0;
  if (rows->size[0] >= 1) {
    nrows = rows->data[0];
    for (k = 2; k <= n; k++) {
      i = rows->data[k - 1];
      if (nrows < i) {
        nrows = i;
      }
    }
  }

  n = cols->size[0];
  ncols = 0;
  if (cols->size[0] >= 1) {
    ncols = cols->data[0];
    for (k = 2; k <= n; k++) {
      i = cols->data[k - 1];
      if (ncols < i) {
        ncols = i;
      }
    }
  }

  i = A->row_ptr->size[0];
  A->row_ptr->size[0] = nrows + 1;
  emxEnsureCapacity_int32_T(A->row_ptr, i);
  for (i = 0; i <= nrows; i++) {
    A->row_ptr->data[i] = 0;
  }

  i = A->col_ind->size[0];
  A->col_ind->size[0] = cols->size[0];
  emxEnsureCapacity_int32_T(A->col_ind, i);
  n = cols->size[0];
  for (i = 0; i < n; i++) {
    A->col_ind->data[i] = 0;
  }

  i = A->val->size[0];
  A->val->size[0] = cols->size[0];
  emxEnsureCapacity_real_T(A->val, i);
  n = cols->size[0];
  for (i = 0; i < n; i++) {
    A->val->data[i] = 0.0;
  }

  A->nrows = nrows;
  A->ncols = ncols;
  i = rows->size[0];
  for (k = 0; k < i; k++) {
    A->row_ptr->data[rows->data[k]]++;
  }

  A->row_ptr->data[0] = 1;
  for (k = 0; k < nrows; k++) {
    A->row_ptr->data[k + 1] += A->row_ptr->data[k];
  }

  ascend = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= rows->size[0] - 2)) {
    if (rows->data[k + 1] < rows->data[k]) {
      ascend = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (ascend) {
    i = A->col_ind->size[0];
    A->col_ind->size[0] = cols->size[0];
    emxEnsureCapacity_int32_T(A->col_ind, i);
    n = cols->size[0];
    for (i = 0; i < n; i++) {
      A->col_ind->data[i] = cols->data[i];
    }

    i = A->val->size[0];
    A->val->size[0] = vs->size[0];
    emxEnsureCapacity_real_T(A->val, i);
    n = vs->size[0];
    for (i = 0; i < n; i++) {
      A->val->data[i] = vs->data[i];
    }
  } else {
    i = A->col_ind->size[0];
    A->col_ind->size[0] = cols->size[0];
    emxEnsureCapacity_int32_T(A->col_ind, i);
    i = A->val->size[0];
    A->val->size[0] = cols->size[0];
    emxEnsureCapacity_real_T(A->val, i);
    i = rows->size[0];
    for (k = 0; k < i; k++) {
      n = A->row_ptr->data[rows->data[k] - 1];
      ncols = n - 1;
      A->val->data[ncols] = vs->data[k];
      A->col_ind->data[ncols] = cols->data[k];
      A->row_ptr->data[rows->data[k] - 1] = n + 1;
    }

    n = A->row_ptr->size[0] - 2;
    i = (int)(((-1.0 - (double)A->row_ptr->size[0]) + 2.0) / -1.0);
    for (k = 0; k < i; k++) {
      ncols = n - k;
      A->row_ptr->data[ncols + 1] = A->row_ptr->data[ncols];
    }

    A->row_ptr->data[0] = 1;
  }

  crs_sort(A->row_ptr, A->col_ind, A->val);
}

void crs_createFromAIJ_initialize(void)
{
}

void crs_createFromAIJ_terminate(void)
{
}
