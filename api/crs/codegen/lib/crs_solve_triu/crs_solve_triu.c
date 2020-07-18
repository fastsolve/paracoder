#include "crs_solve_triu.h"

void crs_solve_triu(const CRS_Matrix *A, emxArray_real_T *b)
{
  int n;
  int i;
  int b_i;
  int i1;
  int i2;
  int cind;
  n = A->row_ptr->size[0] - 1;
  for (i = n; i >= 1; i--) {
    b_i = A->row_ptr->data[i - 1];
    i1 = b_i + 1;
    i2 = A->row_ptr->data[i] - 1;
    for (cind = i1; cind <= i2; cind++) {
      b->data[i - 1] -= A->val->data[cind - 1] * b->data[A->col_ind->data[cind -
        1] - 1];
    }

    b->data[i - 1] /= A->val->data[b_i - 1];
  }
}

void crs_solve_triu_initialize(void)
{
}

void crs_solve_triu_terminate(void)
{
}
