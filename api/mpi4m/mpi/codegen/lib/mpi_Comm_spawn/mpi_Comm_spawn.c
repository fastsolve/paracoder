#include "mpi_Comm_spawn.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static MPI_Info b_m2c_castdata(const emxArray_uint8_T *data);
static void b_m2c_error(const emxArray_char_T *varargin_3);
static MPI_Comm c_m2c_castdata(const emxArray_uint8_T *data);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static char ** m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static MPI_Info b_m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Info*)(&data->data[0]);
}

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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Info.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

static MPI_Comm c_m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Comm*)(&data->data[0]);
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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

static void d_m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("MPI:RuntimeError", "MPI_Comm_spawn failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static char ** m2c_castdata(const emxArray_uint8_T *data)
{
  return *(char ***)(&data->data[0]);
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

  M2C_error("mpi_Comm_spawn:WrongType",
            "Incorrect data type %s. Expected char **.", &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Comm_spawn(const emxArray_char_T *command, const M2C_OpaqueType *argv,
                    int maxprocs, const M2C_OpaqueType *mpiinfo, int root, const
                    M2C_OpaqueType *comm, M2C_OpaqueType *intercomm,
                    emxArray_int32_T *errcodes, int *info, boolean_T *toplevel)
{
  int i;
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_argv;
  static const char cv[7] = { 'c', 'h', 'a', 'r', ' ', '*', '*' };

  emxArray_char_T *r;
  char ** args;
  MPI_Info obj;
  static const char cv1[8] = { 'M', 'P', 'I', '_', 'I', 'n', 'f', 'o' };

  emxArray_uint8_T *data0;
  static const char cv2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm b_comm;
  MPI_Comm arg;
  static const char x2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  char * ptr;
  unsigned char msg0[1024];
  short unnamed_idx_1;
  i = errcodes->size[0];
  errcodes->size[0] = maxprocs;
  emxEnsureCapacity_int32_T(errcodes, i);
  p = (argv->type->size[1] == 7);
  if (p && (argv->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 7)) {
      if (!(argv->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_argv, 2);
  if (!b_p) {
    i = b_argv->size[0] * b_argv->size[1];
    b_argv->size[0] = 1;
    b_argv->size[1] = argv->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_argv, i);
    sizepe = argv->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_argv->data[i] = argv->type->data[i];
    }

    b_argv->data[argv->type->size[1]] = '\x00';
    m2c_error(b_argv);
  }

  emxInit_char_T(&r, 2);
  args = m2c_castdata(argv->data);
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = command->size[1] + 1;
  emxEnsureCapacity_char_T(r, i);
  sizepe = command->size[1];
  for (i = 0; i < sizepe; i++) {
    r->data[i] = command->data[i];
  }

  r->data[command->size[1]] = '\x00';
  p = (mpiinfo->type->size[1] == 8);
  if (p && (mpiinfo->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (!(mpiinfo->type->data[sizepe] == cv1[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_argv->size[0] * b_argv->size[1];
    b_argv->size[0] = 1;
    b_argv->size[1] = mpiinfo->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_argv, i);
    sizepe = mpiinfo->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_argv->data[i] = mpiinfo->type->data[i];
    }

    b_argv->data[mpiinfo->type->size[1]] = '\x00';
    b_m2c_error(b_argv);
  }

  obj = b_m2c_castdata(mpiinfo->data);
  p = (comm->type->size[1] == 8);
  if (p && (comm->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (!(comm->type->data[sizepe] == cv2[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_argv->size[0] * b_argv->size[1];
    b_argv->size[0] = 1;
    b_argv->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_argv, i);
    sizepe = comm->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_argv->data[i] = comm->type->data[i];
    }

    b_argv->data[comm->type->size[1]] = '\x00';
    c_m2c_error(b_argv);
  }

  emxInit_uint8_T(&data0, 1);
  b_comm = c_m2c_castdata(comm->data);
  *info = MPI_Comm_spawn(&r->data[0], args, maxprocs, obj, root, b_comm, &arg,
    &errcodes->data[0]);
  sizepe = sizeof(MPI_Comm);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = intercomm->data->size[0];
  intercomm->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(intercomm->data, i);
  emxFree_char_T(&r);
  for (i = 0; i < sizepe; i++) {
    intercomm->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = intercomm->type->size[0] * intercomm->type->size[1];
  intercomm->type->size[0] = 1;
  intercomm->type->size[1] = 8;
  emxEnsureCapacity_char_T(intercomm->type, i);
  for (i = 0; i < 8; i++) {
    intercomm->type->data[i] = x2[i];
  }

  intercomm->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    intercomm->data->data[i] = *(ptr);
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

    i = b_argv->size[0] * b_argv->size[1];
    b_argv->size[0] = 1;
    b_argv->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_argv, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_argv->data[i] = (signed char)msg0[i];
    }

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
