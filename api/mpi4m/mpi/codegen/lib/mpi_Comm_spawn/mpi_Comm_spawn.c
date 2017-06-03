#include "mpi_Comm_spawn.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Info.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i3;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i3 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i3, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_varargin_3->data[i3] = varargin_3->data[i3];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

static void d_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i4;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i4 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i4, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_varargin_3->data[i4] = varargin_3->data[i4];
  }

  M2C_error("MPI:RuntimeError", "MPI_Comm_spawn failed with error message %s\n",
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

  M2C_error("mpi_Comm_spawn:WrongType",
            "Incorrect data type %s. Expected char **.", &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void mpi_Comm_spawn(const emxArray_char_T *command, const struct0_T *argv, int
                    maxprocs, const struct0_T *mpiinfo, int root, const
                    struct0_T *comm, struct0_T *intercomm, emxArray_int32_T
                    *errcodes, int *info, boolean_T *toplevel)
{
  int i0;
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  int exitg6;
  boolean_T exitg5;
  emxArray_char_T *b_argv;
  static const char cv0[7] = { 'c', 'h', 'a', 'r', ' ', '*', '*' };

  emxArray_uint8_T *data0;
  emxArray_char_T *r0;
  char ** args;
  MPI_Comm intercomm0;
  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *b_mpiinfo;
  static const char cv1[8] = { 'M', 'P', 'I', '_', 'I', 'n', 'f', 'o' };

  MPI_Info obj;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm c_comm;
  int sizepe;
  char t0_type[8];
  static const char x2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  char * ptr;
  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  i0 = errcodes->size[0];
  errcodes->size[0] = maxprocs;
  emxEnsureCapacity((emxArray__common *)errcodes, i0, (int)sizeof(int));
  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg6 = 0;
    if (resultlen < 2) {
      i0 = argv->type->size[resultlen];
      if (i0 != 6 * resultlen + 1) {
        exitg6 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg6 = 1;
    }
  } while (exitg6 == 0);

  if (b_p && (!(argv->type->size[1] == 0))) {
    resultlen = 0;
    exitg5 = false;
    while ((!exitg5) && (resultlen < 7)) {
      if (!(argv->type->data[resultlen] == cv0[resultlen])) {
        b_p = false;
        exitg5 = true;
      } else {
        resultlen++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_argv, 2);
    i0 = b_argv->size[0] * b_argv->size[1];
    b_argv->size[0] = 1;
    b_argv->size[1] = argv->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_argv, i0, (int)sizeof(char));
    resultlen = argv->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_argv->data[b_argv->size[0] * i0] = argv->type->data[argv->type->size[0] *
        i0];
    }

    b_argv->data[b_argv->size[0] * argv->type->size[1]] = '\x00';
    m2c_error(b_argv);
    emxFree_char_T(&b_argv);
  }

  emxInit_uint8_T(&data0, 1);
  i0 = data0->size[0];
  data0->size[0] = argv->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  resultlen = argv->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data0->data[i0] = argv->data->data[i0];
  }

  emxInit_char_T(&r0, 2);
  args = *(char ***)(&data0->data[0]);
  i0 = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = command->size[1] + 1;
  emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof(char));
  resultlen = command->size[1];
  for (i0 = 0; i0 < resultlen; i0++) {
    r0->data[r0->size[0] * i0] = command->data[command->size[0] * i0];
  }

  r0->data[r0->size[0] * command->size[1]] = '\x00';
  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg4 = 0;
    if (resultlen < 2) {
      i0 = mpiinfo->type->size[resultlen];
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

  if (b_p && (!(mpiinfo->type->size[1] == 0))) {
    resultlen = 0;
    exitg3 = false;
    while ((!exitg3) && (resultlen < 8)) {
      if (!(mpiinfo->type->data[resultlen] == cv1[resultlen])) {
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
    emxInit_char_T(&b_mpiinfo, 2);
    i0 = b_mpiinfo->size[0] * b_mpiinfo->size[1];
    b_mpiinfo->size[0] = 1;
    b_mpiinfo->size[1] = mpiinfo->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_mpiinfo, i0, (int)sizeof(char));
    resultlen = mpiinfo->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_mpiinfo->data[b_mpiinfo->size[0] * i0] = mpiinfo->type->data
        [mpiinfo->type->size[0] * i0];
    }

    b_mpiinfo->data[b_mpiinfo->size[0] * mpiinfo->type->size[1]] = '\x00';
    b_m2c_error(b_mpiinfo);
    emxFree_char_T(&b_mpiinfo);
  }

  i0 = data0->size[0];
  data0->size[0] = mpiinfo->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  resultlen = mpiinfo->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data0->data[i0] = mpiinfo->data->data[i0];
  }

  obj = *(MPI_Info*)(&data0->data[0]);
  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg2 = 0;
    if (resultlen < 2) {
      i0 = comm->type->size[resultlen];
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
    emxInit_char_T(&b_comm, 2);
    i0 = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_comm, i0, (int)sizeof(char));
    resultlen = comm->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_comm->data[b_comm->size[0] * i0] = comm->type->data[comm->type->size[0] *
        i0];
    }

    b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
    c_m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }

  i0 = data0->size[0];
  data0->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  resultlen = comm->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data0->data[i0] = comm->data->data[i0];
  }

  c_comm = *(MPI_Comm*)(&data0->data[0]);
  *info = MPI_Comm_spawn(&r0->data[0], args, maxprocs, obj, root, c_comm,
    &intercomm0, &errcodes->data[0]);
  *toplevel = true;
  sizepe = sizeof(MPI_Comm);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  emxFree_char_T(&r0);
  for (i0 = 0; i0 < 8; i0++) {
    t0_type[i0] = x2[i0];
  }

  i0 = intercomm->data->size[0];
  intercomm->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)intercomm->data, i0, (int)sizeof
                    (unsigned char));
  resultlen = data0->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    intercomm->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = intercomm->type->size[0] * intercomm->type->size[1];
  intercomm->type->size[0] = 1;
  intercomm->type->size[1] = 8;
  emxEnsureCapacity((emxArray__common *)intercomm->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 8; i0++) {
    intercomm->type->data[i0] = t0_type[i0];
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
    d_m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }
}

void mpi_Comm_spawn_initialize(void)
{
}

void mpi_Comm_spawn_terminate(void)
{
}
