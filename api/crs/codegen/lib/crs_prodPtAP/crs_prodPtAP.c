#include "crs_prodPtAP.h"
#include "m2c.h"

static void crs_prodAB(const emxArray_int32_T *A_row_ptr, const emxArray_int32_T
  *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int A_ncols, const
  emxArray_int32_T *B_row_ptr, const emxArray_int32_T *B_col_ind, const
  emxArray_real_T *B_val, int B_nrows, int B_ncols, emxArray_int32_T *C_row_ptr,
  emxArray_int32_T *C_col_ind, emxArray_real_T *C_val, int *C_nrows, int
  *C_ncols);
static void heapsort_tag(emxArray_int32_T *r, emxArray_real_T *TAGS);
static void m2c_error(void);
static void crs_prodAB(const emxArray_int32_T *A_row_ptr, const emxArray_int32_T
  *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int A_ncols, const
  emxArray_int32_T *B_row_ptr, const emxArray_int32_T *B_col_ind, const
  emxArray_real_T *B_val, int B_nrows, int B_ncols, emxArray_int32_T *C_row_ptr,
  emxArray_int32_T *C_col_ind, emxArray_real_T *C_val, int *C_nrows, int
  *C_ncols)
{
  int i;
  int b_i;
  emxArray_int32_T *buf_indx;
  int clength;
  int istart;
  int i1;
  int jj;
  emxArray_real_T *buf_val;
  int i2;
  int i3;
  int k;
  int j;
  int i4;
  if (A_ncols != B_nrows) {
    m2c_error();
  }

  i = C_row_ptr->size[0];
  C_row_ptr->size[0] = A_nrows + 1;
  emxEnsureCapacity_int32_T(C_row_ptr, i);
  for (i = 0; i <= A_nrows; i++) {
    C_row_ptr->data[i] = 0;
  }

  C_row_ptr->data[0] = 1;
  for (b_i = 0; b_i < A_nrows; b_i++) {
    C_row_ptr->data[b_i + 1] += C_row_ptr->data[b_i];
  }

  i = C_row_ptr->size[0];
  for (b_i = 0; b_i <= i - 2; b_i++) {
    if (C_row_ptr->data[b_i] + 1 <= C_row_ptr->data[b_i + 1] - 1) {
      abort();
    }
  }

  emxInit_int32_T(&buf_indx, 1);
  i = C_row_ptr->size[0];
  C_row_ptr->size[0] = A_row_ptr->size[0];
  emxEnsureCapacity_int32_T(C_row_ptr, i);
  C_row_ptr->data[0] = 1;
  if (A_ncols > B_ncols) {
    clength = A_ncols;
  } else {
    clength = B_ncols;
  }

  i = buf_indx->size[0];
  buf_indx->size[0] = clength;
  emxEnsureCapacity_int32_T(buf_indx, i);
  for (i = 0; i < clength; i++) {
    buf_indx->data[i] = 0;
  }

  for (b_i = 0; b_i < A_nrows; b_i++) {
    istart = -1;
    clength = 0;
    i = A_row_ptr->data[b_i];
    i1 = A_row_ptr->data[b_i + 1] - 1;
    for (jj = i; jj <= i1; jj++) {
      i2 = A_col_ind->data[jj - 1];
      i3 = B_row_ptr->data[i2 - 1];
      i2 = B_row_ptr->data[i2] - 1;
      for (k = i3; k <= i2; k++) {
        j = B_col_ind->data[k - 1];
        i4 = j - 1;
        if (buf_indx->data[i4] == 0) {
          buf_indx->data[i4] = istart;
          istart = j;
          clength++;
        }
      }
    }

    i = C_row_ptr->data[b_i];
    i1 = C_row_ptr->data[b_i] + clength;
    C_row_ptr->data[b_i + 1] = i1;
    i1--;
    for (j = i; j <= i1; j++) {
      k = istart;
      istart = buf_indx->data[istart - 1];
      buf_indx->data[k - 1] = 0;
    }

    buf_indx->data[b_i] = 0;
  }

  i = C_col_ind->size[0];
  C_col_ind->size[0] = C_row_ptr->data[A_nrows] - 1;
  emxEnsureCapacity_int32_T(C_col_ind, i);
  for (b_i = 0; b_i < A_nrows; b_i++) {
    istart = -1;
    clength = 0;
    i = A_row_ptr->data[b_i];
    i1 = A_row_ptr->data[b_i + 1] - 1;
    for (jj = i; jj <= i1; jj++) {
      i2 = A_col_ind->data[jj - 1];
      i3 = B_row_ptr->data[i2 - 1];
      i2 = B_row_ptr->data[i2] - 1;
      for (k = i3; k <= i2; k++) {
        j = B_col_ind->data[k - 1];
        i4 = j - 1;
        if (buf_indx->data[i4] == 0) {
          buf_indx->data[i4] = istart;
          istart = j;
          clength++;
        }
      }
    }

    i = C_row_ptr->data[b_i];
    i1 = C_row_ptr->data[b_i] + clength;
    C_row_ptr->data[b_i + 1] = i1;
    i1--;
    for (j = i; j <= i1; j++) {
      C_col_ind->data[j - 1] = istart;
      istart = buf_indx->data[istart - 1];
      buf_indx->data[C_col_ind->data[j - 1] - 1] = 0;
    }

    buf_indx->data[b_i] = 0;
  }

  emxInit_real_T(&buf_val, 1);
  i = C_val->size[0];
  C_val->size[0] = C_row_ptr->data[A_nrows] - 1;
  emxEnsureCapacity_real_T(C_val, i);
  i = buf_val->size[0];
  buf_val->size[0] = buf_indx->size[0];
  emxEnsureCapacity_real_T(buf_val, i);
  clength = buf_indx->size[0];
  emxFree_int32_T(&buf_indx);
  for (i = 0; i < clength; i++) {
    buf_val->data[i] = 0.0;
  }

  for (b_i = 0; b_i < A_nrows; b_i++) {
    i = A_row_ptr->data[b_i];
    i1 = A_row_ptr->data[b_i + 1] - 1;
    for (jj = i; jj <= i1; jj++) {
      i2 = A_col_ind->data[jj - 1];
      i3 = B_row_ptr->data[i2 - 1];
      i2 = B_row_ptr->data[i2] - 1;
      for (k = i3; k <= i2; k++) {
        clength = B_col_ind->data[k - 1] - 1;
        buf_val->data[clength] += A_val->data[jj - 1] * B_val->data[k - 1];
      }
    }

    i = C_row_ptr->data[b_i];
    i1 = C_row_ptr->data[b_i + 1] - 1;
    for (j = i; j <= i1; j++) {
      clength = C_col_ind->data[j - 1] - 1;
      C_val->data[j - 1] = buf_val->data[clength];
      buf_val->data[clength] = 0.0;
    }
  }

  emxFree_real_T(&buf_val);
  *C_nrows = A_nrows;
  *C_ncols = B_ncols;
}

