#include "mpi_Scan.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static MPI_Op b_m2c_castdata(const emxArray_uint8_T *data);
static void b_m2c_error(void);
static MPI_Comm c_m2c_castdata(const emxArray_uint8_T *data);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static void e_m2c_error(const emxArray_char_T *varargin_3);
static MPI_Datatype m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_warn(void);
static MPI_Op b_m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Op*)(&data->data[0]);
}

static void b_m2c_error(void)
{
  M2C_error("mpi_Scan:OutOfBound", "Message is larger than send buffer size.");
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
            "Incorrect data type %s. Expected MPI_Op.\n", &b_varargin_3->data[0]);
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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

static void e_m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("MPI:RuntimeError", "MPI_Scan failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static MPI_Datatype m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Datatype*)(&data->data[0]);
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
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_warn(void)
{
  M2C_warn("m2c_opaque_ptr:ConstPtr",
           "Discarding the const modifier of an m2c_opaque_ptr.");
}

void mpi_Scan(const M2C_OpaquePtrType *sptr, const M2C_OpaquePtrType *rptr, int
              count, const M2C_OpaqueType *datatype, const M2C_OpaqueType *op,
              const M2C_OpaqueType *comm, int *info, boolean_T *toplevel)
{
  boolean_T p;
  int resultlen;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_datatype;
  int i;
  static const char cv[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  MPI_Datatype c_datatype;
  int size;
  const char * ptr;
  MPI_Op obj;
  static const char cv1[6] = { 'M', 'P', 'I', '_', 'O', 'p' };

  MPI_Comm b_comm;
  static const char cv2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  char * b_ptr;
  static const char cv3[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  unsigned char msg0[1024];
  short unnamed_idx_1;
  p = (datatype->type->size[1] == 12);
  if (p && (datatype->type->size[1] != 0)) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(datatype->type->data[resultlen] == cv[resultlen])) {
        p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_datatype, 2);
  if (!b_p) {
    i = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = datatype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_datatype, i);
    resultlen = datatype->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_datatype->data[i] = datatype->type->data[i];
    }

    b_datatype->data[datatype->type->size[1]] = '\x00';
    m2c_error(b_datatype);
  }

  c_datatype = m2c_castdata(datatype->data);
  MPI_Type_size(c_datatype, &size);
  if (sptr->nbytes - sptr->offset < count * size) {
    b_m2c_error();
  }

  ptr = *(const char **)(&sptr->data);
  if (sptr->offset != 0) {
    ptr = ptr + sptr->offset;
  }

  p = (datatype->type->size[1] == 12);
  if (p && (datatype->type->size[1] != 0)) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(datatype->type->data[resultlen] == cv[resultlen])) {
        p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = datatype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_datatype, i);
    resultlen = datatype->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_datatype->data[i] = datatype->type->data[i];
    }

    b_datatype->data[datatype->type->size[1]] = '\x00';
    m2c_error(b_datatype);
  }

  c_datatype = m2c_castdata(datatype->data);
  p = (op->type->size[1] == 6);
  if (p && (op->type->size[1] != 0)) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 6)) {
      if (!(op->type->data[resultlen] == cv1[resultlen])) {
        p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = op->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_datatype, i);
    resultlen = op->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_datatype->data[i] = op->type->data[i];
    }

    b_datatype->data[op->type->size[1]] = '\x00';
    c_m2c_error(b_datatype);
  }

  obj = b_m2c_castdata(op->data);
  p = (comm->type->size[1] == 8);
  if (p && (comm->type->size[1] != 0)) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 8)) {
      if (!(comm->type->data[resultlen] == cv2[resultlen])) {
        p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_datatype, i);
    resultlen = comm->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_datatype->data[i] = comm->type->data[i];
    }

    b_datatype->data[comm->type->size[1]] = '\x00';
    d_m2c_error(b_datatype);
  }

  b_comm = c_m2c_castdata(comm->data);
  b_ptr = *(char **)(&rptr->data);
  if (rptr->type->size[1] > 6) {
    p = true;
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 6)) {
      if (!(rptr->type->data[resultlen] == cv3[resultlen])) {
        p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }

    b_p = (int)p;
    if (b_p) {
      m2c_warn();
    }
  }

  if (rptr->offset != 0) {
    b_ptr = b_ptr + rptr->offset;
  }

  *info = MPI_Scan(ptr, b_ptr, count, c_datatype, obj, b_comm);
  *toplevel = true;
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    b_ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, b_ptr, &resultlen);
    if (1 > resultlen) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)resultlen;
    }

    i = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_datatype, i);
    resultlen = unnamed_idx_1;
    for (i = 0; i < resultlen; i++) {
      b_datatype->data[i] = (signed char)msg0[i];
    }

    e_m2c_error(b_datatype);
  }

  emxFree_char_T(&b_datatype);
}

void mpi_Scan_initialize(void)
{
}

void mpi_Scan_terminate(void)
{
}
