#include "crs_solve_utriut.h"

void crs_solve_utriut(const struct0_T *U, emxArray_real_T *b)
{
  int n;
  int i;
  int k;
  n = U->row_ptr->size[0] - 1;
  for (i = 1; i <= n; i++) {
    for (k = U->row_ptr->data[i - 1] - 1; k + 1 < U->row_ptr->data[i]; k++) {
      b->data[U->col_ind->data[k] - 1] -= U->val->data[k] * b->data[i - 1];
    }
  }
}

void crs_solve_utriut_3args(const struct0_T *U, emxArray_real_T *b, int offset)
{
  int n;
  int i;
  int k;
  n = U->row_ptr->size[0] - 1;
  for (i = 1; i <= n; i++) {
    for (k = U->row_ptr->data[i - 1] - 1; k + 1 < U->row_ptr->data[i]; k++) {
      b->data[(U->col_ind->data[k] + offset) - 1] -= U->val->data[k] * b->data
        [(i + offset) - 1];
    }
  }
}

void crs_solve_utriut_initialize(void)
{
}

void crs_solve_utriut_terminate(void)
{
}
