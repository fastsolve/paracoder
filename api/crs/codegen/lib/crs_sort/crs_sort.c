#include "crs_sort.h"
#include "m2c.h"
#include "crs_sort_types.h"

void crs_sort(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind,
              emxArray_real_T *val)
{
  emxArray_int32_T *buf_indx;
  emxArray_real_T *buf_val;
  double t0;
  int b_i;
  int c_i;
  int exitg1;
  int exitg2;
  int i;
  int ir;
  int j;
  int l;
  int r0;
  boolean_T ascend;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  i = row_ptr->size[0];
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  for (b_i = 0; b_i <= i - 2; b_i++) {
    ascend = true;
    j = row_ptr->data[b_i];
    do {
      exitg1 = 0;
      r0 = row_ptr->data[b_i + 1];
      if (j + 1 <= r0 - 1) {
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
      l = r0 - row_ptr->data[b_i];
      r0 = buf_indx->size[0];
      buf_indx->size[0] = l;
      emxEnsureCapacity_int32_T(buf_indx, r0);
      for (r0 = 0; r0 < l; r0++) {
        buf_indx->data[r0] = 0;
      }
      r0 = buf_val->size[0];
      buf_val->size[0] = l;
      emxEnsureCapacity_real_T(buf_val, r0);
      for (r0 = 0; r0 < l; r0++) {
        buf_val->data[r0] = 0.0;
      }
      r0 = row_ptr->data[b_i];
      ir = row_ptr->data[b_i + 1] - 1;
      for (j = r0; j <= ir; j++) {
        l = (int)((unsigned int)j - r0);
        buf_indx->data[l] = col_ind->data[j - 1];
        buf_val->data[l] = val->data[j - 1];
      }
      if (buf_indx->size[0] > 1) {
        l = (int)((unsigned int)buf_indx->size[0] >> 1);
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
      r0 = row_ptr->data[b_i];
      ir = row_ptr->data[b_i + 1] - 1;
      for (j = r0; j <= ir; j++) {
        l = (int)((unsigned int)j - r0);
        col_ind->data[j - 1] = buf_indx->data[l];
        val->data[j - 1] = buf_val->data[l];
      }
    }
  }
  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
}

void crs_sort0(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind)
{
  emxArray_int32_T *buf_indx;
  int b_i;
  int c_i;
  int exitg1;
  int exitg2;
  int i;
  int i1;
  int ir;
  int j;
  int l;
  int r0;
  boolean_T ascend;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  i = row_ptr->size[0];
  emxInit_int32_T(&buf_indx, 1);
  for (b_i = 0; b_i <= i - 2; b_i++) {
    ascend = true;
    j = row_ptr->data[b_i];
    do {
      exitg1 = 0;
      i1 = row_ptr->data[b_i + 1];
      if (j + 1 <= i1 - 1) {
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
      i1 = row_ptr->data[b_i + 1] - 1;
      for (j = ir; j <= i1; j++) {
        buf_indx->data[(int)((unsigned int)j - ir)] = col_ind->data[j - 1];
      }
      if (buf_indx->size[0] > 1) {
        l = (int)((unsigned int)buf_indx->size[0] >> 1) + 1;
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
      i1 = row_ptr->data[b_i];
      ir = row_ptr->data[b_i + 1] - 1;
      for (j = i1; j <= ir; j++) {
        col_ind->data[j - 1] = buf_indx->data[(int)((unsigned int)j - i1)];
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
