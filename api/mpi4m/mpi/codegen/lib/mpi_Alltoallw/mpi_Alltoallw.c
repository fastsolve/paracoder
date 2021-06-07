#include "mpi_Alltoallw.h"
#include "mpi_Alltoallw_types.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(const emxArray_char_T *varargin_3);

static boolean_T isequal(const emxArray_char_T *varargin_1);

static void m2c_error(const emxArray_char_T *varargin_3);

static void m2c_warn(void);

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
  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Comm.\n",
            &b_varargin_3->data[0]);
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
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error("MPI:RuntimeError", "MPI_Alltoallw failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static boolean_T isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[12] = {'M', 'P', 'I', '_', 'D', 'a',
                              't', 'a', 't', 'y', 'p', 'e'};
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 12) {
    b_p = true;
  }
  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return b_p || p;
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  static const char b_varargin_4[13] = "MPI_Datatype";
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  char varargin_4[13];
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  for (i = 0; i < 13; i++) {
    varargin_4[i] = b_varargin_4[i];
  }
  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            &varargin_4[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_warn(void)
{
  M2C_warn("m2c_opaque_ptr:ConstPtr",
           "Discarding the const modifier of an m2c_opaque_ptr.");
}

void mpi_Alltoallw(const M2C_OpaquePtrType *sptr,
                   const emxArray_int32_T *scounts,
                   const emxArray_int32_T *sdisps, const M2C_OpaqueType *stypes,
                   const M2C_OpaquePtrType *rptr,
                   const emxArray_int32_T *rcounts,
                   const emxArray_int32_T *rdisps, const M2C_OpaqueType *rtypes,
                   const M2C_OpaqueType *comm, int *info, boolean_T *toplevel)
{
  static const char cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  static const char cv1[6] = {'c', 'o', 'n', 's', 't', ' '};
  MPI_Comm b_comm;
  MPI_Datatype *b_ptr;
  MPI_Datatype *c_ptr;
  const char *ptr;
  char *d_ptr;
  emxArray_char_T *b_stypes;
  emxArray_uint8_T *rtypes0;
  emxArray_uint8_T *stypes0;
  int i;
  int resultlen;
  short unnamed_idx_1;
  unsigned char msg0[1024];
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  emxInit_char_T(&b_stypes, 2);
  if (!isequal(stypes->type)) {
    i = b_stypes->size[0] * b_stypes->size[1];
    b_stypes->size[0] = 1;
    b_stypes->size[1] = stypes->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stypes, i);
    resultlen = stypes->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_stypes->data[i] = stypes->type->data[i];
    }
    b_stypes->data[stypes->type->size[1]] = '\x00';
    m2c_error(b_stypes);
  }
  emxInit_uint8_T(&stypes0, 1);
  i = stypes0->size[0];
  stypes0->size[0] = stypes->data->size[0];
  emxEnsureCapacity_uint8_T(stypes0, i);
  resultlen = stypes->data->size[0];
  for (i = 0; i < resultlen; i++) {
    stypes0->data[i] = stypes->data->data[i];
  }
  if (!isequal(rtypes->type)) {
    i = b_stypes->size[0] * b_stypes->size[1];
    b_stypes->size[0] = 1;
    b_stypes->size[1] = rtypes->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stypes, i);
    resultlen = rtypes->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_stypes->data[i] = rtypes->type->data[i];
    }
    b_stypes->data[rtypes->type->size[1]] = '\x00';
    m2c_error(b_stypes);
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
  p = false;
  if (comm->type->size[1] == 8) {
    p = true;
  }
  if (p && (comm->type->size[1] != 0)) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 8)) {
      if (!(comm->type->data[resultlen] == cv[resultlen])) {
        p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    i = b_stypes->size[0] * b_stypes->size[1];
    b_stypes->size[0] = 1;
    b_stypes->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stypes, i);
    resultlen = comm->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_stypes->data[i] = comm->type->data[i];
    }
    b_stypes->data[comm->type->size[1]] = '\x00';
    b_m2c_error(b_stypes);
  }
  b_comm = *(MPI_Comm *)(&comm->data->data[0]);
  d_ptr = *(char **)(&rptr->data);
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
    d_ptr = d_ptr + rptr->offset;
  }
  *info = MPI_Alltoallw(ptr, &scounts->data[0], &sdisps->data[0], b_ptr, d_ptr,
                        &rcounts->data[0], &rdisps->data[0], c_ptr, b_comm);
  *toplevel = true;
  emxFree_uint8_T(&rtypes0);
  emxFree_uint8_T(&stypes0);
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    d_ptr = (char *)(&msg0[0]);
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
    c_m2c_error(b_stypes);
  }
  emxFree_char_T(&b_stypes);
}

void mpi_Alltoallw_initialize(void)
{
}

void mpi_Alltoallw_terminate(void)
{
}
