#include "qr_qtmulti.h"
#include "m2c.h"
#include "qr_qtmulti_emxutil.h"

void qr_qtmulti(const emxArray_real_T *A, emxArray_real_T *bs, int ncols, const
                emxArray_real_T *V)
{
  int nrows;
  emxArray_real_T *b_bs;
  int k;
  int A_idx_0;
  int A_idx_1;
  int b_A_idx_1;
  boolean_T empty_non_axis_sizes;
  double v1;
  int i0;
  int result;
  int jj;
  double t2;
  int ii;
  cell_wrap_0 reshapes[2];
  int i1;
  nrows = A->size[0];
  emxInit_real_T(&b_bs, 2);
  if (bs->size[0] < A->size[0]) {
    if (!((bs->size[0] == 0) || (bs->size[1] == 0))) {
      A_idx_1 = bs->size[1];
    } else {
      A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
      b_A_idx_1 = bs->size[1];
      if (!((A_idx_0 == 0) || (b_A_idx_1 == 0))) {
        A_idx_1 = bs->size[1];
      } else {
        A_idx_1 = bs->size[1];
        if (!(A_idx_1 > 0)) {
          A_idx_1 = 0;
        }

        b_A_idx_1 = bs->size[1];
        if (b_A_idx_1 > A_idx_1) {
          A_idx_1 = bs->size[1];
        }
      }
    }

    empty_non_axis_sizes = (A_idx_1 == 0);
    if (empty_non_axis_sizes || (!((bs->size[0] == 0) || (bs->size[1] == 0)))) {
      result = bs->size[0];
    } else {
      result = 0;
    }

    if (empty_non_axis_sizes) {
      A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
    } else {
      A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
      b_A_idx_1 = bs->size[1];
      if (!((A_idx_0 == 0) || (b_A_idx_1 == 0))) {
        A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
      } else {
        A_idx_0 = 0;
      }
    }

    emxInitMatrix_cell_wrap_0(reshapes);
    i0 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = A_idx_0;
    reshapes[1].f1->size[1] = A_idx_1;
    emxEnsureCapacity_real_T(reshapes[1].f1, i0);
    A_idx_0 *= A_idx_1;
    for (i0 = 0; i0 < A_idx_0; i0++) {
      reshapes[1].f1->data[i0] = 0.0;
    }

    i0 = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = result + reshapes[1].f1->size[0];
    b_bs->size[1] = A_idx_1;
    emxEnsureCapacity_real_T(b_bs, i0);
    for (i0 = 0; i0 < A_idx_1; i0++) {
      for (i1 = 0; i1 < result; i1++) {
        b_bs->data[i1 + b_bs->size[0] * i0] = bs->data[i1 + result * i0];
      }
    }

    A_idx_0 = reshapes[1].f1->size[1];
    for (i0 = 0; i0 < A_idx_0; i0++) {
      b_A_idx_1 = reshapes[1].f1->size[0];
      for (i1 = 0; i1 < b_A_idx_1; i1++) {
        b_bs->data[(i1 + result) + b_bs->size[0] * i0] = reshapes[1].f1->data[i1
          + reshapes[1].f1->size[0] * i0];
      }
    }

    emxFreeMatrix_cell_wrap_0(reshapes);
    i0 = bs->size[0] * bs->size[1];
    bs->size[0] = b_bs->size[0];
    bs->size[1] = b_bs->size[1];
    emxEnsureCapacity_real_T(bs, i0);
    A_idx_0 = b_bs->size[1];
    for (i0 = 0; i0 < A_idx_0; i0++) {
      b_A_idx_1 = b_bs->size[0];
      for (i1 = 0; i1 < b_A_idx_1; i1++) {
        bs->data[i1 + bs->size[0] * i0] = b_bs->data[i1 + b_bs->size[0] * i0];
      }
    }
  }

  for (k = 0; k + 1 <= ncols; k++) {
    v1 = V->data[k];
    i0 = bs->size[1];
    for (jj = 0; jj + 1 <= i0; jj++) {
      t2 = v1 * bs->data[k + bs->size[0] * jj];
      for (ii = k + 1; ii + 1 <= nrows; ii++) {
        t2 += A->data[ii + A->size[0] * k] * bs->data[ii + bs->size[0] * jj];
      }

      t2 += t2;
      bs->data[k + bs->size[0] * jj] -= t2 * v1;
      for (ii = k + 1; ii + 1 <= nrows; ii++) {
        bs->data[ii + bs->size[0] * jj] -= t2 * A->data[ii + A->size[0] * k];
      }
    }
  }

  if (bs->size[0] > A->size[0]) {
    if (1 > A->size[0]) {
      A_idx_0 = 0;
    } else {
      A_idx_0 = A->size[0];
    }

    b_A_idx_1 = bs->size[1];
    i0 = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = A_idx_0;
    b_bs->size[1] = b_A_idx_1;
    emxEnsureCapacity_real_T(b_bs, i0);
    for (i0 = 0; i0 < b_A_idx_1; i0++) {
      for (i1 = 0; i1 < A_idx_0; i1++) {
        b_bs->data[i1 + b_bs->size[0] * i0] = bs->data[i1 + bs->size[0] * i0];
      }
    }

    i0 = bs->size[0] * bs->size[1];
    bs->size[0] = b_bs->size[0];
    bs->size[1] = b_bs->size[1];
    emxEnsureCapacity_real_T(bs, i0);
    A_idx_0 = b_bs->size[1];
    for (i0 = 0; i0 < A_idx_0; i0++) {
      b_A_idx_1 = b_bs->size[0];
      for (i1 = 0; i1 < b_A_idx_1; i1++) {
        bs->data[i1 + bs->size[0] * i0] = b_bs->data[i1 + b_bs->size[0] * i0];
      }
    }
  }

  emxFree_real_T(&b_bs);
}

