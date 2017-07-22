#include "qr_rescale.h"
#include "m2c.h"

static double vec_norm2(const emxArray_real_T *v);
static double vec_norm2(const emxArray_real_T *v)
{
  double s;
  double w;
  int ii;
  double t;
  w = 0.0;
  for (ii = 1; ii <= v->size[0]; ii++) {
    w = fmax(w, fabs(v->data[ii - 1]));
  }

  s = 0.0;
  if (w == 0.0) {
    for (ii = 1; ii <= v->size[0]; ii++) {
      s += v->data[ii - 1];
    }
  } else {
    for (ii = 1; ii <= v->size[0]; ii++) {
      t = v->data[ii - 1] / w;
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
  int nv;
  int ii;
  emxArray_real_T *v;
  int j;
  int nrows;
  int k;
  double t2;
  double t;
  emxInit_real_T(&ts, 1);
  nv = V->size[0];
  V->size[0] = ncols;
  emxEnsureCapacity_real_T(V, nv);
  nv = ts->size[0];
  ts->size[0] = ncols;
  emxEnsureCapacity_real_T(ts, nv);
  ii = 0;
  emxInit_real_T(&v, 1);
  while (ii + 1 <= ncols) {
    j = A->size[0];
    nv = v->size[0];
    v->size[0] = j;
    emxEnsureCapacity_real_T(v, nv);
    for (nv = 0; nv < j; nv++) {
      v->data[nv] = A->data[nv + A->size[0] * ii];
    }

    ts->data[ii] = vec_norm2(v);
    if (fabs(ts->data[ii]) == 0.0) {
      ts->data[ii] = 0.0;
    } else {
      nv = A->size[0];
      for (j = 0; j + 1 <= nv; j++) {
        A->data[j + A->size[0] * ii] /= ts->data[ii];
      }
    }

    ii++;
  }

  *rnk = ncols;
  nrows = A->size[0];
  nv = v->size[0];
  v->size[0] = A->size[0];
  emxEnsureCapacity_real_T(v, nv);
  for (k = 0; k + 1 <= ncols; k++) {
    nv = nrows - k;
    for (j = 0; j + 1 <= nv; j++) {
      v->data[j] = A->data[(j + k) + A->size[0] * k];
    }

    t2 = 0.0;
    for (j = 0; j + 1 <= nv; j++) {
      t2 += v->data[j] * v->data[j];
    }

    t = sqrt(t2);
    if (v->data[0] >= 0.0) {
      t2 = sqrt(2.0 * (t2 + v->data[0] * t));
      v->data[0] += t;
    } else {
      t2 = sqrt(2.0 * (t2 - v->data[0] * t));
      v->data[0] -= t;
      for (j = 0; j + 1 <= nv; j++) {
        v->data[j] = -v->data[j];
      }
    }

    if (t2 > 0.0) {
      for (j = 0; j + 1 <= nv; j++) {
        v->data[j] /= t2;
      }
    }

    for (j = k; j + 1 <= ncols; j++) {
      t2 = 0.0;
      for (ii = 0; ii + 1 <= nv; ii++) {
        t2 += v->data[ii] * A->data[(ii + k) + A->size[0] * j];
      }

      t2 += t2;
      for (ii = 0; ii + 1 <= nv; ii++) {
        A->data[(ii + k) + A->size[0] * j] -= t2 * v->data[ii];
      }
    }

    if ((fabs(A->data[k + A->size[0] * k]) < tol) && (*rnk == ncols)) {
      *rnk = k;
    }

    for (j = 1; j + 1 <= nv; j++) {
      A->data[(j + k) + A->size[0] * k] = v->data[j];
    }

    V->data[k] = v->data[0];
  }

  emxFree_real_T(&v);
  for (k = 0; k + 1 <= ncols; k++) {
    for (j = 0; j + 1 <= k + 1; j++) {
      A->data[j + A->size[0] * k] *= ts->data[k];
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
