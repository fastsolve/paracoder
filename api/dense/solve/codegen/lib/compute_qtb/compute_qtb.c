#include "compute_qtb.h"

void compute_qtb(const emxArray_real_T *Q, emxArray_real_T *bs, int ncols)
{
  int nrow;
  int k;
  int i0;
  int jj;
  double t2;
  int ii;
  nrow = Q->size[0];
  for (k = 0; k + 1 <= ncols; k++) {
    i0 = bs->size[1];
    for (jj = 0; jj + 1 <= i0; jj++) {
      t2 = 0.0;
      for (ii = k; ii + 1 <= nrow; ii++) {
        t2 += Q->data[ii + Q->size[0] * k] * bs->data[ii + bs->size[0] * jj];
      }

      t2 += t2;
      for (ii = k; ii + 1 <= nrow; ii++) {
        bs->data[ii + bs->size[0] * jj] -= t2 * Q->data[ii + Q->size[0] * k];
      }
    }
  }
}

void compute_qtb_initialize(void)
{
}

void compute_qtb_terminate(void)
{
}
