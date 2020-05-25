#include "mpi_Error_string.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

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
  short unnamed_idx_1;
  int i;
  memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
  ptr = (char *)(msg0);
  resultlen = 0;
  *info = MPI_Error_string(errcode, ptr, &resultlen);
  if (1 > resultlen) {
    unnamed_idx_1 = 0;
  } else {
    unnamed_idx_1 = (short)resultlen;
  }

  i = msg->size[0] * msg->size[1];
  msg->size[0] = 1;
  msg->size[1] = unnamed_idx_1;
  emxEnsureCapacity_char_T(msg, i);
  resultlen = unnamed_idx_1;
  for (i = 0; i < resultlen; i++) {
    msg->data[i] = (signed char)msg0[i];
  }

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
