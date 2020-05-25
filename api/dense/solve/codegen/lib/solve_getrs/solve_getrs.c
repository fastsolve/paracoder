#include "solve_getrs.h"

void solve_getrs(const emxArray_real_T *A, emxArray_real_T *b)
{
  int n;
  int k;
  int j;
  int i;
  int b_i;
  n = b->size[0];
  k = 0;
  for (j = 0; j < n; j++) {
    k = (k + j) + 1;
    i = j + 2;
    for (b_i = i; b_i <= n; b_i++) {
      b->data[b_i - 1] -= A->data[k] * b->data[j];
      k++;
    }
  }

  k = n * n - 1;
  for (j = n; j >= 1; j--) {
    b->data[j - 1] /= A->data[k];
    i = j - 1;
    for (b_i = i; b_i >= 1; b_i--) {
      k--;
      b->data[b_i - 1] -= A->data[k] * b->data[j - 1];
    }

    k = ((k - n) + j) - 2;
  }
}

void solve_getrs_3args(const emxArray_real_T *A, emxArray_real_T *b, int n)
{
  int k;
  int j;
  int i;
  int b_i;
  k = 0;
  for (j = 0; j < n; j++) {
    k = (k + j) + 1;
    i = j + 2;
    for (b_i = i; b_i <= n; b_i++) {
      b->data[b_i - 1] -= A->data[k] * b->data[j];
      k++;
    }
  }

  k = n * n - 1;
  for (j = n; j >= 1; j--) {
    b->data[j - 1] /= A->data[k];
    i = j - 1;
    for (b_i = i; b_i >= 1; b_i--) {
      k--;
      b->data[b_i - 1] -= A->data[k] * b->data[j - 1];
    }

    k = ((k - n) + j) - 2;
  }
}

void solve_getrs_4args(const emxArray_real_T *A, emxArray_real_T *b, int n, int
  offset)
{
  int k;
  int j;
  int i;
  int b_i;
  int i1;
  int i2;
  k = 0;
  for (j = 0; j < n; j++) {
    k = (k + j) + 1;
    i = j + 2;
    for (b_i = i; b_i <= n; b_i++) {
      i1 = (b_i + offset) - 1;
      b->data[i1] -= A->data[k] * b->data[j + offset];
      k++;
    }
  }

  k = n * n - 1;
  for (j = n; j >= 1; j--) {
    i = (j + offset) - 1;
    b->data[i] /= A->data[k];
    i1 = j - 1;
    for (b_i = i1; b_i >= 1; b_i--) {
      k--;
      i2 = (b_i + offset) - 1;
      b->data[i2] -= A->data[k] * b->data[i];
    }

    k = ((k - n) + j) - 2;
  }
}

void solve_getrs_initialize(void)
{
}

void solve_getrs_terminate(void)
{
}
