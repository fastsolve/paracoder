#include "crs_solve_utriu.h"

void crs_solve_utriu(const struct0_T *A, emxArray_real_T *b)
{
  int i;
  int cind;
  for (i = A->row_ptr->size[0] - 2; i + 1 > 0; i--) {
    for (cind = A->row_ptr->data[i]; cind < A->row_ptr->data[i + 1]; cind++) {
      b->data[i] -= A->val->data[cind - 1] * b->data[A->col_ind->data[cind - 1]
        - 1];
    }
  }
}

void crs_solve_utriu_initialize(void)
{
}

void crs_solve_utriu_terminate(void)
{
}
