#include "ccs_solve_utriu.h"

void ccs_solve_utriu(const struct0_T *U, emxArray_real_T *b)
{
  int j;
  int k;
  for (j = U->col_ptr->size[0] - 1; j > 0; j--) {
    for (k = U->col_ptr->data[j - 1] - 1; k + 1 < U->col_ptr->data[j]; k++) {
      b->data[U->row_ind->data[k] - 1] -= U->val->data[k] * b->data[j - 1];
    }
  }
}

void ccs_solve_utriu_3args(const struct0_T *U, emxArray_real_T *b, int offset)
{
  int j;
  int k;
  for (j = U->col_ptr->size[0] - 1; j > 0; j--) {
    for (k = U->col_ptr->data[j - 1] - 1; k + 1 < U->col_ptr->data[j]; k++) {
      b->data[(U->row_ind->data[k] + offset) - 1] -= U->val->data[k] * b->data
        [(j + offset) - 1];
    }
  }
}

void ccs_solve_utriu_initialize(void)
{
}

void ccs_solve_utriu_terminate(void)
{
}
