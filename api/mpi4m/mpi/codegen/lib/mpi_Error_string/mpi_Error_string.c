#include "mpi_Error_string.h"
#include "m2c.h"
#include "mpi.h"

static void m2c_error(int varargin_3);
static void m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Error_string with error code %d\n",
            varargin_3);
}

void mpi_Error_string(int errcode, emxArray_char_T *msg, int *info, boolean_T
                      *toplevel)
{
  unsigned char msg0[1024];
  char * ptr;
  int resultlen;
  emxArray_uint8_T *b_msg0;
  int i0;
  emxArray_char_T *c_msg0;
  memset(&msg0[0], 0, sizeof(unsigned char) << 10);
  ptr = (char *)(msg0);
  resultlen = 0;
  *info = MPI_Error_string(errcode, ptr, &resultlen);
  if (1 > resultlen) {
    resultlen = 0;
  }

  emxInit_uint8_T(&b_msg0, 2);
  i0 = b_msg0->size[0] * b_msg0->size[1];
  b_msg0->size[0] = 1;
  b_msg0->size[1] = resultlen;
  emxEnsureCapacity_uint8_T(b_msg0, i0);
  for (i0 = 0; i0 < resultlen; i0++) {
    b_msg0->data[b_msg0->size[0] * i0] = msg0[i0];
  }

  emxInit_char_T(&c_msg0, 1);
  i0 = c_msg0->size[0];
  c_msg0->size[0] = resultlen;
  emxEnsureCapacity_char_T(c_msg0, i0);
  for (i0 = 0; i0 < resultlen; i0++) {
    c_msg0->data[i0] = (signed char)b_msg0->data[i0];
  }

  emxFree_uint8_T(&b_msg0);
  i0 = msg->size[0] * msg->size[1];
  msg->size[0] = 1;
  msg->size[1] = (short)resultlen;
  emxEnsureCapacity_char_T(msg, i0);
  resultlen = (short)resultlen;
  for (i0 = 0; i0 < resultlen; i0++) {
    msg->data[msg->size[0] * i0] = c_msg0->data[i0];
  }

  emxFree_char_T(&c_msg0);
  if (*info != 0) {
    m2c_error(*info);
  }

  *toplevel = true;
}

void mpi_Error_string_initialize(void)
{
}

void mpi_Error_string_terminate(void)
{
}
