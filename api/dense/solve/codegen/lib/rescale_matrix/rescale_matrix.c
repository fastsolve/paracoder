#include "rescale_matrix.h"
#include "m2c.h"
#include "rescale_matrix_types.h"
#include <math.h>

static double vec_norm2(const emxArray_real_T *v);

static double vec_norm2(const emxArray_real_T *v)
{
  double s;
  double t;
  double w;
  int i;
  int ii;
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

void rescale_matrix(emxArray_real_T *V, int ncols, emxArray_real_T *ts)
{
  emxArray_real_T *b_V;
  int i;
  int ii;
  int loop_ub;
  emxInit_real_T(&b_V, 1);
  for (ii = 0; ii < ncols; ii++) {
    loop_ub = V->size[0];
    i = b_V->size[0];
    b_V->size[0] = loop_ub;
    emxEnsureCapacity_real_T(b_V, i);
    for (i = 0; i < loop_ub; i++) {
      b_V->data[i] = V->data[i + V->size[0] * ii];
    }
    ts->data[ii] = vec_norm2(b_V);
    if (fabs(ts->data[ii]) == 0.0) {
      ts->data[ii] = 1.0;
    } else {
      i = V->size[0];
      for (loop_ub = 0; loop_ub < i; loop_ub++) {
        V->data[loop_ub + V->size[0] * ii] /= ts->data[ii];
      }
    }
  }
  emxFree_real_T(&b_V);
}

void rescale_matrix_initialize(void)
{
}

void rescale_matrix_terminate(void)
{
}
