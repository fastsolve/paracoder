#include "ccs_solve_utril.h"

void ccs_solve_utril(const struct0_T *L, emxArray_real_T *b)
{
  int n;
  int j;
  int k;
  n = L->col_ptr->size[0] - 1;
  for (j = 1; j <= n; j++) {
    for (k = L->col_ptr->data[j - 1] - 1; k + 1 < L->col_ptr->data[j]; k++) {
      b->data[L->row_ind->data[k] - 1] -= L->val->data[k] * b->data[j - 1];
    }
  }
}

void ccs_solve_utril_3args(const struct0_T *L, emxArray_real_T *b, int offset)
{
  int n;
  int j;
  int k;
  n = L->col_ptr->size[0] - 1;
  for (j = 1; j <= n; j++) {
    for (k = L->col_ptr->data[j - 1] - 1; k + 1 < L->col_ptr->data[j]; k++) {
      b->data[(L->row_ind->data[k] + offset) - 1] -= L->val->data[k] * b->data
        [(j + offset) - 1];
    }
  }
}

void ccs_solve_utril_initialize(void)
{
}

void ccs_solve_utril_terminate(void)
{
}
