#include "mpi_Graph_map.h"
#include "mpi_Graph_map_types.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(void);

static void c_m2c_error(const emxArray_char_T *varargin_3);

static void d_m2c_error(const emxArray_char_T *varargin_3);

static void m2c_error(void);

static void b_m2c_error(void)
{
  M2C_error("mpi_Graph_map:OutOfBound", "edges array is too small.");
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
  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Comm.\n",
            &b_varargin_3->data[0]);
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
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error("MPI:RuntimeError", "MPI_Graph_map failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(void)
{
  M2C_error("mpi_Graph_map:OutOfBound", "index array is too small.");
}

void mpi_Graph_map(const M2C_OpaqueType *comm, int nnodes,
                   const emxArray_int32_T *b_index,
                   const emxArray_int32_T *edges, int *newrank, int *info,
                   boolean_T *toplevel)
{
  static const char cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  MPI_Comm c_comm;
  emxArray_char_T *b_comm;
  int i;
  int resultlen;
  unsigned char msg0[1024];
  char *ptr;
  short unnamed_idx_1;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  if (b_index->size[0] < nnodes) {
    m2c_error();
  }
  if (edges->size[0] < nnodes) {
    b_m2c_error();
  }
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
  emxInit_char_T(&b_comm, 2);
  if (!b_p) {
    i = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm, i);
    resultlen = comm->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_comm->data[i] = comm->type->data[i];
    }
    b_comm->data[comm->type->size[1]] = '\x00';
    c_m2c_error(b_comm);
  }
  c_comm = *(MPI_Comm *)(&comm->data->data[0]);
  *info = MPI_Graph_map(c_comm, nnodes, &b_index->data[0], &edges->data[0],
                        newrank);
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
    i = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_comm, i);
    resultlen = unnamed_idx_1;
    for (i = 0; i < resultlen; i++) {
      b_comm->data[i] = (signed char)msg0[i];
    }
    d_m2c_error(b_comm);
  }
  emxFree_char_T(&b_comm);
}

void mpi_Graph_map_initialize(void)
{
}

void mpi_Graph_map_terminate(void)
{
}