static void heapsort_tag(emxArray_int32_T *r, emxArray_real_T *TAGS)
{
  int l;
  int ir;
  int exitg1;
  boolean_T guard1 = false;
  int r0;
  double t0;
  int j;
  int exitg2;
  int i;
  boolean_T gt;
  boolean_T guard2 = false;
  if (r->size[0] > 1) {
    l = (int)((unsigned int)r->size[0] >> 1U);
    ir = r->size[0];
    do {
      exitg1 = 0;
      guard1 = false;
      if (l + 1 <= 1) {
        r0 = r->data[ir - 1];
        t0 = TAGS->data[ir - 1];
        r->data[ir - 1] = r->data[0];
        TAGS->data[ir - 1] = TAGS->data[0];
        ir--;
        if (ir == 1) {
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
          if (j + 1 >= ir) {
            if (j + 1 == ir) {
              gt = true;
              guard2 = true;
            } else if (j + 1 > ir) {
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
  int i;
  int nrows;
  int b_i;
  int n;
  int i1;
  int j;
  int ncols;
  emxArray_int32_T *Pt_row_ptr;
  emxArray_int32_T *buf_indx;
  emxArray_real_T *Pt_val;
  boolean_T ascend;
  boolean_T exitg1;
  emxArray_real_T *buf_val;
  int exitg2;
  int i2;
  unsigned int ind;
  emxInit_int32_T(&C_row_ptr, 1);
  emxInit_int32_T(&C_col_ind, 1);
  emxInit_real_T(&C_val, 1);
  emxInit_int32_T(&js, 1);
  crs_prodAB(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, P->row_ptr,
             P->col_ind, P->val, P->nrows, P->ncols, C_row_ptr, C_col_ind, C_val,
             &C_nrows, &C_ncols);
  i = js->size[0];
  js->size[0] = P->col_ind->size[0];
  emxEnsureCapacity_int32_T(js, i);
  nrows = P->row_ptr->size[0];
  for (b_i = 0; b_i <= nrows - 2; b_i++) {
    i = P->row_ptr->data[b_i];
    i1 = P->row_ptr->data[b_i + 1] - 1;
    for (j = i; j <= i1; j++) {
      js->data[j - 1] = b_i + 1;
    }
  }

  n = P->col_ind->size[0];
  nrows = 0;
  if (P->col_ind->size[0] >= 1) {
    nrows = P->col_ind->data[0];
    for (j = 2; j <= n; j++) {
      i = P->col_ind->data[j - 1];
      if (nrows < i) {
        nrows = i;
      }
    }
  }

  n = js->size[0];
  ncols = 0;
  if (js->size[0] >= 1) {
    ncols = js->data[0];
    for (j = 2; j <= n; j++) {
      i = js->data[j - 1];
      if (ncols < i) {
        ncols = i;
      }
    }
  }

  emxInit_int32_T(&Pt_row_ptr, 1);
  i = Pt_row_ptr->size[0];
  Pt_row_ptr->size[0] = nrows + 1;
  emxEnsureCapacity_int32_T(Pt_row_ptr, i);
  for (i = 0; i <= nrows; i++) {
    Pt_row_ptr->data[i] = 0;
  }

  emxInit_int32_T(&buf_indx, 1);
  i = buf_indx->size[0];
  buf_indx->size[0] = js->size[0];
  emxEnsureCapacity_int32_T(buf_indx, i);
  j = js->size[0];
  for (i = 0; i < j; i++) {
    buf_indx->data[i] = 0;
  }

  emxInit_real_T(&Pt_val, 1);
  i = Pt_val->size[0];
  Pt_val->size[0] = js->size[0];
  emxEnsureCapacity_real_T(Pt_val, i);
  j = js->size[0];
  for (i = 0; i < j; i++) {
    Pt_val->data[i] = 0.0;
  }

  i = P->col_ind->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    Pt_row_ptr->data[P->col_ind->data[b_i]]++;
  }

  Pt_row_ptr->data[0] = 1;
  for (b_i = 0; b_i < nrows; b_i++) {
    Pt_row_ptr->data[b_i + 1] += Pt_row_ptr->data[b_i];
  }

  ascend = true;
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= P->col_ind->size[0] - 2)) {
    if (P->col_ind->data[b_i + 1] < P->col_ind->data[b_i]) {
      ascend = false;
      exitg1 = true;
    } else {
      b_i++;
    }
  }

  if (ascend) {
    i = buf_indx->size[0];
    buf_indx->size[0] = js->size[0];
    emxEnsureCapacity_int32_T(buf_indx, i);
    j = js->size[0];
    for (i = 0; i < j; i++) {
      buf_indx->data[i] = js->data[i];
    }

    i = Pt_val->size[0];
    Pt_val->size[0] = P->val->size[0];
    emxEnsureCapacity_real_T(Pt_val, i);
    j = P->val->size[0];
    for (i = 0; i < j; i++) {
      Pt_val->data[i] = P->val->data[i];
    }
  } else {
    i = buf_indx->size[0];
    buf_indx->size[0] = js->size[0];
    emxEnsureCapacity_int32_T(buf_indx, i);
    i = Pt_val->size[0];
    Pt_val->size[0] = js->size[0];
    emxEnsureCapacity_real_T(Pt_val, i);
    i = P->col_ind->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      n = Pt_row_ptr->data[P->col_ind->data[b_i] - 1];
      j = n - 1;
      Pt_val->data[j] = P->val->data[b_i];
      buf_indx->data[j] = js->data[b_i];
      Pt_row_ptr->data[P->col_ind->data[b_i] - 1] = n + 1;
    }

    n = Pt_row_ptr->size[0] - 2;
    i = (int)(((-1.0 - (double)Pt_row_ptr->size[0]) + 2.0) / -1.0);
    for (b_i = 0; b_i < i; b_i++) {
      j = n - b_i;
      Pt_row_ptr->data[j + 1] = Pt_row_ptr->data[j];
    }

    Pt_row_ptr->data[0] = 1;
  }

  i = js->size[0];
  js->size[0] = buf_indx->size[0];
  emxEnsureCapacity_int32_T(js, i);
  j = buf_indx->size[0];
  for (i = 0; i < j; i++) {
    js->data[i] = buf_indx->data[i];
  }

  i = Pt_row_ptr->size[0];
  emxInit_real_T(&buf_val, 1);
  for (b_i = 0; b_i <= i - 2; b_i++) {
    ascend = true;
    j = Pt_row_ptr->data[b_i];
    do {
      exitg2 = 0;
      i1 = Pt_row_ptr->data[b_i + 1];
      i2 = i1 - 1;
      if (j + 1 <= i2) {
        if (js->data[j] < js->data[j - 1]) {
          ascend = false;
          exitg2 = 1;
        } else {
          j++;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (!ascend) {
      j = i1 - Pt_row_ptr->data[b_i];
      i1 = buf_indx->size[0];
      buf_indx->size[0] = j;
      emxEnsureCapacity_int32_T(buf_indx, i1);
      for (i1 = 0; i1 < j; i1++) {
        buf_indx->data[i1] = 0;
      }

      i1 = buf_val->size[0];
      buf_val->size[0] = j;
      emxEnsureCapacity_real_T(buf_val, i1);
      for (i1 = 0; i1 < j; i1++) {
        buf_val->data[i1] = 0.0;
      }

      ind = 1U;
      i1 = Pt_row_ptr->data[b_i];
      for (j = i1; j <= i2; j++) {
        n = (int)ind - 1;
        buf_indx->data[n] = js->data[j - 1];
        buf_val->data[n] = Pt_val->data[j - 1];
        ind++;
      }

      heapsort_tag(buf_indx, buf_val);
      ind = 1U;
      i1 = Pt_row_ptr->data[b_i];
      for (j = i1; j <= i2; j++) {
        n = (int)ind - 1;
        js->data[j - 1] = buf_indx->data[n];
        Pt_val->data[j - 1] = buf_val->data[n];
        ind++;
      }
    }
  }

  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
  crs_prodAB(Pt_row_ptr, js, Pt_val, nrows, ncols, C_row_ptr, C_col_ind, C_val,
             C_nrows, C_ncols, B->row_ptr, B->col_ind, B->val, &B->nrows,
             &B->ncols);
  emxFree_int32_T(&js);
  emxFree_real_T(&Pt_val);
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
