#include "mpi_Sendrecv.h"
#include "mpi_Sendrecv_types.h"
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
  M2C_error("MPI:RuntimeError", "MPI_Sendrecv failed with error message %s\n",
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

void mpi_Sendrecv(const M2C_OpaquePtrType *sptr, int scount,
                  const M2C_OpaqueType *stype, int dst, int stag,
                  const M2C_OpaquePtrType *rptr, int rcount,
                  const M2C_OpaqueType *rtype, int src, int rtag,
                  const M2C_OpaqueType *comm, M2C_OpaqueType *stat, int *info,
                  boolean_T *toplevel)
{
  static const char cv2[10] = {'M', 'P', 'I', '_', 'S',
                               't', 'a', 't', 'u', 's'};
  static const char cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  static const char cv1[6] = {'c', 'o', 'n', 's', 't', ' '};
  MPI_Comm b_comm;
  MPI_Datatype b_datatype;
  MPI_Datatype datatype;
  MPI_Status arg;
  const char *ptr;
  char *b_ptr;
  emxArray_char_T *b_stype;
  int i;
  int sizepe;
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
    sizepe = stype->type->size[1];
    for (i = 0; i < sizepe; i++) {
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
    sizepe = rtype->type->size[1];
    for (i = 0; i < sizepe; i++) {
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
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (!(comm->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    i = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stype, i);
    sizepe = comm->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_stype->data[i] = comm->type->data[i];
    }
    b_stype->data[comm->type->size[1]] = '\x00';
    b_m2c_error(b_stype);
  }
  b_comm = *(MPI_Comm *)(&comm->data->data[0]);
  b_ptr = *(char **)(&rptr->data);
  if (rptr->type->size[1] > 6) {
    p = true;
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 6)) {
      if (!(rptr->type->data[sizepe] == cv1[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
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
  *info = MPI_Sendrecv(ptr, scount, datatype, dst, stag, b_ptr, rcount,
                       b_datatype, src, rtag, b_comm, &arg);
  sizepe = sizeof(MPI_Status);
  i = stat->data->size[0];
  stat->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(stat->data, i);
  i = stat->type->size[0] * stat->type->size[1];
  stat->type->size[0] = 1;
  stat->type->size[1] = 10;
  emxEnsureCapacity_char_T(stat->type, i);
  for (i = 0; i < 10; i++) {
    stat->type->data[i] = cv2[i];
  }
  stat->nitems = 1;
  b_ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    stat->data->data[i] = *(b_ptr);
    b_ptr = b_ptr + 1;
  }
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    b_ptr = (char *)(&msg0[0]);
    sizepe = 0;
    MPI_Error_string(*info, b_ptr, &sizepe);
    if (1 > sizepe) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)sizepe;
    }
    i = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_stype, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_stype->data[i] = (signed char)msg0[i];
    }
    c_m2c_error(b_stype);
  }
  emxFree_char_T(&b_stype);
  *toplevel = true;
}

void mpi_Sendrecv_initialize(void)
{
}

void mpi_Sendrecv_terminate(void)
{
}
