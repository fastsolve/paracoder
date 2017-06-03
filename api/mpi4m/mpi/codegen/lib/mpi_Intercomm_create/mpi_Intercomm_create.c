#include "mpi_Intercomm_create.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("MPI:RuntimeError",
            "MPI_Intercomm_create failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void mpi_Intercomm_create(const struct0_T *local_comm, int local_leader, const
  struct0_T *peer_comm, int remote_leader, int tag, struct0_T *newcomm, int
  *info, boolean_T *toplevel)
{
  MPI_Comm newcomm0;
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  int exitg4;
  int i0;
  boolean_T exitg3;
  emxArray_char_T *b_local_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data0;
  MPI_Comm comm;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_peer_comm;
  MPI_Comm b_comm;
  int sizepe;
  char t0_type[8];
  static const char x2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  char * ptr;
  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg4 = 0;
    if (resultlen < 2) {
      i0 = local_comm->type->size[resultlen];
      if (i0 != 7 * resultlen + 1) {
        exitg4 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(local_comm->type->size[1] == 0))) {
    resultlen = 0;
    exitg3 = false;
    while ((!exitg3) && (resultlen < 8)) {
      if (!(local_comm->type->data[resultlen] == cv0[resultlen])) {
        b_p = false;
        exitg3 = true;
      } else {
        resultlen++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_local_comm, 2);
    i0 = b_local_comm->size[0] * b_local_comm->size[1];
    b_local_comm->size[0] = 1;
    b_local_comm->size[1] = local_comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_local_comm, i0, (int)sizeof(char));
    resultlen = local_comm->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_local_comm->data[b_local_comm->size[0] * i0] = local_comm->type->
        data[local_comm->type->size[0] * i0];
    }

    b_local_comm->data[b_local_comm->size[0] * local_comm->type->size[1]] =
      '\x00';
    m2c_error(b_local_comm);
    emxFree_char_T(&b_local_comm);
  }

  emxInit_uint8_T(&data0, 1);
  i0 = data0->size[0];
  data0->size[0] = local_comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  resultlen = local_comm->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data0->data[i0] = local_comm->data->data[i0];
  }

  comm = *(MPI_Comm*)(&data0->data[0]);
  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg2 = 0;
    if (resultlen < 2) {
      i0 = peer_comm->type->size[resultlen];
      if (i0 != 7 * resultlen + 1) {
        exitg2 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

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
    emxInit_char_T(&b_peer_comm, 2);
    i0 = b_peer_comm->size[0] * b_peer_comm->size[1];
    b_peer_comm->size[0] = 1;
    b_peer_comm->size[1] = peer_comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_peer_comm, i0, (int)sizeof(char));
    resultlen = peer_comm->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_peer_comm->data[b_peer_comm->size[0] * i0] = peer_comm->type->
        data[peer_comm->type->size[0] * i0];
    }

    b_peer_comm->data[b_peer_comm->size[0] * peer_comm->type->size[1]] = '\x00';
    m2c_error(b_peer_comm);
    emxFree_char_T(&b_peer_comm);
  }

  i0 = data0->size[0];
  data0->size[0] = peer_comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  resultlen = peer_comm->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data0->data[i0] = peer_comm->data->data[i0];
  }

  b_comm = *(MPI_Comm*)(&data0->data[0]);
  *info = MPI_Intercomm_create(comm, local_leader, b_comm, remote_leader, tag,
    &newcomm0);
  *toplevel = true;
  sizepe = sizeof(MPI_Comm);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 8; i0++) {
    t0_type[i0] = x2[i0];
  }

  i0 = newcomm->data->size[0];
  newcomm->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)newcomm->data, i0, (int)sizeof(unsigned
    char));
  resultlen = data0->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    newcomm->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = newcomm->type->size[0] * newcomm->type->size[1];
  newcomm->type->size[0] = 1;
  newcomm->type->size[1] = 8;
  emxEnsureCapacity((emxArray__common *)newcomm->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 8; i0++) {
    newcomm->type->data[i0] = t0_type[i0];
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
      resultlen = 0;
    }

    emxInit_char_T(&b_msg0, 2);
    emxInit_uint8_T(&c_msg0, 2);
    i0 = c_msg0->size[0] * c_msg0->size[1];
    c_msg0->size[0] = 1;
    c_msg0->size[1] = resultlen;
    emxEnsureCapacity((emxArray__common *)c_msg0, i0, (int)sizeof(unsigned char));
    for (i0 = 0; i0 < resultlen; i0++) {
      c_msg0->data[c_msg0->size[0] * i0] = msg0[i0];
    }

    emxInit_char_T(&d_msg0, 1);
    i0 = d_msg0->size[0];
    d_msg0->size[0] = resultlen;
    emxEnsureCapacity((emxArray__common *)d_msg0, i0, (int)sizeof(char));
    for (i0 = 0; i0 < resultlen; i0++) {
      d_msg0->data[i0] = (signed char)c_msg0->data[i0];
    }

    emxFree_uint8_T(&c_msg0);
    i0 = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = (short)resultlen;
    emxEnsureCapacity((emxArray__common *)b_msg0, i0, (int)sizeof(char));
    resultlen = (short)resultlen;
    for (i0 = 0; i0 < resultlen; i0++) {
      b_msg0->data[b_msg0->size[0] * i0] = d_msg0->data[i0];
    }

    emxFree_char_T(&d_msg0);
    b_m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }
}

void mpi_Intercomm_create_initialize(void)
{
}

void mpi_Intercomm_create_terminate(void)
{
}
