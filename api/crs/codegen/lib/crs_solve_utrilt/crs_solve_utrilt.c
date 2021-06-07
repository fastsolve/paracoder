#include "crs_solve_utrilt.h"
#include "crs_solve_utrilt_types.h"

void crs_solve_utrilt(const CRS_Matrix *L, emxArray_real_T *b)
{
  int b_i;
  int i;
  int i1;
  int i2;
  int k;
  int n;
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

void crs_solve_utrilt_3args(const CRS_Matrix *L, emxArray_real_T *b, int offset)
{
  int b_i;
  int i;
  int i1;
  int i2;
  int k;
  int n;
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
