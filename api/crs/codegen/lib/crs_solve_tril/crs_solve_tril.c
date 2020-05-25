#include "crs_solve_tril.h"

void crs_solve_tril(const struct0_T *A, emxArray_real_T *b)
{
  int n;
  int i;
  int b_i;
  int i1;
  int k;
  n = A->row_ptr->size[0];
  for (i = 0; i <= n - 2; i++) {
    b_i = A->row_ptr->data[i];
    i1 = A->row_ptr->data[i + 1] - 2;
    for (k = b_i; k <= i1; k++) {
      b->data[i] -= A->val->data[k - 1] * b->data[A->col_ind->data[k - 1] - 1];
    }

    b->data[i] /= A->val->data[i1];
  }
}

void crs_solve_tril_initialize(void)
{
}

void crs_solve_tril_terminate(void)
{
}
