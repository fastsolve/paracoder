#include "crs_diag.h"
#include "m2c.h"

static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_int32_T(&pStruct->row_ptr);
  emxFree_int32_T(&pStruct->col_ind);
  emxFree_real_T(&pStruct->val);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_int32_T(&pStruct->row_ptr, 1);
  emxInit_int32_T(&pStruct->col_ind, 1);
  emxInit_real_T(&pStruct->val, 1);
}

void crs_diag(const struct0_T *A, emxArray_real_T *D)
{
  int i0;
  int loop_ub;
  int j;
  boolean_T exitg1;
  i0 = D->size[0];
  D->size[0] = A->nrows;
  emxEnsureCapacity((emxArray__common *)D, i0, (int)sizeof(double));
  loop_ub = A->nrows;
  for (i0 = 0; i0 < loop_ub; i0++) {
    D->data[i0] = 0.0;
  }

  for (loop_ub = 1; loop_ub <= A->nrows; loop_ub++) {
    i0 = A->row_ptr->data[loop_ub] - 1;
    j = A->row_ptr->data[loop_ub - 1];
    exitg1 = false;
    while ((!exitg1) && (j <= i0)) {
      if (A->col_ind->data[j - 1] == loop_ub) {
        D->data[loop_ub - 1] = A->val->data[j - 1];
        exitg1 = true;
      } else {
        j++;
      }
    }
  }
}

void crs_diag1(const struct0_T *A, int k, emxArray_real_T *D)
{
  int y;
  int i1;
  int j;
  boolean_T exitg1;
  boolean_T exitg2;
  if (k < 0) {
    y = -k;
  } else {
    y = k;
  }

  i1 = D->size[0];
  D->size[0] = A->nrows - y;
  emxEnsureCapacity((emxArray__common *)D, i1, (int)sizeof(double));
  y = A->nrows - y;
  for (i1 = 0; i1 < y; i1++) {
    D->data[i1] = 0.0;
  }

  if (k >= 0) {
    for (y = 1; y <= A->nrows; y++) {
      i1 = A->row_ptr->data[y] - 1;
      j = A->row_ptr->data[y - 1];
      exitg2 = false;
      while ((!exitg2) && (j <= i1)) {
        if (A->col_ind->data[j - 1] == y + k) {
          D->data[y - 1] = A->val->data[j - 1];
          exitg2 = true;
        } else {
          j++;
        }
      }
    }
  } else {
    for (y = 1; y <= A->nrows; y++) {
      i1 = A->row_ptr->data[y] - 1;
      j = A->row_ptr->data[y - 1];
      exitg1 = false;
      while ((!exitg1) && (j <= i1)) {
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

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}
