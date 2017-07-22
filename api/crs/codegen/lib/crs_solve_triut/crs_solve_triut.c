#include "crs_solve_triut.h"

void crs_solve_triut(const struct0_T *A, emxArray_real_T *b)
{
  int i0;
  int i;
  int k;
  i0 = A->row_ptr->size[0] - 1;
  for (i = 0; i + 1 <= i0; i++) {
    b->data[i] /= A->val->data[A->row_ptr->data[i] - 1];
    for (k = A->row_ptr->data[i]; k + 1 < A->row_ptr->data[i + 1]; k++) {
      b->data[A->col_ind->data[k] - 1] -= A->val->data[k] * b->data[i];
    }
  }
}

void crs_solve_triut_initialize(void)
{
}

void crs_solve_triut_terminate(void)
{
}
