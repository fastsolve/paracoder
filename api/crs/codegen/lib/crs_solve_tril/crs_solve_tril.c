#include "crs_solve_tril.h"

void crs_solve_tril(const struct0_T *A, emxArray_real_T *b)
{
  int n;
  int i;
  int k;
  n = A->row_ptr->size[0] - 1;
  for (i = 0; i + 1 <= n; i++) {
    for (k = A->row_ptr->data[i]; k <= A->row_ptr->data[i + 1] - 2; k++) {
      b->data[i] -= A->val->data[k - 1] * b->data[A->col_ind->data[k - 1] - 1];
    }

    b->data[i] /= A->val->data[A->row_ptr->data[i + 1] - 2];
  }
}

void crs_solve_tril_initialize(void)
{
}

void crs_solve_tril_terminate(void)
{
}
