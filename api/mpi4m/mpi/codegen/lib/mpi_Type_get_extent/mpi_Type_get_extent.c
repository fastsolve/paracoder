#include "mpi_Type_get_extent.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);
static MPI_Datatype m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error("MPI:RuntimeError",
            "MPI_Type_get_extent failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static MPI_Datatype m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Datatype*)(&data->data[0]);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Type_get_extent(const M2C_OpaqueType *datatype, M2C_OpaqueType *lb,
  M2C_OpaqueType *extent, int *info, boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_datatype;
  int i;
  static const char cv[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_uint8_T *data0;
  MPI_Datatype c_datatype;
  MPI_Aint arg;
  MPI_Aint b_arg;
  static const char t0_type[8] = { 'M', 'P', 'I', '_', 'A', 'i', 'n', 't' };

  char * ptr;
  emxArray_uint8_T *b_data0;
  unsigned char msg0[1024];
  short unnamed_idx_1;
  p = (datatype->type->size[1] == 12);
  if (p && (datatype->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 12)) {
      if (!(datatype->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_datatype, 2);
  if (!b_p) {
    i = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = datatype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_datatype, i);
    sizepe = datatype->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_datatype->data[i] = datatype->type->data[i];
    }

    b_datatype->data[datatype->type->size[1]] = '\x00';
    m2c_error(b_datatype);
  }

  emxInit_uint8_T(&data0, 1);
  c_datatype = m2c_castdata(datatype->data);
  *info = MPI_Type_get_extent(c_datatype, &arg, &b_arg);
  sizepe = sizeof(MPI_Aint);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = extent->data->size[0];
  extent->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(extent->data, i);
  for (i = 0; i < sizepe; i++) {
    extent->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = extent->type->size[0] * extent->type->size[1];
  extent->type->size[0] = 1;
  extent->type->size[1] = 8;
  emxEnsureCapacity_char_T(extent->type, i);
  for (i = 0; i < 8; i++) {
    extent->type->data[i] = t0_type[i];
  }

  extent->nitems = 1;
  ptr = (char *)(&b_arg);
  for (i = 0; i < sizepe; i++) {
    extent->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  emxInit_uint8_T(&b_data0, 1);
  sizepe = sizeof(MPI_Aint);
  i = b_data0->size[0];
  b_data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(b_data0, i);
  i = lb->data->size[0];
  lb->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(lb->data, i);
  for (i = 0; i < sizepe; i++) {
    lb->data->data[i] = b_data0->data[i];
  }

  emxFree_uint8_T(&b_data0);
  i = lb->type->size[0] * lb->type->size[1];
  lb->type->size[0] = 1;
  lb->type->size[1] = 8;
  emxEnsureCapacity_char_T(lb->type, i);
  for (i = 0; i < 8; i++) {
    lb->type->data[i] = t0_type[i];
  }

  lb->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    lb->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    ptr = (char *)(msg0);
    sizepe = 0;
    MPI_Error_string(*info, ptr, &sizepe);
    if (1 > sizepe) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)sizepe;
    }

    i = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_datatype, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_datatype->data[i] = (signed char)msg0[i];
    }

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
