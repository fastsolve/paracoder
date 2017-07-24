#include "crs_solve_utrilt.h"

void crs_solve_utrilt(const struct0_T *L, emxArray_real_T *b)
{
  int i;
  int k;
  for (i = L->row_ptr->size[0] - 1; i > 0; i--) {
    for (k = L->row_ptr->data[i - 1] - 1; k + 1 < L->row_ptr->data[i]; k++) {
      b->data[L->col_ind->data[k] - 1] -= L->val->data[k] * b->data[i - 1];
    }
  }
}

void crs_solve_utrilt_3args(const struct0_T *L, emxArray_real_T *b, int offset)
{
  int i;
  int k;
  for (i = L->row_ptr->size[0] - 1; i > 0; i--) {
    for (k = L->row_ptr->data[i - 1] - 1; k + 1 < L->row_ptr->data[i]; k++) {
      b->data[(L->col_ind->data[k] + offset) - 1] -= L->val->data[k] * b->data
        [(i + offset) - 1];
    }
  }
}

void crs_solve_utrilt_initialize(void)
{
}

void crs_solve_utrilt_terminate(void)
{
}
