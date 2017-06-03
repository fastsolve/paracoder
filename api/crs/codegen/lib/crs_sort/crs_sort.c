#include "crs_sort.h"
#include "m2c.h"

void crs_sort(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind,
              emxArray_real_T *val)
{
  int i0;
  int i;
  emxArray_real_T *buf_val;
  emxArray_int32_T *buf_indx;
  boolean_T ascend;
  int l;
  int j;
  boolean_T exitg3;
  int n;
  unsigned int ind;
  int exitg1;
  boolean_T guard1 = false;
  int r0;
  double t0;
  int exitg2;
  int b_i;
  boolean_T guard2 = false;
  i0 = row_ptr->size[0] - 1;
  i = 1;
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  while (i <= i0) {
    ascend = true;
    l = row_ptr->data[i] - 1;
    j = row_ptr->data[i - 1];
    exitg3 = false;
    while ((!exitg3) && (j + 1 <= l)) {
      if (col_ind->data[j] < col_ind->data[j - 1]) {
        ascend = false;
        exitg3 = true;
      } else {
        j++;
      }
    }

    if (!ascend) {
      l = buf_indx->size[0];
      buf_indx->size[0] = row_ptr->data[i] - row_ptr->data[i - 1];
      emxEnsureCapacity((emxArray__common *)buf_indx, l, (int)sizeof(int));
      n = row_ptr->data[i] - row_ptr->data[i - 1];
      for (l = 0; l < n; l++) {
        buf_indx->data[l] = 0;
      }

      l = buf_val->size[0];
      buf_val->size[0] = row_ptr->data[i] - row_ptr->data[i - 1];
      emxEnsureCapacity((emxArray__common *)buf_val, l, (int)sizeof(double));
      n = row_ptr->data[i] - row_ptr->data[i - 1];
      for (l = 0; l < n; l++) {
        buf_val->data[l] = 0.0;
      }

      ind = 1U;
      l = row_ptr->data[i] - 1;
      for (j = row_ptr->data[i - 1]; j <= l; j++) {
        buf_indx->data[(int)ind - 1] = col_ind->data[j - 1];
        buf_val->data[(int)ind - 1] = val->data[j - 1];
        ind++;
      }

      n = buf_indx->size[0];
      if (!(n <= 1)) {
        l = (int)((unsigned int)n >> 1U);
        do {
          exitg1 = 0;
          guard1 = false;
          if (l + 1 <= 1) {
            r0 = buf_indx->data[n - 1];
            t0 = buf_val->data[n - 1];
            buf_indx->data[n - 1] = buf_indx->data[0];
            buf_val->data[n - 1] = buf_val->data[0];
            n--;
            if (n == 1) {
              exitg1 = 1;
            } else {
              guard1 = true;
            }
          } else {
            l--;
            r0 = buf_indx->data[l];
            t0 = buf_val->data[l];
            guard1 = true;
          }

          if (guard1) {
            j = l;
            do {
              exitg2 = 0;
              b_i = j;
              j = ((j + 1) << 1) - 1;
              ascend = false;
              guard2 = false;
              if (j + 1 >= n) {
                if (j + 1 == n) {
                  ascend = true;
                  guard2 = true;
                } else if (j + 1 > n) {
                  exitg2 = 1;
                } else {
                  guard2 = true;
                }
              } else {
                guard2 = true;
              }

              if (guard2) {
                if ((!ascend) && (buf_indx->data[j] < buf_indx->data[j + 1])) {
                  j++;
                }

                if (r0 >= buf_indx->data[j]) {
                  exitg2 = 1;
                } else {
                  buf_indx->data[b_i] = buf_indx->data[j];
                  buf_val->data[b_i] = buf_val->data[j];
                }
              }
            } while (exitg2 == 0);

            buf_indx->data[b_i] = r0;
            buf_val->data[b_i] = t0;
          }
        } while (exitg1 == 0);

        buf_indx->data[0] = r0;
        buf_val->data[0] = t0;
      }

      ind = 1U;
      l = row_ptr->data[i] - 1;
      for (j = row_ptr->data[i - 1]; j <= l; j++) {
        col_ind->data[j - 1] = buf_indx->data[(int)ind - 1];
        val->data[j - 1] = buf_val->data[(int)ind - 1];
        ind++;
      }
    }

    i++;
  }

  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
}

void crs_sort0(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind)
{
  int i1;
  int i;
  emxArray_int32_T *buf_indx;
  boolean_T ascend;
  int n;
  int j;
  boolean_T exitg3;
  unsigned int ind;
  int l;
  int exitg1;
  boolean_T guard1 = false;
  int r0;
  int exitg2;
  int b_i;
  boolean_T guard2 = false;
  i1 = row_ptr->size[0] - 1;
  i = 1;
  emxInit_int32_T(&buf_indx, 1);
  while (i <= i1) {
    ascend = true;
    n = row_ptr->data[i] - 1;
    j = row_ptr->data[i - 1];
    exitg3 = false;
    while ((!exitg3) && (j + 1 <= n)) {
      if (col_ind->data[j] < col_ind->data[j - 1]) {
        ascend = false;
        exitg3 = true;
      } else {
        j++;
      }
    }

    if (!ascend) {
      n = buf_indx->size[0];
      buf_indx->size[0] = row_ptr->data[i] - row_ptr->data[i - 1];
      emxEnsureCapacity((emxArray__common *)buf_indx, n, (int)sizeof(int));
      ind = 1U;
      n = row_ptr->data[i] - 1;
      for (j = row_ptr->data[i - 1]; j <= n; j++) {
        buf_indx->data[(int)ind - 1] = col_ind->data[j - 1];
        ind++;
      }

      n = buf_indx->size[0];
      if (!(n <= 1)) {
        l = (int)((unsigned int)n >> 1U) + 1;
        do {
          exitg1 = 0;
          guard1 = false;
          if (l <= 1) {
            r0 = buf_indx->data[n - 1];
            buf_indx->data[n - 1] = buf_indx->data[0];
            n--;
            if (n == 1) {
              exitg1 = 1;
            } else {
              guard1 = true;
            }
          } else {
            l--;
            r0 = buf_indx->data[l - 1];
            guard1 = true;
          }

          if (guard1) {
            j = l;
            do {
              exitg2 = 0;
              b_i = j - 1;
              j <<= 1;
              ascend = false;
              guard2 = false;
              if (j >= n) {
                if (j == n) {
                  ascend = true;
                  guard2 = true;
                } else if (j > n) {
                  exitg2 = 1;
                } else {
                  guard2 = true;
                }
              } else {
                guard2 = true;
              }

              if (guard2) {
                if ((!ascend) && (buf_indx->data[j - 1] < buf_indx->data[j])) {
                  j++;
                }

                if (r0 >= buf_indx->data[j - 1]) {
                  exitg2 = 1;
                } else {
                  buf_indx->data[b_i] = buf_indx->data[j - 1];
                }
              }
            } while (exitg2 == 0);

            buf_indx->data[b_i] = r0;
          }
        } while (exitg1 == 0);

        buf_indx->data[0] = r0;
      }

      ind = 1U;
      n = row_ptr->data[i] - 1;
      for (j = row_ptr->data[i - 1]; j <= n; j++) {
        col_ind->data[j - 1] = buf_indx->data[(int)ind - 1];
        ind++;
      }
    }

    i++;
  }

  emxFree_int32_T(&buf_indx);
}

void crs_sort_initialize(void)
{
}

void crs_sort_terminate(void)
{
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}
