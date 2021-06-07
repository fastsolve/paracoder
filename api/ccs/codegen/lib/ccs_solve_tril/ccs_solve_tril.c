#include "ccs_solve_tril.h"
#include "ccs_solve_tril_types.h"

void ccs_solve_tril(const CCS_Matrix *L, emxArray_real_T *b)
{
  int i;
  int i1;
  int i2;
  int i3;
  int j;
  int k;
  i = L->col_ptr->size[0];
  for (j = 0; j <= i - 2; j++) {
    b->data[j] /= L->val->data[L->col_ptr->data[j] - 1];
    i1 = L->col_ptr->data[j] + 1;
    i2 = L->col_ptr->data[j + 1] - 1;
    for (k = i1; k <= i2; k++) {
      i3 = L->row_ind->data[k - 1] - 1;
      b->data[i3] -= L->val->data[k - 1] * b->data[j];
    }
  }
}

void ccs_solve_tril_initialize(void)
{
}

void ccs_solve_tril_terminate(void)
{
}
