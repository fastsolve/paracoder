#include "ccs_solve_tril.h"

void ccs_solve_tril(const struct0_T *L, emxArray_real_T *b)
{
  int i0;
  int j;
  int k;
  i0 = L->col_ptr->size[0] - 1;
  for (j = 0; j + 1 <= i0; j++) {
    b->data[j] /= L->val->data[L->col_ptr->data[j] - 1];
    for (k = L->col_ptr->data[j]; k + 1 < L->col_ptr->data[j + 1]; k++) {
      b->data[L->row_ind->data[k] - 1] -= L->val->data[k] * b->data[j];
    }
  }
}

void ccs_solve_tril_initialize(void)
{
}

void ccs_solve_tril_terminate(void)
{
}
