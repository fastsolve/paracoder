#include "crs_solve_triut.h"

void crs_solve_triut(const CRS_Matrix *A, emxArray_real_T *b)
{
  int i;
  int b_i;
  int i1;
  int i2;
  int k;
  int i3;
  i = A->row_ptr->size[0];
  for (b_i = 0; b_i <= i - 2; b_i++) {
    b->data[b_i] /= A->val->data[A->row_ptr->data[b_i] - 1];
    i1 = A->row_ptr->data[b_i] + 1;
    i2 = A->row_ptr->data[b_i + 1] - 1;
    for (k = i1; k <= i2; k++) {
      i3 = A->col_ind->data[k - 1] - 1;
      b->data[i3] -= A->val->data[k - 1] * b->data[b_i];
    }
  }
}

void crs_solve_triut_initialize(void)
{
}

void crs_solve_triut_terminate(void)
{
}
