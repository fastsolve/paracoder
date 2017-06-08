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
  int j;
  boolean_T exitg1;
  int n;
  unsigned int ind;
  int l;
  int exitg2;
  boolean_T guard1 = false;
  int r0;
  double t0;
  int exitg3;
  int b_i;
  boolean_T guard2 = false;
  i0 = row_ptr->size[0] - 1;
  i = 1;
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  while (i <= i0) {
    ascend = true;
    j = row_ptr->data[i - 1];
    exitg1 = false;
    while ((!exitg1) && (j + 1 <= row_ptr->data[i] - 1)) {
      if (col_ind->data[j] < col_ind->data[j - 1]) {
        ascend = false;
        exitg1 = true;
      } else {
        j++;
      }
    }

    if (!ascend) {
      j = buf_indx->size[0];
      buf_indx->size[0] = row_ptr->data[i] - row_ptr->data[i - 1];
      emxEnsureCapacity((emxArray__common *)buf_indx, j, sizeof(int));
      n = row_ptr->data[i] - row_ptr->data[i - 1];
      for (j = 0; j < n; j++) {
        buf_indx->data[j] = 0;
      }

      j = buf_val->size[0];
      buf_val->size[0] = row_ptr->data[i] - row_ptr->data[i - 1];
      emxEnsureCapacity((emxArray__common *)buf_val, j, sizeof(double));
      n = row_ptr->data[i] - row_ptr->data[i - 1];
      for (j = 0; j < n; j++) {
        buf_val->data[j] = 0.0;
      }

      ind = 1U;
      for (j = row_ptr->data[i - 1]; j < row_ptr->data[i]; j++) {
        buf_indx->data[(int)ind - 1] = col_ind->data[j - 1];
        buf_val->data[(int)ind - 1] = val->data[j - 1];
        ind++;
      }

      n = buf_indx->size[0];
      if (!(n <= 1)) {
        l = (int)((unsigned int)n >> 1U);
        do {
          exitg2 = 0;
          guard1 = false;
          if (l + 1 <= 1) {
            r0 = buf_indx->data[n - 1];
            t0 = buf_val->data[n - 1];
            buf_indx->data[n - 1] = buf_indx->data[0];
            buf_val->data[n - 1] = buf_val->data[0];
            n--;
            if (n == 1) {
              exitg2 = 1;
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
              exitg3 = 0;
              b_i = j;
              j = ((j + 1) << 1) - 1;
              ascend = false;
              guard2 = false;
              if (j + 1 >= n) {
                if (j + 1 == n) {
                  ascend = true;
                  guard2 = true;
                } else if (j + 1 > n) {
                  exitg3 = 1;
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
                  exitg3 = 1;
                } else {
                  buf_indx->data[b_i] = buf_indx->data[j];
                  buf_val->data[b_i] = buf_val->data[j];
                }
              }
            } while (exitg3 == 0);

            buf_indx->data[b_i] = r0;
            buf_val->data[b_i] = t0;
          }
        } while (exitg2 == 0);

        buf_indx->data[0] = r0;
        buf_val->data[0] = t0;
      }

      ind = 1U;
      for (j = row_ptr->data[i - 1]; j < row_ptr->data[i]; j++) {
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
  int j;
  boolean_T exitg1;
  unsigned int ind;
  int n;
  int l;
  int exitg2;
  boolean_T guard1 = false;
  int r0;
  int exitg3;
  int b_i;
  boolean_T guard2 = false;
  i1 = row_ptr->size[0] - 1;
  i = 1;
  emxInit_int32_T(&buf_indx, 1);
  while (i <= i1) {
    ascend = true;
    j = row_ptr->data[i - 1];
    exitg1 = false;
    while ((!exitg1) && (j + 1 <= row_ptr->data[i] - 1)) {
      if (col_ind->data[j] < col_ind->data[j - 1]) {
        ascend = false;
        exitg1 = true;
      } else {
        j++;
      }
    }

    if (!ascend) {
      j = buf_indx->size[0];
      buf_indx->size[0] = row_ptr->data[i] - row_ptr->data[i - 1];
      emxEnsureCapacity((emxArray__common *)buf_indx, j, sizeof(int));
      ind = 1U;
      for (j = row_ptr->data[i - 1]; j < row_ptr->data[i]; j++) {
        buf_indx->data[(int)ind - 1] = col_ind->data[j - 1];
        ind++;
      }

      n = buf_indx->size[0];
      if (!(n <= 1)) {
        l = (int)((unsigned int)n >> 1U) + 1;
        do {
          exitg2 = 0;
          guard1 = false;
          if (l <= 1) {
            r0 = buf_indx->data[n - 1];
            buf_indx->data[n - 1] = buf_indx->data[0];
            n--;
            if (n == 1) {
              exitg2 = 1;
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
              exitg3 = 0;
              b_i = j - 1;
              j <<= 1;
              ascend = false;
              guard2 = false;
              if (j >= n) {
                if (j == n) {
                  ascend = true;
                  guard2 = true;
                } else if (j > n) {
                  exitg3 = 1;
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
                  exitg3 = 1;
                } else {
                  buf_indx->data[b_i] = buf_indx->data[j - 1];
                }
              }
            } while (exitg3 == 0);

            buf_indx->data[b_i] = r0;
          }
        } while (exitg2 == 0);

        buf_indx->data[0] = r0;
      }

      ind = 1U;
      for (j = row_ptr->data[i - 1]; j < row_ptr->data[i]; j++) {
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
