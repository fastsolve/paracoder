#include "crs_solve_utril.h"

void crs_solve_utril(const CRS_Matrix *L, emxArray_real_T *b)
{
  int n;
  int i;
  int b_i;
  int i1;
  int k;
  n = L->row_ptr->size[0];
  for (i = 0; i <= n - 2; i++) {
    b_i = L->row_ptr->data[i];
    i1 = L->row_ptr->data[i + 1] - 1;
    for (k = b_i; k <= i1; k++) {
      b->data[i] -= L->val->data[k - 1] * b->data[L->col_ind->data[k - 1] - 1];
    }
  }
}

void crs_solve_utril_3args(const CRS_Matrix *L, emxArray_real_T *b, int offset)
{
  int n;
  int i;
  int b_i;
  int i1;
  int k;
  int i2;
  n = L->row_ptr->size[0];
  for (i = 0; i <= n - 2; i++) {
    b_i = L->row_ptr->data[i];
    i1 = L->row_ptr->data[i + 1] - 1;
    for (k = b_i; k <= i1; k++) {
      i2 = i + offset;
      b->data[i2] -= L->val->data[k - 1] * b->data[(L->col_ind->data[k - 1] +
        offset) - 1];
    }
  }
}

void crs_solve_utril_initialize(void)
{
}

void crs_solve_utril_terminate(void)
{
}
