#include "mpi_Intercomm_create.h"
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

  M2C_error("MPI:RuntimeError",
            "MPI_Intercomm_create failed with error message %s\n",
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

void mpi_Intercomm_create(const struct0_T *local_comm, int local_leader, const
  struct0_T *peer_comm, int remote_leader, int tag, struct0_T *newcomm, int
  *info, boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_local_comm;
  int i;
  static const char cv[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm comm;
  emxArray_uint8_T *data0;
  MPI_Comm b_comm;
  MPI_Comm arg;
  static const char x2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  char * ptr;
  unsigned char msg0[1024];
  short unnamed_idx_1;
  p = (local_comm->type->size[1] == 8);
  if (p && (local_comm->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (!(local_comm->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_local_comm, 2);
  if (!b_p) {
    i = b_local_comm->size[0] * b_local_comm->size[1];
    b_local_comm->size[0] = 1;
    b_local_comm->size[1] = local_comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_local_comm, i);
    sizepe = local_comm->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_local_comm->data[i] = local_comm->type->data[i];
    }

    b_local_comm->data[local_comm->type->size[1]] = '\x00';
    m2c_error(b_local_comm);
  }

  comm = m2c_castdata(local_comm->data);
  p = (peer_comm->type->size[1] == 8);
  if (p && (peer_comm->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (!(peer_comm->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_local_comm->size[0] * b_local_comm->size[1];
    b_local_comm->size[0] = 1;
    b_local_comm->size[1] = peer_comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_local_comm, i);
    sizepe = peer_comm->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_local_comm->data[i] = peer_comm->type->data[i];
    }

    b_local_comm->data[peer_comm->type->size[1]] = '\x00';
    m2c_error(b_local_comm);
  }

  emxInit_uint8_T(&data0, 1);
  b_comm = m2c_castdata(peer_comm->data);
  *info = MPI_Intercomm_create(comm, local_leader, b_comm, remote_leader, tag,
    &arg);
  sizepe = sizeof(MPI_Comm);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = newcomm->data->size[0];
  newcomm->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(newcomm->data, i);
  for (i = 0; i < sizepe; i++) {
    newcomm->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = newcomm->type->size[0] * newcomm->type->size[1];
  newcomm->type->size[0] = 1;
  newcomm->type->size[1] = 8;
  emxEnsureCapacity_char_T(newcomm->type, i);
  for (i = 0; i < 8; i++) {
    newcomm->type->data[i] = x2[i];
  }

  newcomm->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    newcomm->data->data[i] = *(ptr);
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

    i = b_local_comm->size[0] * b_local_comm->size[1];
    b_local_comm->size[0] = 1;
    b_local_comm->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_local_comm, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_local_comm->data[i] = (signed char)msg0[i];
    }

    b_m2c_error(b_local_comm);
  }

  emxFree_char_T(&b_local_comm);
  *toplevel = true;
}

void mpi_Intercomm_create_initialize(void)
{
}

void mpi_Intercomm_create_terminate(void)
{
}
