#include "crs_prodAB.h"
#include "crs_prodAB_types.h"
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
  emxArray_real_T *buf_val;
  int b_i;
  int clength;
  int i;
  int i1;
  int i2;
  int i3;
  int istart;
  int jj;
  int k;
  int u1;
  int varargin_1_tmp;
  if (A->ncols != B->nrows) {
    m2c_error();
  }
  varargin_1_tmp = A->nrows;
  i = C->row_ptr->size[0];
  C->row_ptr->size[0] = A->nrows + 1;
  emxEnsureCapacity_int32_T(C->row_ptr, i);
  for (i = 0; i <= varargin_1_tmp; i++) {
    C->row_ptr->data[i] = 0;
  }
  C->row_ptr->data[0] = 1;
  for (b_i = 0; b_i < varargin_1_tmp; b_i++) {
    C->row_ptr->data[b_i + 1] += C->row_ptr->data[b_i];
  }
  emxInit_int32_T(&buf_indx, 1);
  C->nrows = A->nrows;
  C->ncols = B->ncols;
  i = C->row_ptr->size[0];
  C->row_ptr->size[0] = A->row_ptr->size[0];
  emxEnsureCapacity_int32_T(C->row_ptr, i);
  C->row_ptr->data[0] = 1;
  clength = A->ncols;
  u1 = B->ncols;
  if (clength > u1) {
    u1 = clength;
  }
  i = buf_indx->size[0];
  buf_indx->size[0] = u1;
  emxEnsureCapacity_int32_T(buf_indx, i);
  for (i = 0; i < u1; i++) {
    buf_indx->data[i] = 0;
  }
  for (b_i = 0; b_i < varargin_1_tmp; b_i++) {
    istart = -1;
    clength = 0;
    i = A->row_ptr->data[b_i];
    i1 = A->row_ptr->data[b_i + 1] - 1;
    for (jj = i; jj <= i1; jj++) {
      i2 = A->col_ind->data[jj - 1];
      i3 = B->row_ptr->data[i2 - 1];
      i2 = B->row_ptr->data[i2] - 1;
      for (k = i3; k <= i2; k++) {
        u1 = B->col_ind->data[k - 1];
        if (buf_indx->data[u1 - 1] == 0) {
          buf_indx->data[u1 - 1] = istart;
          istart = u1;
          clength++;
        }
      }
    }
    i = C->row_ptr->data[b_i];
    i1 = C->row_ptr->data[b_i] + clength;
    C->row_ptr->data[b_i + 1] = i1;
    i1--;
    for (u1 = i; u1 <= i1; u1++) {
      k = istart;
      istart = buf_indx->data[istart - 1];
      buf_indx->data[k - 1] = 0;
    }
    buf_indx->data[b_i] = 0;
  }
  i = C->col_ind->size[0];
  C->col_ind->size[0] = C->row_ptr->data[A->nrows] - 1;
  emxEnsureCapacity_int32_T(C->col_ind, i);
  for (b_i = 0; b_i < varargin_1_tmp; b_i++) {
    istart = -1;
    clength = 0;
    i = A->row_ptr->data[b_i];
    i1 = A->row_ptr->data[b_i + 1] - 1;
    for (jj = i; jj <= i1; jj++) {
      i2 = A->col_ind->data[jj - 1];
      i3 = B->row_ptr->data[i2 - 1];
      i2 = B->row_ptr->data[i2] - 1;
      for (k = i3; k <= i2; k++) {
        u1 = B->col_ind->data[k - 1];
        if (buf_indx->data[u1 - 1] == 0) {
          buf_indx->data[u1 - 1] = istart;
          istart = u1;
          clength++;
        }
      }
    }
    i = C->row_ptr->data[b_i];
    i1 = C->row_ptr->data[b_i] + clength;
    C->row_ptr->data[b_i + 1] = i1;
    i1--;
    for (u1 = i; u1 <= i1; u1++) {
      C->col_ind->data[u1 - 1] = istart;
      istart = buf_indx->data[istart - 1];
      buf_indx->data[C->col_ind->data[u1 - 1] - 1] = 0;
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
  for (b_i = 0; b_i < varargin_1_tmp; b_i++) {
    i = A->row_ptr->data[b_i];
    i1 = A->row_ptr->data[b_i + 1] - 1;
    for (jj = i; jj <= i1; jj++) {
      i2 = A->col_ind->data[jj - 1];
      i3 = B->row_ptr->data[i2 - 1];
      i2 = B->row_ptr->data[i2] - 1;
      for (k = i3; k <= i2; k++) {
        clength = B->col_ind->data[k - 1] - 1;
        buf_val->data[clength] += A->val->data[jj - 1] * B->val->data[k - 1];
      }
    }
    i = C->row_ptr->data[b_i];
    i1 = C->row_ptr->data[b_i + 1] - 1;
    for (u1 = i; u1 <= i1; u1++) {
      i2 = C->col_ind->data[u1 - 1] - 1;
      C->val->data[u1 - 1] = buf_val->data[i2];
      buf_val->data[i2] = 0.0;
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
