#include "mpi_Type_create_struct.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  int i1;
  char varargin_4[13];
  static const char b_varargin_4[13] = "MPI_Datatype";
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  for (i1 = 0; i1 < 13; i1++) {
    varargin_4[i1] = b_varargin_4[i1];
  }

  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            varargin_4);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
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
            "MPI_Type_create_struct failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  int i1;
  char varargin_4[9];
  static const char b_varargin_4[9] = "MPI_Aint";
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  for (i1 = 0; i1 < 9; i1++) {
    varargin_4[i1] = b_varargin_4[i1];
  }

  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            varargin_4);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Type_create_struct(int count, const emxArray_int32_T *blocklens, const
  struct0_T *indices, const struct0_T *oldtypes, struct0_T *newtype, int *info,
  boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_indices;
  int i;
  static const char cv[8] = { 'M', 'P', 'I', '_', 'A', 'i', 'n', 't' };

  emxArray_uint8_T *indices0;
  emxArray_uint8_T *oldtypes0;
  static const char cv1[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_uint8_T *data0;
  MPI_Aint * ptr;
  MPI_Datatype * b_ptr;
  MPI_Datatype arg;
  static const char x2[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  char * c_ptr;
  unsigned char msg0[1024];
  short unnamed_idx_1;
  p = (indices->type->size[1] == 8);
  if (p && (indices->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (!(indices->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_indices, 2);
  if (!b_p) {
    i = b_indices->size[0] * b_indices->size[1];
    b_indices->size[0] = 1;
    b_indices->size[1] = indices->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_indices, i);
    sizepe = indices->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_indices->data[i] = indices->type->data[i];
    }

    b_indices->data[indices->type->size[1]] = '\x00';
    m2c_error(b_indices);
  }

  emxInit_uint8_T(&indices0, 1);
  i = indices0->size[0];
  indices0->size[0] = indices->data->size[0];
  emxEnsureCapacity_uint8_T(indices0, i);
  sizepe = indices->data->size[0];
  for (i = 0; i < sizepe; i++) {
    indices0->data[i] = indices->data->data[i];
  }

  p = (oldtypes->type->size[1] == 12);
  if (p && (oldtypes->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 12)) {
      if (!(oldtypes->type->data[sizepe] == cv1[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_indices->size[0] * b_indices->size[1];
    b_indices->size[0] = 1;
    b_indices->size[1] = oldtypes->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_indices, i);
    sizepe = oldtypes->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_indices->data[i] = oldtypes->type->data[i];
    }

    b_indices->data[oldtypes->type->size[1]] = '\x00';
    b_m2c_error(b_indices);
  }

  emxInit_uint8_T(&oldtypes0, 1);
  i = oldtypes0->size[0];
  oldtypes0->size[0] = oldtypes->data->size[0];
  emxEnsureCapacity_uint8_T(oldtypes0, i);
  sizepe = oldtypes->data->size[0];
  for (i = 0; i < sizepe; i++) {
    oldtypes0->data[i] = oldtypes->data->data[i];
  }

  emxInit_uint8_T(&data0, 1);

  ptr = (MPI_Aint *)(&indices0->data[0]);
  b_ptr = (MPI_Datatype *)(&oldtypes0->data[0]);
  *info = MPI_Type_create_struct(count, &blocklens->data[0], ptr, b_ptr, &arg);

  sizepe = sizeof(MPI_Datatype);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = newtype->data->size[0];
  newtype->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(newtype->data, i);
  emxFree_uint8_T(&oldtypes0);
  emxFree_uint8_T(&indices0);
  for (i = 0; i < sizepe; i++) {
    newtype->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = newtype->type->size[0] * newtype->type->size[1];
  newtype->type->size[0] = 1;
  newtype->type->size[1] = 12;
  emxEnsureCapacity_char_T(newtype->type, i);
  for (i = 0; i < 12; i++) {
    newtype->type->data[i] = x2[i];
  }

  newtype->nitems = 1;
  c_ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    newtype->data->data[i] = *(c_ptr);
    c_ptr = c_ptr + 1;
  }

  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    c_ptr = (char *)(msg0);
    sizepe = 0;
    MPI_Error_string(*info, c_ptr, &sizepe);
    if (1 > sizepe) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)sizepe;
    }

    i = b_indices->size[0] * b_indices->size[1];
    b_indices->size[0] = 1;
    b_indices->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_indices, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_indices->data[i] = (signed char)msg0[i];
    }

    c_m2c_error(b_indices);
  }

  emxFree_char_T(&b_indices);
  *toplevel = true;
}

void mpi_Type_create_struct_initialize(void)
{
}

void mpi_Type_create_struct_terminate(void)
{
}
