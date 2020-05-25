#include "crs_solve_utrilt.h"

void crs_solve_utrilt(const struct0_T *L, emxArray_real_T *b)
{
  int n;
  int i;
  int b_i;
  int i1;
  int k;
  int i2;
  n = L->row_ptr->size[0] - 1;
  for (i = n; i >= 1; i--) {
    b_i = L->row_ptr->data[i - 1];
    i1 = L->row_ptr->data[i] - 1;
    for (k = b_i; k <= i1; k++) {
      i2 = L->col_ind->data[k - 1] - 1;
      b->data[i2] -= L->val->data[k - 1] * b->data[i - 1];
    }
  }
}

void crs_solve_utrilt_3args(const struct0_T *L, emxArray_real_T *b, int offset)
{
  int n;
  int i;
  int b_i;
  int i1;
  int k;
  int i2;
  n = L->row_ptr->size[0] - 1;
  for (i = n; i >= 1; i--) {
    b_i = L->row_ptr->data[i - 1];
    i1 = L->row_ptr->data[i] - 1;
    for (k = b_i; k <= i1; k++) {
      i2 = (L->col_ind->data[k - 1] + offset) - 1;
      b->data[i2] -= L->val->data[k - 1] * b->data[(i + offset) - 1];
    }
  }
}

void crs_solve_utrilt_initialize(void)
{
}

void crs_solve_utrilt_terminate(void)
{
}
