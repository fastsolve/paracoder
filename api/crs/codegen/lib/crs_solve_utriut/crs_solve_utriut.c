#include "crs_solve_utriut.h"

void crs_solve_utriut(const CRS_Matrix *U, emxArray_real_T *b)
{
  int n;
  int i;
  int b_i;
  int i1;
  int k;
  int i2;
  n = U->row_ptr->size[0];
  for (i = 0; i <= n - 2; i++) {
    b_i = U->row_ptr->data[i];
    i1 = U->row_ptr->data[i + 1] - 1;
    for (k = b_i; k <= i1; k++) {
      i2 = U->col_ind->data[k - 1] - 1;
      b->data[i2] -= U->val->data[k - 1] * b->data[i];
    }
  }
}

void crs_solve_utriut_3args(const CRS_Matrix *U, emxArray_real_T *b, int offset)
{
  int n;
  int i;
  int b_i;
  int i1;
  int k;
  int i2;
  n = U->row_ptr->size[0];
  for (i = 0; i <= n - 2; i++) {
    b_i = U->row_ptr->data[i];
    i1 = U->row_ptr->data[i + 1] - 1;
    for (k = b_i; k <= i1; k++) {
      i2 = (U->col_ind->data[k - 1] + offset) - 1;
      b->data[i2] -= U->val->data[k - 1] * b->data[i + offset];
    }
  }
}

void crs_solve_utriut_initialize(void)
{
}

void crs_solve_utriut_terminate(void)
{
}
