#include "mpi_Dims_create.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

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
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error("MPI:RuntimeError", "MPI_Dims_create failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Dims_create(int nnodes, int ndims, emxArray_int32_T *dims, int *info,
                     boolean_T *toplevel)
{
  int i;
  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  char * ptr;
  int resultlen;
  short unnamed_idx_1;
  i = dims->size[0];
  dims->size[0] = ndims;
  emxEnsureCapacity_int32_T(dims, i);
  for (i = 0; i < ndims; i++) {
    dims->data[i] = 0;
  }

  *info = MPI_Dims_create(nnodes, ndims, &dims->data[0]);
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    emxInit_char_T(&b_msg0, 2);
    ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, ptr, &resultlen);
    if (1 > resultlen) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)resultlen;
    }

    i = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_msg0, i);
    resultlen = unnamed_idx_1;
    for (i = 0; i < resultlen; i++) {
      b_msg0->data[i] = (signed char)msg0[i];
    }

    m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }

  *toplevel = true;
}

void mpi_Dims_create_initialize(void)
{
}

void mpi_Dims_create_terminate(void)
{
}
