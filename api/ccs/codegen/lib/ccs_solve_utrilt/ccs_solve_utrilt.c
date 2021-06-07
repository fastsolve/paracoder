#include "ccs_solve_utrilt.h"
#include "ccs_solve_utrilt_types.h"

void ccs_solve_utrilt(const CCS_Matrix *L, emxArray_real_T *b)
{
  int i;
  int i1;
  int j;
  int k;
  int n;
  n = L->col_ptr->size[0] - 1;
  for (j = n; j >= 1; j--) {
    i = L->col_ptr->data[j - 1];
    i1 = L->col_ptr->data[j] - 1;
    for (k = i; k <= i1; k++) {
      b->data[j - 1] -=
          L->val->data[k - 1] * b->data[L->row_ind->data[k - 1] - 1];
    }
  }
}

void ccs_solve_utrilt_3args(const CCS_Matrix *U, emxArray_real_T *b, int offset)
{
  int i;
  int i1;
  int i2;
  int j;
  int k;
  int n;
  n = U->col_ptr->size[0] - 1;
  for (j = n; j >= 1; j--) {
    i = U->col_ptr->data[j - 1];
    i1 = U->col_ptr->data[j] - 1;
    for (k = i; k <= i1; k++) {
      i2 = (j + offset) - 1;
      b->data[i2] -=
          U->val->data[k - 1] * b->data[(U->row_ind->data[k - 1] + offset) - 1];
    }
  }
}

void ccs_solve_utrilt_initialize(void)
{
}

void ccs_solve_utrilt_terminate(void)
{
}
