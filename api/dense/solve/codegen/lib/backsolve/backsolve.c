#include "backsolve.h"

void backsolve(const emxArray_real_T *R, emxArray_real_T *bs, int cend, const
               emxArray_real_T *ws)
{
  int i0;
  int kk;
  int jj;
  int ii;
  i0 = bs->size[1];
  for (kk = 0; kk + 1 <= i0; kk++) {
    for (jj = cend - 1; jj + 1 > 0; jj--) {
      for (ii = jj + 1; ii + 1 <= cend; ii++) {
        bs->data[jj + bs->size[0] * kk] -= R->data[jj + R->size[0] * ii] *
          bs->data[ii + bs->size[0] * kk];
      }

      bs->data[jj + bs->size[0] * kk] /= R->data[jj + R->size[0] * jj];
    }
  }

  i0 = bs->size[1];
  for (kk = 0; kk + 1 <= i0; kk++) {
    for (jj = 0; jj + 1 <= cend; jj++) {
      bs->data[jj + bs->size[0] * kk] /= ws->data[jj];
    }
  }
}

void backsolve_2args(const emxArray_real_T *R, emxArray_real_T *bs)
{
  int cend;
  int i1;
  int kk;
  int jj;
  int ii;
  cend = R->size[1];
  i1 = bs->size[1];
  for (kk = 0; kk + 1 <= i1; kk++) {
    for (jj = cend - 1; jj + 1 > 0; jj--) {
      for (ii = jj + 1; ii + 1 <= cend; ii++) {
        bs->data[jj + bs->size[0] * kk] -= R->data[jj + R->size[0] * ii] *
          bs->data[ii + bs->size[0] * kk];
      }

      bs->data[jj + bs->size[0] * kk] /= R->data[jj + R->size[0] * jj];
    }
  }
}

void backsolve_3args(const emxArray_real_T *R, emxArray_real_T *bs, int cend)
{
  int i2;
  int kk;
  int jj;
  int ii;
  i2 = bs->size[1];
  for (kk = 0; kk + 1 <= i2; kk++) {
    for (jj = cend - 1; jj + 1 > 0; jj--) {
      for (ii = jj + 1; ii + 1 <= cend; ii++) {
        bs->data[jj + bs->size[0] * kk] -= R->data[jj + R->size[0] * ii] *
          bs->data[ii + bs->size[0] * kk];
      }

      bs->data[jj + bs->size[0] * kk] /= R->data[jj + R->size[0] * jj];
    }
  }
}

void backsolve_initialize(void)
{
}

void backsolve_terminate(void)
{
}
