#include "mpi_Dims_create.h"
#include "m2c.h"
#include "mpi.h"

static void m2c_error(const emxArray_char_T *varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("MPI:RuntimeError", "MPI_Dims_create failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

void mpi_Dims_create(int nnodes, int ndims, emxArray_int32_T *dims, int *info,
                     boolean_T *toplevel)
{
  int resultlen;
  unsigned char msg0[1024];
  char * ptr;
  int loop_ub;
  emxArray_uint8_T *varargin_1;
  emxArray_char_T *b_varargin_1;
  resultlen = dims->size[0];
  dims->size[0] = ndims;
  emxEnsureCapacity((emxArray__common *)dims, resultlen, (int)sizeof(int));
  for (resultlen = 0; resultlen < ndims; resultlen++) {
    dims->data[resultlen] = 0;
  }

  *info = MPI_Dims_create(nnodes, ndims, &dims->data[0]);
  *toplevel = true;
  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, ptr, &resultlen);
    if (1 > resultlen) {
      loop_ub = 0;
    } else {
      loop_ub = resultlen;
    }

    emxInit_uint8_T(&varargin_1, 2);
    resultlen = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity((emxArray__common *)varargin_1, resultlen, (int)sizeof
                      (unsigned char));
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      varargin_1->data[varargin_1->size[0] * resultlen] = msg0[resultlen];
    }

    emxInit_char_T(&b_varargin_1, 2);
    resultlen = b_varargin_1->size[0] * b_varargin_1->size[1];
    b_varargin_1->size[0] = 1;
    b_varargin_1->size[1] = (short)loop_ub;
    emxEnsureCapacity((emxArray__common *)b_varargin_1, resultlen, (int)sizeof
                      (char));
    loop_ub = (short)loop_ub;
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_varargin_1->data[resultlen] = (signed char)varargin_1->data[resultlen];
    }

    emxFree_uint8_T(&varargin_1);
    m2c_error(b_varargin_1);
    emxFree_char_T(&b_varargin_1);
  }
}

void mpi_Dims_create_initialize(void)
{
}

void mpi_Dims_create_terminate(void)
{
}
