#include "qr_rescale.h"
#include "m2c.h"
#include <math.h>

static double vec_norm2(const emxArray_real_T *v);
static double vec_norm2(const emxArray_real_T *v)
{
  double s;
  double w;
  int i;
  int ii;
  double t;
  w = 0.0;
  i = v->size[0];
  for (ii = 0; ii < i; ii++) {
    w = fmax(w, fabs(v->data[ii]));
  }

  s = 0.0;
  if (w == 0.0) {
    i = v->size[0];
    for (ii = 0; ii < i; ii++) {
      s += v->data[ii];
    }
  } else {
    i = v->size[0];
    for (ii = 0; ii < i; ii++) {
      t = v->data[ii] / w;
      s += t * t;
    }

    s = w * sqrt(s);
  }

  return s;
}

void qr_rescale(emxArray_real_T *A, int ncols, double tol, int *rnk,
                emxArray_real_T *V)
{
  emxArray_real_T *ts;
  int i;
  emxArray_real_T *v;
  int ii;
  int nrows;
  int k;
  double t2;
  int nv;
  int jj;
  double t;
  emxInit_real_T(&ts, 1);
  i = V->size[0];
  V->size[0] = ncols;
  emxEnsureCapacity_real_T(V, i);
  i = ts->size[0];
  ts->size[0] = ncols;
  emxEnsureCapacity_real_T(ts, i);
  emxInit_real_T(&v, 1);
  for (ii = 0; ii < ncols; ii++) {
    nrows = A->size[0];
    i = v->size[0];
    v->size[0] = nrows;
    emxEnsureCapacity_real_T(v, i);
    for (i = 0; i < nrows; i++) {
      v->data[i] = A->data[i + A->size[0] * ii];
    }

    t2 = vec_norm2(v);
    ts->data[ii] = t2;
    if (fabs(t2) == 0.0) {
      ts->data[ii] = 0.0;
    } else {
      i = A->size[0];
      for (nrows = 0; nrows < i; nrows++) {
        A->data[nrows + A->size[0] * ii] /= ts->data[ii];
      }
    }
  }

  *rnk = ncols;
  nrows = A->size[0] - 1;
  i = v->size[0];
  v->size[0] = A->size[0];
  emxEnsureCapacity_real_T(v, i);
  for (k = 0; k < ncols; k++) {
    nv = nrows - k;
    t2 = 0.0;
    for (jj = 0; jj <= nv; jj++) {
      v->data[jj] = A->data[(jj + k) + A->size[0] * k];
      t2 += v->data[jj] * v->data[jj];
    }

    t = sqrt(t2);
    if (v->data[0] >= 0.0) {
      t2 = sqrt(2.0 * (t2 + v->data[0] * t));
      v->data[0] += t;
    } else {
      t2 = sqrt(2.0 * (t2 - v->data[0] * t));
      v->data[0] -= t;
      for (jj = 0; jj <= nv; jj++) {
        v->data[jj] = -v->data[jj];
      }
    }

    if (t2 > 0.0) {
      for (jj = 0; jj <= nv; jj++) {
        v->data[jj] /= t2;
      }
    }

    for (jj = k + 1; jj <= ncols; jj++) {
      t2 = 0.0;
      for (ii = 0; ii <= nv; ii++) {
        t2 += v->data[ii] * A->data[(ii + k) + A->size[0] * (jj - 1)];
      }

      t2 += t2;
      for (ii = 0; ii <= nv; ii++) {
        i = ii + k;
        A->data[i + A->size[0] * (jj - 1)] -= t2 * v->data[ii];
      }
    }

    if ((fabs(A->data[k + A->size[0] * k]) < tol) && (*rnk == ncols)) {
      *rnk = k;
    }

    for (jj = 2; jj <= nv + 1; jj++) {
      A->data[((jj + k) + A->size[0] * k) - 1] = v->data[jj - 1];
    }

    V->data[k] = v->data[0];
  }

  emxFree_real_T(&v);
  for (k = 0; k < ncols; k++) {
    for (nrows = 0; nrows <= k; nrows++) {
      A->data[nrows + A->size[0] * k] *= ts->data[k];
    }
  }

  emxFree_real_T(&ts);
}

void qr_rescale_initialize(void)
{
}

void qr_rescale_terminate(void)
{
}
