#include "qr_qtmulti.h"
#include "m2c.h"
#include <math.h>

void qr_qtmulti(const emxArray_real_T *A, emxArray_real_T *bs, int ncols, const
                emxArray_real_T *V)
{
  int nrows;
  emxArray_real_T *b_bs;
  int u0;
  double v1;
  boolean_T empty_non_axis_sizes;
  int i;
  int input_sizes_idx_0;
  double t2;
  int i1;
  int sizes_idx_0;
  nrows = A->size[0];
  emxInit_real_T(&b_bs, 2);
  if (bs->size[0] < A->size[0]) {
    if ((bs->size[0] != 0) && (bs->size[1] != 0)) {
      u0 = bs->size[1];
    } else if ((A->size[0] - bs->size[0] != 0) && (bs->size[1] != 0)) {
      u0 = bs->size[1];
    } else {
      u0 = bs->size[1];
      if (u0 <= 0) {
        u0 = 0;
      }

      if (bs->size[1] > u0) {
        u0 = bs->size[1];
      }
    }

    empty_non_axis_sizes = (u0 == 0);
    if (empty_non_axis_sizes || ((bs->size[0] != 0) && (bs->size[1] != 0))) {
      input_sizes_idx_0 = bs->size[0];
    } else {
      input_sizes_idx_0 = 0;
    }

    if (empty_non_axis_sizes || ((A->size[0] - bs->size[0] != 0) && (bs->size[1]
          != 0))) {
      sizes_idx_0 = A->size[0] - bs->size[0];
    } else {
      sizes_idx_0 = 0;
    }

    i = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = input_sizes_idx_0 + sizes_idx_0;
    b_bs->size[1] = u0;
    emxEnsureCapacity_real_T(b_bs, i);
    for (i = 0; i < u0; i++) {
      for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
        b_bs->data[i1 + b_bs->size[0] * i] = bs->data[i1 + input_sizes_idx_0 * i];
      }
    }

    for (i = 0; i < u0; i++) {
      for (i1 = 0; i1 < sizes_idx_0; i1++) {
        b_bs->data[(i1 + input_sizes_idx_0) + b_bs->size[0] * i] = 0.0;
      }
    }

    i = bs->size[0] * bs->size[1];
    bs->size[0] = b_bs->size[0];
    bs->size[1] = b_bs->size[1];
    emxEnsureCapacity_real_T(bs, i);
    u0 = b_bs->size[1];
    for (i = 0; i < u0; i++) {
      input_sizes_idx_0 = b_bs->size[0];
      for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
        bs->data[i1 + bs->size[0] * i] = b_bs->data[i1 + b_bs->size[0] * i];
      }
    }
  }

  for (u0 = 0; u0 < ncols; u0++) {
    v1 = V->data[u0];
    i = bs->size[1];
    for (input_sizes_idx_0 = 0; input_sizes_idx_0 < i; input_sizes_idx_0++) {
      t2 = v1 * bs->data[u0 + bs->size[0] * input_sizes_idx_0];
      i1 = u0 + 2;
      for (sizes_idx_0 = i1; sizes_idx_0 <= nrows; sizes_idx_0++) {
        t2 += A->data[(sizes_idx_0 + A->size[0] * u0) - 1] * bs->data
          [(sizes_idx_0 + bs->size[0] * input_sizes_idx_0) - 1];
      }

      t2 += t2;
      bs->data[u0 + bs->size[0] * input_sizes_idx_0] -= t2 * v1;
      i1 = u0 + 2;
      for (sizes_idx_0 = i1; sizes_idx_0 <= nrows; sizes_idx_0++) {
        bs->data[(sizes_idx_0 + bs->size[0] * input_sizes_idx_0) - 1] -= t2 *
          A->data[(sizes_idx_0 + A->size[0] * u0) - 1];
      }
    }
  }

  if (bs->size[0] > A->size[0]) {
    if (1 > A->size[0]) {
      u0 = 0;
    } else {
      u0 = A->size[0];
    }

    input_sizes_idx_0 = bs->size[1] - 1;
    i = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = u0;
    b_bs->size[1] = input_sizes_idx_0 + 1;
    emxEnsureCapacity_real_T(b_bs, i);
    for (i = 0; i <= input_sizes_idx_0; i++) {
      for (i1 = 0; i1 < u0; i1++) {
        b_bs->data[i1 + b_bs->size[0] * i] = bs->data[i1 + bs->size[0] * i];
      }
    }

    i = bs->size[0] * bs->size[1];
    bs->size[0] = b_bs->size[0];
    bs->size[1] = b_bs->size[1];
    emxEnsureCapacity_real_T(bs, i);
    u0 = b_bs->size[1];
    for (i = 0; i < u0; i++) {
      input_sizes_idx_0 = b_bs->size[0];
      for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
        bs->data[i1 + bs->size[0] * i] = b_bs->data[i1 + b_bs->size[0] * i];
      }
    }
  }

  emxFree_real_T(&b_bs);
}

