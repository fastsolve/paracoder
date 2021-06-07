#include "mpi_Graph_create.h"
#include "mpi_Graph_create_types.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(void);

static void c_m2c_error(const emxArray_char_T *varargin_3);

static void d_m2c_error(const emxArray_char_T *varargin_3);

static void m2c_error(void);

static void b_m2c_error(void)
{
  M2C_error("mpi_Graph_create:OutOfBound", "edges array is too small.");
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
  M2C_error("MPI:RuntimeError",
            "MPI_Graph_create failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(void)
{
  M2C_error("mpi_Graph_create:OutOfBound", "index array is too small.");
}

void mpi_Graph_create(const M2C_OpaqueType *comm, int nnodes,
                      const emxArray_int32_T *b_index,
                      const emxArray_int32_T *edges, int reorder,
                      M2C_OpaqueType *newcomm, int *info, boolean_T *toplevel)
{
  static const char cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  static const char x2[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  MPI_Comm arg;
  MPI_Comm c_comm;
  char *ptr;
  emxArray_char_T *b_comm;
  double bsum;
  double y;
  int firstBlockLength;
  int hi;
  int ib;
  int k;
  int lastBlockLength;
  int nblocks;
  short unnamed_idx_1;
  unsigned char msg0[1024];
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  if (b_index->size[0] < nnodes) {
    m2c_error();
  }
  if (1 > nnodes) {
    hi = 0;
  } else {
    hi = nnodes;
  }
  if (hi == 0) {
    y = 0.0;
  } else {
    if (hi <= 1024) {
      firstBlockLength = hi;
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = hi / 1024;
      lastBlockLength = hi - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    y = b_index->data[0];
    for (k = 2; k <= firstBlockLength; k++) {
      y += (double)b_index->data[k - 1];
    }
    for (ib = 2; ib <= nblocks; ib++) {
      firstBlockLength = (ib - 1) << 10;
      bsum = b_index->data[firstBlockLength];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        bsum += (double)b_index->data[(firstBlockLength + k) - 1];
      }
      y += bsum;
    }
  }
  if (edges->size[0] < y) {
    b_m2c_error();
  }
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
  emxInit_char_T(&b_comm, 2);
  if (!b_p) {
    hi = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm, hi);
    firstBlockLength = comm->type->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      b_comm->data[hi] = comm->type->data[hi];
    }
    b_comm->data[comm->type->size[1]] = '\x00';
    c_m2c_error(b_comm);
  }
  c_comm = *(MPI_Comm *)(&comm->data->data[0]);
  *info = MPI_Graph_create(c_comm, nnodes, &b_index->data[0], &edges->data[0],
                           reorder, &arg);
  firstBlockLength = sizeof(MPI_Comm);
  hi = newcomm->data->size[0];
  newcomm->data->size[0] = firstBlockLength;
  emxEnsureCapacity_uint8_T(newcomm->data, hi);
  hi = newcomm->type->size[0] * newcomm->type->size[1];
  newcomm->type->size[0] = 1;
  newcomm->type->size[1] = 8;
  emxEnsureCapacity_char_T(newcomm->type, hi);
  for (hi = 0; hi < 8; hi++) {
    newcomm->type->data[hi] = x2[hi];
  }
  newcomm->nitems = 1;
  ptr = (char *)(&arg);
  for (hi = 0; hi < firstBlockLength; hi++) {
    newcomm->data->data[hi] = *(ptr);
    ptr = ptr + 1;
  }
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    ptr = (char *)(&msg0[0]);
    firstBlockLength = 0;
    MPI_Error_string(*info, ptr, &firstBlockLength);
    if (1 > firstBlockLength) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)firstBlockLength;
    }
    hi = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_comm, hi);
    firstBlockLength = unnamed_idx_1;
    for (hi = 0; hi < firstBlockLength; hi++) {
      b_comm->data[hi] = (signed char)msg0[hi];
    }
    d_m2c_error(b_comm);
  }
  emxFree_char_T(&b_comm);
  *toplevel = true;
}

void mpi_Graph_create_initialize(void)
{
}

void mpi_Graph_create_terminate(void)
{
}
