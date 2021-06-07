#include "mpi_Ssend.h"
#include "mpi_Ssend_types.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

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

static void c_m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Ssend error code %d\n", varargin_3);
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

void mpi_Ssend(const M2C_OpaquePtrType *ptr, int count,
               const M2C_OpaqueType *datatype, int dest, int tag,
               const M2C_OpaqueType *comm, int *info, boolean_T *toplevel)
{
  static const char cv[12] = {'M', 'P', 'I', '_', 'D', 'a',
                              't', 'a', 't', 'y', 'p', 'e'};
  static const char cv1[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  MPI_Comm b_comm;
  MPI_Datatype c_datatype;
  const char *b_ptr;
  emxArray_char_T *b_datatype;
  int i;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  b_ptr = *(const char **)(&ptr->data);
  if (ptr->offset != 0) {
    b_ptr = b_ptr + ptr->offset;
  }
  p = false;
  if (datatype->type->size[1] == 12) {
    p = true;
  }
  if (p && (datatype->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(datatype->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
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
    k = datatype->type->size[1];
    for (i = 0; i < k; i++) {
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
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(comm->type->data[k] == cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    i = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_datatype, i);
    k = comm->type->size[1];
    for (i = 0; i < k; i++) {
      b_datatype->data[i] = comm->type->data[i];
    }
    b_datatype->data[comm->type->size[1]] = '\x00';
    b_m2c_error(b_datatype);
  }
  emxFree_char_T(&b_datatype);
  b_comm = *(MPI_Comm *)(&comm->data->data[0]);
  *info = MPI_Ssend(b_ptr, count, c_datatype, dest, tag, b_comm);
  *toplevel = true;
  if (*info != 0) {
    c_m2c_error(*info);
  }
}

void mpi_Ssend_initialize(void)
{
}

void mpi_Ssend_terminate(void)
{
}
