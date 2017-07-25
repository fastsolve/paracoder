#include "ccs_solve_trilt.h"

void ccs_solve_trilt(const struct0_T *L, emxArray_real_T *b)
{
  int j;
  int i;
  for (j = L->col_ptr->size[0] - 2; j + 1 > 0; j--) {
    for (i = L->col_ptr->data[j]; i + 1 < L->col_ptr->data[j + 1]; i++) {
      b->data[j] -= L->val->data[i] * b->data[L->row_ind->data[i] - 1];
    }

    b->data[j] /= L->val->data[L->col_ptr->data[j] - 1];
  }
}

void ccs_solve_trilt_initialize(void)
{
}

void ccs_solve_trilt_terminate(void)
{
}
