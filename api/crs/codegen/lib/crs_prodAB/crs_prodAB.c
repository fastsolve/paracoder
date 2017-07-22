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
  emxArray_int32_T *t0_row_ptr;
  int k;
  int loop_ub;
  int i;
  int clength;
  emxArray_int32_T *b_index;
  int istart;
  emxArray_real_T *temp;
  if (A->ncols != B->nrows) {
    m2c_error();
  }

  emxInit_int32_T(&t0_row_ptr, 1);
  k = t0_row_ptr->size[0];
  t0_row_ptr->size[0] = A->nrows + 1;
  emxEnsureCapacity_int32_T(t0_row_ptr, k);
  loop_ub = A->nrows;
  for (k = 0; k <= loop_ub; k++) {
    t0_row_ptr->data[k] = 0;
  }

  t0_row_ptr->data[0] = 1;
  for (i = 1; i <= A->nrows; i++) {
    t0_row_ptr->data[i] += t0_row_ptr->data[i - 1];
  }

  k = C->row_ptr->size[0];
  C->row_ptr->size[0] = t0_row_ptr->size[0];
  emxEnsureCapacity_int32_T(C->row_ptr, k);
  loop_ub = t0_row_ptr->size[0];
  for (k = 0; k < loop_ub; k++) {
    C->row_ptr->data[k] = t0_row_ptr->data[k];
  }

  emxFree_int32_T(&t0_row_ptr);
  C->nrows = A->nrows;
  C->ncols = B->ncols;
  k = C->row_ptr->size[0];
  C->row_ptr->size[0] = A->row_ptr->size[0];
  emxEnsureCapacity_int32_T(C->row_ptr, k);
  C->row_ptr->data[0] = 1;
  loop_ub = A->ncols;
  clength = B->ncols;
  if (loop_ub > clength) {
    clength = loop_ub;
  }

  emxInit_int32_T(&b_index, 1);
  k = b_index->size[0];
  b_index->size[0] = clength;
  emxEnsureCapacity_int32_T(b_index, k);
  for (k = 0; k < clength; k++) {
    b_index->data[k] = 0;
  }

  for (i = 1; i <= A->nrows; i++) {
    istart = -1;
    clength = 0;
    for (loop_ub = A->row_ptr->data[i - 1]; loop_ub < A->row_ptr->data[i];
         loop_ub++) {
      for (k = B->row_ptr->data[A->col_ind->data[loop_ub - 1] - 1] - 1; k + 1 <
           B->row_ptr->data[A->col_ind->data[loop_ub - 1]]; k++) {
        if (b_index->data[B->col_ind->data[k] - 1] == 0) {
          b_index->data[B->col_ind->data[k] - 1] = istart;
          istart = B->col_ind->data[k];
          clength++;
        }
      }
    }

    C->row_ptr->data[i] = C->row_ptr->data[i - 1] + clength;
    for (loop_ub = C->row_ptr->data[i - 1]; loop_ub < C->row_ptr->data[i];
         loop_ub++) {
      k = istart;
      istart = b_index->data[istart - 1];
      b_index->data[k - 1] = 0;
    }

    b_index->data[i - 1] = 0;
  }

  k = C->col_ind->size[0];
  C->col_ind->size[0] = C->row_ptr->data[A->nrows] - 1;
  emxEnsureCapacity_int32_T(C->col_ind, k);
  for (i = 1; i <= A->nrows; i++) {
    istart = -1;
    clength = 0;
    for (loop_ub = A->row_ptr->data[i - 1]; loop_ub < A->row_ptr->data[i];
         loop_ub++) {
      for (k = B->row_ptr->data[A->col_ind->data[loop_ub - 1] - 1] - 1; k + 1 <
           B->row_ptr->data[A->col_ind->data[loop_ub - 1]]; k++) {
        if (b_index->data[B->col_ind->data[k] - 1] == 0) {
          b_index->data[B->col_ind->data[k] - 1] = istart;
          istart = B->col_ind->data[k];
          clength++;
        }
      }
    }

    C->row_ptr->data[i] = C->row_ptr->data[i - 1] + clength;
    k = C->row_ptr->data[i] - 1;
    for (loop_ub = C->row_ptr->data[i - 1]; loop_ub <= k; loop_ub++) {
      C->col_ind->data[loop_ub - 1] = istart;
      istart = b_index->data[istart - 1];
      b_index->data[C->col_ind->data[loop_ub - 1] - 1] = 0;
    }

    b_index->data[i - 1] = 0;
  }

  emxInit_real_T(&temp, 1);
  k = C->val->size[0];
  C->val->size[0] = C->row_ptr->data[A->nrows] - 1;
  emxEnsureCapacity_real_T(C->val, k);
  k = temp->size[0];
  temp->size[0] = b_index->size[0];
  emxEnsureCapacity_real_T(temp, k);
  loop_ub = b_index->size[0];
  emxFree_int32_T(&b_index);
  for (k = 0; k < loop_ub; k++) {
    temp->data[k] = 0.0;
  }

  for (i = 1; i <= A->nrows; i++) {
    for (loop_ub = A->row_ptr->data[i - 1] - 1; loop_ub + 1 < A->row_ptr->data[i];
         loop_ub++) {
      for (k = B->row_ptr->data[A->col_ind->data[loop_ub] - 1] - 1; k + 1 <
           B->row_ptr->data[A->col_ind->data[loop_ub]]; k++) {
        temp->data[B->col_ind->data[k] - 1] += A->val->data[loop_ub] * B->
          val->data[k];
      }
    }

    k = C->row_ptr->data[i] - 1;
    for (loop_ub = C->row_ptr->data[i - 1] - 1; loop_ub + 1 <= k; loop_ub++) {
      C->val->data[loop_ub] = temp->data[C->col_ind->data[loop_ub] - 1];
      temp->data[C->col_ind->data[loop_ub] - 1] = 0.0;
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
