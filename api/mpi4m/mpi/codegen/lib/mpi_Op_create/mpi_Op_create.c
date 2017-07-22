#include "mpi_Op_create.h"
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

  M2C_error("MPI:RuntimeError", "MPI_Op_create failed with error message %s\n",
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
            "Incorrect data type %s. Expected MPI_User_function *.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Op_create(const struct0_T *func, int commute, struct0_T *op, int *info,
                   boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_func;
  static const char cv0[19] = { 'M', 'P', 'I', '_', 'U', 's', 'e', 'r', '_', 'f',
    'u', 'n', 'c', 't', 'i', 'o', 'n', ' ', '*' };

  emxArray_uint8_T *data0;
  int loop_ub;
  MPI_User_function * t_func;
  MPI_Op t_op;
  int sizepe;
  char t0_type[11];
  static const char cv1[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  char * ptr;
  unsigned char msg0[1024];
  emxArray_uint8_T *b_msg0;
  emxArray_char_T *c_msg0;
  p = false;
  b_p = false;
  if (func->type->size[1] == 19) {
    b_p = true;
  }

  if (b_p && (!(func->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 19)) {
      if (!(func->type->data[resultlen] == cv0[resultlen])) {
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

  emxInit_char_T(&b_func, 2);
  if (!p) {
    resultlen = b_func->size[0] * b_func->size[1];
    b_func->size[0] = 1;
    b_func->size[1] = func->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_func, resultlen);
    loop_ub = func->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_func->data[b_func->size[0] * resultlen] = func->type->data[func->
        type->size[0] * resultlen];
    }

    b_func->data[b_func->size[0] * func->type->size[1]] = '\x00';
    m2c_error(b_func);
  }

  emxInit_uint8_T(&data0, 1);
  resultlen = data0->size[0];
  data0->size[0] = func->data->size[0];
  emxEnsureCapacity_uint8_T(data0, resultlen);
  loop_ub = func->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = func->data->data[resultlen];
  }

  t_func = *(MPI_User_function **)(&data0->data[0]);
  *info = MPI_Op_create(t_func, commute, &t_op);
  sizepe = sizeof(MPI_Request);
  resultlen = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, resultlen);
  for (resultlen = 0; resultlen < 11; resultlen++) {
    t0_type[resultlen] = cv1[resultlen];
  }

  resultlen = op->data->size[0];
  op->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(op->data, resultlen);
  loop_ub = data0->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    op->data->data[resultlen] = data0->data[resultlen];
  }

  emxFree_uint8_T(&data0);
  resultlen = op->type->size[0] * op->type->size[1];
  op->type->size[0] = 1;
  op->type->size[1] = 11;
  emxEnsureCapacity_char_T(op->type, resultlen);
  for (resultlen = 0; resultlen < 11; resultlen++) {
    op->type->data[resultlen] = t0_type[resultlen];
  }

  op->nitems = 1;
  ptr = (char *)(&t_op);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    op->data->data[resultlen - 1] = *(ptr);
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
    resultlen = b_func->size[0] * b_func->size[1];
    b_func->size[0] = 1;
    b_func->size[1] = (short)loop_ub;
    emxEnsureCapacity_char_T(b_func, resultlen);
    loop_ub = (short)loop_ub;
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_func->data[b_func->size[0] * resultlen] = c_msg0->data[resultlen];
    }

    emxFree_char_T(&c_msg0);
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
