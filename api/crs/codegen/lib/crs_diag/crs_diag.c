#include "crs_diag.h"
#include "m2c.h"
#include "crs_diag_types.h"

void crs_diag(const CRS_Matrix *A, emxArray_real_T *D)
{
  int b_i;
  int i;
  int loop_ub;
  boolean_T exitg1;
  i = D->size[0];
  D->size[0] = A->nrows;
  emxEnsureCapacity_real_T(D, i);
  loop_ub = A->nrows;
  for (i = 0; i < loop_ub; i++) {
    D->data[i] = 0.0;
  }
  i = A->nrows;
  for (b_i = 0; b_i < i; b_i++) {
    loop_ub = A->row_ptr->data[b_i];
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= A->row_ptr->data[b_i + 1] - 1)) {
      if (A->col_ind->data[loop_ub - 1] == b_i + 1) {
        D->data[b_i] = A->val->data[loop_ub - 1];
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
  }
}

void crs_diag1(const CRS_Matrix *A, int k, emxArray_real_T *D)
{
  int b_i;
  int i;
  int i1;
  int y;
  boolean_T exitg1;
  if (k < 0) {
    y = -k;
  } else {
    y = k;
  }
  i = D->size[0];
  D->size[0] = A->nrows - y;
  emxEnsureCapacity_real_T(D, i);
  y = A->nrows - y;
  for (i = 0; i < y; i++) {
    D->data[i] = 0.0;
  }
  if (k >= 0) {
    i = A->nrows;
    for (b_i = 0; b_i < i; b_i++) {
      y = A->row_ptr->data[b_i];
      exitg1 = false;
      while ((!exitg1) && (y <= A->row_ptr->data[b_i + 1] - 1)) {
        if (A->col_ind->data[y - 1] == (b_i + k) + 1) {
          D->data[b_i] = A->val->data[y - 1];
          exitg1 = true;
        } else {
          y++;
        }
      }
    }
  } else {
    i = A->nrows;
    for (b_i = 0; b_i < i; b_i++) {
      y = A->row_ptr->data[b_i];
      exitg1 = false;
      while ((!exitg1) && (y <= A->row_ptr->data[b_i + 1] - 1)) {
        i1 = b_i + k;
        if (A->col_ind->data[y - 1] == i1 + 1) {
          D->data[i1] = A->val->data[y - 1];
          exitg1 = true;
        } else {
          y++;
        }
      }
    }
  }
}

void crs_diag_initialize(void)
{
}

void crs_diag_terminate(void)
{
}
