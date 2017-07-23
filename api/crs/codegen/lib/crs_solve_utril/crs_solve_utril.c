#include "crs_solve_utril.h"

void crs_solve_utril(const struct0_T *A, emxArray_real_T *b)
{
  int n;
  int i;
  int k;
  n = A->row_ptr->size[0] - 1;
  for (i = 0; i + 1 <= n; i++) {
    for (k = A->row_ptr->data[i]; k < A->row_ptr->data[i + 1]; k++) {
      b->data[i] -= A->val->data[k - 1] * b->data[A->col_ind->data[k - 1] - 1];
    }
  }
}

void crs_solve_utril_initialize(void)
{
}

void crs_solve_utril_terminate(void)
{
}
