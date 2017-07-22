#include "mpi_Get_processor_name.h"
#include "m2c.h"
#include "mpi.h"

static void b_char(const emxArray_uint8_T *varargin_1, emxArray_char_T *y);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_char(const emxArray_uint8_T *varargin_1, emxArray_char_T *y)
{
  int i1;
  unsigned int uv0[2];
  int loop_ub;
  for (i1 = 0; i1 < 2; i1++) {
    uv0[i1] = (unsigned int)varargin_1->size[i1];
  }

  i1 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int)uv0[1];
  emxEnsureCapacity_char_T(y, i1);
  loop_ub = (int)uv0[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    y->data[i1] = (signed char)varargin_1->data[i1];
  }
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i2);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
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
  int i0;
  char * ptr;
  emxArray_uint8_T *b_name0;
  emxArray_char_T *msg;
  unsigned char msg0[1024];
  emxInit_uint8_T(&name0, 2);
  resultlen = (MPI_MAX_PROCESSOR_NAME);
  i0 = name0->size[0] * name0->size[1];
  name0->size[0] = 1;
  name0->size[1] = resultlen;
  emxEnsureCapacity_uint8_T(name0, i0);
  for (i0 = 0; i0 < resultlen; i0++) {
    name0->data[i0] = 0;
  }

  resultlen = (MPI_MAX_PROCESSOR_NAME);
  ptr = (char *)(&name0->data[0]);
  *info = MPI_Get_processor_name(ptr, &resultlen);
  if (1 > resultlen) {
    resultlen = 0;
  }

  emxInit_uint8_T(&b_name0, 2);
  i0 = b_name0->size[0] * b_name0->size[1];
  b_name0->size[0] = 1;
  b_name0->size[1] = resultlen;
  emxEnsureCapacity_uint8_T(b_name0, i0);
  for (i0 = 0; i0 < resultlen; i0++) {
    b_name0->data[b_name0->size[0] * i0] = name0->data[i0];
  }

  b_char(b_name0, name);
  emxFree_uint8_T(&b_name0);
  if (*info != 0) {
    emxInit_char_T(&msg, 2);
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, ptr, &resultlen);
    if (1 > resultlen) {
      resultlen = 0;
    }

    i0 = name0->size[0] * name0->size[1];
    name0->size[0] = 1;
    name0->size[1] = resultlen;
    emxEnsureCapacity_uint8_T(name0, i0);
    for (i0 = 0; i0 < resultlen; i0++) {
      name0->data[name0->size[0] * i0] = msg0[i0];
    }

    b_char(name0, msg);
    m2c_error(msg);
    emxFree_char_T(&msg);
  }

  emxFree_uint8_T(&name0);
  *toplevel = true;
}

void mpi_Get_processor_name_initialize(void)
{
}

void mpi_Get_processor_name_terminate(void)
{
}
