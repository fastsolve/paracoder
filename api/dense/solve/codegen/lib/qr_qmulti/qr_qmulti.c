#include "qr_qmulti.h"
#include "m2c.h"
#include "qr_qmulti_emxutil.h"

void qr_qmulti(const emxArray_real_T *A, emxArray_real_T *bs, int ncols, const
               emxArray_real_T *V)
{
  int nrows;
  emxArray_real_T *b_bs;
  int A_idx_1;
  int A_idx_0;
  int u0;
  boolean_T empty_non_axis_sizes;
  double v1;
  int i0;
  int result;
  double t2;
  cell_wrap_0 reshapes[2];
  int i1;
  nrows = A->size[0];
  emxInit_real_T(&b_bs, 2);
  if (bs->size[0] < A->size[0]) {
    if (!((bs->size[0] == 0) || (bs->size[1] == 0))) {
      u0 = bs->size[1];
    } else {
      A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
      A_idx_1 = bs->size[1];
      if (!((A_idx_0 == 0) || (A_idx_1 == 0))) {
        A_idx_1 = bs->size[1];
        u0 = A_idx_1;
      } else {
        u0 = bs->size[1];
        if (!(u0 > 0)) {
          u0 = 0;
        }

        A_idx_1 = bs->size[1];
        if (A_idx_1 > u0) {
          A_idx_1 = bs->size[1];
          u0 = A_idx_1;
        }
      }
    }

    empty_non_axis_sizes = (u0 == 0);
    if (empty_non_axis_sizes || (!((bs->size[0] == 0) || (bs->size[1] == 0)))) {
      result = bs->size[0];
    } else {
      result = 0;
    }

    if (empty_non_axis_sizes) {
      A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
    } else {
      A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
      A_idx_1 = bs->size[1];
      if (!((A_idx_0 == 0) || (A_idx_1 == 0))) {
        A_idx_0 = (int)((double)A->size[0] - (double)bs->size[0]);
      } else {
        A_idx_0 = 0;
      }
    }

    emxInitMatrix_cell_wrap_0(reshapes);
    i0 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = A_idx_0;
    reshapes[1].f1->size[1] = u0;
    emxEnsureCapacity_real_T(reshapes[1].f1, i0);
    A_idx_0 *= u0;
    for (i0 = 0; i0 < A_idx_0; i0++) {
      reshapes[1].f1->data[i0] = 0.0;
    }

    i0 = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = result + reshapes[1].f1->size[0];
    b_bs->size[1] = u0;
    emxEnsureCapacity_real_T(b_bs, i0);
    for (i0 = 0; i0 < u0; i0++) {
      for (i1 = 0; i1 < result; i1++) {
        b_bs->data[i1 + b_bs->size[0] * i0] = bs->data[i1 + result * i0];
      }
    }

    A_idx_0 = reshapes[1].f1->size[1];
    for (i0 = 0; i0 < A_idx_0; i0++) {
      A_idx_1 = reshapes[1].f1->size[0];
      for (i1 = 0; i1 < A_idx_1; i1++) {
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
      A_idx_1 = b_bs->size[0];
      for (i1 = 0; i1 < A_idx_1; i1++) {
        bs->data[i1 + bs->size[0] * i0] = b_bs->data[i1 + b_bs->size[0] * i0];
      }
    }
  }

  for (A_idx_1 = ncols - 1; A_idx_1 + 1 > 0; A_idx_1--) {
    v1 = V->data[A_idx_1];
    i0 = bs->size[1];
    for (A_idx_0 = 0; A_idx_0 + 1 <= i0; A_idx_0++) {
      t2 = v1 * bs->data[A_idx_1 + bs->size[0] * A_idx_0];
      for (u0 = A_idx_1 + 1; u0 + 1 <= nrows; u0++) {
        t2 += A->data[u0 + A->size[0] * A_idx_1] * bs->data[u0 + bs->size[0] *
          A_idx_0];
      }

      t2 += t2;
      bs->data[A_idx_1 + bs->size[0] * A_idx_0] -= t2 * v1;
      for (u0 = A_idx_1 + 1; u0 + 1 <= nrows; u0++) {
        bs->data[u0 + bs->size[0] * A_idx_0] -= t2 * A->data[u0 + A->size[0] *
          A_idx_1];
      }
    }
  }

  if (bs->size[0] > A->size[0]) {
    if (1 > A->size[0]) {
      A_idx_0 = 0;
    } else {
      A_idx_0 = A->size[0];
    }

    A_idx_1 = bs->size[1];
    i0 = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = A_idx_0;
    b_bs->size[1] = A_idx_1;
    emxEnsureCapacity_real_T(b_bs, i0);
    for (i0 = 0; i0 < A_idx_1; i0++) {
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
      A_idx_1 = b_bs->size[0];
      for (i1 = 0; i1 < A_idx_1; i1++) {
        bs->data[i1 + bs->size[0] * i0] = b_bs->data[i1 + b_bs->size[0] * i0];
      }
    }
  }

  emxFree_real_T(&b_bs);
}

void qr_qmulti_initialize(void)
{
}

void qr_qmulti_terminate(void)
{
}
