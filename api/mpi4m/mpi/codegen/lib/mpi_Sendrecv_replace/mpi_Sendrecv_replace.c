#include "mpi_Sendrecv_replace.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(void);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_warn(void);
static void b_m2c_error(void)
{
  M2C_error("mpi_Sendrecv_replace:OutOfBound",
            "Message size is larger than variable size.");
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

  M2C_error("MPI:RuntimeError",
            "MPI_Sendrecv_replace failed with error message %s\n",
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
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_warn(void)
{
  M2C_warn("m2c_opaque_ptr:ConstPtr",
           "Discarding the const modifier of an m2c_opaque_ptr.");
}

void mpi_Sendrecv_replace(const struct0_T *ptr, int count, const struct1_T
  *datatype, int dst, int stag, int src, int rtag, const struct1_T *comm,
  struct1_T *stat, int *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_datatype;
  static const char cv0[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_uint8_T *data0;
  int loop_ub;
  MPI_Datatype c_datatype;
  int sizepe;
  unsigned long data;
  char * b_ptr;
  static const signed char iv0[6] = { 1, 2, 3, 4, 5, 6 };

  static const char cv1[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  static const char cv2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm b_comm;
  MPI_Status stat0;
  char t0_type[10];
  static const char cv3[10] = { 'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u', 's'
  };

  unsigned char msg0[1024];
  emxArray_uint8_T *b_msg0;
  emxArray_char_T *c_msg0;
  p = false;
  b_p = false;
  if (datatype->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(datatype->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(datatype->type->data[resultlen] == cv0[resultlen])) {
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

  emxInit_char_T(&b_datatype, 2);
  if (!p) {
    resultlen = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = datatype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_datatype, resultlen);
    loop_ub = datatype->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_datatype->data[b_datatype->size[0] * resultlen] = datatype->type->
        data[datatype->type->size[0] * resultlen];
    }

    b_datatype->data[b_datatype->size[0] * datatype->type->size[1]] = '\x00';
    m2c_error(b_datatype);
  }

  emxInit_uint8_T(&data0, 1);
  resultlen = data0->size[0];
  data0->size[0] = datatype->data->size[0];
  emxEnsureCapacity_uint8_T(data0, resultlen);
  loop_ub = datatype->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = datatype->data->data[resultlen];
  }

  c_datatype = *(MPI_Datatype*)(&data0->data[0]);
  MPI_Type_size(c_datatype, &sizepe);
  if (ptr->nbytes - ptr->offset < count * sizepe) {
    b_m2c_error();
  }

  data = ptr->data;
  b_ptr = *(char **)(&data);
  if (ptr->type->size[1] > 6) {
    p = false;
    b_p = true;
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 6)) {
      if (!(ptr->type->data[iv0[resultlen] - 1] == cv1[resultlen])) {
        b_p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }

    if (b_p) {
      p = true;
    }

    if (p) {
      m2c_warn();
    }
  }

  if (ptr->offset != 0) {
    b_ptr = b_ptr + ptr->offset;
  }

  p = false;
  b_p = false;
  if (datatype->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(datatype->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(datatype->type->data[resultlen] == cv0[resultlen])) {
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
    resultlen = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = datatype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_datatype, resultlen);
    loop_ub = datatype->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_datatype->data[b_datatype->size[0] * resultlen] = datatype->type->
        data[datatype->type->size[0] * resultlen];
    }

    b_datatype->data[b_datatype->size[0] * datatype->type->size[1]] = '\x00';
    m2c_error(b_datatype);
  }

  resultlen = data0->size[0];
  data0->size[0] = datatype->data->size[0];
  emxEnsureCapacity_uint8_T(data0, resultlen);
  loop_ub = datatype->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = datatype->data->data[resultlen];
  }

  c_datatype = *(MPI_Datatype*)(&data0->data[0]);
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
    resultlen = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_datatype, resultlen);
    loop_ub = comm->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_datatype->data[b_datatype->size[0] * resultlen] = comm->type->data
        [comm->type->size[0] * resultlen];
    }

    b_datatype->data[b_datatype->size[0] * comm->type->size[1]] = '\x00';
    c_m2c_error(b_datatype);
  }

  resultlen = data0->size[0];
  data0->size[0] = comm->data->size[0];
  emxEnsureCapacity_uint8_T(data0, resultlen);
  loop_ub = comm->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = comm->data->data[resultlen];
  }

  b_comm = *(MPI_Comm*)(&data0->data[0]);
  *info = MPI_Sendrecv_replace(b_ptr, count, c_datatype, dst, stag, src, rtag,
    b_comm, &stat0);
  sizepe = sizeof(MPI_Status);
  resultlen = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, resultlen);
  for (resultlen = 0; resultlen < 10; resultlen++) {
    t0_type[resultlen] = cv3[resultlen];
  }

  resultlen = stat->data->size[0];
  stat->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(stat->data, resultlen);
  loop_ub = data0->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    stat->data->data[resultlen] = data0->data[resultlen];
  }

  emxFree_uint8_T(&data0);
  resultlen = stat->type->size[0] * stat->type->size[1];
  stat->type->size[0] = 1;
  stat->type->size[1] = 10;
  emxEnsureCapacity_char_T(stat->type, resultlen);
  for (resultlen = 0; resultlen < 10; resultlen++) {
    stat->type->data[resultlen] = t0_type[resultlen];
  }

  stat->nitems = 1;
  b_ptr = (char *)(&stat0);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    stat->data->data[resultlen - 1] = *(b_ptr);
    b_ptr = b_ptr + 1;
  }

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
    resultlen = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = (short)loop_ub;
    emxEnsureCapacity_char_T(b_datatype, resultlen);
    loop_ub = (short)loop_ub;
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_datatype->data[b_datatype->size[0] * resultlen] = c_msg0->data[resultlen];
    }

    emxFree_char_T(&c_msg0);
    d_m2c_error(b_datatype);
  }

  emxFree_char_T(&b_datatype);
  *toplevel = true;
}

void mpi_Sendrecv_replace_initialize(void)
{
}

void mpi_Sendrecv_replace_terminate(void)
{
}
