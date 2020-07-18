#include "ccs_solve_trilt.h"

void ccs_solve_trilt(const CCS_Matrix *L, emxArray_real_T *b)
{
  int n;
  int j;
  int i;
  int i1;
  int i2;
  int b_i;
  n = L->col_ptr->size[0] - 1;
  for (j = n; j >= 1; j--) {
    i = L->col_ptr->data[j - 1];
    i1 = i + 1;
    i2 = L->col_ptr->data[j] - 1;
    for (b_i = i1; b_i <= i2; b_i++) {
      b->data[j - 1] -= L->val->data[b_i - 1] * b->data[L->row_ind->data[b_i - 1]
        - 1];
    }

    b->data[j - 1] /= L->val->data[i - 1];
  }
}

void ccs_solve_trilt_initialize(void)
{
}

void ccs_solve_trilt_terminate(void)
{
}
