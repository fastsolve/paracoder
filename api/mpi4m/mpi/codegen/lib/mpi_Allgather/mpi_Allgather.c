#include "mpi_Allgather.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static const char cv[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
  'p', 'e' };

static MPI_Comm b_m2c_castdata(const emxArray_uint8_T *data);
static void b_m2c_error(void);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static MPI_Datatype m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_warn(void);
static int mpi_Type_size(const emxArray_uint8_T *datatype_data, const
  emxArray_char_T *datatype_type);
static MPI_Comm b_m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Comm*)(&data->data[0]);
}

static void b_m2c_error(void)
{
  M2C_error("mpi_Allgather:OutOfBound",
            "Message size is larger than variable size.");
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

  M2C_error("MPI:RuntimeError", "MPI_Allgather failed with error message %s\n",
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

static int mpi_Type_size(const emxArray_uint8_T *datatype_data, const
  emxArray_char_T *datatype_type)
{
  int size;
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_datatype_type;
  MPI_Datatype datatype;
  int i;
  p = (datatype_type->size[1] == 12);
  if (p && (datatype_type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(datatype_type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_datatype_type, 2);
    i = b_datatype_type->size[0] * b_datatype_type->size[1];
    b_datatype_type->size[0] = 1;
    b_datatype_type->size[1] = datatype_type->size[1] + 1;
    emxEnsureCapacity_char_T(b_datatype_type, i);
    k = datatype_type->size[1];
    for (i = 0; i < k; i++) {
      b_datatype_type->data[i] = datatype_type->data[i];
    }

    b_datatype_type->data[datatype_type->size[1]] = '\x00';
    m2c_error(b_datatype_type);
    emxFree_char_T(&b_datatype_type);
  }

  datatype = m2c_castdata(datatype_data);
  MPI_Type_size(datatype, &size);
  return size;
}

void mpi_Allgather(const M2C_OpaquePtrType *sptr, int scount, const
                   M2C_OpaqueType *stype, const M2C_OpaquePtrType *rptr, int
                   rcount, const M2C_OpaqueType *rtype, const M2C_OpaqueType
                   *comm, int *info, boolean_T *toplevel)
{
  const char * ptr;
  boolean_T p;
  int resultlen;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_stype;
  int i;
  MPI_Datatype datatype;
  MPI_Datatype b_datatype;
  MPI_Comm b_comm;
  static const char b_cv[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  char * b_ptr;
  static const char cv1[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  unsigned char msg0[1024];
  short unnamed_idx_1;
  if ((sptr->nbytes - sptr->offset < scount * mpi_Type_size(stype->data,
        stype->type)) || (rptr->nbytes - rptr->offset < rcount * mpi_Type_size
                          (rtype->data, rtype->type))) {
    b_m2c_error();
  }

  ptr = *(const char **)(&sptr->data);
  if (sptr->offset != 0) {
    ptr = ptr + sptr->offset;
  }

  p = (stype->type->size[1] == 12);
  if (p && (stype->type->size[1] != 0)) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(stype->type->data[resultlen] == cv[resultlen])) {
        p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_stype, 2);
  if (!b_p) {
    i = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = stype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stype, i);
    resultlen = stype->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_stype->data[i] = stype->type->data[i];
    }

    b_stype->data[stype->type->size[1]] = '\x00';
    m2c_error(b_stype);
  }

  datatype = m2c_castdata(stype->data);
  p = (rtype->type->size[1] == 12);
  if (p && (rtype->type->size[1] != 0)) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(rtype->type->data[resultlen] == cv[resultlen])) {
        p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = rtype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stype, i);
    resultlen = rtype->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_stype->data[i] = rtype->type->data[i];
    }

    b_stype->data[rtype->type->size[1]] = '\x00';
    m2c_error(b_stype);
  }

  b_datatype = m2c_castdata(rtype->data);
  p = (comm->type->size[1] == 8);
  if (p && (comm->type->size[1] != 0)) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 8)) {
      if (!(comm->type->data[resultlen] == b_cv[resultlen])) {
        p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stype, i);
    resultlen = comm->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_stype->data[i] = comm->type->data[i];
    }

    b_stype->data[comm->type->size[1]] = '\x00';
    c_m2c_error(b_stype);
  }

  b_comm = b_m2c_castdata(comm->data);
  b_ptr = *(char **)(&rptr->data);
  if (rptr->type->size[1] > 6) {
    p = true;
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 6)) {
      if (!(rptr->type->data[resultlen] == cv1[resultlen])) {
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

  *info = MPI_Allgather(ptr, scount, datatype, b_ptr, rcount, b_datatype, b_comm);
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

    i = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_stype, i);
    resultlen = unnamed_idx_1;
    for (i = 0; i < resultlen; i++) {
      b_stype->data[i] = (signed char)msg0[i];
    }

    d_m2c_error(b_stype);
  }

  emxFree_char_T(&b_stype);
}

void mpi_Allgather_initialize(void)
{
}

void mpi_Allgather_terminate(void)
{
}
