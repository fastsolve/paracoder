#include "ccs_solve_utriu.h"

void ccs_solve_utriu(const struct0_T *U, emxArray_real_T *b)
{
  int n;
  int j;
  int i;
  int i1;
  int k;
  int i2;
  n = U->col_ptr->size[0] - 1;
  for (j = n; j >= 1; j--) {
    i = U->col_ptr->data[j - 1];
    i1 = U->col_ptr->data[j] - 1;
    for (k = i; k <= i1; k++) {
      i2 = U->row_ind->data[k - 1] - 1;
      b->data[i2] -= U->val->data[k - 1] * b->data[j - 1];
    }
  }
}

void ccs_solve_utriu_3args(const struct0_T *U, emxArray_real_T *b, int offset)
{
  int n;
  int j;
  int i;
  int i1;
  int k;
  int i2;
  n = U->col_ptr->size[0] - 1;
  for (j = n; j >= 1; j--) {
    i = U->col_ptr->data[j - 1];
    i1 = U->col_ptr->data[j] - 1;
    for (k = i; k <= i1; k++) {
      i2 = (U->row_ind->data[k - 1] + offset) - 1;
      b->data[i2] -= U->val->data[k - 1] * b->data[(j + offset) - 1];
    }
  }
}

void ccs_solve_utriu_initialize(void)
{
}

void ccs_solve_utriu_terminate(void)
{
}
