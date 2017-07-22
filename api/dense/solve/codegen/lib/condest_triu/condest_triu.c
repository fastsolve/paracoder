#include "condest_triu.h"
#include "m2c.h"

void condest_triu(const emxArray_real_T *R, int m, int maxiter, double *kappa,
                  struct0_T *buf)
{
  int u0;
  int cstart;
  double nrm1;
  int j;
  emxArray_real_T *bs;
  int exitg1;
  double t;
  int k;
  int exitg2;
  int ii;
  boolean_T exitg3;
  double a;
  if (m == 0) {
    u0 = R->size[0];
    m = R->size[1];
    if (u0 < m) {
      m = u0;
    }
  }

  cstart = buf->x->size[0];
  buf->x->size[0] = m;
  emxEnsureCapacity_real_T(buf->x, cstart);
  for (cstart = 0; cstart < m; cstart++) {
    buf->x->data[cstart] = 0.0;
  }

  cstart = buf->z->size[0];
  buf->z->size[0] = m;
  emxEnsureCapacity_real_T(buf->z, cstart);
  for (cstart = 0; cstart < m; cstart++) {
    buf->z->data[cstart] = 0.0;
  }

  nrm1 = 0.0;
  j = 0;
  emxInit_real_T(&bs, 1);
  do {
    exitg1 = 0;
    if (j + 1 <= m) {
      if (R->data[j + R->size[0] * j] == 0.0) {
        *kappa = 1.0 / R->data[j + R->size[0] * j];
        exitg1 = 1;
      } else {
        t = 0.0;
        for (u0 = 1; u0 <= j + 1; u0++) {
          t += fabs(R->data[(u0 + R->size[0] * j) - 1]);
        }

        if (t > nrm1) {
          nrm1 = t;
        }

        j++;
      }
    } else {
      buf->x->data[m - 1] = 1.0;
      j = m;
      k = 1;
      do {
        exitg2 = 0;
        for (u0 = m - 1; u0 + 1 > 0; u0--) {
          for (ii = u0 + 1; ii + 1 <= m; ii++) {
            buf->x->data[u0] -= R->data[u0 + R->size[0] * ii] * buf->x->data[ii];
          }

          buf->x->data[u0] /= R->data[u0 + R->size[0] * u0];
        }

        if (k >= maxiter) {
          exitg2 = 1;
        } else {
          k++;
          for (u0 = 0; u0 + 1 <= m; u0++) {
            buf->z->data[u0] = 2.0 * (double)(buf->x->data[u0] >= 0.0) - 1.0;
          }

          cstart = bs->size[0];
          bs->size[0] = buf->z->size[0];
          emxEnsureCapacity_real_T(bs, cstart);
          u0 = buf->z->size[0];
          for (cstart = 0; cstart < u0; cstart++) {
            bs->data[cstart] = buf->z->data[cstart];
          }

          cstart = m;
          ii = 1;
          exitg3 = false;
          while ((!exitg3) && (ii <= m)) {
            if (bs->data[ii - 1] != 0.0) {
              cstart = ii - 1;
              exitg3 = true;
            } else {
              ii++;
            }
          }

          for (u0 = cstart; u0 + 1 <= m; u0++) {
            for (ii = cstart; ii + 1 <= u0; ii++) {
              buf->z->data[u0] -= R->data[ii + R->size[0] * u0] * buf->z->
                data[ii];
            }

            buf->z->data[u0] /= R->data[u0 + R->size[0] * u0];
          }

          t = fabs(buf->z->data[j - 1]);
          j = 0;
          for (u0 = 1; u0 <= m; u0++) {
            a = fabs(buf->z->data[u0 - 1]);
            if (a > t) {
              t = a;
              j = u0;
            }
          }

          if (j == 0) {
            exitg2 = 1;
          } else {
            u0 = buf->x->size[0];
            cstart = buf->x->size[0];
            buf->x->size[0] = u0;
            emxEnsureCapacity_real_T(buf->x, cstart);
            for (cstart = 0; cstart < u0; cstart++) {
              buf->x->data[cstart] = 0.0;
            }

            buf->x->data[j - 1] = 1.0;
          }
        }
      } while (exitg2 == 0);

      t = 0.0;
      for (u0 = 1; u0 <= m; u0++) {
        t += fabs(buf->x->data[u0 - 1]);
      }

      *kappa = t * nrm1;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&bs);
}

void condest_triu_initialize(void)
{
}

void condest_triu_terminate(void)
{
}
