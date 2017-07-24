#include "solve_getrs.h"

void solve_getrs(const emxArray_real_T *A, emxArray_real_T *b)
{
  int n;
  int k;
  int j;
  int i;
  n = b->size[0];
  k = 0;
  for (j = 1; j <= n; j++) {
    k += j;
    for (i = j; i + 1 <= n; i++) {
      b->data[i] -= A->data[k] * b->data[j - 1];
      k++;
    }
  }

  k = n * n - 1;
  for (j = n - 1; j + 1 > 0; j--) {
    b->data[j] /= A->data[k];
    for (i = j; i > 0; i--) {
      k--;
      b->data[i - 1] -= A->data[k] * b->data[j];
    }

    k = ((k - n) + j) - 1;
  }
}

void solve_getrs_3args(const emxArray_real_T *A, emxArray_real_T *b, int n)
{
  int k;
  int j;
  int i;
  k = 0;
  for (j = 1; j <= n; j++) {
    k += j;
    for (i = j; i + 1 <= n; i++) {
      b->data[i] -= A->data[k] * b->data[j - 1];
      k++;
    }
  }

  k = n * n - 1;
  for (j = n - 1; j + 1 > 0; j--) {
    b->data[j] /= A->data[k];
    for (i = j; i > 0; i--) {
      k--;
      b->data[i - 1] -= A->data[k] * b->data[j];
    }

    k = ((k - n) + j) - 1;
  }
}

void solve_getrs_4args(const emxArray_real_T *A, emxArray_real_T *b, int n, int
  offset)
{
  int k;
  int j;
  int i;
  double b_A;
  k = 0;
  for (j = 1; j <= n; j++) {
    k += j;
    for (i = j; i + 1 <= n; i++) {
      b->data[i + offset] -= A->data[k] * b->data[(j + offset) - 1];
      k++;
    }
  }

  k = n * n - 1;
  for (j = n - 1; j + 1 > 0; j--) {
    b_A = b->data[j + offset];
    b->data[j + offset] = b_A / A->data[k];
    for (i = j; i > 0; i--) {
      k--;
      b->data[(i + offset) - 1] -= A->data[k] * b->data[j + offset];
    }

    k = ((k - n) + j) - 1;
  }
}

void solve_getrs_initialize(void)
{
}

void solve_getrs_terminate(void)
{
}
