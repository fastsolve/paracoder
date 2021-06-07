#include "backsolve.h"
#include "backsolve_types.h"

void backsolve(const emxArray_real_T *R, emxArray_real_T *bs, int cend,
               const emxArray_real_T *ws)
{
  int i;
  int i1;
  int ii;
  int jj;
  int kk;
  i = bs->size[1];
  for (kk = 0; kk < i; kk++) {
    for (jj = cend; jj >= 1; jj--) {
      i1 = jj + 1;
      for (ii = i1; ii <= cend; ii++) {
        bs->data[(jj + bs->size[0] * kk) - 1] -=
            R->data[(jj + R->size[0] * (ii - 1)) - 1] *
            bs->data[(ii + bs->size[0] * kk) - 1];
      }
      bs->data[(jj + bs->size[0] * kk) - 1] /=
          R->data[(jj + R->size[0] * (jj - 1)) - 1];
    }
  }
  i = bs->size[1];
  for (kk = 0; kk < i; kk++) {
    for (jj = 0; jj < cend; jj++) {
      bs->data[jj + bs->size[0] * kk] /= ws->data[jj];
    }
  }
}

void backsolve_2args(const emxArray_real_T *R, emxArray_real_T *bs)
{
  int cend;
  int i;
  int i1;
  int ii;
  int jj;
  int kk;
  cend = R->size[1];
  i = bs->size[1];
  for (kk = 0; kk < i; kk++) {
    for (jj = cend; jj >= 1; jj--) {
      i1 = jj + 1;
      for (ii = i1; ii <= cend; ii++) {
        bs->data[(jj + bs->size[0] * kk) - 1] -=
            R->data[(jj + R->size[0] * (ii - 1)) - 1] *
            bs->data[(ii + bs->size[0] * kk) - 1];
      }
      bs->data[(jj + bs->size[0] * kk) - 1] /=
          R->data[(jj + R->size[0] * (jj - 1)) - 1];
    }
  }
}

void backsolve_3args(const emxArray_real_T *R, emxArray_real_T *bs, int cend)
{
  int i;
  int i1;
  int ii;
  int jj;
  int kk;
  i = bs->size[1];
  for (kk = 0; kk < i; kk++) {
    for (jj = cend; jj >= 1; jj--) {
      i1 = jj + 1;
      for (ii = i1; ii <= cend; ii++) {
        bs->data[(jj + bs->size[0] * kk) - 1] -=
            R->data[(jj + R->size[0] * (ii - 1)) - 1] *
            bs->data[(ii + bs->size[0] * kk) - 1];
      }
      bs->data[(jj + bs->size[0] * kk) - 1] /=
          R->data[(jj + R->size[0] * (jj - 1)) - 1];
    }
  }
}

void backsolve_initialize(void)
{
}

void backsolve_terminate(void)
{
}
