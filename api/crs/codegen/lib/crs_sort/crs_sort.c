#include "crs_sort.h"
#include "m2c.h"

void crs_sort(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind,
              emxArray_real_T *val)
{
  int i;
  emxArray_real_T *buf_val;
  emxArray_int32_T *buf_indx;
  int b_i;
  boolean_T ascend;
  int j;
  int exitg1;
  int ir;
  int i1;
  int l;
  unsigned int ind;
  boolean_T guard1 = false;
  int r0;
  double t0;
  int exitg2;
  int c_i;
  boolean_T guard2 = false;
  i = row_ptr->size[0];
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  for (b_i = 0; b_i <= i - 2; b_i++) {
    ascend = true;
    j = row_ptr->data[b_i];
    do {
      exitg1 = 0;
      ir = row_ptr->data[b_i + 1];
      i1 = ir - 1;
      if (j + 1 <= i1) {
        if (col_ind->data[j] < col_ind->data[j - 1]) {
          ascend = false;
          exitg1 = 1;
        } else {
          j++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (!ascend) {
      l = ir - row_ptr->data[b_i];
      ir = buf_indx->size[0];
      buf_indx->size[0] = l;
      emxEnsureCapacity_int32_T(buf_indx, ir);
      for (ir = 0; ir < l; ir++) {
        buf_indx->data[ir] = 0;
      }

      ir = buf_val->size[0];
      buf_val->size[0] = l;
      emxEnsureCapacity_real_T(buf_val, ir);
      for (ir = 0; ir < l; ir++) {
        buf_val->data[ir] = 0.0;
      }

      ind = 1U;
      ir = row_ptr->data[b_i];
      for (j = ir; j <= i1; j++) {
        l = (int)ind - 1;
        buf_indx->data[l] = col_ind->data[j - 1];
        buf_val->data[l] = val->data[j - 1];
        ind++;
      }

      if (buf_indx->size[0] > 1) {
        l = (int)((unsigned int)buf_indx->size[0] >> 1U);
        ir = buf_indx->size[0];
        do {
          exitg1 = 0;
          guard1 = false;
          if (l + 1 <= 1) {
            r0 = buf_indx->data[ir - 1];
            t0 = buf_val->data[ir - 1];
            buf_indx->data[ir - 1] = buf_indx->data[0];
            buf_val->data[ir - 1] = buf_val->data[0];
            ir--;
            if (ir == 1) {
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
              c_i = j;
              j = ((j + 1) << 1) - 1;
              ascend = false;
              guard2 = false;
              if (j + 1 >= ir) {
                if (j + 1 == ir) {
                  ascend = true;
                  guard2 = true;
                } else if (j + 1 > ir) {
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
                  buf_indx->data[c_i] = buf_indx->data[j];
                  buf_val->data[c_i] = buf_val->data[j];
                }
              }
            } while (exitg2 == 0);

            buf_indx->data[c_i] = r0;
            buf_val->data[c_i] = t0;
          }
        } while (exitg1 == 0);

        buf_indx->data[0] = r0;
        buf_val->data[0] = t0;
      }

      ind = 1U;
      ir = row_ptr->data[b_i];
      for (j = ir; j <= i1; j++) {
        l = (int)ind - 1;
        col_ind->data[j - 1] = buf_indx->data[l];
        val->data[j - 1] = buf_val->data[l];
        ind++;
      }
    }
  }

  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
}

void crs_sort0(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind)
{
  int i;
  emxArray_int32_T *buf_indx;
  int b_i;
  boolean_T ascend;
  int j;
  int exitg1;
  int i1;
  int i2;
  int ir;
  int l;
  unsigned int ind;
  boolean_T guard1 = false;
  int r0;
  int exitg2;
  int c_i;
  boolean_T guard2 = false;
  i = row_ptr->size[0];
  emxInit_int32_T(&buf_indx, 1);
  for (b_i = 0; b_i <= i - 2; b_i++) {
    ascend = true;
    j = row_ptr->data[b_i];
    do {
      exitg1 = 0;
      i1 = row_ptr->data[b_i + 1];
      i2 = i1 - 1;
      if (j + 1 <= i2) {
        if (col_ind->data[j] < col_ind->data[j - 1]) {
          ascend = false;
          exitg1 = 1;
        } else {
          j++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (!ascend) {
      ir = row_ptr->data[b_i];
      l = buf_indx->size[0];
      buf_indx->size[0] = i1 - row_ptr->data[b_i];
      emxEnsureCapacity_int32_T(buf_indx, l);
      ind = 1U;
      for (j = ir; j <= i2; j++) {
        buf_indx->data[(int)ind - 1] = col_ind->data[j - 1];
        ind++;
      }

      if (buf_indx->size[0] > 1) {
        l = (int)((unsigned int)buf_indx->size[0] >> 1U) + 1;
        ir = buf_indx->size[0];
        do {
          exitg1 = 0;
          guard1 = false;
          if (l <= 1) {
            r0 = buf_indx->data[ir - 1];
            buf_indx->data[ir - 1] = buf_indx->data[0];
            ir--;
            if (ir == 1) {
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
              c_i = j - 1;
              j <<= 1;
              ascend = false;
              guard2 = false;
              if (j >= ir) {
                if (j == ir) {
                  ascend = true;
                  guard2 = true;
                } else if (j > ir) {
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

                i1 = buf_indx->data[j - 1];
                if (r0 >= i1) {
                  exitg2 = 1;
                } else {
                  buf_indx->data[c_i] = i1;
                }
              }
            } while (exitg2 == 0);

            buf_indx->data[c_i] = r0;
          }
        } while (exitg1 == 0);

        buf_indx->data[0] = r0;
      }

      ind = 1U;
      i1 = row_ptr->data[b_i];
      for (j = i1; j <= i2; j++) {
        col_ind->data[j - 1] = buf_indx->data[(int)ind - 1];
        ind++;
      }
    }
  }

  emxFree_int32_T(&buf_indx);
}

void crs_sort_initialize(void)
{
}

void crs_sort_terminate(void)
{
}
