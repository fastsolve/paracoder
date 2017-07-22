#include "mpi_Comm_spawn.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Info.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i2);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

static void d_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i3;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i3 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i3);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_varargin_3->data[i3] = varargin_3->data[i3];
  }

  M2C_error("MPI:RuntimeError", "MPI_Comm_spawn failed with error message %s\n",
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

  M2C_error("mpi_Comm_spawn:WrongType",
            "Incorrect data type %s. Expected char **.", &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Comm_spawn(const emxArray_char_T *command, const struct0_T *argv, int
                    maxprocs, const struct0_T *mpiinfo, int root, const
                    struct0_T *comm, struct0_T *intercomm, emxArray_int32_T
                    *errcodes, int *info, boolean_T *toplevel)
{
  int resultlen;
  boolean_T p;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_argv;
  static const char cv0[7] = { 'c', 'h', 'a', 'r', ' ', '*', '*' };

  emxArray_uint8_T *data0;
  int loop_ub;
  emxArray_char_T *r0;
  char ** args;
  static const char cv1[8] = { 'M', 'P', 'I', '_', 'I', 'n', 'f', 'o' };

  MPI_Info obj;
  static const char cv2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm b_comm;
  MPI_Comm intercomm0;
  int sizepe;
  char t0_type[8];
  static const char x2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  char * ptr;
  unsigned char msg0[1024];
  emxArray_uint8_T *b_msg0;
  emxArray_char_T *c_msg0;
  resultlen = errcodes->size[0];
  errcodes->size[0] = maxprocs;
  emxEnsureCapacity_int32_T(errcodes, resultlen);
  p = false;
  b_p = false;
  if (argv->type->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(argv->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 7)) {
      if (!(argv->type->data[resultlen] == cv0[resultlen])) {
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

  emxInit_char_T(&b_argv, 2);
  if (!p) {
    resultlen = b_argv->size[0] * b_argv->size[1];
    b_argv->size[0] = 1;
    b_argv->size[1] = argv->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_argv, resultlen);
    loop_ub = argv->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_argv->data[b_argv->size[0] * resultlen] = argv->type->data[argv->
        type->size[0] * resultlen];
    }

    b_argv->data[b_argv->size[0] * argv->type->size[1]] = '\x00';
    m2c_error(b_argv);
  }

  emxInit_uint8_T(&data0, 1);
  resultlen = data0->size[0];
  data0->size[0] = argv->data->size[0];
  emxEnsureCapacity_uint8_T(data0, resultlen);
  loop_ub = argv->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = argv->data->data[resultlen];
  }

  emxInit_char_T(&r0, 2);
  args = *(char ***)(&data0->data[0]);
  resultlen = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = command->size[1] + 1;
  emxEnsureCapacity_char_T(r0, resultlen);
  loop_ub = command->size[1];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    r0->data[r0->size[0] * resultlen] = command->data[command->size[0] *
      resultlen];
  }

  r0->data[r0->size[0] * command->size[1]] = '\x00';
  p = false;
  b_p = false;
  if (mpiinfo->type->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(mpiinfo->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 8)) {
      if (!(mpiinfo->type->data[resultlen] == cv1[resultlen])) {
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
    resultlen = b_argv->size[0] * b_argv->size[1];
    b_argv->size[0] = 1;
    b_argv->size[1] = mpiinfo->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_argv, resultlen);
    loop_ub = mpiinfo->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_argv->data[b_argv->size[0] * resultlen] = mpiinfo->type->data
        [mpiinfo->type->size[0] * resultlen];
    }

    b_argv->data[b_argv->size[0] * mpiinfo->type->size[1]] = '\x00';
    b_m2c_error(b_argv);
  }

  resultlen = data0->size[0];
  data0->size[0] = mpiinfo->data->size[0];
  emxEnsureCapacity_uint8_T(data0, resultlen);
  loop_ub = mpiinfo->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = mpiinfo->data->data[resultlen];
  }

  obj = *(MPI_Info*)(&data0->data[0]);
  p = false;
  b_p = false;
  if (comm->type->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(comm->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 8)) {
      if (!(comm->type->data[resultlen] == cv2[resultlen])) {
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
    resultlen = b_argv->size[0] * b_argv->size[1];
    b_argv->size[0] = 1;
    b_argv->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_argv, resultlen);
    loop_ub = comm->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_argv->data[b_argv->size[0] * resultlen] = comm->type->data[comm->
        type->size[0] * resultlen];
    }

    b_argv->data[b_argv->size[0] * comm->type->size[1]] = '\x00';
    c_m2c_error(b_argv);
  }

  resultlen = data0->size[0];
  data0->size[0] = comm->data->size[0];
  emxEnsureCapacity_uint8_T(data0, resultlen);
  loop_ub = comm->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = comm->data->data[resultlen];
  }

  b_comm = *(MPI_Comm*)(&data0->data[0]);
  *info = MPI_Comm_spawn(&r0->data[0], args, maxprocs, obj, root, b_comm,
    &intercomm0, &errcodes->data[0]);
  sizepe = sizeof(MPI_Comm);
  resultlen = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, resultlen);
  emxFree_char_T(&r0);
  for (resultlen = 0; resultlen < 8; resultlen++) {
    t0_type[resultlen] = x2[resultlen];
  }

  resultlen = intercomm->data->size[0];
  intercomm->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(intercomm->data, resultlen);
  loop_ub = data0->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    intercomm->data->data[resultlen] = data0->data[resultlen];
  }

  emxFree_uint8_T(&data0);
  resultlen = intercomm->type->size[0] * intercomm->type->size[1];
  intercomm->type->size[0] = 1;
  intercomm->type->size[1] = 8;
  emxEnsureCapacity_char_T(intercomm->type, resultlen);
  for (resultlen = 0; resultlen < 8; resultlen++) {
    intercomm->type->data[resultlen] = t0_type[resultlen];
  }

  intercomm->nitems = 1;
  ptr = (char *)(&intercomm0);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    intercomm->data->data[resultlen - 1] = *(ptr);
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
    resultlen = b_argv->size[0] * b_argv->size[1];
    b_argv->size[0] = 1;
    b_argv->size[1] = (short)loop_ub;
    emxEnsureCapacity_char_T(b_argv, resultlen);
    loop_ub = (short)loop_ub;
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_argv->data[b_argv->size[0] * resultlen] = c_msg0->data[resultlen];
    }

    emxFree_char_T(&c_msg0);
    d_m2c_error(b_argv);
  }

  emxFree_char_T(&b_argv);
  *toplevel = true;
}

void mpi_Comm_spawn_initialize(void)
{
}

void mpi_Comm_spawn_terminate(void)
{
}