void qr_qtmulti_2args(const emxArray_real_T *A, emxArray_real_T *bs)
{
  int nrows;
  emxArray_real_T *b_bs;
  int k;
  int A_idx_0;
  int A_idx_1;
  int b_A_idx_1;
  boolean_T empty_non_axis_sizes;
  double v1;
  int ii;
  int result;
  int i2;
  cell_wrap_0 reshapes[2];
  int jj;
  int i3;
  double t2;
  nrows = A->size[0];
  emxInit_real_T(&b_bs, 2);
  if (bs->size[0] < A->size[0]) {
    if (!((bs->size[0] == 0) || (bs->size[1] == 0))) {
      A_idx_1 = bs->size[1];
    } else {
      A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
      b_A_idx_1 = bs->size[1];
      if (!((A_idx_0 == 0) || (b_A_idx_1 == 0))) {
        A_idx_1 = bs->size[1];
      } else {
        A_idx_1 = bs->size[1];
        if (!(A_idx_1 > 0)) {
          A_idx_1 = 0;
        }

        b_A_idx_1 = bs->size[1];
        if (b_A_idx_1 > A_idx_1) {
          A_idx_1 = bs->size[1];
        }
      }
    }

    empty_non_axis_sizes = (A_idx_1 == 0);
    if (empty_non_axis_sizes || (!((bs->size[0] == 0) || (bs->size[1] == 0)))) {
      result = bs->size[0];
    } else {
      result = 0;
    }

    if (empty_non_axis_sizes) {
      A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
    } else {
      A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
      b_A_idx_1 = bs->size[1];
      if (!((A_idx_0 == 0) || (b_A_idx_1 == 0))) {
        A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
      } else {
        A_idx_0 = 0;
      }
    }

    emxInitMatrix_cell_wrap_0(reshapes);
    i2 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = A_idx_0;
    reshapes[1].f1->size[1] = A_idx_1;
    emxEnsureCapacity_real_T(reshapes[1].f1, i2);
    A_idx_0 *= A_idx_1;
    for (i2 = 0; i2 < A_idx_0; i2++) {
      reshapes[1].f1->data[i2] = 0.0;
    }

    i2 = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = result + reshapes[1].f1->size[0];
    b_bs->size[1] = A_idx_1;
    emxEnsureCapacity_real_T(b_bs, i2);
    for (i2 = 0; i2 < A_idx_1; i2++) {
      for (i3 = 0; i3 < result; i3++) {
        b_bs->data[i3 + b_bs->size[0] * i2] = bs->data[i3 + result * i2];
      }
    }

    A_idx_0 = reshapes[1].f1->size[1];
    for (i2 = 0; i2 < A_idx_0; i2++) {
      b_A_idx_1 = reshapes[1].f1->size[0];
      for (i3 = 0; i3 < b_A_idx_1; i3++) {
        b_bs->data[(i3 + result) + b_bs->size[0] * i2] = reshapes[1].f1->data[i3
          + reshapes[1].f1->size[0] * i2];
      }
    }

    emxFreeMatrix_cell_wrap_0(reshapes);
    i2 = bs->size[0] * bs->size[1];
    bs->size[0] = b_bs->size[0];
    bs->size[1] = b_bs->size[1];
    emxEnsureCapacity_real_T(bs, i2);
    A_idx_0 = b_bs->size[1];
    for (i2 = 0; i2 < A_idx_0; i2++) {
      b_A_idx_1 = b_bs->size[0];
      for (i3 = 0; i3 < b_A_idx_1; i3++) {
        bs->data[i3 + bs->size[0] * i2] = b_bs->data[i3 + b_bs->size[0] * i2];
      }
    }
  }

  for (k = 0; k + 1 <= A->size[1]; k++) {
    v1 = 1.0;
    for (ii = k + 1; ii + 1 <= nrows; ii++) {
      v1 -= A->data[ii + A->size[0] * k] * A->data[ii + A->size[0] * k];
    }

    if (v1 < 0.0) {
      v1 = 0.0;
    } else {
      v1 = sqrt(v1);
    }

    i2 = bs->size[1];
    for (jj = 0; jj + 1 <= i2; jj++) {
      t2 = v1 * bs->data[k + bs->size[0] * jj];
      for (ii = k + 1; ii + 1 <= nrows; ii++) {
        t2 += A->data[ii + A->size[0] * k] * bs->data[ii + bs->size[0] * jj];
      }

      t2 += t2;
      bs->data[k + bs->size[0] * jj] -= t2 * v1;
      for (ii = k + 1; ii + 1 <= nrows; ii++) {
        bs->data[ii + bs->size[0] * jj] -= t2 * A->data[ii + A->size[0] * k];
      }
    }
  }

  if (bs->size[0] > A->size[0]) {
    if (1 > A->size[0]) {
      A_idx_0 = 0;
    } else {
      A_idx_0 = A->size[0];
    }

    b_A_idx_1 = bs->size[1];
    i2 = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = A_idx_0;
    b_bs->size[1] = b_A_idx_1;
    emxEnsureCapacity_real_T(b_bs, i2);
    for (i2 = 0; i2 < b_A_idx_1; i2++) {
      for (i3 = 0; i3 < A_idx_0; i3++) {
        b_bs->data[i3 + b_bs->size[0] * i2] = bs->data[i3 + bs->size[0] * i2];
      }
    }

    i2 = bs->size[0] * bs->size[1];
    bs->size[0] = b_bs->size[0];
    bs->size[1] = b_bs->size[1];
    emxEnsureCapacity_real_T(bs, i2);
    A_idx_0 = b_bs->size[1];
    for (i2 = 0; i2 < A_idx_0; i2++) {
      b_A_idx_1 = b_bs->size[0];
      for (i3 = 0; i3 < b_A_idx_1; i3++) {
        bs->data[i3 + bs->size[0] * i2] = b_bs->data[i3 + b_bs->size[0] * i2];
      }
    }
  }

  emxFree_real_T(&b_bs);
}

