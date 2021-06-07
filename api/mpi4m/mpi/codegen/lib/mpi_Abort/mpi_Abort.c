#include "mpi_Abort.h"
#include "mpi_Abort_types.h"
#include "m2c.h"
#include "mpi.h"

static void m2c_error(const emxArray_char_T *varargin_3);

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
            "Incorrect data type %s. Expected MPI_Comm.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

int mpi_Abort(const M2C_OpaqueType *comm, int errorcode)
{
  static const char cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  MPI_Comm c_comm;
  emxArray_char_T *b_comm;
  int i;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (comm->type->size[1] == 8) {
    p = true;
  }
  if (p && (comm->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(comm->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_comm, 2);
    i = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm, i);
    k = comm->type->size[1];
    for (i = 0; i < k; i++) {
      b_comm->data[i] = comm->type->data[i];
    }
    b_comm->data[comm->type->size[1]] = '\x00';
    m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }
  c_comm = *(MPI_Comm *)(&comm->data->data[0]);
  return MPI_Abort(c_comm, errorcode);
}

void mpi_Abort_initialize(void)
{
}

void mpi_Abort_terminate(void)
{
}
