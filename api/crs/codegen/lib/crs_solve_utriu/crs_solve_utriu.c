#include "crs_solve_utriu.h"
#include "crs_solve_utriu_types.h"

void crs_solve_utriu(const CRS_Matrix *U, emxArray_real_T *b)
{
  int b_i;
  int i;
  int i1;
  int k;
  int n;
  n = U->row_ptr->size[0] - 1;
  for (i = n; i >= 1; i--) {
    b_i = U->row_ptr->data[i - 1];
    i1 = U->row_ptr->data[i] - 1;
    for (k = b_i; k <= i1; k++) {
      b->data[i - 1] -=
          U->val->data[k - 1] * b->data[U->col_ind->data[k - 1] - 1];
    }
  }
}

void crs_solve_utriu_3args(const CRS_Matrix *L, emxArray_real_T *b, int offset)
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
      i2 = (i + offset) - 1;
      b->data[i2] -=
          L->val->data[k - 1] * b->data[(L->col_ind->data[k - 1] + offset) - 1];
    }
  }
}

void crs_solve_utriu_initialize(void)
{
}

void crs_solve_utriu_terminate(void)
{
}
