#include "ccs_solve_triut.h"

void ccs_solve_triut(const struct0_T *U, emxArray_real_T *b)
{
  int n;
  int j;
  int k;
  n = U->col_ptr->size[0] - 1;
  for (j = 0; j + 1 <= n; j++) {
    for (k = U->col_ptr->data[j]; k <= U->col_ptr->data[j + 1] - 2; k++) {
      b->data[j] -= U->val->data[k - 1] * b->data[U->row_ind->data[k - 1] - 1];
    }

    b->data[j] /= U->val->data[U->col_ptr->data[j + 1] - 2];
  }
}

void ccs_solve_triut_initialize(void)
{
}

void ccs_solve_triut_terminate(void)
{
}
