#include "mpi_Alltoallw.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static MPI_Comm m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(void);
static void m2c_warn(void);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  int i1;
  char varargin_4[13];
  static const char b_varargin_4[13] = "MPI_Datatype";
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  for (i1 = 0; i1 < 13; i1++) {
    varargin_4[i1] = b_varargin_4[i1];
  }

  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            varargin_4);
  emxFree_char_T(&b_varargin_3);
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

  M2C_error("MPI:RuntimeError", "MPI_Alltoallw failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static MPI_Comm m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Comm*)(&data->data[0]);
}

static void m2c_error(void)
{
  M2C_error("mpi_Alltoallw:NoInPlace",
            "MPI_Alltoallw does not support in-place communication.");
}

static void m2c_warn(void)
{
  M2C_warn("m2c_opaque_ptr:ConstPtr",
           "Discarding the const modifier of an m2c_opaque_ptr.");
}

void mpi_Alltoallw(const M2C_OpaquePtrType *sptr, const emxArray_int32_T
                   *scounts, const emxArray_int32_T *sdisps, const
                   M2C_OpaqueType *stypes, const M2C_OpaquePtrType *rptr, const
                   emxArray_int32_T *rcounts, const emxArray_int32_T *rdisps,
                   const M2C_OpaqueType *rtypes, const M2C_OpaqueType *comm, int
                   *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_stypes;
  int i;
  static const char cv[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_uint8_T *stypes0;
  emxArray_uint8_T *rtypes0;
  const char * ptr;
  MPI_Datatype * b_ptr;
  MPI_Datatype * c_ptr;
  MPI_Comm b_comm;
  static const char cv1[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  char * d_ptr;
  static const char cv2[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  unsigned char msg0[1024];
  short unnamed_idx_1;
  p = (sptr->data == rptr->data);
  if (p) {
    m2c_error();
  }

  b_p = (stypes->type->size[1] == 12);
  if (b_p && (stypes->type->size[1] != 0)) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(stypes->type->data[resultlen] == cv[resultlen])) {
        b_p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  p = (int)b_p;
  emxInit_char_T(&b_stypes, 2);
  if (!p) {
    i = b_stypes->size[0] * b_stypes->size[1];
    b_stypes->size[0] = 1;
    b_stypes->size[1] = stypes->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stypes, i);
    resultlen = stypes->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_stypes->data[i] = stypes->type->data[i];
    }

    b_stypes->data[stypes->type->size[1]] = '\x00';
    b_m2c_error(b_stypes);
  }

  emxInit_uint8_T(&stypes0, 1);
  i = stypes0->size[0];
  stypes0->size[0] = stypes->data->size[0];
  emxEnsureCapacity_uint8_T(stypes0, i);
  resultlen = stypes->data->size[0];
  for (i = 0; i < resultlen; i++) {
    stypes0->data[i] = stypes->data->data[i];
  }

  b_p = (rtypes->type->size[1] == 12);
  if (b_p && (rtypes->type->size[1] != 0)) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(rtypes->type->data[resultlen] == cv[resultlen])) {
        b_p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  p = (int)b_p;
  if (!p) {
    i = b_stypes->size[0] * b_stypes->size[1];
    b_stypes->size[0] = 1;
    b_stypes->size[1] = rtypes->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stypes, i);
    resultlen = rtypes->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_stypes->data[i] = rtypes->type->data[i];
    }

    b_stypes->data[rtypes->type->size[1]] = '\x00';
    b_m2c_error(b_stypes);
  }

  emxInit_uint8_T(&rtypes0, 1);
  i = rtypes0->size[0];
  rtypes0->size[0] = rtypes->data->size[0];
  emxEnsureCapacity_uint8_T(rtypes0, i);
  resultlen = rtypes->data->size[0];
  for (i = 0; i < resultlen; i++) {
    rtypes0->data[i] = rtypes->data->data[i];
  }

  ptr = *(const char **)(&sptr->data);
  if (sptr->offset != 0) {
    ptr = ptr + sptr->offset;
  }

  b_ptr = (MPI_Datatype *)(&stypes0->data[0]);
  c_ptr = (MPI_Datatype *)(&rtypes0->data[0]);
  b_p = (comm->type->size[1] == 8);
  if (b_p && (comm->type->size[1] != 0)) {
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

  p = (int)b_p;
  if (!p) {
    i = b_stypes->size[0] * b_stypes->size[1];
    b_stypes->size[0] = 1;
    b_stypes->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stypes, i);
    resultlen = comm->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_stypes->data[i] = comm->type->data[i];
    }

    b_stypes->data[comm->type->size[1]] = '\x00';
    c_m2c_error(b_stypes);
  }

  b_comm = m2c_castdata(comm->data);
  d_ptr = *(char **)(&rptr->data);
  if (rptr->type->size[1] > 6) {
    b_p = true;
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 6)) {
      if (!(rptr->type->data[resultlen] == cv2[resultlen])) {
        b_p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }

    p = (int)b_p;
    if (p) {
      m2c_warn();
    }
  }

  if (rptr->offset != 0) {
    d_ptr = d_ptr + rptr->offset;
  }

  *info = MPI_Alltoallw(ptr, &scounts->data[0], &sdisps->data[0], b_ptr, d_ptr,
                        &rcounts->data[0], &rdisps->data[0], c_ptr, b_comm);

  *toplevel = true;
  emxFree_uint8_T(&rtypes0);
  emxFree_uint8_T(&stypes0);
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    d_ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, d_ptr, &resultlen);
    if (1 > resultlen) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)resultlen;
    }

    i = b_stypes->size[0] * b_stypes->size[1];
    b_stypes->size[0] = 1;
    b_stypes->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_stypes, i);
    resultlen = unnamed_idx_1;
    for (i = 0; i < resultlen; i++) {
      b_stypes->data[i] = (signed char)msg0[i];
    }

    d_m2c_error(b_stypes);
  }

  emxFree_char_T(&b_stypes);
}

void mpi_Alltoallw_initialize(void)
{
}

void mpi_Alltoallw_terminate(void)
{
}