void qr_qtmulti_2args(const emxArray_real_T *A, emxArray_real_T *bs)
{
  int nrows;
  int ncols;
  emxArray_real_T *b_bs;
  int u0;
  double v1;
  boolean_T empty_non_axis_sizes;
  int i;
  int input_sizes_idx_0;
  double t2;
  int sizes_idx_0;
  int i1;
  nrows = A->size[0];
  ncols = A->size[1];
  emxInit_real_T(&b_bs, 2);
  if (bs->size[0] < A->size[0]) {
    if ((bs->size[0] != 0) && (bs->size[1] != 0)) {
      u0 = bs->size[1];
    } else if ((A->size[0] - bs->size[0] != 0) && (bs->size[1] != 0)) {
      u0 = bs->size[1];
    } else {
      u0 = bs->size[1];
      if (u0 <= 0) {
        u0 = 0;
      }

      if (bs->size[1] > u0) {
        u0 = bs->size[1];
      }
    }

    empty_non_axis_sizes = (u0 == 0);
    if (empty_non_axis_sizes || ((bs->size[0] != 0) && (bs->size[1] != 0))) {
      input_sizes_idx_0 = bs->size[0];
    } else {
      input_sizes_idx_0 = 0;
    }

    if (empty_non_axis_sizes || ((A->size[0] - bs->size[0] != 0) && (bs->size[1]
          != 0))) {
      sizes_idx_0 = A->size[0] - bs->size[0];
    } else {
      sizes_idx_0 = 0;
    }

    i = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = input_sizes_idx_0 + sizes_idx_0;
    b_bs->size[1] = u0;
    emxEnsureCapacity_real_T(b_bs, i);
    for (i = 0; i < u0; i++) {
      for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
        b_bs->data[i1 + b_bs->size[0] * i] = bs->data[i1 + input_sizes_idx_0 * i];
      }
    }

    for (i = 0; i < u0; i++) {
      for (i1 = 0; i1 < sizes_idx_0; i1++) {
        b_bs->data[(i1 + input_sizes_idx_0) + b_bs->size[0] * i] = 0.0;
      }
    }

    i = bs->size[0] * bs->size[1];
    bs->size[0] = b_bs->size[0];
    bs->size[1] = b_bs->size[1];
    emxEnsureCapacity_real_T(bs, i);
    u0 = b_bs->size[1];
    for (i = 0; i < u0; i++) {
      input_sizes_idx_0 = b_bs->size[0];
      for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
        bs->data[i1 + bs->size[0] * i] = b_bs->data[i1 + b_bs->size[0] * i];
      }
    }
  }

  for (u0 = 0; u0 < ncols; u0++) {
    v1 = 1.0;
    i = u0 + 2;
    for (input_sizes_idx_0 = i; input_sizes_idx_0 <= nrows; input_sizes_idx_0++)
    {
      t2 = A->data[(input_sizes_idx_0 + A->size[0] * u0) - 1];
      v1 -= t2 * t2;
    }

    if (v1 < 0.0) {
      v1 = 0.0;
    } else {
      v1 = sqrt(v1);
    }

    i = bs->size[1];
    for (sizes_idx_0 = 0; sizes_idx_0 < i; sizes_idx_0++) {
      t2 = v1 * bs->data[u0 + bs->size[0] * sizes_idx_0];
      i1 = u0 + 2;
      for (input_sizes_idx_0 = i1; input_sizes_idx_0 <= nrows; input_sizes_idx_0
           ++) {
        t2 += A->data[(input_sizes_idx_0 + A->size[0] * u0) - 1] * bs->data
          [(input_sizes_idx_0 + bs->size[0] * sizes_idx_0) - 1];
      }

      t2 += t2;
      bs->data[u0 + bs->size[0] * sizes_idx_0] -= t2 * v1;
      i1 = u0 + 2;
      for (input_sizes_idx_0 = i1; input_sizes_idx_0 <= nrows; input_sizes_idx_0
           ++) {
        bs->data[(input_sizes_idx_0 + bs->size[0] * sizes_idx_0) - 1] -= t2 *
          A->data[(input_sizes_idx_0 + A->size[0] * u0) - 1];
      }
    }
  }

  if (bs->size[0] > A->size[0]) {
    if (1 > A->size[0]) {
      u0 = 0;
    } else {
      u0 = A->size[0];
    }

    input_sizes_idx_0 = bs->size[1] - 1;
    i = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = u0;
    b_bs->size[1] = input_sizes_idx_0 + 1;
    emxEnsureCapacity_real_T(b_bs, i);
    for (i = 0; i <= input_sizes_idx_0; i++) {
      for (i1 = 0; i1 < u0; i1++) {
        b_bs->data[i1 + b_bs->size[0] * i] = bs->data[i1 + bs->size[0] * i];
      }
    }

    i = bs->size[0] * bs->size[1];
    bs->size[0] = b_bs->size[0];
    bs->size[1] = b_bs->size[1];
    emxEnsureCapacity_real_T(bs, i);
    u0 = b_bs->size[1];
    for (i = 0; i < u0; i++) {
      input_sizes_idx_0 = b_bs->size[0];
      for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
        bs->data[i1 + bs->size[0] * i] = b_bs->data[i1 + b_bs->size[0] * i];
      }
    }
  }

  emxFree_real_T(&b_bs);
}

