#include "mpi_Op_free.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);
static MPI_Op m2c_castdata(const emxArray_uint8_T *data);
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

  M2C_error("MPI:RuntimeError", "MPI_Op_free failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static MPI_Op m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Op*)(&data->data[0]);
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
            "Incorrect data type %s. Expected MPI_Op.\n", &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Op_free(struct0_T *op, int *info, boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_op;
  int i;
  static const char cv[6] = { 'M', 'P', 'I', '_', 'O', 'p' };

  emxArray_uint8_T *data0;
  MPI_Op arg;
  static const char t0_type[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e',
    's', 't' };

  char * ptr;
  unsigned char msg0[1024];
  short unnamed_idx_1;
  p = (op->type->size[1] == 6);
  if (p && (op->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 6)) {
      if (!(op->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_op, 2);
  if (!b_p) {
    i = b_op->size[0] * b_op->size[1];
    b_op->size[0] = 1;
    b_op->size[1] = op->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_op, i);
    sizepe = op->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_op->data[i] = op->type->data[i];
    }

    b_op->data[op->type->size[1]] = '\x00';
    m2c_error(b_op);
  }

  emxInit_uint8_T(&data0, 1);
  arg = m2c_castdata(op->data);
  *info = MPI_Op_free(&arg);
  *toplevel = true;
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

    i = b_op->size[0] * b_op->size[1];
    b_op->size[0] = 1;
    b_op->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_op, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_op->data[i] = (signed char)msg0[i];
    }

    b_m2c_error(b_op);
  }

  emxFree_char_T(&b_op);
}

void mpi_Op_free_initialize(void)
{
}

void mpi_Op_free_terminate(void)
{
}
