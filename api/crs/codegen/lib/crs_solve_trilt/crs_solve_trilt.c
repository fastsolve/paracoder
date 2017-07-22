#include "crs_solve_trilt.h"

void crs_solve_trilt(const struct0_T *A, emxArray_real_T *b)
{
  int i;
  int k;
  for (i = A->row_ptr->size[0] - 2; i + 1 > 0; i--) {
    b->data[i] /= A->val->data[A->row_ptr->data[i + 1] - 2];
    for (k = A->row_ptr->data[i] - 1; k + 1 <= A->row_ptr->data[i + 1] - 2; k++)
    {
      b->data[A->col_ind->data[k] - 1] -= A->val->data[k] * b->data[i];
    }
  }
}

void crs_solve_trilt_initialize(void)
{
}

void crs_solve_trilt_terminate(void)
{
}
