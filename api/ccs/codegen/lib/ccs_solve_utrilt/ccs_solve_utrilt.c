#include "ccs_solve_utrilt.h"

void ccs_solve_utrilt(const struct0_T *L, emxArray_real_T *b)
{
  int j;
  int k;
  for (j = L->col_ptr->size[0] - 2; j + 1 > 0; j--) {
    for (k = L->col_ptr->data[j]; k < L->col_ptr->data[j + 1]; k++) {
      b->data[j] -= L->val->data[k - 1] * b->data[L->row_ind->data[k - 1] - 1];
    }
  }
}

void ccs_solve_utrilt_3args(const struct0_T *U, emxArray_real_T *b, int offset)
{
  int j;
  int k;
  for (j = U->col_ptr->size[0] - 2; j + 1 > 0; j--) {
    for (k = U->col_ptr->data[j]; k < U->col_ptr->data[j + 1]; k++) {
      b->data[j + offset] -= U->val->data[k - 1] * b->data[(U->row_ind->data[k -
        1] + offset) - 1];
    }
  }
}

void ccs_solve_utrilt_initialize(void)
{
}

void ccs_solve_utrilt_terminate(void)
{
}
