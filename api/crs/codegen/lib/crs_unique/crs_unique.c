#include "crs_unique.h"
#include "m2c.h"
#include "crs_unique_types.h"

void crs_unique(emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind,
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
  int i1;
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
      c_i = row_ptr->data[b_i + 1];
      if (j + 1 <= c_i - 1) {
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
      ir = c_i - row_ptr->data[b_i];
      c_i = buf_indx->size[0];
      buf_indx->size[0] = ir;
      emxEnsureCapacity_int32_T(buf_indx, c_i);
      for (c_i = 0; c_i < ir; c_i++) {
        buf_indx->data[c_i] = 0;
      }
      c_i = buf_val->size[0];
      buf_val->size[0] = ir;
      emxEnsureCapacity_real_T(buf_val, c_i);
      for (c_i = 0; c_i < ir; c_i++) {
        buf_val->data[c_i] = 0.0;
      }
      c_i = row_ptr->data[b_i];
      i1 = row_ptr->data[b_i + 1] - 1;
      for (j = c_i; j <= i1; j++) {
        l = (int)((unsigned int)j - c_i);
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
      c_i = row_ptr->data[b_i];
      for (j = c_i; j <= i1; j++) {
        l = (int)((unsigned int)j - c_i);
        col_ind->data[j - 1] = buf_indx->data[l];
        val->data[j - 1] = buf_val->data[l];
      }
    }
  }
  ir = 0;
  r0 = 0;
  i = row_ptr->size[0];
  for (b_i = 0; b_i <= i - 2; b_i++) {
    if (ir != 0) {
      c_i = r0 - ir;
      col_ind->data[c_i] = col_ind->data[r0];
      val->data[c_i] = val->data[r0];
    }
    c_i = r0 + 2;
    r0 = row_ptr->data[b_i + 1] - 1;
    for (j = c_i; j <= r0; j++) {
      i1 = j - ir;
      l = col_ind->data[j - 1];
      if (l == col_ind->data[i1 - 2]) {
        val->data[i1 - 2] += val->data[j - 1];
        ir++;
      } else if (ir != 0) {
        col_ind->data[i1 - 1] = l;
        val->data[i1 - 1] = val->data[j - 1];
      }
    }
    row_ptr->data[b_i + 1] -= ir;
  }
  if (ir != 0) {
    l = col_ind->size[0] - ir;
    i = buf_indx->size[0];
    buf_indx->size[0] = col_ind->size[0];
    emxEnsureCapacity_int32_T(buf_indx, i);
    ir = col_ind->size[0];
    for (i = 0; i < ir; i++) {
      buf_indx->data[i] = col_ind->data[i];
    }
    if (l < 1) {
      col_ind->size[0] = 0;
    } else {
      i = col_ind->size[0];
      col_ind->size[0] = l;
      emxEnsureCapacity_int32_T(col_ind, i);
      i = l - 1;
      for (b_i = 0; b_i <= i; b_i++) {
        col_ind->data[b_i] = buf_indx->data[b_i];
      }
    }
    i = buf_val->size[0];
    buf_val->size[0] = val->size[0];
    emxEnsureCapacity_real_T(buf_val, i);
    ir = val->size[0];
    for (i = 0; i < ir; i++) {
      buf_val->data[i] = val->data[i];
    }
    if (l < 1) {
      val->size[0] = 0;
    } else {
      i = val->size[0];
      val->size[0] = l;
      emxEnsureCapacity_real_T(val, i);
      i = l - 1;
      for (b_i = 0; b_i <= i; b_i++) {
        val->data[b_i] = buf_val->data[b_i];
      }
    }
  }
  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
}

void crs_unique_initialize(void)
{
}

void crs_unique_terminate(void)
{
}
