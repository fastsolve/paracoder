#include "crs_solve_utril.h"

void crs_solve_utril(const struct0_T *L, emxArray_real_T *b)
{
  int n;
  int i;
  int k;
  n = L->row_ptr->size[0] - 1;
  for (i = 0; i + 1 <= n; i++) {
    for (k = L->row_ptr->data[i]; k < L->row_ptr->data[i + 1]; k++) {
      b->data[i] -= L->val->data[k - 1] * b->data[L->col_ind->data[k - 1] - 1];
    }
  }
}

void crs_solve_utril_3args(const struct0_T *L, emxArray_real_T *b, int offset)
{
  int n;
  int i;
  int k;
  n = L->row_ptr->size[0] - 1;
  for (i = 0; i + 1 <= n; i++) {
    for (k = L->row_ptr->data[i]; k < L->row_ptr->data[i + 1]; k++) {
      b->data[i + offset] -= L->val->data[k - 1] * b->data[(L->col_ind->data[k -
        1] + offset) - 1];
    }
  }
}

void crs_solve_utril_initialize(void)
{
}

void crs_solve_utril_terminate(void)
{
}
