#include "mpi_Group_compare.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i1);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("MPI:RuntimeError",
            "MPI_Group_compare failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i0);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Group.\n", &b_varargin_3->
            data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Group_compare(const struct0_T *group1, const struct0_T *group2, int
  *result, int *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_group1;
  static const char cv0[9] = { 'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p' };

  emxArray_uint8_T *data;
  int loop_ub;
  MPI_Group obj;
  MPI_Group b_obj;
  unsigned char msg0[1024];
  char * ptr;
  emxArray_uint8_T *b_msg0;
  emxArray_char_T *c_msg0;
  p = false;
  b_p = false;
  if (group1->type->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(group1->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 9)) {
      if (!(group1->type->data[resultlen] == cv0[resultlen])) {
        b_p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  emxInit_char_T(&b_group1, 2);
  if (!p) {
    resultlen = b_group1->size[0] * b_group1->size[1];
    b_group1->size[0] = 1;
    b_group1->size[1] = group1->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_group1, resultlen);
    loop_ub = group1->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_group1->data[b_group1->size[0] * resultlen] = group1->type->data
        [group1->type->size[0] * resultlen];
    }

    b_group1->data[b_group1->size[0] * group1->type->size[1]] = '\x00';
    m2c_error(b_group1);
  }

  emxInit_uint8_T(&data, 1);
  resultlen = data->size[0];
  data->size[0] = group1->data->size[0];
  emxEnsureCapacity_uint8_T(data, resultlen);
  loop_ub = group1->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data->data[resultlen] = group1->data->data[resultlen];
  }

  obj = *(MPI_Group*)(&data->data[0]);
  p = false;
  b_p = false;
  if (group2->type->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(group2->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 9)) {
      if (!(group2->type->data[resultlen] == cv0[resultlen])) {
        b_p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    resultlen = b_group1->size[0] * b_group1->size[1];
    b_group1->size[0] = 1;
    b_group1->size[1] = group2->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_group1, resultlen);
    loop_ub = group2->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_group1->data[b_group1->size[0] * resultlen] = group2->type->data
        [group2->type->size[0] * resultlen];
    }

    b_group1->data[b_group1->size[0] * group2->type->size[1]] = '\x00';
    m2c_error(b_group1);
  }

  resultlen = data->size[0];
  data->size[0] = group2->data->size[0];
  emxEnsureCapacity_uint8_T(data, resultlen);
  loop_ub = group2->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data->data[resultlen] = group2->data->data[resultlen];
  }

  b_obj = *(MPI_Group*)(&data->data[0]);
  *info = MPI_Group_compare(obj, b_obj, result);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, ptr, &resultlen);
    if (1 > resultlen) {
      loop_ub = 0;
    } else {
      loop_ub = resultlen;
    }

    emxInit_uint8_T(&b_msg0, 2);
    resultlen = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = loop_ub;
    emxEnsureCapacity_uint8_T(b_msg0, resultlen);
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_msg0->data[b_msg0->size[0] * resultlen] = msg0[resultlen];
    }

    emxInit_char_T(&c_msg0, 1);
    resultlen = c_msg0->size[0];
    c_msg0->size[0] = loop_ub;
    emxEnsureCapacity_char_T(c_msg0, resultlen);
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      c_msg0->data[resultlen] = (signed char)b_msg0->data[resultlen];
    }

    emxFree_uint8_T(&b_msg0);
    resultlen = b_group1->size[0] * b_group1->size[1];
    b_group1->size[0] = 1;
    b_group1->size[1] = (short)loop_ub;
    emxEnsureCapacity_char_T(b_group1, resultlen);
    loop_ub = (short)loop_ub;
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_group1->data[b_group1->size[0] * resultlen] = c_msg0->data[resultlen];
    }

    emxFree_char_T(&c_msg0);
    b_m2c_error(b_group1);
  }

  emxFree_char_T(&b_group1);
}

void mpi_Group_compare_initialize(void)
{
}

void mpi_Group_compare_terminate(void)
{
}
