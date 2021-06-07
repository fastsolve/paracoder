#include "mpi_Type_create_hindexed.h"
#include "mpi_Type_create_hindexed_types.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(const emxArray_char_T *varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  static const char b_varargin_4[9] = "MPI_Aint";
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  char varargin_4[9];
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  for (i = 0; i < 9; i++) {
    varargin_4[i] = b_varargin_4[i];
  }
  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            &varargin_4[0]);
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
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error("MPI:RuntimeError",
            "MPI_Type_create_hindexed failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
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
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Type_create_hindexed(int count, const emxArray_int32_T *blocklens,
                              const M2C_OpaqueType *indices,
                              const M2C_OpaqueType *oldtype,
                              M2C_OpaqueType *newtype, int *info,
                              boolean_T *toplevel)
{
  static const char cv[12] = {'M', 'P', 'I', '_', 'D', 'a',
                              't', 'a', 't', 'y', 'p', 'e'};
  static const char x2[12] = {'M', 'P', 'I', '_', 'D', 'a',
                              't', 'a', 't', 'y', 'p', 'e'};
  static const char cv1[8] = {'M', 'P', 'I', '_', 'A', 'i', 'n', 't'};
  MPI_Aint *ptr;
  MPI_Datatype arg;
  MPI_Datatype dtype;
  char *b_ptr;
  emxArray_char_T *b_oldtype;
  int i;
  int sizepe;
  short unnamed_idx_1;
  unsigned char msg0[1024];
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (oldtype->type->size[1] == 12) {
    p = true;
  }
  if (p && (oldtype->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 12)) {
      if (!(oldtype->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  b_p = (int)p;
  emxInit_char_T(&b_oldtype, 2);
  if (!b_p) {
    i = b_oldtype->size[0] * b_oldtype->size[1];
    b_oldtype->size[0] = 1;
    b_oldtype->size[1] = oldtype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_oldtype, i);
    sizepe = oldtype->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_oldtype->data[i] = oldtype->type->data[i];
    }
    b_oldtype->data[oldtype->type->size[1]] = '\x00';
    m2c_error(b_oldtype);
  }
  dtype = *(MPI_Datatype *)(&oldtype->data->data[0]);
  p = false;
  if (indices->type->size[1] == 8) {
    p = true;
  }
  if (p && (indices->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (!(indices->type->data[sizepe] == cv1[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    i = b_oldtype->size[0] * b_oldtype->size[1];
    b_oldtype->size[0] = 1;
    b_oldtype->size[1] = indices->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_oldtype, i);
    sizepe = indices->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_oldtype->data[i] = indices->type->data[i];
    }
    b_oldtype->data[indices->type->size[1]] = '\x00';
    b_m2c_error(b_oldtype);
  }
  ptr = (MPI_Aint *)(&indices->data->data[0]);
  *info =
      MPI_Type_create_hindexed(count, &blocklens->data[0], ptr, dtype, &arg);
  sizepe = sizeof(MPI_Datatype);
  i = newtype->data->size[0];
  newtype->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(newtype->data, i);
  i = newtype->type->size[0] * newtype->type->size[1];
  newtype->type->size[0] = 1;
  newtype->type->size[1] = 12;
  emxEnsureCapacity_char_T(newtype->type, i);
  for (i = 0; i < 12; i++) {
    newtype->type->data[i] = x2[i];
  }
  newtype->nitems = 1;
  b_ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    newtype->data->data[i] = *(b_ptr);
    b_ptr = b_ptr + 1;
  }
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    b_ptr = (char *)(&msg0[0]);
    sizepe = 0;
    MPI_Error_string(*info, b_ptr, &sizepe);
    if (1 > sizepe) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)sizepe;
    }
    i = b_oldtype->size[0] * b_oldtype->size[1];
    b_oldtype->size[0] = 1;
    b_oldtype->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_oldtype, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_oldtype->data[i] = (signed char)msg0[i];
    }
    c_m2c_error(b_oldtype);
  }
  emxFree_char_T(&b_oldtype);
  *toplevel = true;
}

void mpi_Type_create_hindexed_initialize(void)
{
}

void mpi_Type_create_hindexed_terminate(void)
{
}
