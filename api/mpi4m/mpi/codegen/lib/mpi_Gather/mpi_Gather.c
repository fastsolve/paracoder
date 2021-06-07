#include "mpi_Gather.h"
#include "mpi_Gather_types.h"
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
  M2C_error("MPI:RuntimeError", "MPI_Gather failed with error message %s\n",
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
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_warn(void)
{
  M2C_warn("m2c_opaque_ptr:ConstPtr",
           "Discarding the const modifier of an m2c_opaque_ptr.");
}

void mpi_Gather(const M2C_OpaquePtrType *sptr, int scount,
                const M2C_OpaqueType *stype, const M2C_OpaquePtrType *rptr,
                int rcount, const M2C_OpaqueType *rtype, int root,
                const M2C_OpaqueType *comm, int *info, boolean_T *toplevel)
{
  static const char cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  static const char cv1[6] = {'c', 'o', 'n', 's', 't', ' '};
  MPI_Comm b_comm;
  MPI_Datatype b_datatype;
  MPI_Datatype datatype;
  const char *ptr;
  char *b_ptr;
  emxArray_char_T *b_stype;
  int i;
  int resultlen;
  short unnamed_idx_1;
  unsigned char msg0[1024];
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  ptr = *(const char **)(&sptr->data);
  if (sptr->offset != 0) {
    ptr = ptr + sptr->offset;
  }
  emxInit_char_T(&b_stype, 2);
  if (!isequal(stype->type)) {
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
  datatype = *(MPI_Datatype *)(&stype->data->data[0]);
  if (!isequal(rtype->type)) {
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
  b_datatype = *(MPI_Datatype *)(&rtype->data->data[0]);
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
    i = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stype, i);
    resultlen = comm->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_stype->data[i] = comm->type->data[i];
    }
    b_stype->data[comm->type->size[1]] = '\x00';
    b_m2c_error(b_stype);
  }
  b_comm = *(MPI_Comm *)(&comm->data->data[0]);
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
  *info = MPI_Gather(ptr, scount, datatype, b_ptr, rcount, b_datatype, root,
                     b_comm);
  *toplevel = true;
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    b_ptr = (char *)(&msg0[0]);
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
    c_m2c_error(b_stype);
  }
  emxFree_char_T(&b_stype);
}

void mpi_Gather_initialize(void)
{
}

void mpi_Gather_terminate(void)
{
}
