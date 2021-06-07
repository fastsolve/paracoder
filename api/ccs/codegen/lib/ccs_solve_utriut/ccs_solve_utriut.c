#include "ccs_solve_utriut.h"
#include "ccs_solve_utriut_types.h"

void ccs_solve_utril_3args(const CCS_Matrix *L, emxArray_real_T *b, int offset)
{
  int i;
  int i1;
  int i2;
  int j;
  int k;
  int n;
  n = L->col_ptr->size[0];
  for (j = 0; j <= n - 2; j++) {
    i = L->col_ptr->data[j];
    i1 = L->col_ptr->data[j + 1] - 1;
    for (k = i; k <= i1; k++) {
      i2 = (L->row_ind->data[k - 1] + offset) - 1;
      b->data[i2] -= L->val->data[k - 1] * b->data[j + offset];
    }
  }
}

void ccs_solve_utriut(const CCS_Matrix *U, emxArray_real_T *b)
{
  int i;
  int i1;
  int j;
  int k;
  int n;
  n = U->col_ptr->size[0];
  for (j = 0; j <= n - 2; j++) {
    i = U->col_ptr->data[j];
    i1 = U->col_ptr->data[j + 1] - 1;
    for (k = i; k <= i1; k++) {
      b->data[j] -= U->val->data[k - 1] * b->data[U->row_ind->data[k - 1] - 1];
    }
  }
}

void ccs_solve_utriut_initialize(void)
{
}

void ccs_solve_utriut_terminate(void)
{
}
