#include "crs_prodPtAP.h"
#include "m2c.h"

static void crs_create(const emxArray_int32_T *rows, const emxArray_int32_T
  *cols, const emxArray_real_T *vs, emxArray_int32_T *A_row_ptr,
  emxArray_int32_T *A_col_ind, emxArray_real_T *A_val, int *A_nrows, int
  *A_ncols);
static void crs_prodAB(const emxArray_int32_T *A_row_ptr, const emxArray_int32_T
  *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int A_ncols, const
  emxArray_int32_T *B_row_ptr, const emxArray_int32_T *B_col_ind, const
  emxArray_real_T *B_val, int B_nrows, int B_ncols, emxArray_int32_T *C_row_ptr,
  emxArray_int32_T *C_col_ind, emxArray_real_T *C_val, int *C_nrows, int
  *C_ncols);
static void m2c_error(void);
static void crs_create(const emxArray_int32_T *rows, const emxArray_int32_T
  *cols, const emxArray_real_T *vs, emxArray_int32_T *A_row_ptr,
  emxArray_int32_T *A_col_ind, emxArray_real_T *A_val, int *A_nrows, int
  *A_ncols)
{
  emxArray_int32_T *col_ind;
  emxArray_real_T *val;
  emxArray_real_T *buf_val;
  emxArray_int32_T *buf_indx;
  int mtmp;
  int i0;
  int j;
  int b_mtmp;
  int n;
  int i;
  boolean_T ascend;
  boolean_T exitg1;
  int b_i;
  unsigned int ind;
  int l;
  int exitg2;
  boolean_T guard1 = false;
  int r0;
  double t0;
  int exitg3;
  boolean_T guard2 = false;
  emxInit_int32_T(&col_ind, 1);
  emxInit_real_T(&val, 1);
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  if ((rows->size[0] == 1) && (cols->size[0] == 1)) {
    i0 = A_row_ptr->size[0];
    A_row_ptr->size[0] = 0;
    emxEnsureCapacity((emxArray__common *)A_row_ptr, i0, sizeof(int));
    i0 = A_col_ind->size[0];
    A_col_ind->size[0] = 0;
    emxEnsureCapacity((emxArray__common *)A_col_ind, i0, sizeof(int));
    i0 = A_val->size[0];
    A_val->size[0] = vs->size[0];
    emxEnsureCapacity((emxArray__common *)A_val, i0, sizeof(double));
    j = vs->size[0];
    for (i0 = 0; i0 < j; i0++) {
      A_val->data[i0] = vs->data[i0];
    }

    mtmp = rows->data[0];
    b_mtmp = cols->data[0];
  } else {
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
    n = cols->size[0];
    i0 = A_row_ptr->size[0];
    A_row_ptr->size[0] = mtmp + 1;
    emxEnsureCapacity((emxArray__common *)A_row_ptr, i0, sizeof(int));
    for (i0 = 0; i0 <= mtmp; i0++) {
      A_row_ptr->data[i0] = 0;
    }

    i0 = A_col_ind->size[0];
    A_col_ind->size[0] = j;
    emxEnsureCapacity((emxArray__common *)A_col_ind, i0, sizeof(int));
    for (i0 = 0; i0 < j; i0++) {
      A_col_ind->data[i0] = 0;
    }

    i0 = A_val->size[0];
    A_val->size[0] = n;
    emxEnsureCapacity((emxArray__common *)A_val, i0, sizeof(double));
    for (i0 = 0; i0 < n; i0++) {
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
      emxEnsureCapacity((emxArray__common *)A_col_ind, i0, sizeof(int));
      j = cols->size[0];
      for (i0 = 0; i0 < j; i0++) {
        A_col_ind->data[i0] = cols->data[i0];
      }

      i0 = A_val->size[0];
      A_val->size[0] = vs->size[0];
      emxEnsureCapacity((emxArray__common *)A_val, i0, sizeof(double));
      j = vs->size[0];
      for (i0 = 0; i0 < j; i0++) {
        A_val->data[i0] = vs->data[i0];
      }
    } else {
      i0 = A_col_ind->size[0];
      A_col_ind->size[0] = cols->size[0];
      emxEnsureCapacity((emxArray__common *)A_col_ind, i0, sizeof(int));
      i0 = A_val->size[0];
      A_val->size[0] = cols->size[0];
      emxEnsureCapacity((emxArray__common *)A_val, i0, sizeof(double));
      for (i = 0; i < rows->size[0]; i++) {
        j = A_row_ptr->data[rows->data[i] - 1];
        A_val->data[A_row_ptr->data[rows->data[i] - 1] - 1] = vs->data[i];
        A_col_ind->data[j - 1] = cols->data[i];
        A_row_ptr->data[rows->data[i] - 1]++;
      }

      j = A_row_ptr->size[0] - 2;
      i0 = (int)((2.0 + (-1.0 - (double)A_row_ptr->size[0])) / -1.0);
      for (i = 0; i < i0; i++) {
        b_i = j - i;
        A_row_ptr->data[b_i + 1] = A_row_ptr->data[b_i];
      }

      A_row_ptr->data[0] = 1;
    }

    i0 = col_ind->size[0];
    col_ind->size[0] = A_col_ind->size[0];
    emxEnsureCapacity((emxArray__common *)col_ind, i0, sizeof(int));
    j = A_col_ind->size[0];
    for (i0 = 0; i0 < j; i0++) {
      col_ind->data[i0] = A_col_ind->data[i0];
    }

    i0 = val->size[0];
    val->size[0] = A_val->size[0];
    emxEnsureCapacity((emxArray__common *)val, i0, sizeof(double));
    j = A_val->size[0];
    for (i0 = 0; i0 < j; i0++) {
      val->data[i0] = A_val->data[i0];
    }

    i0 = A_row_ptr->size[0] - 1;
    for (i = 1; i <= i0; i++) {
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
        n = buf_indx->size[0];
        buf_indx->size[0] = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
        emxEnsureCapacity((emxArray__common *)buf_indx, n, sizeof(int));
        j = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
        for (n = 0; n < j; n++) {
          buf_indx->data[n] = 0;
        }

        n = buf_val->size[0];
        buf_val->size[0] = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
        emxEnsureCapacity((emxArray__common *)buf_val, n, sizeof(double));
        j = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
        for (n = 0; n < j; n++) {
          buf_val->data[n] = 0.0;
        }

        ind = 1U;
        for (j = A_row_ptr->data[i - 1]; j < A_row_ptr->data[i]; j++) {
          buf_indx->data[(int)ind - 1] = col_ind->data[j - 1];
          buf_val->data[(int)ind - 1] = val->data[j - 1];
          ind++;
        }

        n = buf_indx->size[0];
        if (!(n <= 1)) {
          l = (int)((unsigned int)n >> 1U);
          do {
            exitg2 = 0;
            guard1 = false;
            if (l + 1 <= 1) {
              r0 = buf_indx->data[n - 1];
              t0 = buf_val->data[n - 1];
              buf_indx->data[n - 1] = buf_indx->data[0];
              buf_val->data[n - 1] = buf_val->data[0];
              n--;
              if (n == 1) {
                exitg2 = 1;
              } else {
                guard1 = true;
              }
            } else {
              l--;
              r0 = buf_indx->data[l];
              t0 = buf_val->data[l];
              guard1 = true;
            }

            if (guard1) {
              j = l;
              do {
                exitg3 = 0;
                b_i = j;
                j = ((j + 1) << 1) - 1;
                ascend = false;
                guard2 = false;
                if (j + 1 >= n) {
                  if (j + 1 == n) {
                    ascend = true;
                    guard2 = true;
                  } else if (j + 1 > n) {
                    exitg3 = 1;
                  } else {
                    guard2 = true;
                  }
                } else {
                  guard2 = true;
                }

                if (guard2) {
                  if ((!ascend) && (buf_indx->data[j] < buf_indx->data[j + 1]))
                  {
                    j++;
                  }

                  if (r0 >= buf_indx->data[j]) {
                    exitg3 = 1;
                  } else {
                    buf_indx->data[b_i] = buf_indx->data[j];
                    buf_val->data[b_i] = buf_val->data[j];
                  }
                }
              } while (exitg3 == 0);

              buf_indx->data[b_i] = r0;
              buf_val->data[b_i] = t0;
            }
          } while (exitg2 == 0);

          buf_indx->data[0] = r0;
          buf_val->data[0] = t0;
        }

        ind = 1U;
        for (j = A_row_ptr->data[i - 1]; j < A_row_ptr->data[i]; j++) {
          col_ind->data[j - 1] = buf_indx->data[(int)ind - 1];
          val->data[j - 1] = buf_val->data[(int)ind - 1];
          ind++;
        }
      }
    }

    i0 = A_col_ind->size[0];
    A_col_ind->size[0] = col_ind->size[0];
    emxEnsureCapacity((emxArray__common *)A_col_ind, i0, sizeof(int));
    j = col_ind->size[0];
    for (i0 = 0; i0 < j; i0++) {
      A_col_ind->data[i0] = col_ind->data[i0];
    }

    i0 = A_val->size[0];
    A_val->size[0] = val->size[0];
    emxEnsureCapacity((emxArray__common *)A_val, i0, sizeof(double));
    j = val->size[0];
    for (i0 = 0; i0 < j; i0++) {
      A_val->data[i0] = val->data[i0];
    }
  }

  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
  emxFree_real_T(&val);
  emxFree_int32_T(&col_ind);
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
  int clength;
  int maxval;
  emxArray_int32_T *b_index;
  int i;
  int istart;
  int k;
  emxArray_real_T *temp;
  if (A_ncols != B_nrows) {
    m2c_error();
  }

  clength = C_row_ptr->size[0];
  C_row_ptr->size[0] = 0;
  emxEnsureCapacity((emxArray__common *)C_row_ptr, clength, sizeof(int));
  clength = C_col_ind->size[0];
  C_col_ind->size[0] = 0;
  emxEnsureCapacity((emxArray__common *)C_col_ind, clength, sizeof(int));
  clength = C_val->size[0];
  C_val->size[0] = 0;
  emxEnsureCapacity((emxArray__common *)C_val, clength, sizeof(double));
  clength = C_row_ptr->size[0];
  C_row_ptr->size[0] = A_row_ptr->size[0];
  emxEnsureCapacity((emxArray__common *)C_row_ptr, clength, sizeof(int));
  C_row_ptr->data[0] = 1;
  if (A_ncols > B_ncols) {
    maxval = A_ncols;
  } else {
    maxval = B_ncols;
  }

  emxInit_int32_T(&b_index, 1);
  clength = b_index->size[0];
  b_index->size[0] = maxval;
  emxEnsureCapacity((emxArray__common *)b_index, clength, sizeof(int));
  for (clength = 0; clength < maxval; clength++) {
    b_index->data[clength] = 0;
  }

  for (i = 1; i <= A_nrows; i++) {
    istart = -1;
    clength = 0;
    for (maxval = A_row_ptr->data[i - 1]; maxval < A_row_ptr->data[i]; maxval++)
    {
      for (k = B_row_ptr->data[A_col_ind->data[maxval - 1] - 1] - 1; k + 1 <
           B_row_ptr->data[A_col_ind->data[maxval - 1]]; k++) {
        if (b_index->data[B_col_ind->data[k] - 1] == 0) {
          b_index->data[B_col_ind->data[k] - 1] = istart;
          istart = B_col_ind->data[k];
          clength++;
        }
      }
    }

    C_row_ptr->data[i] = C_row_ptr->data[i - 1] + clength;
    for (maxval = C_row_ptr->data[i - 1]; maxval < C_row_ptr->data[i]; maxval++)
    {
      k = istart;
      istart = b_index->data[istart - 1];
      b_index->data[k - 1] = 0;
    }

    b_index->data[i - 1] = 0;
  }

  clength = C_col_ind->size[0];
  C_col_ind->size[0] = C_row_ptr->data[A_nrows] - 1;
  emxEnsureCapacity((emxArray__common *)C_col_ind, clength, sizeof(int));
  for (i = 1; i <= A_nrows; i++) {
    istart = -1;
    clength = 0;
    for (maxval = A_row_ptr->data[i - 1]; maxval < A_row_ptr->data[i]; maxval++)
    {
      for (k = B_row_ptr->data[A_col_ind->data[maxval - 1] - 1] - 1; k + 1 <
           B_row_ptr->data[A_col_ind->data[maxval - 1]]; k++) {
        if (b_index->data[B_col_ind->data[k] - 1] == 0) {
          b_index->data[B_col_ind->data[k] - 1] = istart;
          istart = B_col_ind->data[k];
          clength++;
        }
      }
    }

    C_row_ptr->data[i] = C_row_ptr->data[i - 1] + clength;
    clength = C_row_ptr->data[i] - 1;
    for (maxval = C_row_ptr->data[i - 1]; maxval <= clength; maxval++) {
      C_col_ind->data[maxval - 1] = istart;
      istart = b_index->data[istart - 1];
      b_index->data[C_col_ind->data[maxval - 1] - 1] = 0;
    }

    b_index->data[i - 1] = 0;
  }

  emxInit_real_T(&temp, 1);
  clength = C_val->size[0];
  C_val->size[0] = C_row_ptr->data[A_nrows] - 1;
  emxEnsureCapacity((emxArray__common *)C_val, clength, sizeof(double));
  clength = temp->size[0];
  temp->size[0] = b_index->size[0];
  emxEnsureCapacity((emxArray__common *)temp, clength, sizeof(double));
  maxval = b_index->size[0];
  emxFree_int32_T(&b_index);
  for (clength = 0; clength < maxval; clength++) {
    temp->data[clength] = 0.0;
  }

  for (i = 1; i <= A_nrows; i++) {
    for (maxval = A_row_ptr->data[i - 1] - 1; maxval + 1 < A_row_ptr->data[i];
         maxval++) {
      for (k = B_row_ptr->data[A_col_ind->data[maxval] - 1] - 1; k + 1 <
           B_row_ptr->data[A_col_ind->data[maxval]]; k++) {
        temp->data[B_col_ind->data[k] - 1] += A_val->data[maxval] * B_val->
          data[k];
      }
    }

    clength = C_row_ptr->data[i] - 1;
    for (maxval = C_row_ptr->data[i - 1] - 1; maxval + 1 <= clength; maxval++) {
      C_val->data[maxval] = temp->data[C_col_ind->data[maxval] - 1];
      temp->data[C_col_ind->data[maxval] - 1] = 0.0;
    }
  }

  emxFree_real_T(&temp);
  *C_nrows = A_nrows;
  *C_ncols = B_ncols;
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
  emxEnsureCapacity((emxArray__common *)js, nrows, sizeof(int));
  nrows = P->row_ptr->size[0] - 1;
  for (i = 1; i <= nrows; i++) {
    for (j = P->row_ptr->data[i - 1]; j < P->row_ptr->data[i]; j++) {
      js->data[j - 1] = i;
    }
  }

  emxInit_int32_T(&Pt_row_ptr, 1);
  emxInit_int32_T(&Pt_col_ind, 1);
  emxInit_real_T(&Pt_val, 1);
  crs_create(P->col_ind, js, P->val, Pt_row_ptr, Pt_col_ind, Pt_val, &nrows, &i);
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
