#include "solve_getrs.h"
#include "solve_getrs_types.h"

void solve_getrs(const emxArray_real_T *A, emxArray_real_T *b)
{
  int b_i;
  int i;
  int j;
  int k;
  int n;
  n = b->size[0];
  k = 0;
  for (j = 0; j < n; j++) {
    k = (k + j) + 1;
    i = j + 2;
    for (b_i = i; b_i <= n; b_i++) {
      b->data[b_i - 1] -= A->data[((k + b_i) - j) - 2] * b->data[j];
    }
    k = ((k + n) - j) - 1;
  }
  k = n * n - 1;
  for (j = n; j >= 1; j--) {
    b->data[j - 1] /= A->data[k];
    i = j - 1;
    for (b_i = i; b_i >= 1; b_i--) {
      b->data[b_i - 1] -= A->data[(k + b_i) - j] * b->data[j - 1];
    }
    k = (k - j) + 1;
    k = ((k - n) + j) - 2;
  }
}

void solve_getrs_3args(const emxArray_real_T *A, emxArray_real_T *b, int n)
{
  int b_i;
  int i;
  int j;
  int k;
  k = 0;
  for (j = 0; j < n; j++) {
    k = (k + j) + 1;
    i = j + 2;
    for (b_i = i; b_i <= n; b_i++) {
      b->data[b_i - 1] -= A->data[((k + b_i) - j) - 2] * b->data[j];
    }
    k = ((k + n) - j) - 1;
  }
  k = n * n - 1;
  for (j = n; j >= 1; j--) {
    b->data[j - 1] /= A->data[k];
    i = j - 1;
    for (b_i = i; b_i >= 1; b_i--) {
      b->data[b_i - 1] -= A->data[(k + b_i) - j] * b->data[j - 1];
    }
    k = (k - j) + 1;
    k = ((k - n) + j) - 2;
  }
}

void solve_getrs_4args(const emxArray_real_T *A, emxArray_real_T *b, int n,
                       int offset)
{
  int b_i;
  int i;
  int i1;
  int i2;
  int j;
  int k;
  k = 0;
  for (j = 0; j < n; j++) {
    k = (k + j) + 1;
    i = j + 2;
    for (b_i = i; b_i <= n; b_i++) {
      i1 = (b_i + offset) - 1;
      b->data[i1] -= A->data[((k + b_i) - j) - 2] * b->data[j + offset];
    }
    k = ((k + n) - j) - 1;
  }
  k = n * n - 1;
  for (j = n; j >= 1; j--) {
    i = (j + offset) - 1;
    b->data[i] /= A->data[k];
    i1 = j - 1;
    for (b_i = i1; b_i >= 1; b_i--) {
      i2 = (b_i + offset) - 1;
      b->data[i2] -= A->data[(k + b_i) - j] * b->data[i];
    }
    k = (k - j) + 1;
    k = ((k - n) + j) - 2;
  }
}

void solve_getrs_initialize(void)
{
}

void solve_getrs_terminate(void)
{
}
