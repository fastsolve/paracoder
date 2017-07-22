#include "crs_diag.h"
#include "m2c.h"

void crs_diag(const struct0_T *A, emxArray_real_T *D)
{
  int i;
  int loop_ub;
  boolean_T exitg1;
  i = D->size[0];
  D->size[0] = A->nrows;
  emxEnsureCapacity_real_T(D, i);
  loop_ub = A->nrows;
  for (i = 0; i < loop_ub; i++) {
    D->data[i] = 0.0;
  }

  for (i = 1; i <= A->nrows; i++) {
    loop_ub = A->row_ptr->data[i - 1];
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= A->row_ptr->data[i] - 1)) {
      if (A->col_ind->data[loop_ub - 1] == i) {
        D->data[i - 1] = A->val->data[loop_ub - 1];
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
  }
}

void crs_diag1(const struct0_T *A, int k, emxArray_real_T *D)
{
  int y;
  int j;
  boolean_T exitg1;
  if (k < 0) {
    y = -k;
  } else {
    y = k;
  }

  j = D->size[0];
  D->size[0] = A->nrows - y;
  emxEnsureCapacity_real_T(D, j);
  y = A->nrows - y;
  for (j = 0; j < y; j++) {
    D->data[j] = 0.0;
  }

  if (k >= 0) {
    for (y = 1; y <= A->nrows; y++) {
      j = A->row_ptr->data[y - 1];
      exitg1 = false;
      while ((!exitg1) && (j <= A->row_ptr->data[y] - 1)) {
        if (A->col_ind->data[j - 1] == y + k) {
          D->data[y - 1] = A->val->data[j - 1];
          exitg1 = true;
        } else {
          j++;
        }
      }
    }
  } else {
    for (y = 1; y <= A->nrows; y++) {
      j = A->row_ptr->data[y - 1];
      exitg1 = false;
      while ((!exitg1) && (j <= A->row_ptr->data[y] - 1)) {
        if (A->col_ind->data[j - 1] == y + k) {
          D->data[(y + k) - 1] = A->val->data[j - 1];
          exitg1 = true;
        } else {
          j++;
        }
      }
    }
  }
}

void crs_diag_initialize(void)
{
}

void crs_diag_terminate(void)
{
}
