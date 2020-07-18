#include "crs_solve_trilt.h"

void crs_solve_trilt(const CRS_Matrix *A, emxArray_real_T *b)
{
  int n;
  int i;
  int b_i;
  int i1;
  int k;
  int i2;
  n = A->row_ptr->size[0] - 1;
  for (i = n; i >= 1; i--) {
    b->data[i - 1] /= A->val->data[A->row_ptr->data[i] - 2];
    b_i = A->row_ptr->data[i - 1];
    i1 = A->row_ptr->data[i] - 2;
    for (k = b_i; k <= i1; k++) {
      i2 = A->col_ind->data[k - 1] - 1;
      b->data[i2] -= A->val->data[k - 1] * b->data[i - 1];
    }
  }
}

void crs_solve_trilt_initialize(void)
{
}

void crs_solve_trilt_terminate(void)
{
}
