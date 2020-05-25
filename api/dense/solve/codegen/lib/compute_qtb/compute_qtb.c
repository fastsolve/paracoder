#include "compute_qtb.h"

void compute_qtb(const emxArray_real_T *Q, emxArray_real_T *bs, int ncols)
{
  int nrow;
  int k;
  int i;
  int jj;
  double t2;
  int ii;
  nrow = Q->size[0];
  for (k = 0; k < ncols; k++) {
    i = bs->size[1];
    for (jj = 0; jj < i; jj++) {
      t2 = 0.0;
      for (ii = k + 1; ii <= nrow; ii++) {
        t2 += Q->data[(ii + Q->size[0] * k) - 1] * bs->data[(ii + bs->size[0] *
          jj) - 1];
      }

      t2 += t2;
      for (ii = k + 1; ii <= nrow; ii++) {
        bs->data[(ii + bs->size[0] * jj) - 1] -= t2 * Q->data[(ii + Q->size[0] *
          k) - 1];
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
