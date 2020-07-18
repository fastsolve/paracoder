#include "mpi_Iprobe.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);
static MPI_Comm m2c_castdata(const emxArray_uint8_T *data);
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

  M2C_error("MPI:RuntimeError", "MPI_Iprobe failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static MPI_Comm m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Comm*)(&data->data[0]);
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
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Iprobe(int source, int tag, const M2C_OpaqueType *comm, int *flag,
                M2C_OpaqueType *stat, int *info, boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  int i;
  static const char cv[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data0;
  MPI_Comm c_comm;
  MPI_Status arg;
  static const char t0_type[10] = { 'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u',
    's' };

  char * ptr;
  unsigned char msg0[1024];
  short unnamed_idx_1;
  p = (comm->type->size[1] == 8);
  if (p && (comm->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (!(comm->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_comm, 2);
  if (!b_p) {
    i = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm, i);
    sizepe = comm->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_comm->data[i] = comm->type->data[i];
    }

    b_comm->data[comm->type->size[1]] = '\x00';
    m2c_error(b_comm);
  }

  emxInit_uint8_T(&data0, 1);
  c_comm = m2c_castdata(comm->data);
  *info = MPI_Iprobe(source, tag, c_comm, flag, &arg);
  sizepe = sizeof(MPI_Status);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = stat->data->size[0];
  stat->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(stat->data, i);
  for (i = 0; i < sizepe; i++) {
    stat->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = stat->type->size[0] * stat->type->size[1];
  stat->type->size[0] = 1;
  stat->type->size[1] = 10;
  emxEnsureCapacity_char_T(stat->type, i);
  for (i = 0; i < 10; i++) {
    stat->type->data[i] = t0_type[i];
  }

  stat->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    stat->data->data[i] = *(ptr);
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

    i = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_comm, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_comm->data[i] = (signed char)msg0[i];
    }

    b_m2c_error(b_comm);
  }

  emxFree_char_T(&b_comm);
  *toplevel = true;
}

void mpi_Iprobe_initialize(void)
{
}

void mpi_Iprobe_terminate(void)
{
}
