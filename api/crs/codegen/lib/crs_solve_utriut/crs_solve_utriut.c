#include "crs_solve_utriut.h"

void crs_solve_utriut(const struct0_T *A, emxArray_real_T *b)
{
  int n;
  int i;
  int k;
  n = A->row_ptr->size[0] - 1;
  for (i = 1; i <= n; i++) {
    for (k = A->row_ptr->data[i - 1] - 1; k + 1 < A->row_ptr->data[i]; k++) {
      b->data[A->col_ind->data[k] - 1] -= A->val->data[k] * b->data[i - 1];
    }
  }
}

void crs_solve_utriut_initialize(void)
{
}

void crs_solve_utriut_terminate(void)
{
}
