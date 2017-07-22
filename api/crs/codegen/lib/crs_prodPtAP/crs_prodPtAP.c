#include "crs_prodPtAP.h"
#include "m2c.h"

static void crs_createFromAIJ(const emxArray_int32_T *rows, const
  emxArray_int32_T *cols, const emxArray_real_T *vs, emxArray_int32_T *A_row_ptr,
  emxArray_int32_T *A_col_ind, emxArray_real_T *A_val, int *A_nrows, int
  *A_ncols);
static void crs_prodAB(const emxArray_int32_T *A_row_ptr, const emxArray_int32_T
  *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int A_ncols, const
  emxArray_int32_T *B_row_ptr, const emxArray_int32_T *B_col_ind, const
  emxArray_real_T *B_val, int B_nrows, int B_ncols, emxArray_int32_T *C_row_ptr,
  emxArray_int32_T *C_col_ind, emxArray_real_T *C_val, int *C_nrows, int
  *C_ncols);
static void heapsort_tag(emxArray_int32_T *r, emxArray_real_T *TAGS);
static void m2c_error(void);
static void crs_createFromAIJ(const emxArray_int32_T *rows, const
  emxArray_int32_T *cols, const emxArray_real_T *vs, emxArray_int32_T *A_row_ptr,
  emxArray_int32_T *A_col_ind, emxArray_real_T *A_val, int *A_nrows, int
  *A_ncols)
{
  int mtmp;
  int j;
  int b_mtmp;
  int unnamed_idx_0;
  int i0;
  int i;
  boolean_T ascend;
  boolean_T exitg1;
  emxArray_int32_T *col_ind;
  emxArray_real_T *val;
  emxArray_real_T *buf_val;
  emxArray_int32_T *buf_indx;
  unsigned int ind;
  mtmp = rows->data[0];
  if (rows->size[0] > 1) {
    for (j = 1; j + 1 <= rows->size[0]; j++) {
      if (rows->data[j] > mtmp) {
        mtmp = rows->data[j];
      }
    }
  }

  b_mtmp = cols->data[0];
  if (cols->size[0] > 1) {
    for (j = 1; j + 1 <= cols->size[0]; j++) {
      if (cols->data[j] > b_mtmp) {
        b_mtmp = cols->data[j];
      }
    }
  }

  j = cols->size[0];
  unnamed_idx_0 = cols->size[0];
  i0 = A_row_ptr->size[0];
  A_row_ptr->size[0] = mtmp + 1;
  emxEnsureCapacity_int32_T(A_row_ptr, i0);
  for (i0 = 0; i0 <= mtmp; i0++) {
    A_row_ptr->data[i0] = 0;
  }

  i0 = A_col_ind->size[0];
  A_col_ind->size[0] = j;
  emxEnsureCapacity_int32_T(A_col_ind, i0);
  for (i0 = 0; i0 < j; i0++) {
    A_col_ind->data[i0] = 0;
  }

  i0 = A_val->size[0];
  A_val->size[0] = unnamed_idx_0;
  emxEnsureCapacity_real_T(A_val, i0);
  for (i0 = 0; i0 < unnamed_idx_0; i0++) {
    A_val->data[i0] = 0.0;
  }

  i0 = rows->size[0];
  for (i = 0; i + 1 <= i0; i++) {
    A_row_ptr->data[rows->data[i]]++;
  }

  A_row_ptr->data[0] = 1;
  for (i = 1; i <= mtmp; i++) {
    A_row_ptr->data[i] += A_row_ptr->data[i - 1];
  }

  ascend = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= rows->size[0] - 2)) {
    if (rows->data[1 + i] < rows->data[i]) {
      ascend = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (ascend) {
    i0 = A_col_ind->size[0];
    A_col_ind->size[0] = cols->size[0];
    emxEnsureCapacity_int32_T(A_col_ind, i0);
    unnamed_idx_0 = cols->size[0];
    for (i0 = 0; i0 < unnamed_idx_0; i0++) {
      A_col_ind->data[i0] = cols->data[i0];
    }

    i0 = A_val->size[0];
    A_val->size[0] = vs->size[0];
    emxEnsureCapacity_real_T(A_val, i0);
    unnamed_idx_0 = vs->size[0];
    for (i0 = 0; i0 < unnamed_idx_0; i0++) {
      A_val->data[i0] = vs->data[i0];
    }
  } else {
    i0 = A_col_ind->size[0];
    A_col_ind->size[0] = cols->size[0];
    emxEnsureCapacity_int32_T(A_col_ind, i0);
    i0 = A_val->size[0];
    A_val->size[0] = cols->size[0];
    emxEnsureCapacity_real_T(A_val, i0);
    for (i = 0; i < rows->size[0]; i++) {
      j = A_row_ptr->data[rows->data[i] - 1];
      A_val->data[A_row_ptr->data[rows->data[i] - 1] - 1] = vs->data[i];
      A_col_ind->data[j - 1] = cols->data[i];
      A_row_ptr->data[rows->data[i] - 1]++;
    }

    unnamed_idx_0 = A_row_ptr->size[0] - 2;
    i0 = (int)((2.0 + (-1.0 - (double)A_row_ptr->size[0])) / -1.0);
    for (i = 0; i < i0; i++) {
      j = unnamed_idx_0 - i;
      A_row_ptr->data[j + 1] = A_row_ptr->data[j];
    }

    A_row_ptr->data[0] = 1;
  }

  emxInit_int32_T(&col_ind, 1);
  i0 = col_ind->size[0];
  col_ind->size[0] = A_col_ind->size[0];
  emxEnsureCapacity_int32_T(col_ind, i0);
  unnamed_idx_0 = A_col_ind->size[0];
  for (i0 = 0; i0 < unnamed_idx_0; i0++) {
    col_ind->data[i0] = A_col_ind->data[i0];
  }

  emxInit_real_T(&val, 1);
  i0 = val->size[0];
  val->size[0] = A_val->size[0];
  emxEnsureCapacity_real_T(val, i0);
  unnamed_idx_0 = A_val->size[0];
  for (i0 = 0; i0 < unnamed_idx_0; i0++) {
    val->data[i0] = A_val->data[i0];
  }

  i0 = A_row_ptr->size[0] - 1;
  i = 1;
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  while (i <= i0) {
    ascend = true;
    j = A_row_ptr->data[i - 1];
    exitg1 = false;
    while ((!exitg1) && (j + 1 <= A_row_ptr->data[i] - 1)) {
      if (col_ind->data[j] < col_ind->data[j - 1]) {
        ascend = false;
        exitg1 = true;
      } else {
        j++;
      }
    }

    if (!ascend) {
      j = buf_indx->size[0];
      buf_indx->size[0] = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
      emxEnsureCapacity_int32_T(buf_indx, j);
      unnamed_idx_0 = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
      for (j = 0; j < unnamed_idx_0; j++) {
        buf_indx->data[j] = 0;
      }

      j = buf_val->size[0];
      buf_val->size[0] = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
      emxEnsureCapacity_real_T(buf_val, j);
      unnamed_idx_0 = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
      for (j = 0; j < unnamed_idx_0; j++) {
        buf_val->data[j] = 0.0;
      }

      ind = 1U;
      for (j = A_row_ptr->data[i - 1]; j < A_row_ptr->data[i]; j++) {
        buf_indx->data[(int)ind - 1] = col_ind->data[j - 1];
        buf_val->data[(int)ind - 1] = val->data[j - 1];
        ind++;
      }

      heapsort_tag(buf_indx, buf_val);
      ind = 1U;
      for (j = A_row_ptr->data[i - 1]; j < A_row_ptr->data[i]; j++) {
        col_ind->data[j - 1] = buf_indx->data[(int)ind - 1];
        val->data[j - 1] = buf_val->data[(int)ind - 1];
        ind++;
      }
    }

    i++;
  }

  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
  i0 = A_col_ind->size[0];
  A_col_ind->size[0] = col_ind->size[0];
  emxEnsureCapacity_int32_T(A_col_ind, i0);
  unnamed_idx_0 = col_ind->size[0];
  for (i0 = 0; i0 < unnamed_idx_0; i0++) {
    A_col_ind->data[i0] = col_ind->data[i0];
  }

  emxFree_int32_T(&col_ind);
  i0 = A_val->size[0];
  A_val->size[0] = val->size[0];
  emxEnsureCapacity_real_T(A_val, i0);
  unnamed_idx_0 = val->size[0];
  for (i0 = 0; i0 < unnamed_idx_0; i0++) {
    A_val->data[i0] = val->data[i0];
  }

  emxFree_real_T(&val);
  *A_nrows = mtmp;
  *A_ncols = b_mtmp;
}

static void crs_prodAB(const emxArray_int32_T *A_row_ptr, const emxArray_int32_T
  *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int A_ncols, const
  emxArray_int32_T *B_row_ptr, const emxArray_int32_T *B_col_ind, const
  emxArray_real_T *B_val, int B_nrows, int B_ncols, emxArray_int32_T *C_row_ptr,
  emxArray_int32_T *C_col_ind, emxArray_real_T *C_val, int *C_nrows, int
  *C_ncols)
{
  emxArray_int32_T *t0_row_ptr;
  int clength;
  int i;
  emxArray_int32_T *b_index;
  emxArray_real_T *temp;
  int loop_ub;
  int istart;
  int k;
  if (A_ncols != B_nrows) {
    m2c_error();
  }

  emxInit_int32_T(&t0_row_ptr, 1);
  clength = t0_row_ptr->size[0];
  t0_row_ptr->size[0] = A_nrows + 1;
  emxEnsureCapacity_int32_T(t0_row_ptr, clength);
  for (clength = 0; clength <= A_nrows; clength++) {
    t0_row_ptr->data[clength] = 0;
  }

  t0_row_ptr->data[0] = 1;
  for (i = 1; i <= A_nrows; i++) {
    t0_row_ptr->data[i] += t0_row_ptr->data[i - 1];
  }

  emxInit_int32_T(&b_index, 1);
  emxInit_real_T(&temp, 1);
  clength = C_row_ptr->size[0];
  C_row_ptr->size[0] = t0_row_ptr->size[0];
  emxEnsureCapacity_int32_T(C_row_ptr, clength);
  loop_ub = t0_row_ptr->size[0];
  for (clength = 0; clength < loop_ub; clength++) {
    C_row_ptr->data[clength] = t0_row_ptr->data[clength];
  }

  emxFree_int32_T(&t0_row_ptr);
  clength = C_row_ptr->size[0];
  C_row_ptr->size[0] = A_row_ptr->size[0];
  emxEnsureCapacity_int32_T(C_row_ptr, clength);
  C_row_ptr->data[0] = 1;
  if (A_ncols > B_ncols) {
    loop_ub = A_ncols;
  } else {
    loop_ub = B_ncols;
  }

  clength = b_index->size[0];
  b_index->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(b_index, clength);
  for (clength = 0; clength < loop_ub; clength++) {
    b_index->data[clength] = 0;
  }

  for (i = 1; i <= A_nrows; i++) {
    istart = -1;
    clength = 0;
    for (loop_ub = A_row_ptr->data[i - 1]; loop_ub < A_row_ptr->data[i]; loop_ub
         ++) {
      for (k = B_row_ptr->data[A_col_ind->data[loop_ub - 1] - 1] - 1; k + 1 <
           B_row_ptr->data[A_col_ind->data[loop_ub - 1]]; k++) {
        if (b_index->data[B_col_ind->data[k] - 1] == 0) {
          b_index->data[B_col_ind->data[k] - 1] = istart;
          istart = B_col_ind->data[k];
          clength++;
        }
      }
    }

    C_row_ptr->data[i] = C_row_ptr->data[i - 1] + clength;
    for (loop_ub = C_row_ptr->data[i - 1]; loop_ub < C_row_ptr->data[i]; loop_ub
         ++) {
      k = istart;
      istart = b_index->data[istart - 1];
      b_index->data[k - 1] = 0;
    }

    b_index->data[i - 1] = 0;
  }

  clength = C_col_ind->size[0];
  C_col_ind->size[0] = C_row_ptr->data[A_nrows] - 1;
  emxEnsureCapacity_int32_T(C_col_ind, clength);
  for (i = 1; i <= A_nrows; i++) {
    istart = -1;
    clength = 0;
    for (loop_ub = A_row_ptr->data[i - 1]; loop_ub < A_row_ptr->data[i]; loop_ub
         ++) {
      for (k = B_row_ptr->data[A_col_ind->data[loop_ub - 1] - 1] - 1; k + 1 <
           B_row_ptr->data[A_col_ind->data[loop_ub - 1]]; k++) {
        if (b_index->data[B_col_ind->data[k] - 1] == 0) {
          b_index->data[B_col_ind->data[k] - 1] = istart;
          istart = B_col_ind->data[k];
          clength++;
        }
      }
    }

    C_row_ptr->data[i] = C_row_ptr->data[i - 1] + clength;
    clength = C_row_ptr->data[i] - 1;
    for (loop_ub = C_row_ptr->data[i - 1]; loop_ub <= clength; loop_ub++) {
      C_col_ind->data[loop_ub - 1] = istart;
      istart = b_index->data[istart - 1];
      b_index->data[C_col_ind->data[loop_ub - 1] - 1] = 0;
    }

    b_index->data[i - 1] = 0;
  }

  clength = C_val->size[0];
  C_val->size[0] = C_row_ptr->data[A_nrows] - 1;
  emxEnsureCapacity_real_T(C_val, clength);
  clength = temp->size[0];
  temp->size[0] = b_index->size[0];
  emxEnsureCapacity_real_T(temp, clength);
  loop_ub = b_index->size[0];
  emxFree_int32_T(&b_index);
  for (clength = 0; clength < loop_ub; clength++) {
    temp->data[clength] = 0.0;
  }

  for (i = 1; i <= A_nrows; i++) {
    for (loop_ub = A_row_ptr->data[i - 1] - 1; loop_ub + 1 < A_row_ptr->data[i];
         loop_ub++) {
      for (k = B_row_ptr->data[A_col_ind->data[loop_ub] - 1] - 1; k + 1 <
           B_row_ptr->data[A_col_ind->data[loop_ub]]; k++) {
        temp->data[B_col_ind->data[k] - 1] += A_val->data[loop_ub] * B_val->
          data[k];
      }
    }

    clength = C_row_ptr->data[i] - 1;
    for (loop_ub = C_row_ptr->data[i - 1] - 1; loop_ub + 1 <= clength; loop_ub++)
    {
      C_val->data[loop_ub] = temp->data[C_col_ind->data[loop_ub] - 1];
      temp->data[C_col_ind->data[loop_ub] - 1] = 0.0;
    }
  }

  emxFree_real_T(&temp);
  *C_nrows = A_nrows;
  *C_ncols = B_ncols;
}

static void heapsort_tag(emxArray_int32_T *r, emxArray_real_T *TAGS)
{
  int n;
  int l;
  int exitg1;
  boolean_T guard1 = false;
  int r0;
  double t0;
  int j;
  int exitg2;
  int i;
  boolean_T gt;
  boolean_T guard2 = false;
  n = r->size[0];
  if (!(n <= 1)) {
    l = (int)((unsigned int)n >> 1U);
    do {
      exitg1 = 0;
      guard1 = false;
      if (l + 1 <= 1) {
        r0 = r->data[n - 1];
        t0 = TAGS->data[n - 1];
        r->data[n - 1] = r->data[0];
        TAGS->data[n - 1] = TAGS->data[0];
        n--;
        if (n == 1) {
          exitg1 = 1;
        } else {
          guard1 = true;
        }
      } else {
        l--;
        r0 = r->data[l];
        t0 = TAGS->data[l];
        guard1 = true;
      }

      if (guard1) {
        j = l;
        do {
          exitg2 = 0;
          i = j;
          j = ((j + 1) << 1) - 1;
          gt = false;
          guard2 = false;
          if (j + 1 >= n) {
            if (j + 1 == n) {
              gt = true;
              guard2 = true;
            } else if (j + 1 > n) {
              exitg2 = 1;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }

          if (guard2) {
            if ((!gt) && (r->data[j] < r->data[j + 1])) {
              j++;
            }

            if (r0 >= r->data[j]) {
              exitg2 = 1;
            } else {
              r->data[i] = r->data[j];
              TAGS->data[i] = TAGS->data[j];
            }
          }
        } while (exitg2 == 0);

        r->data[i] = r0;
        TAGS->data[i] = t0;
      }
    } while (exitg1 == 0);

    r->data[0] = r0;
    TAGS->data[0] = t0;
  }
}

static void m2c_error(void)
{
  M2C_error("crs_prodMatMat:WrongSizes",
            "Number of columns of A must be equal to number of rows in B.");
}

void crs_prodPtAP(const struct0_T *A, const struct0_T *P, struct0_T *B)
{
  emxArray_int32_T *C_row_ptr;
  emxArray_int32_T *C_col_ind;
  emxArray_real_T *C_val;
  emxArray_int32_T *js;
  int C_nrows;
  int C_ncols;
  unsigned int unnamed_idx_0;
  int nrows;
  int i;
  emxArray_int32_T *Pt_row_ptr;
  int j;
  emxArray_int32_T *Pt_col_ind;
  emxArray_real_T *Pt_val;
  emxInit_int32_T(&C_row_ptr, 1);
  emxInit_int32_T(&C_col_ind, 1);
  emxInit_real_T(&C_val, 1);
  emxInit_int32_T(&js, 1);
  crs_prodAB(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, P->row_ptr,
             P->col_ind, P->val, P->nrows, P->ncols, C_row_ptr, C_col_ind, C_val,
             &C_nrows, &C_ncols);
  unnamed_idx_0 = (unsigned int)P->col_ind->size[0];
  nrows = js->size[0];
  js->size[0] = (int)unnamed_idx_0;
  emxEnsureCapacity_int32_T(js, nrows);
  nrows = P->row_ptr->size[0] - 1;
  for (i = 1; i <= nrows; i++) {
    for (j = P->row_ptr->data[i - 1]; j < P->row_ptr->data[i]; j++) {
      js->data[j - 1] = i;
    }
  }

  emxInit_int32_T(&Pt_row_ptr, 1);
  emxInit_int32_T(&Pt_col_ind, 1);
  emxInit_real_T(&Pt_val, 1);
  crs_createFromAIJ(P->col_ind, js, P->val, Pt_row_ptr, Pt_col_ind, Pt_val,
                    &nrows, &i);
  crs_prodAB(Pt_row_ptr, Pt_col_ind, Pt_val, nrows, i, C_row_ptr, C_col_ind,
             C_val, C_nrows, C_ncols, B->row_ptr, B->col_ind, B->val, &B->nrows,
             &B->ncols);
  emxFree_int32_T(&js);
  emxFree_real_T(&Pt_val);
  emxFree_int32_T(&Pt_col_ind);
  emxFree_int32_T(&Pt_row_ptr);
  emxFree_real_T(&C_val);
  emxFree_int32_T(&C_col_ind);
  emxFree_int32_T(&C_row_ptr);
}

void crs_prodPtAP_initialize(void)
{
}

void crs_prodPtAP_terminate(void)
{
}
