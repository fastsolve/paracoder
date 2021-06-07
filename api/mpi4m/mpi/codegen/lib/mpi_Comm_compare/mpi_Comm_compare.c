#include "mpi_Comm_compare.h"
#include "mpi_Comm_compare_types.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);

static boolean_T isequal(const emxArray_char_T *varargin_1);

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
  M2C_error("MPI:RuntimeError",
            "MPI_Comm_compare failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static boolean_T isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }
  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
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
            "Incorrect data type %s. Expected MPI_Comm.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Comm_compare(const M2C_OpaqueType *comm1, const M2C_OpaqueType *comm2,
                      int *result, int *info, boolean_T *toplevel)
{
  MPI_Comm b_comm;
  MPI_Comm comm;
  emxArray_char_T *b_comm1;
  int i;
  int resultlen;
  unsigned char msg0[1024];
  char *ptr;
  short unnamed_idx_1;
  emxInit_char_T(&b_comm1, 2);
  if (!isequal(comm1->type)) {
    i = b_comm1->size[0] * b_comm1->size[1];
    b_comm1->size[0] = 1;
    b_comm1->size[1] = comm1->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm1, i);
    resultlen = comm1->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_comm1->data[i] = comm1->type->data[i];
    }
    b_comm1->data[comm1->type->size[1]] = '\x00';
    m2c_error(b_comm1);
  }
  comm = *(MPI_Comm *)(&comm1->data->data[0]);
  if (!isequal(comm2->type)) {
    i = b_comm1->size[0] * b_comm1->size[1];
    b_comm1->size[0] = 1;
    b_comm1->size[1] = comm2->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm1, i);
    resultlen = comm2->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_comm1->data[i] = comm2->type->data[i];
    }
    b_comm1->data[comm2->type->size[1]] = '\x00';
    m2c_error(b_comm1);
  }
  b_comm = *(MPI_Comm *)(&comm2->data->data[0]);
  *info = MPI_Comm_compare(comm, b_comm, result);
  *toplevel = true;
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    ptr = (char *)(&msg0[0]);
    resultlen = 0;
    MPI_Error_string(*info, ptr, &resultlen);
    if (1 > resultlen) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)resultlen;
    }
    i = b_comm1->size[0] * b_comm1->size[1];
    b_comm1->size[0] = 1;
    b_comm1->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_comm1, i);
    resultlen = unnamed_idx_1;
    for (i = 0; i < resultlen; i++) {
      b_comm1->data[i] = (signed char)msg0[i];
    }
    b_m2c_error(b_comm1);
  }
  emxFree_char_T(&b_comm1);
}

void mpi_Comm_compare_initialize(void)
{
}

void mpi_Comm_compare_terminate(void)
{
}
