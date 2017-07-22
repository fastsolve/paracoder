#include "crs_solve_triu.h"

void crs_solve_triu(const struct0_T *A, emxArray_real_T *b)
{
  int i;
  int cind;
  for (i = A->row_ptr->size[0] - 2; i + 1 > 0; i--) {
    for (cind = A->row_ptr->data[i]; cind + 1 < A->row_ptr->data[i + 1]; cind++)
    {
      b->data[i] -= A->val->data[cind] * b->data[A->col_ind->data[cind] - 1];
    }

    b->data[i] /= A->val->data[A->row_ptr->data[i] - 1];
  }
}

void crs_solve_triu_initialize(void)
{
}

void crs_solve_triu_terminate(void)
{
}
