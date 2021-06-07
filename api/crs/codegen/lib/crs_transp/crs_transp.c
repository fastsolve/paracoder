#include "crs_transp.h"
#include "m2c.h"
#include "crs_transp_types.h"

void crs_transp(const CRS_Matrix *A, CRS_Matrix *At)
{
  emxArray_int32_T *buf_indx;
  emxArray_int32_T *js;
  emxArray_real_T *buf_val;
  double t0;
  int b_i;
  int exitg2;
  int exitg3;
  int i;
  int i1;
  int ir;
  int j;
  int k;
  int l;
  int nrows;
  boolean_T ascend;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  emxInit_int32_T(&js, 1);
  i = js->size[0];
  js->size[0] = A->col_ind->size[0];
  emxEnsureCapacity_int32_T(js, i);
  nrows = A->row_ptr->size[0];
  for (b_i = 0; b_i <= nrows - 2; b_i++) {
    i = A->row_ptr->data[b_i];
    i1 = A->row_ptr->data[b_i + 1] - 1;
    for (j = i; j <= i1; j++) {
      js->data[j - 1] = b_i + 1;
    }
  }
  l = A->col_ind->size[0];
  nrows = 0;
  if (A->col_ind->size[0] >= 1) {
    nrows = A->col_ind->data[0];
    for (k = 2; k <= l; k++) {
      i = A->col_ind->data[k - 1];
      if (nrows < i) {
        nrows = i;
      }
    }
  }
  l = js->size[0];
  ir = 0;
  if (js->size[0] >= 1) {
    ir = js->data[0];
    for (k = 2; k <= l; k++) {
      i = js->data[k - 1];
      if (ir < i) {
        ir = i;
      }
    }
  }
  At->ncols = ir;
  i = At->row_ptr->size[0];
  At->row_ptr->size[0] = nrows + 1;
  emxEnsureCapacity_int32_T(At->row_ptr, i);
  for (i = 0; i <= nrows; i++) {
    At->row_ptr->data[i] = 0;
  }
  i = At->col_ind->size[0];
  At->col_ind->size[0] = js->size[0];
  emxEnsureCapacity_int32_T(At->col_ind, i);
  l = js->size[0];
  for (i = 0; i < l; i++) {
    At->col_ind->data[i] = 0;
  }
  i = At->val->size[0];
  At->val->size[0] = js->size[0];
  emxEnsureCapacity_real_T(At->val, i);
  l = js->size[0];
  for (i = 0; i < l; i++) {
    At->val->data[i] = 0.0;
  }
  At->nrows = nrows;
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
    l = js->size[0];
    for (i = 0; i < l; i++) {
      At->col_ind->data[i] = js->data[i];
    }
    i = At->val->size[0];
    At->val->size[0] = A->val->size[0];
    emxEnsureCapacity_real_T(At->val, i);
    l = A->val->size[0];
    for (i = 0; i < l; i++) {
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
      i1 = At->row_ptr->data[A->col_ind->data[b_i] - 1];
      At->val->data[i1 - 1] = A->val->data[b_i];
      At->col_ind->data[i1 - 1] = js->data[b_i];
      At->row_ptr->data[A->col_ind->data[b_i] - 1] = i1 + 1;
    }
    i = At->row_ptr->size[0] - 2;
    i1 = (int)(((-1.0 - (double)At->row_ptr->size[0]) + 2.0) / -1.0);
    for (b_i = 0; b_i < i1; b_i++) {
      k = i - b_i;
      At->row_ptr->data[k + 1] = At->row_ptr->data[k];
    }
    At->row_ptr->data[0] = 1;
  }
  i = js->size[0];
  js->size[0] = At->col_ind->size[0];
  emxEnsureCapacity_int32_T(js, i);
  l = At->col_ind->size[0];
  for (i = 0; i < l; i++) {
    js->data[i] = At->col_ind->data[i];
  }
  i = At->row_ptr->size[0];
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  for (b_i = 0; b_i <= i - 2; b_i++) {
    ascend = true;
    j = At->row_ptr->data[b_i];
    do {
      exitg2 = 0;
      i1 = At->row_ptr->data[b_i + 1];
      if (j + 1 <= i1 - 1) {
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
      l = i1 - At->row_ptr->data[b_i];
      i1 = buf_indx->size[0];
      buf_indx->size[0] = l;
      emxEnsureCapacity_int32_T(buf_indx, i1);
      for (i1 = 0; i1 < l; i1++) {
        buf_indx->data[i1] = 0;
      }
      i1 = buf_val->size[0];
      buf_val->size[0] = l;
      emxEnsureCapacity_real_T(buf_val, i1);
      for (i1 = 0; i1 < l; i1++) {
        buf_val->data[i1] = 0.0;
      }
      i1 = At->row_ptr->data[b_i];
      ir = At->row_ptr->data[b_i + 1] - 1;
      for (j = i1; j <= ir; j++) {
        l = (int)((unsigned int)j - i1);
        buf_indx->data[l] = js->data[j - 1];
        buf_val->data[l] = At->val->data[j - 1];
      }
      if (buf_indx->size[0] > 1) {
        l = (int)((unsigned int)buf_indx->size[0] >> 1);
        ir = buf_indx->size[0];
        do {
          exitg2 = 0;
          guard1 = false;
          if (l + 1 <= 1) {
            nrows = buf_indx->data[ir - 1];
            t0 = buf_val->data[ir - 1];
            buf_indx->data[ir - 1] = buf_indx->data[0];
            buf_val->data[ir - 1] = buf_val->data[0];
            ir--;
            if (ir == 1) {
              exitg2 = 1;
            } else {
              guard1 = true;
            }
          } else {
            l--;
            nrows = buf_indx->data[l];
            t0 = buf_val->data[l];
            guard1 = true;
          }
          if (guard1) {
            j = l;
            do {
              exitg3 = 0;
              k = j;
              j = ((j + 1) << 1) - 1;
              ascend = false;
              guard2 = false;
              if (j + 1 >= ir) {
                if (j + 1 == ir) {
                  ascend = true;
                  guard2 = true;
                } else if (j + 1 > ir) {
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
      i1 = At->row_ptr->data[b_i];
      ir = At->row_ptr->data[b_i + 1] - 1;
      for (j = i1; j <= ir; j++) {
        l = (int)((unsigned int)j - i1);
        js->data[j - 1] = buf_indx->data[l];
        At->val->data[j - 1] = buf_val->data[l];
      }
    }
  }
  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
  i = At->col_ind->size[0];
  At->col_ind->size[0] = js->size[0];
  emxEnsureCapacity_int32_T(At->col_ind, i);
  l = js->size[0];
  for (i = 0; i < l; i++) {
    At->col_ind->data[i] = js->data[i];
  }
  emxFree_int32_T(&js);
}

void crs_transp_initialize(void)
{
}

void crs_transp_terminate(void)
{
}
