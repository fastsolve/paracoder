#include "rescale_matrix.h"
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

void rescale_matrix(emxArray_real_T *V, int ncols, emxArray_real_T *ts)
{
  int ii;
  emxArray_real_T *b_V;
  int loop_ub;
  int i0;
  ii = 0;
  emxInit_real_T(&b_V, 1);
  while (ii + 1 <= ncols) {
    loop_ub = V->size[0];
    i0 = b_V->size[0];
    b_V->size[0] = loop_ub;
    emxEnsureCapacity_real_T(b_V, i0);
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_V->data[i0] = V->data[i0 + V->size[0] * ii];
    }

    ts->data[ii] = vec_norm2(b_V);
    if (fabs(ts->data[ii]) == 0.0) {
      ts->data[ii] = 1.0;
    } else {
      i0 = V->size[0];
      for (loop_ub = 0; loop_ub + 1 <= i0; loop_ub++) {
        V->data[loop_ub + V->size[0] * ii] /= ts->data[ii];
      }
    }

    ii++;
  }

  emxFree_real_T(&b_V);
}

void rescale_matrix_initialize(void)
{
}

void rescale_matrix_terminate(void)
{
}
