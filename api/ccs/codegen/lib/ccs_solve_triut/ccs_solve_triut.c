#include "ccs_solve_triut.h"

void ccs_solve_triut(const CCS_Matrix *U, emxArray_real_T *b)
{
  int n;
  int j;
  int i;
  int i1;
  int k;
  n = U->col_ptr->size[0];
  for (j = 0; j <= n - 2; j++) {
    i = U->col_ptr->data[j];
    i1 = U->col_ptr->data[j + 1] - 2;
    for (k = i; k <= i1; k++) {
      b->data[j] -= U->val->data[k - 1] * b->data[U->row_ind->data[k - 1] - 1];
    }

    b->data[j] /= U->val->data[i1];
  }
}

void ccs_solve_triut_initialize(void)
{
}

void ccs_solve_triut_terminate(void)
{
}
