#include "mpi_Type_indexed.h"
#include "mpi_Type_indexed_types.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(const emxArray_char_T *varargin_3);

static void m2c_error(void);

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
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
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
            "MPI_Type_hvector failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(void)
{
  M2C_error("runtime:Error",
            "The specified blocklens or indices are too small.");
}

void mpi_Type_indexed(int count, const emxArray_int32_T *blocklens,
                      const emxArray_int32_T *indices,
                      const M2C_OpaqueType *oldtype, M2C_OpaqueType *newtype,
                      int *info, boolean_T *toplevel)
{
  static const char cv[12] = {'M', 'P', 'I', '_', 'D', 'a',
                              't', 'a', 't', 'y', 'p', 'e'};
  static const char x2[12] = {'M', 'P', 'I', '_', 'D', 'a',
                              't', 'a', 't', 'y', 'p', 'e'};
  MPI_Datatype arg;
  MPI_Datatype datatype;
  char *ptr;
  emxArray_char_T *b_oldtype;
  int i;
  int sizepe;
  short unnamed_idx_1;
  unsigned char msg0[1024];
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  if ((blocklens->size[0] < count) && (indices->size[0] < count)) {
    m2c_error();
  }
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
    b_m2c_error(b_oldtype);
  }
  datatype = *(MPI_Datatype *)(&oldtype->data->data[0]);
  *info = MPI_Type_indexed(count, &blocklens->data[0], &indices->data[0],
                           datatype, &arg);
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
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    newtype->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    ptr = (char *)(&msg0[0]);
    sizepe = 0;
    MPI_Error_string(*info, ptr, &sizepe);
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

void mpi_Type_indexed_initialize(void)
{
}

void mpi_Type_indexed_terminate(void)
{
}
