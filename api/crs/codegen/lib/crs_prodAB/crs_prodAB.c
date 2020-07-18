#include "crs_prodAB.h"
#include "m2c.h"

static void m2c_error(void);
static void m2c_error(void)
{
  M2C_error("crs_prodMatMat:WrongSizes",
            "Number of columns of A must be equal to number of rows in B.");
}

void crs_prodAB(const CRS_Matrix *A, const CRS_Matrix *B, CRS_Matrix *C)
{
  emxArray_int32_T *buf_indx;
  int varargin_1;
  int i;
  int clength;
  int b_i;
  int istart;
  int i1;
  int i2;
  int jj;
  emxArray_real_T *buf_val;
  int i3;
  int i4;
  int k;
  int i5;
  if (A->ncols != B->nrows) {
    m2c_error();
  }

  emxInit_int32_T(&buf_indx, 1);
  varargin_1 = A->nrows;
  i = buf_indx->size[0];
  buf_indx->size[0] = A->nrows + 1;
  emxEnsureCapacity_int32_T(buf_indx, i);
  clength = A->nrows;
  for (i = 0; i <= clength; i++) {
    buf_indx->data[i] = 0;
  }

  buf_indx->data[0] = 1;
  for (b_i = 0; b_i < varargin_1; b_i++) {
    buf_indx->data[b_i + 1] += buf_indx->data[b_i];
  }

  i = buf_indx->size[0];
  for (b_i = 0; b_i <= i - 2; b_i++) {
    if (buf_indx->data[b_i] + 1 <= buf_indx->data[b_i + 1] - 1) {
      abort();
    }
  }

  i = C->row_ptr->size[0];
  C->row_ptr->size[0] = buf_indx->size[0];
  emxEnsureCapacity_int32_T(C->row_ptr, i);
  clength = buf_indx->size[0];
  for (i = 0; i < clength; i++) {
    C->row_ptr->data[i] = buf_indx->data[i];
  }

  C->nrows = A->nrows;
  C->ncols = B->ncols;
  i = C->row_ptr->size[0];
  C->row_ptr->size[0] = A->row_ptr->size[0];
  emxEnsureCapacity_int32_T(C->row_ptr, i);
  C->row_ptr->data[0] = 1;
  clength = A->ncols;
  varargin_1 = B->ncols;
  if (clength > varargin_1) {
    varargin_1 = clength;
  }

  i = buf_indx->size[0];
  buf_indx->size[0] = varargin_1;
  emxEnsureCapacity_int32_T(buf_indx, i);
  for (i = 0; i < varargin_1; i++) {
    buf_indx->data[i] = 0;
  }

  i = A->nrows;
  for (b_i = 0; b_i < i; b_i++) {
    istart = -1;
    clength = 0;
    i1 = A->row_ptr->data[b_i];
    i2 = A->row_ptr->data[b_i + 1] - 1;
    for (jj = i1; jj <= i2; jj++) {
      i3 = A->col_ind->data[jj - 1];
      i4 = B->row_ptr->data[i3 - 1];
      i3 = B->row_ptr->data[i3] - 1;
      for (k = i4; k <= i3; k++) {
        varargin_1 = B->col_ind->data[k - 1];
        i5 = varargin_1 - 1;
        if (buf_indx->data[i5] == 0) {
          buf_indx->data[i5] = istart;
          istart = varargin_1;
          clength++;
        }
      }
    }

    i1 = C->row_ptr->data[b_i];
    i2 = C->row_ptr->data[b_i] + clength;
    C->row_ptr->data[b_i + 1] = i2;
    i2--;
    for (clength = i1; clength <= i2; clength++) {
      k = istart;
      istart = buf_indx->data[istart - 1];
      buf_indx->data[k - 1] = 0;
    }

    buf_indx->data[b_i] = 0;
  }

  i = C->col_ind->size[0];
  C->col_ind->size[0] = C->row_ptr->data[A->nrows] - 1;
  emxEnsureCapacity_int32_T(C->col_ind, i);
  i = A->nrows;
  for (b_i = 0; b_i < i; b_i++) {
    istart = -1;
    clength = 0;
    i1 = A->row_ptr->data[b_i];
    i2 = A->row_ptr->data[b_i + 1] - 1;
    for (jj = i1; jj <= i2; jj++) {
      i3 = A->col_ind->data[jj - 1];
      i4 = B->row_ptr->data[i3 - 1];
      i3 = B->row_ptr->data[i3] - 1;
      for (k = i4; k <= i3; k++) {
        varargin_1 = B->col_ind->data[k - 1];
        i5 = varargin_1 - 1;
        if (buf_indx->data[i5] == 0) {
          buf_indx->data[i5] = istart;
          istart = varargin_1;
          clength++;
        }
      }
    }

    i1 = C->row_ptr->data[b_i];
    i2 = C->row_ptr->data[b_i] + clength;
    C->row_ptr->data[b_i + 1] = i2;
    i2--;
    for (clength = i1; clength <= i2; clength++) {
      C->col_ind->data[clength - 1] = istart;
      istart = buf_indx->data[istart - 1];
      buf_indx->data[C->col_ind->data[clength - 1] - 1] = 0;
    }

    buf_indx->data[b_i] = 0;
  }

  emxInit_real_T(&buf_val, 1);
  i = C->val->size[0];
  C->val->size[0] = C->row_ptr->data[A->nrows] - 1;
  emxEnsureCapacity_real_T(C->val, i);
  i = buf_val->size[0];
  buf_val->size[0] = buf_indx->size[0];
  emxEnsureCapacity_real_T(buf_val, i);
  clength = buf_indx->size[0];
  emxFree_int32_T(&buf_indx);
  for (i = 0; i < clength; i++) {
    buf_val->data[i] = 0.0;
  }

  i = A->nrows;
  for (b_i = 0; b_i < i; b_i++) {
    i1 = A->row_ptr->data[b_i];
    i2 = A->row_ptr->data[b_i + 1] - 1;
    for (jj = i1; jj <= i2; jj++) {
      i3 = A->col_ind->data[jj - 1];
      i4 = B->row_ptr->data[i3 - 1];
      i3 = B->row_ptr->data[i3] - 1;
      for (k = i4; k <= i3; k++) {
        clength = B->col_ind->data[k - 1] - 1;
        buf_val->data[clength] += A->val->data[jj - 1] * B->val->data[k - 1];
      }
    }

    i1 = C->row_ptr->data[b_i];
    i2 = C->row_ptr->data[b_i + 1] - 1;
    for (clength = i1; clength <= i2; clength++) {
      i3 = C->col_ind->data[clength - 1] - 1;
      C->val->data[clength - 1] = buf_val->data[i3];
      buf_val->data[i3] = 0.0;
    }
  }

  emxFree_real_T(&buf_val);
}

void crs_prodAB_initialize(void)
{
}

void crs_prodAB_terminate(void)
{
}
