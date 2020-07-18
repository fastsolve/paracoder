#include "crs_transp.h"
#include "m2c.h"

void crs_transp(const CRS_Matrix *A, CRS_Matrix *At)
{
  emxArray_int32_T *js;
  int i;
  int nrows;
  int b_i;
  int n;
  int ncols;
  int j;
  int k;
  boolean_T ascend;
  boolean_T exitg1;
  int i1;
  emxArray_real_T *r;
  emxArray_real_T *buf_val;
  emxArray_int32_T *buf_indx;
  int exitg2;
  unsigned int ind;
  boolean_T guard1 = false;
  double t0;
  int exitg3;
  boolean_T guard2 = false;
  emxInit_int32_T(&js, 1);
  i = js->size[0];
  js->size[0] = A->col_ind->size[0];
  emxEnsureCapacity_int32_T(js, i);
  nrows = A->row_ptr->size[0];
  for (b_i = 0; b_i <= nrows - 2; b_i++) {
    i = A->row_ptr->data[b_i];
    ncols = A->row_ptr->data[b_i + 1] - 1;
    for (j = i; j <= ncols; j++) {
      js->data[j - 1] = b_i + 1;
    }
  }

  n = A->col_ind->size[0];
  nrows = 0;
  if (A->col_ind->size[0] >= 1) {
    nrows = A->col_ind->data[0];
    for (k = 2; k <= n; k++) {
      i = A->col_ind->data[k - 1];
      if (nrows < i) {
        nrows = i;
      }
    }
  }

  n = js->size[0];
  ncols = 0;
  if (js->size[0] >= 1) {
    ncols = js->data[0];
    for (k = 2; k <= n; k++) {
      i = js->data[k - 1];
      if (ncols < i) {
        ncols = i;
      }
    }
  }

  i = At->row_ptr->size[0];
  At->row_ptr->size[0] = nrows + 1;
  emxEnsureCapacity_int32_T(At->row_ptr, i);
  for (i = 0; i <= nrows; i++) {
    At->row_ptr->data[i] = 0;
  }

  i = At->col_ind->size[0];
  At->col_ind->size[0] = js->size[0];
  emxEnsureCapacity_int32_T(At->col_ind, i);
  n = js->size[0];
  for (i = 0; i < n; i++) {
    At->col_ind->data[i] = 0;
  }

  i = At->val->size[0];
  At->val->size[0] = js->size[0];
  emxEnsureCapacity_real_T(At->val, i);
  n = js->size[0];
  for (i = 0; i < n; i++) {
    At->val->data[i] = 0.0;
  }

  At->nrows = nrows;
  At->ncols = ncols;
  i = A->col_ind->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    At->row_ptr->data[A->col_ind->data[b_i]]++;
  }

  At->row_ptr->data[0] = 1;
  for (b_i = 0; b_i < nrows; b_i++) {
    At->row_ptr->data[b_i + 1] += At->row_ptr->data[b_i];
  }

  ascend = true;
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= A->col_ind->size[0] - 2)) {
    if (A->col_ind->data[b_i + 1] < A->col_ind->data[b_i]) {
      ascend = false;
      exitg1 = true;
    } else {
      b_i++;
    }
  }

  if (ascend) {
    i = At->col_ind->size[0];
    At->col_ind->size[0] = js->size[0];
    emxEnsureCapacity_int32_T(At->col_ind, i);
    n = js->size[0];
    for (i = 0; i < n; i++) {
      At->col_ind->data[i] = js->data[i];
    }

    i = At->val->size[0];
    At->val->size[0] = A->val->size[0];
    emxEnsureCapacity_real_T(At->val, i);
    n = A->val->size[0];
    for (i = 0; i < n; i++) {
      At->val->data[i] = A->val->data[i];
    }
  } else {
    i = At->col_ind->size[0];
    At->col_ind->size[0] = js->size[0];
    emxEnsureCapacity_int32_T(At->col_ind, i);
    i = At->val->size[0];
    At->val->size[0] = js->size[0];
    emxEnsureCapacity_real_T(At->val, i);
    i = A->col_ind->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      ncols = At->row_ptr->data[A->col_ind->data[b_i] - 1];
      i1 = ncols - 1;
      At->val->data[i1] = A->val->data[b_i];
      At->col_ind->data[i1] = js->data[b_i];
      At->row_ptr->data[A->col_ind->data[b_i] - 1] = ncols + 1;
    }

    n = At->row_ptr->size[0] - 2;
    i = (int)(((-1.0 - (double)At->row_ptr->size[0]) + 2.0) / -1.0);
    for (b_i = 0; b_i < i; b_i++) {
      k = n - b_i;
      At->row_ptr->data[k + 1] = At->row_ptr->data[k];
    }

    At->row_ptr->data[0] = 1;
  }

  i = js->size[0];
  js->size[0] = At->col_ind->size[0];
  emxEnsureCapacity_int32_T(js, i);
  n = At->col_ind->size[0];
  for (i = 0; i < n; i++) {
    js->data[i] = At->col_ind->data[i];
  }

  emxInit_real_T(&r, 1);
  i = r->size[0];
  r->size[0] = At->val->size[0];
  emxEnsureCapacity_real_T(r, i);
  n = At->val->size[0];
  for (i = 0; i < n; i++) {
    r->data[i] = At->val->data[i];
  }

  i = At->row_ptr->size[0];
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  for (b_i = 0; b_i <= i - 2; b_i++) {
    ascend = true;
    j = At->row_ptr->data[b_i];
    do {
      exitg2 = 0;
      ncols = At->row_ptr->data[b_i + 1];
      i1 = ncols - 1;
      if (j + 1 <= i1) {
        if (js->data[j] < js->data[j - 1]) {
          ascend = false;
          exitg2 = 1;
        } else {
          j++;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (!ascend) {
      n = ncols - At->row_ptr->data[b_i];
      ncols = buf_indx->size[0];
      buf_indx->size[0] = n;
      emxEnsureCapacity_int32_T(buf_indx, ncols);
      for (ncols = 0; ncols < n; ncols++) {
        buf_indx->data[ncols] = 0;
      }

      ncols = buf_val->size[0];
      buf_val->size[0] = n;
      emxEnsureCapacity_real_T(buf_val, ncols);
      for (ncols = 0; ncols < n; ncols++) {
        buf_val->data[ncols] = 0.0;
      }

      ind = 1U;
      ncols = At->row_ptr->data[b_i];
      for (j = ncols; j <= i1; j++) {
        n = (int)ind - 1;
        buf_indx->data[n] = js->data[j - 1];
        buf_val->data[n] = r->data[j - 1];
        ind++;
      }

      if (buf_indx->size[0] > 1) {
        n = (int)((unsigned int)buf_indx->size[0] >> 1U);
        ncols = buf_indx->size[0];
        do {
          exitg2 = 0;
          guard1 = false;
          if (n + 1 <= 1) {
            nrows = buf_indx->data[ncols - 1];
            t0 = buf_val->data[ncols - 1];
            buf_indx->data[ncols - 1] = buf_indx->data[0];
            buf_val->data[ncols - 1] = buf_val->data[0];
            ncols--;
            if (ncols == 1) {
              exitg2 = 1;
            } else {
              guard1 = true;
            }
          } else {
            n--;
            nrows = buf_indx->data[n];
            t0 = buf_val->data[n];
            guard1 = true;
          }

          if (guard1) {
            j = n;
            do {
              exitg3 = 0;
              k = j;
              j = ((j + 1) << 1) - 1;
              ascend = false;
              guard2 = false;
              if (j + 1 >= ncols) {
                if (j + 1 == ncols) {
                  ascend = true;
                  guard2 = true;
                } else if (j + 1 > ncols) {
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

                if (nrows >= buf_indx->data[j]) {
                  exitg3 = 1;
                } else {
                  buf_indx->data[k] = buf_indx->data[j];
                  buf_val->data[k] = buf_val->data[j];
                }
              }
            } while (exitg3 == 0);

            buf_indx->data[k] = nrows;
            buf_val->data[k] = t0;
          }
        } while (exitg2 == 0);

        buf_indx->data[0] = nrows;
        buf_val->data[0] = t0;
      }

      ind = 1U;
      ncols = At->row_ptr->data[b_i];
      for (j = ncols; j <= i1; j++) {
        n = (int)ind - 1;
        js->data[j - 1] = buf_indx->data[n];
        r->data[j - 1] = buf_val->data[n];
        ind++;
      }
    }
  }

  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
  i = At->col_ind->size[0];
  At->col_ind->size[0] = js->size[0];
  emxEnsureCapacity_int32_T(At->col_ind, i);
  n = js->size[0];
  for (i = 0; i < n; i++) {
    At->col_ind->data[i] = js->data[i];
  }

  emxFree_int32_T(&js);
  i = At->val->size[0];
  At->val->size[0] = r->size[0];
  emxEnsureCapacity_real_T(At->val, i);
  n = r->size[0];
  for (i = 0; i < n; i++) {
    At->val->data[i] = r->data[i];
  }

  emxFree_real_T(&r);
}

void crs_transp_initialize(void)
{
}

void crs_transp_terminate(void)
{
}
