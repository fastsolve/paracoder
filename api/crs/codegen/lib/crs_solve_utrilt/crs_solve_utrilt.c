#include "crs_solve_utrilt.h"

void crs_solve_utrilt(const struct0_T *A, emxArray_real_T *b)
{
  int i;
  int k;
  for (i = A->row_ptr->size[0] - 1; i > 0; i--) {
    for (k = A->row_ptr->data[i - 1] - 1; k + 1 < A->row_ptr->data[i]; k++) {
      b->data[A->col_ind->data[k] - 1] -= A->val->data[k] * b->data[i - 1];
    }
  }
}

void crs_solve_utrilt_initialize(void)
{
}

void crs_solve_utrilt_terminate(void)
{
}