void qr_qtmulti_3args(const emxArray_real_T *A, emxArray_real_T *bs, int ncols)
{
  int nrows;
  emxArray_real_T *b_bs;
  int k;
  int A_idx_0;
  int A_idx_1;
  int b_A_idx_1;
  boolean_T empty_non_axis_sizes;
  double v1;
  int ii;
  int result;
  int i4;
  cell_wrap_0 reshapes[2];
  int jj;
  int i5;
  double t2;
  nrows = A->size[0];
  emxInit_real_T(&b_bs, 2);
  if (bs->size[0] < A->size[0]) {
    if (!((bs->size[0] == 0) || (bs->size[1] == 0))) {
      A_idx_1 = bs->size[1];
    } else {
      A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
      b_A_idx_1 = bs->size[1];
      if (!((A_idx_0 == 0) || (b_A_idx_1 == 0))) {
        A_idx_1 = bs->size[1];
      } else {
        A_idx_1 = bs->size[1];
        if (!(A_idx_1 > 0)) {
          A_idx_1 = 0;
        }

        b_A_idx_1 = bs->size[1];
        if (b_A_idx_1 > A_idx_1) {
          A_idx_1 = bs->size[1];
        }
      }
    }

    empty_non_axis_sizes = (A_idx_1 == 0);
    if (empty_non_axis_sizes || (!((bs->size[0] == 0) || (bs->size[1] == 0)))) {
      result = bs->size[0];
    } else {
      result = 0;
    }

    if (empty_non_axis_sizes) {
      A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
    } else {
      A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
      b_A_idx_1 = bs->size[1];
      if (!((A_idx_0 == 0) || (b_A_idx_1 == 0))) {
        A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
      } else {
        A_idx_0 = 0;
      }
    }

    emxInitMatrix_cell_wrap_0(reshapes);
    i4 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = A_idx_0;
    reshapes[1].f1->size[1] = A_idx_1;
    emxEnsureCapacity_real_T(reshapes[1].f1, i4);
    A_idx_0 *= A_idx_1;
    for (i4 = 0; i4 < A_idx_0; i4++) {
      reshapes[1].f1->data[i4] = 0.0;
    }

    i4 = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = result + reshapes[1].f1->size[0];
    b_bs->size[1] = A_idx_1;
    emxEnsureCapacity_real_T(b_bs, i4);
    for (i4 = 0; i4 < A_idx_1; i4++) {
      for (i5 = 0; i5 < result; i5++) {
        b_bs->data[i5 + b_bs->size[0] * i4] = bs->data[i5 + result * i4];
      }
    }

    A_idx_0 = reshapes[1].f1->size[1];
    for (i4 = 0; i4 < A_idx_0; i4++) {
      b_A_idx_1 = reshapes[1].f1->size[0];
      for (i5 = 0; i5 < b_A_idx_1; i5++) {
        b_bs->data[(i5 + result) + b_bs->size[0] * i4] = reshapes[1].f1->data[i5
          + reshapes[1].f1->size[0] * i4];
      }
    }

    emxFreeMatrix_cell_wrap_0(reshapes);
    i4 = bs->size[0] * bs->size[1];
    bs->size[0] = b_bs->size[0];
    bs->size[1] = b_bs->size[1];
    emxEnsureCapacity_real_T(bs, i4);
    A_idx_0 = b_bs->size[1];
    for (i4 = 0; i4 < A_idx_0; i4++) {
      b_A_idx_1 = b_bs->size[0];
      for (i5 = 0; i5 < b_A_idx_1; i5++) {
        bs->data[i5 + bs->size[0] * i4] = b_bs->data[i5 + b_bs->size[0] * i4];
      }
    }
  }

  for (k = 0; k + 1 <= ncols; k++) {
    v1 = 1.0;
    for (ii = k + 1; ii + 1 <= nrows; ii++) {
      v1 -= A->data[ii + A->size[0] * k] * A->data[ii + A->size[0] * k];
    }

    if (v1 < 0.0) {
      v1 = 0.0;
    } else {
      v1 = sqrt(v1);
    }

    i4 = bs->size[1];
    for (jj = 0; jj + 1 <= i4; jj++) {
      t2 = v1 * bs->data[k + bs->size[0] * jj];
      for (ii = k + 1; ii + 1 <= nrows; ii++) {
        t2 += A->data[ii + A->size[0] * k] * bs->data[ii + bs->size[0] * jj];
      }

      t2 += t2;
      bs->data[k + bs->size[0] * jj] -= t2 * v1;
      for (ii = k + 1; ii + 1 <= nrows; ii++) {
        bs->data[ii + bs->size[0] * jj] -= t2 * A->data[ii + A->size[0] * k];
      }
    }
  }

  if (bs->size[0] > A->size[0]) {
    if (1 > A->size[0]) {
      A_idx_0 = 0;
    } else {
      A_idx_0 = A->size[0];
    }

    b_A_idx_1 = bs->size[1];
    i4 = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = A_idx_0;
    b_bs->size[1] = b_A_idx_1;
    emxEnsureCapacity_real_T(b_bs, i4);
    for (i4 = 0; i4 < b_A_idx_1; i4++) {
      for (i5 = 0; i5 < A_idx_0; i5++) {
        b_bs->data[i5 + b_bs->size[0] * i4] = bs->data[i5 + bs->size[0] * i4];
      }
    }

    i4 = bs->size[0] * bs->size[1];
    bs->size[0] = b_bs->size[0];
    bs->size[1] = b_bs->size[1];
    emxEnsureCapacity_real_T(bs, i4);
    A_idx_0 = b_bs->size[1];
    for (i4 = 0; i4 < A_idx_0; i4++) {
      b_A_idx_1 = b_bs->size[0];
      for (i5 = 0; i5 < b_A_idx_1; i5++) {
        bs->data[i5 + bs->size[0] * i4] = b_bs->data[i5 + b_bs->size[0] * i4];
      }
    }
  }

  emxFree_real_T(&b_bs);
}

void qr_qtmulti_initialize(void)
{
}

void qr_qtmulti_terminate(void)
{
}
