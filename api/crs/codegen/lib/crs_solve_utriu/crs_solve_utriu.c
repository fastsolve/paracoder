#include "crs_solve_utriu.h"

void crs_solve_utriu(const struct0_T *U, emxArray_real_T *b)
{
  int i;
  int k;
  for (i = U->row_ptr->size[0] - 2; i + 1 > 0; i--) {
    for (k = U->row_ptr->data[i]; k < U->row_ptr->data[i + 1]; k++) {
      b->data[i] -= U->val->data[k - 1] * b->data[U->col_ind->data[k - 1] - 1];
    }
  }
}

void crs_solve_utriu_3args(const struct0_T *L, emxArray_real_T *b, int offset)
{
  int i;
  int k;
  for (i = L->row_ptr->size[0] - 2; i + 1 > 0; i--) {
    for (k = L->row_ptr->data[i]; k < L->row_ptr->data[i + 1]; k++) {
      b->data[i + offset] -= L->val->data[k - 1] * b->data[(L->col_ind->data[k -
        1] + offset) - 1];
    }
  }
}

void crs_solve_utriu_initialize(void)
{
}

void crs_solve_utriu_terminate(void)
{
}