void qr_qtmulti_3args(const emxArray_real_T *A, emxArray_real_T *bs, int ncols)
{
  int nrows;
  emxArray_real_T *b_bs;
  int u0;
  double v1;
  boolean_T empty_non_axis_sizes;
  int i;
  int input_sizes_idx_0;
  double t2;
  int sizes_idx_0;
  int i1;
  nrows = A->size[0];
  emxInit_real_T(&b_bs, 2);
  if (bs->size[0] < A->size[0]) {
    if ((bs->size[0] != 0) && (bs->size[1] != 0)) {
      u0 = bs->size[1];
    } else if ((A->size[0] - bs->size[0] != 0) && (bs->size[1] != 0)) {
      u0 = bs->size[1];
    } else {
      u0 = bs->size[1];
      if (u0 <= 0) {
        u0 = 0;
      }

      if (bs->size[1] > u0) {
        u0 = bs->size[1];
      }
    }

    empty_non_axis_sizes = (u0 == 0);
    if (empty_non_axis_sizes || ((bs->size[0] != 0) && (bs->size[1] != 0))) {
      input_sizes_idx_0 = bs->size[0];
    } else {
      input_sizes_idx_0 = 0;
    }

    if (empty_non_axis_sizes || ((A->size[0] - bs->size[0] != 0) && (bs->size[1]
          != 0))) {
      sizes_idx_0 = A->size[0] - bs->size[0];
    } else {
      sizes_idx_0 = 0;
    }

    i = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = input_sizes_idx_0 + sizes_idx_0;
    b_bs->size[1] = u0;
    emxEnsureCapacity_real_T(b_bs, i);
    for (i = 0; i < u0; i++) {
      for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
        b_bs->data[i1 + b_bs->size[0] * i] = bs->data[i1 + input_sizes_idx_0 * i];
      }
    }

    for (i = 0; i < u0; i++) {
      for (i1 = 0; i1 < sizes_idx_0; i1++) {
        b_bs->data[(i1 + input_sizes_idx_0) + b_bs->size[0] * i] = 0.0;
      }
    }

    i = bs->size[0] * bs->size[1];
    bs->size[0] = b_bs->size[0];
    bs->size[1] = b_bs->size[1];
    emxEnsureCapacity_real_T(bs, i);
    u0 = b_bs->size[1];
    for (i = 0; i < u0; i++) {
      input_sizes_idx_0 = b_bs->size[0];
      for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
        bs->data[i1 + bs->size[0] * i] = b_bs->data[i1 + b_bs->size[0] * i];
      }
    }
  }

  for (u0 = 0; u0 < ncols; u0++) {
    v1 = 1.0;
    i = u0 + 2;
    for (input_sizes_idx_0 = i; input_sizes_idx_0 <= nrows; input_sizes_idx_0++)
    {
      t2 = A->data[(input_sizes_idx_0 + A->size[0] * u0) - 1];
      v1 -= t2 * t2;
    }

    if (v1 < 0.0) {
      v1 = 0.0;
    } else {
      v1 = sqrt(v1);
    }

    i = bs->size[1];
    for (sizes_idx_0 = 0; sizes_idx_0 < i; sizes_idx_0++) {
      t2 = v1 * bs->data[u0 + bs->size[0] * sizes_idx_0];
      i1 = u0 + 2;
      for (input_sizes_idx_0 = i1; input_sizes_idx_0 <= nrows; input_sizes_idx_0
           ++) {
        t2 += A->data[(input_sizes_idx_0 + A->size[0] * u0) - 1] * bs->data
          [(input_sizes_idx_0 + bs->size[0] * sizes_idx_0) - 1];
      }

      t2 += t2;
      bs->data[u0 + bs->size[0] * sizes_idx_0] -= t2 * v1;
      i1 = u0 + 2;
      for (input_sizes_idx_0 = i1; input_sizes_idx_0 <= nrows; input_sizes_idx_0
           ++) {
        bs->data[(input_sizes_idx_0 + bs->size[0] * sizes_idx_0) - 1] -= t2 *
          A->data[(input_sizes_idx_0 + A->size[0] * u0) - 1];
      }
    }
  }

  if (bs->size[0] > A->size[0]) {
    if (1 > A->size[0]) {
      u0 = 0;
    } else {
      u0 = A->size[0];
    }

    input_sizes_idx_0 = bs->size[1] - 1;
    i = b_bs->size[0] * b_bs->size[1];
    b_bs->size[0] = u0;
    b_bs->size[1] = input_sizes_idx_0 + 1;
    emxEnsureCapacity_real_T(b_bs, i);
    for (i = 0; i <= input_sizes_idx_0; i++) {
      for (i1 = 0; i1 < u0; i1++) {
        b_bs->data[i1 + b_bs->size[0] * i] = bs->data[i1 + bs->size[0] * i];
      }
    }

    i = bs->size[0] * bs->size[1];
    bs->size[0] = b_bs->size[0];
    bs->size[1] = b_bs->size[1];
    emxEnsureCapacity_real_T(bs, i);
    u0 = b_bs->size[1];
    for (i = 0; i < u0; i++) {
      input_sizes_idx_0 = b_bs->size[0];
      for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
        bs->data[i1 + bs->size[0] * i] = b_bs->data[i1 + b_bs->size[0] * i];
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
