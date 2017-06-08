#include "crs_prodAB.h"
#include "m2c.h"

static void m2c_error(void);
static void m2c_error(void)
{
  M2C_error("crs_prodMatMat:WrongSizes",
            "Number of columns of A must be equal to number of rows in B.");
}

void crs_prodAB(const struct0_T *A, const struct0_T *B, struct0_T *C)
{
  int k;
  int u0;
  int clength;
  emxArray_int32_T *b_index;
  int i;
  int istart;
  emxArray_real_T *temp;
  if (A->ncols != B->nrows) {
    m2c_error();
  }

  k = C->row_ptr->size[0];
  C->row_ptr->size[0] = 0;
  emxEnsureCapacity((emxArray__common *)C->row_ptr, k, sizeof(int));
  k = C->col_ind->size[0];
  C->col_ind->size[0] = 0;
  emxEnsureCapacity((emxArray__common *)C->col_ind, k, sizeof(int));
  k = C->val->size[0];
  C->val->size[0] = 0;
  emxEnsureCapacity((emxArray__common *)C->val, k, sizeof(double));
  C->nrows = A->nrows;
  C->ncols = B->ncols;
  k = C->row_ptr->size[0];
  C->row_ptr->size[0] = A->row_ptr->size[0];
  emxEnsureCapacity((emxArray__common *)C->row_ptr, k, sizeof(int));
  C->row_ptr->data[0] = 1;
  u0 = A->ncols;
  clength = B->ncols;
  if (u0 > clength) {
    clength = u0;
  }

  emxInit_int32_T(&b_index, 1);
  k = b_index->size[0];
  b_index->size[0] = clength;
  emxEnsureCapacity((emxArray__common *)b_index, k, sizeof(int));
  for (k = 0; k < clength; k++) {
    b_index->data[k] = 0;
  }

  for (i = 1; i <= A->nrows; i++) {
    istart = -1;
    clength = 0;
    for (u0 = A->row_ptr->data[i - 1]; u0 < A->row_ptr->data[i]; u0++) {
      for (k = B->row_ptr->data[A->col_ind->data[u0 - 1] - 1] - 1; k + 1 <
           B->row_ptr->data[A->col_ind->data[u0 - 1]]; k++) {
        if (b_index->data[B->col_ind->data[k] - 1] == 0) {
          b_index->data[B->col_ind->data[k] - 1] = istart;
          istart = B->col_ind->data[k];
          clength++;
        }
      }
    }

    C->row_ptr->data[i] = C->row_ptr->data[i - 1] + clength;
    for (u0 = C->row_ptr->data[i - 1]; u0 < C->row_ptr->data[i]; u0++) {
      k = istart;
      istart = b_index->data[istart - 1];
      b_index->data[k - 1] = 0;
    }

    b_index->data[i - 1] = 0;
  }

  k = C->col_ind->size[0];
  C->col_ind->size[0] = C->row_ptr->data[A->nrows] - 1;
  emxEnsureCapacity((emxArray__common *)C->col_ind, k, sizeof(int));
  for (i = 1; i <= A->nrows; i++) {
    istart = -1;
    clength = 0;
    for (u0 = A->row_ptr->data[i - 1]; u0 < A->row_ptr->data[i]; u0++) {
      for (k = B->row_ptr->data[A->col_ind->data[u0 - 1] - 1] - 1; k + 1 <
           B->row_ptr->data[A->col_ind->data[u0 - 1]]; k++) {
        if (b_index->data[B->col_ind->data[k] - 1] == 0) {
          b_index->data[B->col_ind->data[k] - 1] = istart;
          istart = B->col_ind->data[k];
          clength++;
        }
      }
    }

    C->row_ptr->data[i] = C->row_ptr->data[i - 1] + clength;
    k = C->row_ptr->data[i] - 1;
    for (u0 = C->row_ptr->data[i - 1]; u0 <= k; u0++) {
      C->col_ind->data[u0 - 1] = istart;
      istart = b_index->data[istart - 1];
      b_index->data[C->col_ind->data[u0 - 1] - 1] = 0;
    }

    b_index->data[i - 1] = 0;
  }

  emxInit_real_T(&temp, 1);
  k = C->val->size[0];
  C->val->size[0] = C->row_ptr->data[A->nrows] - 1;
  emxEnsureCapacity((emxArray__common *)C->val, k, sizeof(double));
  k = temp->size[0];
  temp->size[0] = b_index->size[0];
  emxEnsureCapacity((emxArray__common *)temp, k, sizeof(double));
  u0 = b_index->size[0];
  emxFree_int32_T(&b_index);
  for (k = 0; k < u0; k++) {
    temp->data[k] = 0.0;
  }

  for (i = 1; i <= A->nrows; i++) {
    for (u0 = A->row_ptr->data[i - 1] - 1; u0 + 1 < A->row_ptr->data[i]; u0++) {
      for (k = B->row_ptr->data[A->col_ind->data[u0] - 1] - 1; k + 1 <
           B->row_ptr->data[A->col_ind->data[u0]]; k++) {
        temp->data[B->col_ind->data[k] - 1] += A->val->data[u0] * B->val->data[k];
      }
    }

    k = C->row_ptr->data[i] - 1;
    for (u0 = C->row_ptr->data[i - 1] - 1; u0 + 1 <= k; u0++) {
      C->val->data[u0] = temp->data[C->col_ind->data[u0] - 1];
      temp->data[C->col_ind->data[u0] - 1] = 0.0;
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
