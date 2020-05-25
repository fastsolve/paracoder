#include "mpi_Get_processor_name.h"
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

  M2C_error("MPI:RuntimeError",
            "MPI_Get_processor_name failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Get_processor_name(emxArray_char_T *name, int *info, boolean_T
  *toplevel)
{
  emxArray_uint8_T *name0;
  int resultlen;
  int i;
  char * ptr;
  unsigned int unnamed_idx_1;
  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  emxInit_uint8_T(&name0, 2);
  resultlen = (MPI_MAX_PROCESSOR_NAME);
  i = name0->size[0] * name0->size[1];
  name0->size[0] = 1;
  name0->size[1] = resultlen;
  emxEnsureCapacity_uint8_T(name0, i);
  for (i = 0; i < resultlen; i++) {
    name0->data[i] = 0U;
  }

  resultlen = (MPI_MAX_PROCESSOR_NAME);
  ptr = (char *)(&name0->data[0]);
  *info = MPI_Get_processor_name(ptr, &resultlen);
  if (1 > resultlen) {
    unnamed_idx_1 = 0U;
  } else {
    unnamed_idx_1 = (unsigned int)resultlen;
  }

  i = name->size[0] * name->size[1];
  name->size[0] = 1;
  name->size[1] = (int)unnamed_idx_1;
  emxEnsureCapacity_char_T(name, i);
  resultlen = (int)unnamed_idx_1;
  for (i = 0; i < resultlen; i++) {
    name->data[i] = (signed char)name0->data[i];
  }

  emxFree_uint8_T(&name0);
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    emxInit_char_T(&b_msg0, 2);
    ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, ptr, &resultlen);
    if (1 > resultlen) {
      unnamed_idx_1 = 0U;
    } else {
      unnamed_idx_1 = (unsigned int)resultlen;
    }

    i = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = (int)unnamed_idx_1;
    emxEnsureCapacity_char_T(b_msg0, i);
    resultlen = (int)unnamed_idx_1;
    for (i = 0; i < resultlen; i++) {
      b_msg0->data[i] = (signed char)msg0[i];
    }

    m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }

  *toplevel = true;
}

void mpi_Get_processor_name_initialize(void)
{
}

void mpi_Get_processor_name_terminate(void)
{
}
