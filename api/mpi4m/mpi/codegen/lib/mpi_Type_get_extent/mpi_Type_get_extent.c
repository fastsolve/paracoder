#include "mpi_Type_get_extent.h"
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
            "MPI_Type_get_extent failed with error message %s\n",
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
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Type_get_extent(const struct0_T *datatype, struct0_T *lb, struct0_T
  *extent, int *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_datatype;
  static const char cv0[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_uint8_T *data0;
  int loop_ub;
  MPI_Datatype c_datatype;
  MPI_Aint lb0;
  MPI_Aint extent0;
  int sizepe;
  char t0_type[8];
  static const char cv1[8] = { 'M', 'P', 'I', '_', 'A', 'i', 'n', 't' };

  char * ptr;
  unsigned char msg0[1024];
  emxArray_uint8_T *b_msg0;
  emxArray_char_T *c_msg0;
  p = false;
  b_p = false;
  if (datatype->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(datatype->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(datatype->type->data[resultlen] == cv0[resultlen])) {
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

  emxInit_char_T(&b_datatype, 2);
  if (!p) {
    resultlen = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = datatype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_datatype, resultlen);
    loop_ub = datatype->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_datatype->data[b_datatype->size[0] * resultlen] = datatype->type->
        data[datatype->type->size[0] * resultlen];
    }

    b_datatype->data[b_datatype->size[0] * datatype->type->size[1]] = '\x00';
    m2c_error(b_datatype);
  }

  emxInit_uint8_T(&data0, 1);
  resultlen = data0->size[0];
  data0->size[0] = datatype->data->size[0];
  emxEnsureCapacity_uint8_T(data0, resultlen);
  loop_ub = datatype->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = datatype->data->data[resultlen];
  }

  c_datatype = *(MPI_Datatype*)(&data0->data[0]);
  *info = MPI_Type_get_extent(c_datatype, &lb0, &extent0);
  sizepe = sizeof(MPI_Aint);
  resultlen = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, resultlen);
  for (resultlen = 0; resultlen < 8; resultlen++) {
    t0_type[resultlen] = cv1[resultlen];
  }

  resultlen = extent->data->size[0];
  extent->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(extent->data, resultlen);
  loop_ub = data0->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    extent->data->data[resultlen] = data0->data[resultlen];
  }

  resultlen = extent->type->size[0] * extent->type->size[1];
  extent->type->size[0] = 1;
  extent->type->size[1] = 8;
  emxEnsureCapacity_char_T(extent->type, resultlen);
  for (resultlen = 0; resultlen < 8; resultlen++) {
    extent->type->data[resultlen] = t0_type[resultlen];
  }

  extent->nitems = 1;
  ptr = (char *)(&extent0);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    extent->data->data[resultlen - 1] = *(ptr);
    ptr = ptr + 1;
  }

  sizepe = sizeof(MPI_Aint);
  resultlen = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, resultlen);
  for (resultlen = 0; resultlen < 8; resultlen++) {
    t0_type[resultlen] = cv1[resultlen];
  }

  resultlen = lb->data->size[0];
  lb->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(lb->data, resultlen);
  loop_ub = data0->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    lb->data->data[resultlen] = data0->data[resultlen];
  }

  emxFree_uint8_T(&data0);
  resultlen = lb->type->size[0] * lb->type->size[1];
  lb->type->size[0] = 1;
  lb->type->size[1] = 8;
  emxEnsureCapacity_char_T(lb->type, resultlen);
  for (resultlen = 0; resultlen < 8; resultlen++) {
    lb->type->data[resultlen] = t0_type[resultlen];
  }

  lb->nitems = 1;
  ptr = (char *)(&lb0);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    lb->data->data[resultlen - 1] = *(ptr);
    ptr = ptr + 1;
  }

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
    resultlen = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = (short)loop_ub;
    emxEnsureCapacity_char_T(b_datatype, resultlen);
    loop_ub = (short)loop_ub;
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_datatype->data[b_datatype->size[0] * resultlen] = c_msg0->data[resultlen];
    }

    emxFree_char_T(&c_msg0);
    b_m2c_error(b_datatype);
  }

  emxFree_char_T(&b_datatype);
  *toplevel = true;
}

void mpi_Type_get_extent_initialize(void)
{
}

void mpi_Type_get_extent_terminate(void)
{
}
