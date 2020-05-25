#include "mpi_Op_create.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);
static MPI_User_function * m2c_castdata(const emxArray_uint8_T *data);
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

  M2C_error("MPI:RuntimeError", "MPI_Op_create failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static MPI_User_function * m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_User_function **)(&data->data[0]);
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
            "Incorrect data type %s. Expected MPI_User_function *.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Op_create(const struct0_T *func, int commute, struct0_T *op, int *info,
                   boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_func;
  int i;
  static const char cv[19] = { 'M', 'P', 'I', '_', 'U', 's', 'e', 'r', '_', 'f',
    'u', 'n', 'c', 't', 'i', 'o', 'n', ' ', '*' };

  emxArray_uint8_T *data0;
  MPI_User_function * t_func;
  MPI_Op arg;
  static const char t0_type[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e',
    's', 't' };

  char * ptr;
  unsigned char msg0[1024];
  short unnamed_idx_1;
  p = (func->type->size[1] == 19);
  if (p && (func->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 19)) {
      if (!(func->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_func, 2);
  if (!b_p) {
    i = b_func->size[0] * b_func->size[1];
    b_func->size[0] = 1;
    b_func->size[1] = func->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_func, i);
    sizepe = func->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_func->data[i] = func->type->data[i];
    }

    b_func->data[func->type->size[1]] = '\x00';
    m2c_error(b_func);
  }

  emxInit_uint8_T(&data0, 1);
  t_func = m2c_castdata(func->data);
  *info = MPI_Op_create(t_func, commute, &arg);
  sizepe = sizeof(MPI_Request);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = op->data->size[0];
  op->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(op->data, i);
  for (i = 0; i < sizepe; i++) {
    op->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = op->type->size[0] * op->type->size[1];
  op->type->size[0] = 1;
  op->type->size[1] = 11;
  emxEnsureCapacity_char_T(op->type, i);
  for (i = 0; i < 11; i++) {
    op->type->data[i] = t0_type[i];
  }

  op->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    op->data->data[i] = *(ptr);
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

    i = b_func->size[0] * b_func->size[1];
    b_func->size[0] = 1;
    b_func->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_func, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_func->data[i] = (signed char)msg0[i];
    }

    b_m2c_error(b_func);
  }

  emxFree_char_T(&b_func);
  *toplevel = true;
}

void mpi_Op_create_initialize(void)
{
}

void mpi_Op_create_terminate(void)
{
}
