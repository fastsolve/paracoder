#include "mpi_Issend.h"
#include "mpi_Issend_types.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(const emxArray_char_T *varargin_3);

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
  M2C_error("MPI:RuntimeError", "MPI_Issend failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
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

void mpi_Issend(const M2C_OpaquePtrType *ptr, int count,
                const M2C_OpaqueType *datatype, int dest, int tag,
                const M2C_OpaqueType *comm, M2C_OpaqueType *req, int *info,
                boolean_T *toplevel)
{
  static const char cv[12] = {'M', 'P', 'I', '_', 'D', 'a',
                              't', 'a', 't', 'y', 'p', 'e'};
  static const char cv3[11] = {'M', 'P', 'I', '_', 'R', 'e',
                               'q', 'u', 'e', 's', 't'};
  static const char cv1[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  static const char cv2[6] = {'c', 'o', 'n', 's', 't', ' '};
  MPI_Comm b_comm;
  MPI_Datatype c_datatype;
  MPI_Request arg;
  char *b_ptr;
  emxArray_char_T *b_datatype;
  int i;
  int sizepe;
  short unnamed_idx_1;
  unsigned char msg0[1024];
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (datatype->type->size[1] == 12) {
    p = true;
  }
  if (p && (datatype->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 12)) {
      if (!(datatype->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
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
    sizepe = datatype->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_datatype->data[i] = datatype->type->data[i];
    }
    b_datatype->data[datatype->type->size[1]] = '\x00';
    m2c_error(b_datatype);
  }
  c_datatype = *(MPI_Datatype *)(&datatype->data->data[0]);
  p = false;
  if (comm->type->size[1] == 8) {
    p = true;
  }
  if (p && (comm->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (!(comm->type->data[sizepe] == cv1[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    i = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_datatype, i);
    sizepe = comm->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_datatype->data[i] = comm->type->data[i];
    }
    b_datatype->data[comm->type->size[1]] = '\x00';
    b_m2c_error(b_datatype);
  }
  b_comm = *(MPI_Comm *)(&comm->data->data[0]);
  b_ptr = *(char **)(&ptr->data);
  if (ptr->type->size[1] > 6) {
    p = true;
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 6)) {
      if (!(ptr->type->data[sizepe] == cv2[sizepe])) {
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
  if (ptr->offset != 0) {
    b_ptr = b_ptr + ptr->offset;
  }
  *info = MPI_Issend(b_ptr, count, c_datatype, dest, tag, b_comm, &arg);
  sizepe = sizeof(MPI_Request);
  i = req->data->size[0];
  req->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(req->data, i);
  i = req->type->size[0] * req->type->size[1];
  req->type->size[0] = 1;
  req->type->size[1] = 11;
  emxEnsureCapacity_char_T(req->type, i);
  for (i = 0; i < 11; i++) {
    req->type->data[i] = cv3[i];
  }
  req->nitems = 1;
  b_ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    req->data->data[i] = *(b_ptr);
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
    i = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_datatype, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_datatype->data[i] = (signed char)msg0[i];
    }
    c_m2c_error(b_datatype);
  }
  emxFree_char_T(&b_datatype);
  *toplevel = true;
}

void mpi_Issend_initialize(void)
{
}

void mpi_Issend_terminate(void)
{
}
