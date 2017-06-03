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
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(void);
static void crs_create(const emxArray_int32_T *rows, const emxArray_int32_T
  *cols, const emxArray_real_T *vs, emxArray_int32_T *A_row_ptr,
  emxArray_int32_T *A_col_ind, emxArray_real_T *A_val, int *A_nrows, int
  *A_ncols)
{
  emxArray_int32_T *r0;
  emxArray_real_T *r1;
  emxArray_real_T *buf_val;
  emxArray_int32_T *buf_indx;
  int b_r0;
  int i3;
  int n;
  int l;
  int i;
  boolean_T ascend;
  boolean_T exitg4;
  int j;
  int b_i;
  boolean_T exitg3;
  unsigned int ind;
  int exitg1;
  boolean_T guard1 = false;
  double t0;
  int exitg2;
  boolean_T guard2 = false;
  emxInit_int32_T(&r0, 1);
  emxInit_real_T(&r1, 1);
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  if ((rows->size[0] == 1) && (cols->size[0] == 1)) {
    i3 = A_row_ptr->size[0];
    A_row_ptr->size[0] = 0;
    emxEnsureCapacity((emxArray__common *)A_row_ptr, i3, (int)sizeof(int));
    i3 = A_col_ind->size[0];
    A_col_ind->size[0] = 0;
    emxEnsureCapacity((emxArray__common *)A_col_ind, i3, (int)sizeof(int));
    i3 = A_val->size[0];
    A_val->size[0] = vs->size[0];
    emxEnsureCapacity((emxArray__common *)A_val, i3, (int)sizeof(double));
    n = vs->size[0];
    for (i3 = 0; i3 < n; i3++) {
      A_val->data[i3] = vs->data[i3];
    }

    *A_nrows = rows->data[0];
    *A_ncols = cols->data[0];
  } else {
    b_r0 = rows->data[0];
    if (rows->size[0] > 1) {
      for (n = 1; n + 1 <= rows->size[0]; n++) {
        if (rows->data[n] > b_r0) {
          b_r0 = rows->data[n];
        }
      }
    }

    l = cols->data[0];
    if (cols->size[0] > 1) {
      for (n = 1; n + 1 <= cols->size[0]; n++) {
        if (cols->data[n] > l) {
          l = cols->data[n];
        }
      }
    }

    i3 = A_row_ptr->size[0];
    A_row_ptr->size[0] = b_r0 + 1;
    emxEnsureCapacity((emxArray__common *)A_row_ptr, i3, (int)sizeof(int));
    for (i3 = 0; i3 <= b_r0; i3++) {
      A_row_ptr->data[i3] = 0;
    }

    *A_nrows = b_r0;
    *A_ncols = l;
    i3 = rows->size[0];
    for (i = 0; i + 1 <= i3; i++) {
      A_row_ptr->data[rows->data[i]]++;
    }

    A_row_ptr->data[0] = 1;
    for (i = 1; i <= b_r0; i++) {
      A_row_ptr->data[i] += A_row_ptr->data[i - 1];
    }

    ascend = true;
    i = 0;
    exitg4 = false;
    while ((!exitg4) && (i <= rows->size[0] - 2)) {
      if (rows->data[1 + i] < rows->data[i]) {
        ascend = false;
        exitg4 = true;
      } else {
        i++;
      }
    }

    if (ascend) {
      i3 = A_col_ind->size[0];
      A_col_ind->size[0] = cols->size[0];
      emxEnsureCapacity((emxArray__common *)A_col_ind, i3, (int)sizeof(int));
      n = cols->size[0];
      for (i3 = 0; i3 < n; i3++) {
        A_col_ind->data[i3] = cols->data[i3];
      }

      i3 = A_val->size[0];
      A_val->size[0] = vs->size[0];
      emxEnsureCapacity((emxArray__common *)A_val, i3, (int)sizeof(double));
      n = vs->size[0];
      for (i3 = 0; i3 < n; i3++) {
        A_val->data[i3] = vs->data[i3];
      }
    } else {
      i3 = A_col_ind->size[0];
      A_col_ind->size[0] = cols->size[0];
      emxEnsureCapacity((emxArray__common *)A_col_ind, i3, (int)sizeof(int));
      i3 = A_val->size[0];
      A_val->size[0] = cols->size[0];
      emxEnsureCapacity((emxArray__common *)A_val, i3, (int)sizeof(double));
      for (i = 0; i < rows->size[0]; i++) {
        j = A_row_ptr->data[rows->data[i] - 1];
        A_val->data[A_row_ptr->data[rows->data[i] - 1] - 1] = vs->data[i];
        A_col_ind->data[j - 1] = cols->data[i];
        A_row_ptr->data[rows->data[i] - 1]++;
      }

      n = A_row_ptr->size[0] - 2;
      i3 = (int)((2.0 + (-1.0 - (double)A_row_ptr->size[0])) / -1.0);
      for (i = 0; i < i3; i++) {
        b_i = n - i;
        A_row_ptr->data[b_i + 1] = A_row_ptr->data[b_i];
      }

      A_row_ptr->data[0] = 1;
    }

    i3 = r1->size[0];
    r1->size[0] = A_val->size[0];
    emxEnsureCapacity((emxArray__common *)r1, i3, (int)sizeof(double));
    n = A_val->size[0];
    for (i3 = 0; i3 < n; i3++) {
      r1->data[i3] = A_val->data[i3];
    }

    i3 = r0->size[0];
    r0->size[0] = A_col_ind->size[0];
    emxEnsureCapacity((emxArray__common *)r0, i3, (int)sizeof(int));
    n = A_col_ind->size[0];
    for (i3 = 0; i3 < n; i3++) {
      r0->data[i3] = A_col_ind->data[i3];
    }

    i3 = A_row_ptr->size[0] - 1;
    for (i = 1; i <= i3; i++) {
      ascend = true;
      l = A_row_ptr->data[i] - 1;
      j = A_row_ptr->data[i - 1];
      exitg3 = false;
      while ((!exitg3) && (j + 1 <= l)) {
        if (r0->data[j] < r0->data[j - 1]) {
          ascend = false;
          exitg3 = true;
        } else {
          j++;
        }
      }

      if (!ascend) {
        l = buf_indx->size[0];
        buf_indx->size[0] = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
        emxEnsureCapacity((emxArray__common *)buf_indx, l, (int)sizeof(int));
        n = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
        for (l = 0; l < n; l++) {
          buf_indx->data[l] = 0;
        }

        l = buf_val->size[0];
        buf_val->size[0] = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
        emxEnsureCapacity((emxArray__common *)buf_val, l, (int)sizeof(double));
        n = A_row_ptr->data[i] - A_row_ptr->data[i - 1];
        for (l = 0; l < n; l++) {
          buf_val->data[l] = 0.0;
        }

        ind = 1U;
        l = A_row_ptr->data[i] - 1;
        for (j = A_row_ptr->data[i - 1]; j <= l; j++) {
          buf_indx->data[(int)ind - 1] = r0->data[j - 1];
          buf_val->data[(int)ind - 1] = r1->data[j - 1];
          ind++;
        }

        n = buf_indx->size[0];
        if (!(n <= 1)) {
          l = (int)((unsigned int)n >> 1U);
          do {
            exitg1 = 0;
            guard1 = false;
            if (l + 1 <= 1) {
              b_r0 = buf_indx->data[n - 1];
              t0 = buf_val->data[n - 1];
              buf_indx->data[n - 1] = buf_indx->data[0];
              buf_val->data[n - 1] = buf_val->data[0];
              n--;
              if (n == 1) {
                exitg1 = 1;
              } else {
                guard1 = true;
              }
            } else {
              l--;
              b_r0 = buf_indx->data[l];
              t0 = buf_val->data[l];
              guard1 = true;
            }

            if (guard1) {
              j = l;
              do {
                exitg2 = 0;
                b_i = j;
                j = ((j + 1) << 1) - 1;
                ascend = false;
                guard2 = false;
                if (j + 1 >= n) {
                  if (j + 1 == n) {
                    ascend = true;
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
                  if ((!ascend) && (buf_indx->data[j] < buf_indx->data[j + 1]))
                  {
                    j++;
                  }

                  if (b_r0 >= buf_indx->data[j]) {
                    exitg2 = 1;
                  } else {
                    buf_indx->data[b_i] = buf_indx->data[j];
                    buf_val->data[b_i] = buf_val->data[j];
                  }
                }
              } while (exitg2 == 0);

              buf_indx->data[b_i] = b_r0;
              buf_val->data[b_i] = t0;
            }
          } while (exitg1 == 0);

          buf_indx->data[0] = b_r0;
          buf_val->data[0] = t0;
        }

        ind = 1U;
        l = A_row_ptr->data[i] - 1;
        for (j = A_row_ptr->data[i - 1]; j <= l; j++) {
          r0->data[j - 1] = buf_indx->data[(int)ind - 1];
          r1->data[j - 1] = buf_val->data[(int)ind - 1];
          ind++;
        }
      }
    }

    i3 = A_col_ind->size[0];
    A_col_ind->size[0] = r0->size[0];
    emxEnsureCapacity((emxArray__common *)A_col_ind, i3, (int)sizeof(int));
    n = r0->size[0];
    for (i3 = 0; i3 < n; i3++) {
      A_col_ind->data[i3] = r0->data[i3];
    }

    i3 = A_val->size[0];
    A_val->size[0] = r1->size[0];
    emxEnsureCapacity((emxArray__common *)A_val, i3, (int)sizeof(double));
    n = r1->size[0];
    for (i3 = 0; i3 < n; i3++) {
      A_val->data[i3] = r1->data[i3];
    }
  }

  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
  emxFree_real_T(&r1);
  emxFree_int32_T(&r0);
}

static void crs_prodAB(const emxArray_int32_T *A_row_ptr, const emxArray_int32_T
  *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int A_ncols, const
  emxArray_int32_T *B_row_ptr, const emxArray_int32_T *B_col_ind, const
  emxArray_real_T *B_val, int B_nrows, int B_ncols, emxArray_int32_T *C_row_ptr,
  emxArray_int32_T *C_col_ind, emxArray_real_T *C_val, int *C_nrows, int
  *C_ncols)
{
  int i1;
  int maxval;
  emxArray_int32_T *b_index;
  int i;
  int istart;
  int clength;
  int i2;
  emxArray_real_T *temp;
  int k;
  if (A_ncols != B_nrows) {
    m2c_error();
  }

  *C_nrows = A_nrows;
  *C_ncols = B_ncols;
  i1 = C_row_ptr->size[0];
  C_row_ptr->size[0] = A_row_ptr->size[0];
  emxEnsureCapacity((emxArray__common *)C_row_ptr, i1, (int)sizeof(int));
  C_row_ptr->data[0] = 1;
  if (A_ncols >= B_ncols) {
    maxval = A_ncols;
  } else {
    maxval = B_ncols;
  }

  emxInit_int32_T(&b_index, 1);
  i1 = b_index->size[0];
  b_index->size[0] = maxval;
  emxEnsureCapacity((emxArray__common *)b_index, i1, (int)sizeof(int));
  for (i1 = 0; i1 < maxval; i1++) {
    b_index->data[i1] = 0;
  }

  for (i = 1; i <= A_nrows; i++) {
    istart = -1;
    clength = 0;
    i1 = A_row_ptr->data[i] - 1;
    for (maxval = A_row_ptr->data[i - 1]; maxval <= i1; maxval++) {
      i2 = B_row_ptr->data[A_col_ind->data[maxval - 1]] - 1;
      for (k = B_row_ptr->data[A_col_ind->data[maxval - 1] - 1] - 1; k + 1 <= i2;
           k++) {
        if (b_index->data[B_col_ind->data[k] - 1] == 0) {
          b_index->data[B_col_ind->data[k] - 1] = istart;
          istart = B_col_ind->data[k];
          clength++;
        }
      }
    }

    C_row_ptr->data[i] = C_row_ptr->data[i - 1] + clength;
    i1 = C_row_ptr->data[i] - 1;
    for (maxval = C_row_ptr->data[i - 1]; maxval <= i1; maxval++) {
      k = istart;
      istart = b_index->data[istart - 1];
      b_index->data[k - 1] = 0;
    }

    b_index->data[i - 1] = 0;
  }

  maxval = C_row_ptr->data[A_nrows] - 1;
  i1 = C_col_ind->size[0];
  C_col_ind->size[0] = maxval;
  emxEnsureCapacity((emxArray__common *)C_col_ind, i1, (int)sizeof(int));
  for (i = 1; i <= A_nrows; i++) {
    istart = -1;
    clength = 0;
    i1 = A_row_ptr->data[i] - 1;
    for (maxval = A_row_ptr->data[i - 1]; maxval <= i1; maxval++) {
      i2 = B_row_ptr->data[A_col_ind->data[maxval - 1]] - 1;
      for (k = B_row_ptr->data[A_col_ind->data[maxval - 1] - 1] - 1; k + 1 <= i2;
           k++) {
        if (b_index->data[B_col_ind->data[k] - 1] == 0) {
          b_index->data[B_col_ind->data[k] - 1] = istart;
          istart = B_col_ind->data[k];
          clength++;
        }
      }
    }

    C_row_ptr->data[i] = C_row_ptr->data[i - 1] + clength;
    i1 = C_row_ptr->data[i] - 1;
    for (maxval = C_row_ptr->data[i - 1]; maxval <= i1; maxval++) {
      C_col_ind->data[maxval - 1] = istart;
      istart = b_index->data[istart - 1];
      b_index->data[C_col_ind->data[maxval - 1] - 1] = 0;
    }

    b_index->data[i - 1] = 0;
  }

  emxInit_real_T(&temp, 1);
  maxval = C_row_ptr->data[A_nrows] - 1;
  i1 = C_val->size[0];
  C_val->size[0] = maxval;
  emxEnsureCapacity((emxArray__common *)C_val, i1, (int)sizeof(double));
  i1 = temp->size[0];
  temp->size[0] = b_index->size[0];
  emxEnsureCapacity((emxArray__common *)temp, i1, (int)sizeof(double));
  maxval = b_index->size[0];
  emxFree_int32_T(&b_index);
  for (i1 = 0; i1 < maxval; i1++) {
    temp->data[i1] = 0.0;
  }

  for (i = 1; i <= A_nrows; i++) {
    i1 = A_row_ptr->data[i] - 1;
    for (maxval = A_row_ptr->data[i - 1] - 1; maxval + 1 <= i1; maxval++) {
      i2 = B_row_ptr->data[A_col_ind->data[maxval]] - 1;
      for (k = B_row_ptr->data[A_col_ind->data[maxval] - 1] - 1; k + 1 <= i2; k
           ++) {
        temp->data[B_col_ind->data[k] - 1] += A_val->data[maxval] * B_val->
          data[k];
      }
    }

    i1 = C_row_ptr->data[i] - 1;
    for (maxval = C_row_ptr->data[i - 1] - 1; maxval + 1 <= i1; maxval++) {
      C_val->data[maxval] = temp->data[C_col_ind->data[maxval] - 1];
      temp->data[C_col_ind->data[maxval] - 1] = 0.0;
    }
  }

  emxFree_real_T(&temp);
}

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

void crs_prodPtAP(const struct0_T *A, const struct0_T *P, struct0_T *B)
{
  emxArray_int32_T *C_row_ptr;
  emxArray_int32_T *C_col_ind;
  emxArray_real_T *C_val;
  emxArray_int32_T *js;
  int C_nrows;
  int C_ncols;
  unsigned int unnamed_idx_0;
  int i0;
  int nrows;
  int i;
  emxArray_int32_T *Pt_row_ptr;
  emxArray_int32_T *Pt_col_ind;
  int j;
  emxArray_real_T *Pt_val;
  int Pt_nrows;
  int Pt_ncols;
  emxInit_int32_T(&C_row_ptr, 1);
  emxInit_int32_T(&C_col_ind, 1);
  emxInit_real_T(&C_val, 1);
  emxInit_int32_T(&js, 1);
  crs_prodAB(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, P->row_ptr,
             P->col_ind, P->val, P->nrows, P->ncols, C_row_ptr, C_col_ind, C_val,
             &C_nrows, &C_ncols);
  unnamed_idx_0 = (unsigned int)P->col_ind->size[0];
  i0 = js->size[0];
  js->size[0] = (int)unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)js, i0, (int)sizeof(int));
  nrows = P->row_ptr->size[0] - 1;
  for (i = 1; i <= nrows; i++) {
    i0 = P->row_ptr->data[i] - 1;
    for (j = P->row_ptr->data[i - 1]; j <= i0; j++) {
      js->data[j - 1] = i;
    }
  }

  emxInit_int32_T(&Pt_row_ptr, 1);
  emxInit_int32_T(&Pt_col_ind, 1);
  emxInit_real_T(&Pt_val, 1);
  crs_create(P->col_ind, js, P->val, Pt_row_ptr, Pt_col_ind, Pt_val, &Pt_nrows,
             &Pt_ncols);
  crs_prodAB(Pt_row_ptr, Pt_col_ind, Pt_val, Pt_nrows, Pt_ncols, C_row_ptr,
             C_col_ind, C_val, C_nrows, C_ncols, B->row_ptr, B->col_ind, B->val,
             &B->nrows, &B->ncols);
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

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}
