#include "mpi_Comm_remote_group.h"
#include "mpi_Comm_remote_group_types.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);

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
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error("MPI:RuntimeError",
            "MPI_Comm_remote_group failed with error message %s\n",
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
            "Incorrect data type %s. Expected MPI_Comm.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Comm_remote_group(const M2C_OpaqueType *comm, M2C_OpaqueType *group,
                           int *info, boolean_T *toplevel)
{
  static const char cv1[9] = {'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p'};
  static const char cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  MPI_Comm c_comm;
  MPI_Group arg;
  char *ptr;
  emxArray_char_T *b_comm;
  int i;
  int sizepe;
  short unnamed_idx_1;
  unsigned char msg0[1024];
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (comm->type->size[1] == 8) {
    p = true;
  }
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
  c_comm = *(MPI_Comm *)(&comm->data->data[0]);
  *info = MPI_Comm_remote_group(c_comm, &arg);
  sizepe = sizeof(MPI_Group);
  i = group->data->size[0];
  group->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(group->data, i);
  i = group->type->size[0] * group->type->size[1];
  group->type->size[0] = 1;
  group->type->size[1] = 9;
  emxEnsureCapacity_char_T(group->type, i);
  for (i = 0; i < 9; i++) {
    group->type->data[i] = cv1[i];
  }
  group->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    group->data->data[i] = *(ptr);
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

void mpi_Comm_remote_group_initialize(void)
{
}

void mpi_Comm_remote_group_terminate(void)
{
}
