#include "mpi_Get_processor_name.h"
#include "m2c.h"
#include "mpi.h"

static void b_char(const emxArray_uint8_T *varargin_1, emxArray_char_T *y);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_char(const emxArray_uint8_T *varargin_1, emxArray_char_T *y)
{
  unsigned int uv0[2];
  int i1;
  int loop_ub;
  for (i1 = 0; i1 < 2; i1++) {
    uv0[i1] = (unsigned int)varargin_1->size[i1];
  }

  i1 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int)uv0[1];
  emxEnsureCapacity((emxArray__common *)y, i1, (int)sizeof(char));
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("MPI:RuntimeError",
            "MPI_Get_processor_name failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void mpi_Get_processor_name(emxArray_char_T *name, int *info, boolean_T
  *toplevel)
{
  emxArray_uint8_T *name0;
  int resultlen;
  int i0;
  char * ptr;
  emxArray_uint8_T *b_name0;
  unsigned char msg0[1024];
  emxArray_uint8_T *b_msg0;
  emxArray_char_T *msg;
  emxInit_uint8_T(&name0, 2);
  resultlen = (MPI_MAX_PROCESSOR_NAME);
  i0 = name0->size[0] * name0->size[1];
  name0->size[0] = 1;
  name0->size[1] = resultlen;
  emxEnsureCapacity((emxArray__common *)name0, i0, (int)sizeof(unsigned char));
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
  emxEnsureCapacity((emxArray__common *)b_name0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < resultlen; i0++) {
    b_name0->data[b_name0->size[0] * i0] = name0->data[i0];
  }

  emxFree_uint8_T(&name0);
  b_char(b_name0, name);
  *toplevel = true;
  emxFree_uint8_T(&b_name0);
  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, ptr, &resultlen);
    if (1 > resultlen) {
      resultlen = 0;
    }

    emxInit_uint8_T(&b_msg0, 2);
    i0 = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = resultlen;
    emxEnsureCapacity((emxArray__common *)b_msg0, i0, (int)sizeof(unsigned char));
    for (i0 = 0; i0 < resultlen; i0++) {
      b_msg0->data[b_msg0->size[0] * i0] = msg0[i0];
    }

    emxInit_char_T(&msg, 2);
    b_char(b_msg0, msg);
    m2c_error(msg);
    emxFree_uint8_T(&b_msg0);
    emxFree_char_T(&msg);
  }
}

void mpi_Get_processor_name_initialize(void)
{
}

void mpi_Get_processor_name_terminate(void)
{
}
