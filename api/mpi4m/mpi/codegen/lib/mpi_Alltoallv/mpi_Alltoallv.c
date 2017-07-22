#include "mpi_Alltoallv.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static boolean_T isequal(const char varargin_1[6]);
static void m2c_error(void);
static void m2c_warn(void);
static void b_m2c_error(const emxArray_char_T *varargin_3)
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
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
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
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

static void d_m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("MPI:RuntimeError", "MPI_Alltoallv failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static boolean_T isequal(const char varargin_1[6])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv2[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 6)) {
    if (!(varargin_1[k] == cv2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static void m2c_error(void)
{
  M2C_error("mpi_Alltoallv:NoInPlace",
            "MPI_Alltoallv does not support in-place communication.");
}

static void m2c_warn(void)
{
  M2C_warn("m2c_opaque_ptr:ConstPtr",
           "Discarding the const modifier of an m2c_opaque_ptr.");
}

void mpi_Alltoallv(const struct0_T *sptr, const emxArray_int32_T *scounts, const
                   emxArray_int32_T *sdisps, const struct1_T *stype, const
                   struct0_T *rptr, const emxArray_int32_T *rcounts, const
                   emxArray_int32_T *rdisps, const struct1_T *rtype, const
                   struct1_T *comm, int *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  unsigned long data;
  const char * ptr;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_stype;
  static const char cv0[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_uint8_T *b_data;
  int loop_ub;
  MPI_Datatype datatype;
  char * b_ptr;
  MPI_Datatype b_datatype;
  static const char cv1[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm b_comm;
  unsigned char msg0[1024];
  emxArray_uint8_T *b_msg0;
  emxArray_char_T *c_msg0;
  p = false;
  b_p = true;
  if (!(sptr->data == rptr->data)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (p) {
    m2c_error();
  }

  data = sptr->data;
  ptr = *(const char **)(&data);
  if (sptr->offset != 0) {
    ptr = ptr + sptr->offset;
  }

  p = false;
  b_p = false;
  if (stype->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(stype->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(stype->type->data[resultlen] == cv0[resultlen])) {
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

  emxInit_char_T(&b_stype, 2);
  if (!p) {
    resultlen = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = stype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stype, resultlen);
    loop_ub = stype->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_stype->data[b_stype->size[0] * resultlen] = stype->type->data
        [stype->type->size[0] * resultlen];
    }

    b_stype->data[b_stype->size[0] * stype->type->size[1]] = '\x00';
    b_m2c_error(b_stype);
  }

  emxInit_uint8_T(&b_data, 1);
  resultlen = b_data->size[0];
  b_data->size[0] = stype->data->size[0];
  emxEnsureCapacity_uint8_T(b_data, resultlen);
  loop_ub = stype->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    b_data->data[resultlen] = stype->data->data[resultlen];
  }

  datatype = *(MPI_Datatype*)(&b_data->data[0]);
  data = rptr->data;
  b_ptr = *(char **)(&data);
  if ((rptr->type->size[1] > 6) && isequal(*(char (*)[6])&rptr->type->data[0]))
  {
    m2c_warn();
  }

  if (rptr->offset != 0) {
    b_ptr = b_ptr + rptr->offset;
  }

  p = false;
  b_p = false;
  if (rtype->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(rtype->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(rtype->type->data[resultlen] == cv0[resultlen])) {
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
    resultlen = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = rtype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stype, resultlen);
    loop_ub = rtype->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_stype->data[b_stype->size[0] * resultlen] = rtype->type->data
        [rtype->type->size[0] * resultlen];
    }

    b_stype->data[b_stype->size[0] * rtype->type->size[1]] = '\x00';
    b_m2c_error(b_stype);
  }

  resultlen = b_data->size[0];
  b_data->size[0] = rtype->data->size[0];
  emxEnsureCapacity_uint8_T(b_data, resultlen);
  loop_ub = rtype->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    b_data->data[resultlen] = rtype->data->data[resultlen];
  }

  b_datatype = *(MPI_Datatype*)(&b_data->data[0]);
  p = false;
  b_p = false;
  if (comm->type->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(comm->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 8)) {
      if (!(comm->type->data[resultlen] == cv1[resultlen])) {
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
    resultlen = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stype, resultlen);
    loop_ub = comm->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_stype->data[b_stype->size[0] * resultlen] = comm->type->data[comm->
        type->size[0] * resultlen];
    }

    b_stype->data[b_stype->size[0] * comm->type->size[1]] = '\x00';
    c_m2c_error(b_stype);
  }

  resultlen = b_data->size[0];
  b_data->size[0] = comm->data->size[0];
  emxEnsureCapacity_uint8_T(b_data, resultlen);
  loop_ub = comm->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    b_data->data[resultlen] = comm->data->data[resultlen];
  }

  b_comm = *(MPI_Comm*)(&b_data->data[0]);
  *info = MPI_Alltoallv(ptr, &scounts->data[0], &sdisps->data[0], datatype,
                        b_ptr, &rcounts->data[0], &rdisps->data[0], b_datatype,
                        b_comm);
  *toplevel = true;
  emxFree_uint8_T(&b_data);
  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    b_ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, b_ptr, &resultlen);
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
    resultlen = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = (short)loop_ub;
    emxEnsureCapacity_char_T(b_stype, resultlen);
    loop_ub = (short)loop_ub;
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_stype->data[b_stype->size[0] * resultlen] = c_msg0->data[resultlen];
    }

    emxFree_char_T(&c_msg0);
    d_m2c_error(b_stype);
  }

  emxFree_char_T(&b_stype);
}

void mpi_Alltoallv_initialize(void)
{
}

void mpi_Alltoallv_terminate(void)
{
}
