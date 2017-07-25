#include "ccs_solve_triu.h"

void ccs_solve_triu(const struct0_T *U, emxArray_real_T *b)
{
  int j;
  int k;
  for (j = U->col_ptr->size[0] - 2; j + 1 > 0; j--) {
    b->data[j] /= U->val->data[U->col_ptr->data[j + 1] - 2];
    for (k = U->col_ptr->data[j] - 1; k + 1 <= U->col_ptr->data[j + 1] - 2; k++)
    {
      b->data[U->row_ind->data[k] - 1] -= U->val->data[k] * b->data[j];
    }
  }
}

void ccs_solve_triu_initialize(void)
{
}

void ccs_solve_triu_terminate(void)
{
}
