#include "crs_prodAB.h"
#include "m2c.h"

static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(void);

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

static void m2c_error(void)
{
  M2C_error("crs_prodMatMat:WrongSizes",
            "Number of columns of A must be equal to number of rows in B.");
}

void crs_prodAB(const struct0_T *A, const struct0_T *B, struct0_T *C)
{
  int i0;
  int maxval;
  emxArray_int32_T *b_index;
  int i;
  int istart;
  int clength;
  int i1;
  emxArray_real_T *temp;
  int k;
  if (A->ncols != B->nrows) {
    m2c_error();
  }

  C->nrows = A->nrows;
  C->ncols = B->ncols;
  i0 = C->row_ptr->size[0];
  C->row_ptr->size[0] = A->row_ptr->size[0];
  emxEnsureCapacity((emxArray__common *)C->row_ptr, i0, (int)sizeof(int));
  C->row_ptr->data[0] = 1;
  if (A->ncols >= B->ncols) {
    maxval = A->ncols;
  } else {
    maxval = B->ncols;
  }

  emxInit_int32_T(&b_index, 1);
  i0 = b_index->size[0];
  b_index->size[0] = maxval;
  emxEnsureCapacity((emxArray__common *)b_index, i0, (int)sizeof(int));
  for (i0 = 0; i0 < maxval; i0++) {
    b_index->data[i0] = 0;
  }

  for (i = 1; i <= A->nrows; i++) {
    istart = -1;
    clength = 0;
    i0 = A->row_ptr->data[i] - 1;
    for (maxval = A->row_ptr->data[i - 1]; maxval <= i0; maxval++) {
      i1 = B->row_ptr->data[A->col_ind->data[maxval - 1]] - 1;
      for (k = B->row_ptr->data[A->col_ind->data[maxval - 1] - 1] - 1; k + 1 <=
           i1; k++) {
        if (b_index->data[B->col_ind->data[k] - 1] == 0) {
          b_index->data[B->col_ind->data[k] - 1] = istart;
          istart = B->col_ind->data[k];
          clength++;
        }
      }
    }

    C->row_ptr->data[i] = C->row_ptr->data[i - 1] + clength;
    i0 = C->row_ptr->data[i] - 1;
    for (maxval = C->row_ptr->data[i - 1]; maxval <= i0; maxval++) {
      k = istart;
      istart = b_index->data[istart - 1];
      b_index->data[k - 1] = 0;
    }

    b_index->data[i - 1] = 0;
  }

  maxval = C->row_ptr->data[A->nrows] - 1;
  i0 = C->col_ind->size[0];
  C->col_ind->size[0] = maxval;
  emxEnsureCapacity((emxArray__common *)C->col_ind, i0, (int)sizeof(int));
  for (i = 1; i <= A->nrows; i++) {
    istart = -1;
    clength = 0;
    i0 = A->row_ptr->data[i] - 1;
    for (maxval = A->row_ptr->data[i - 1]; maxval <= i0; maxval++) {
      i1 = B->row_ptr->data[A->col_ind->data[maxval - 1]] - 1;
      for (k = B->row_ptr->data[A->col_ind->data[maxval - 1] - 1] - 1; k + 1 <=
           i1; k++) {
        if (b_index->data[B->col_ind->data[k] - 1] == 0) {
          b_index->data[B->col_ind->data[k] - 1] = istart;
          istart = B->col_ind->data[k];
          clength++;
        }
      }
    }

    C->row_ptr->data[i] = C->row_ptr->data[i - 1] + clength;
    i0 = C->row_ptr->data[i] - 1;
    for (maxval = C->row_ptr->data[i - 1]; maxval <= i0; maxval++) {
      C->col_ind->data[maxval - 1] = istart;
      istart = b_index->data[istart - 1];
      b_index->data[C->col_ind->data[maxval - 1] - 1] = 0;
    }

    b_index->data[i - 1] = 0;
  }

  emxInit_real_T(&temp, 1);
  maxval = C->row_ptr->data[A->nrows] - 1;
  i0 = C->val->size[0];
  C->val->size[0] = maxval;
  emxEnsureCapacity((emxArray__common *)C->val, i0, (int)sizeof(double));
  i0 = temp->size[0];
  temp->size[0] = b_index->size[0];
  emxEnsureCapacity((emxArray__common *)temp, i0, (int)sizeof(double));
  maxval = b_index->size[0];
  emxFree_int32_T(&b_index);
  for (i0 = 0; i0 < maxval; i0++) {
    temp->data[i0] = 0.0;
  }

  for (i = 1; i <= A->nrows; i++) {
    i0 = A->row_ptr->data[i] - 1;
    for (maxval = A->row_ptr->data[i - 1] - 1; maxval + 1 <= i0; maxval++) {
      i1 = B->row_ptr->data[A->col_ind->data[maxval]] - 1;
      for (k = B->row_ptr->data[A->col_ind->data[maxval] - 1] - 1; k + 1 <= i1;
           k++) {
        temp->data[B->col_ind->data[k] - 1] += A->val->data[maxval] * B->
          val->data[k];
      }
    }

    i0 = C->row_ptr->data[i] - 1;
    for (maxval = C->row_ptr->data[i - 1] - 1; maxval + 1 <= i0; maxval++) {
      C->val->data[maxval] = temp->data[C->col_ind->data[maxval] - 1];
      temp->data[C->col_ind->data[maxval] - 1] = 0.0;
    }
  }

  emxFree_real_T(&temp);
}

void crs_prodAB_initialize(void)
{
}

void crs_prodAB_terminate(void)
{
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}
