#include "mpi_Intercomm_create.h"
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

  M2C_error("MPI:RuntimeError",
            "MPI_Intercomm_create failed with error message %s\n",
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
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Intercomm_create(const struct0_T *local_comm, int local_leader, const
  struct0_T *peer_comm, int remote_leader, int tag, struct0_T *newcomm, int
  *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_local_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data0;
  int loop_ub;
  MPI_Comm comm;
  MPI_Comm b_comm;
  MPI_Comm newcomm0;
  int sizepe;
  char t0_type[8];
  static const char x2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  char * ptr;
  unsigned char msg0[1024];
  emxArray_uint8_T *b_msg0;
  emxArray_char_T *c_msg0;
  p = false;
  b_p = false;
  if (local_comm->type->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(local_comm->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 8)) {
      if (!(local_comm->type->data[resultlen] == cv0[resultlen])) {
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

  emxInit_char_T(&b_local_comm, 2);
  if (!p) {
    resultlen = b_local_comm->size[0] * b_local_comm->size[1];
    b_local_comm->size[0] = 1;
    b_local_comm->size[1] = local_comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_local_comm, resultlen);
    loop_ub = local_comm->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_local_comm->data[b_local_comm->size[0] * resultlen] = local_comm->
        type->data[local_comm->type->size[0] * resultlen];
    }

    b_local_comm->data[b_local_comm->size[0] * local_comm->type->size[1]] =
      '\x00';
    m2c_error(b_local_comm);
  }

  emxInit_uint8_T(&data0, 1);
  resultlen = data0->size[0];
  data0->size[0] = local_comm->data->size[0];
  emxEnsureCapacity_uint8_T(data0, resultlen);
  loop_ub = local_comm->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = local_comm->data->data[resultlen];
  }

  comm = *(MPI_Comm*)(&data0->data[0]);
  p = false;
  b_p = false;
  if (peer_comm->type->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(peer_comm->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 8)) {
      if (!(peer_comm->type->data[resultlen] == cv0[resultlen])) {
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
    resultlen = b_local_comm->size[0] * b_local_comm->size[1];
    b_local_comm->size[0] = 1;
    b_local_comm->size[1] = peer_comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_local_comm, resultlen);
    loop_ub = peer_comm->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_local_comm->data[b_local_comm->size[0] * resultlen] = peer_comm->
        type->data[peer_comm->type->size[0] * resultlen];
    }

    b_local_comm->data[b_local_comm->size[0] * peer_comm->type->size[1]] =
      '\x00';
    m2c_error(b_local_comm);
  }

  resultlen = data0->size[0];
  data0->size[0] = peer_comm->data->size[0];
  emxEnsureCapacity_uint8_T(data0, resultlen);
  loop_ub = peer_comm->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = peer_comm->data->data[resultlen];
  }

  b_comm = *(MPI_Comm*)(&data0->data[0]);
  *info = MPI_Intercomm_create(comm, local_leader, b_comm, remote_leader, tag,
    &newcomm0);
  sizepe = sizeof(MPI_Comm);
  resultlen = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, resultlen);
  for (resultlen = 0; resultlen < 8; resultlen++) {
    t0_type[resultlen] = x2[resultlen];
  }

  resultlen = newcomm->data->size[0];
  newcomm->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(newcomm->data, resultlen);
  loop_ub = data0->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    newcomm->data->data[resultlen] = data0->data[resultlen];
  }

  emxFree_uint8_T(&data0);
  resultlen = newcomm->type->size[0] * newcomm->type->size[1];
  newcomm->type->size[0] = 1;
  newcomm->type->size[1] = 8;
  emxEnsureCapacity_char_T(newcomm->type, resultlen);
  for (resultlen = 0; resultlen < 8; resultlen++) {
    newcomm->type->data[resultlen] = t0_type[resultlen];
  }

  newcomm->nitems = 1;
  ptr = (char *)(&newcomm0);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    newcomm->data->data[resultlen - 1] = *(ptr);
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
    resultlen = b_local_comm->size[0] * b_local_comm->size[1];
    b_local_comm->size[0] = 1;
    b_local_comm->size[1] = (short)loop_ub;
    emxEnsureCapacity_char_T(b_local_comm, resultlen);
    loop_ub = (short)loop_ub;
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_local_comm->data[b_local_comm->size[0] * resultlen] = c_msg0->
        data[resultlen];
    }

    emxFree_char_T(&c_msg0);
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
