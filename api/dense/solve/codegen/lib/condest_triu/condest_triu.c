#include "condest_triu.h"
#include "m2c.h"
#include <math.h>

static void forwardsolve_trans(const emxArray_real_T *R, emxArray_real_T *bs,
  int cend);
static void forwardsolve_trans(const emxArray_real_T *R, emxArray_real_T *bs,
  int cend)
{
  int cstart;
  int ii;
  boolean_T exitg1;
  int jj;
  int i;
  cstart = cend + 1;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= cend - 1)) {
    if (bs->data[ii] != 0.0) {
      cstart = ii + 1;
      exitg1 = true;
    } else {
      ii++;
    }
  }

  for (jj = cstart; jj <= cend; jj++) {
    i = jj - 1;
    for (ii = cstart; ii <= i; ii++) {
      bs->data[jj - 1] -= R->data[(ii + R->size[0] * (jj - 1)) - 1] * bs->
        data[ii - 1];
    }

    bs->data[jj - 1] /= R->data[(jj + R->size[0] * (jj - 1)) - 1];
  }
}

double condest_triu(const emxArray_real_T *R, int m, int maxiter, struct0_T *buf)
{
  double kappa;
  int u0;
  double nrm1;
  int j;
  int exitg1;
  double t;
  int k;
  int exitg2;
  int i;
  int ii;
  double a;
  if (m == 0) {
    u0 = R->size[0];
    m = R->size[1];
    if (u0 < m) {
      m = u0;
    }
  }

  nrm1 = 0.0;
  j = 0;
  do {
    exitg1 = 0;
    if (j <= m - 1) {
      if (R->data[j + R->size[0] * j] == 0.0) {
        kappa = 1.0 / R->data[j + R->size[0] * j];
        exitg1 = 1;
      } else {
        t = 0.0;
        for (u0 = 0; u0 <= j; u0++) {
          t += fabs(R->data[u0 + R->size[0] * j]);
        }

        if (t > nrm1) {
          nrm1 = t;
        }

        j++;
      }
    } else {
      buf->x->data[m - 1] = 1.0;
      j = m - 1;
      k = 1;
      do {
        exitg2 = 0;
        for (u0 = m; u0 >= 1; u0--) {
          i = u0 + 1;
          for (ii = i; ii <= m; ii++) {
            buf->x->data[u0 - 1] -= R->data[(u0 + R->size[0] * (ii - 1)) - 1] *
              buf->x->data[ii - 1];
          }

          buf->x->data[u0 - 1] /= R->data[(u0 + R->size[0] * (u0 - 1)) - 1];
        }

        if (k >= maxiter) {
          exitg2 = 1;
        } else {
          k++;
          for (u0 = 0; u0 < m; u0++) {
            buf->z->data[u0] = 2.0 * (double)(buf->x->data[u0] >= 0.0) - 1.0;
          }

          forwardsolve_trans(R, buf->z, m);
          t = fabs(buf->z->data[j]);
          j = -1;
          for (u0 = 0; u0 < m; u0++) {
            a = fabs(buf->z->data[u0]);
            if (a > t) {
              t = a;
              j = u0;
            }
          }

          if (j + 1 == 0) {
            exitg2 = 1;
          } else {
            u0 = buf->x->size[0];
            i = buf->x->size[0];
            buf->x->size[0] = u0;
            emxEnsureCapacity_real_T(buf->x, i);
            for (i = 0; i < u0; i++) {
              buf->x->data[i] = 0.0;
            }

            buf->x->data[j] = 1.0;
          }
        }
      } while (exitg2 == 0);

      t = 0.0;
      for (u0 = 0; u0 < m; u0++) {
        t += fabs(buf->x->data[u0]);
      }

      kappa = t * nrm1;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return kappa;
}

void condest_triu_3args(const emxArray_real_T *R, int m, int maxiter, double
  *kappa, struct0_T *buf)
{
  int u1;
  int u0;
  int i;
  double nrm1;
  int j;
  int exitg1;
  double t;
  int k;
  int exitg2;
  int ii;
  double a;
  u1 = m;
  if (m == 0) {
    u0 = R->size[0];
    u1 = R->size[1];
    if (u0 < u1) {
      u1 = u0;
    }
  }

  i = buf->x->size[0];
  buf->x->size[0] = u1;
  emxEnsureCapacity_real_T(buf->x, i);
  for (i = 0; i < u1; i++) {
    buf->x->data[i] = 0.0;
  }

  i = buf->z->size[0];
  buf->z->size[0] = u1;
  emxEnsureCapacity_real_T(buf->z, i);
  for (i = 0; i < u1; i++) {
    buf->z->data[i] = 0.0;
  }

  nrm1 = 0.0;
  j = 0;
  do {
    exitg1 = 0;
    if (j <= u1 - 1) {
      if (R->data[j + R->size[0] * j] == 0.0) {
        *kappa = 1.0 / R->data[j + R->size[0] * j];
        exitg1 = 1;
      } else {
        t = 0.0;
        for (u0 = 0; u0 <= j; u0++) {
          t += fabs(R->data[u0 + R->size[0] * j]);
        }

        if (t > nrm1) {
          nrm1 = t;
        }

        j++;
      }
    } else {
      buf->x->data[u1 - 1] = 1.0;
      j = u1 - 1;
      k = 1;
      do {
        exitg2 = 0;
        for (u0 = u1; u0 >= 1; u0--) {
          i = u0 + 1;
          for (ii = i; ii <= u1; ii++) {
            buf->x->data[u0 - 1] -= R->data[(u0 + R->size[0] * (ii - 1)) - 1] *
              buf->x->data[ii - 1];
          }

          buf->x->data[u0 - 1] /= R->data[(u0 + R->size[0] * (u0 - 1)) - 1];
        }

        if (k >= maxiter) {
          exitg2 = 1;
        } else {
          k++;
          for (u0 = 0; u0 < u1; u0++) {
            buf->z->data[u0] = 2.0 * (double)(buf->x->data[u0] >= 0.0) - 1.0;
          }

          forwardsolve_trans(R, buf->z, u1);
          t = fabs(buf->z->data[j]);
          j = -1;
          for (u0 = 0; u0 < u1; u0++) {
            a = fabs(buf->z->data[u0]);
            if (a > t) {
              t = a;
              j = u0;
            }
          }

          if (j + 1 == 0) {
            exitg2 = 1;
          } else {
            u0 = buf->x->size[0];
            for (i = 0; i < u0; i++) {
              buf->x->data[i] = 0.0;
            }

            buf->x->data[j] = 1.0;
          }
        }
      } while (exitg2 == 0);

      t = 0.0;
      for (u0 = 0; u0 < u1; u0++) {
        t += fabs(buf->x->data[u0]);
      }

      *kappa = t * nrm1;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

void condest_triu_initialize(void)
{
}

void condest_triu_terminate(void)
{
}
