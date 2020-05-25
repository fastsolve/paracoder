#include "mpi_Comm_get_parent.h"
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
            "MPI_Comm_get_parent failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Comm_get_parent(struct0_T *comm, int *info, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  MPI_Comm arg;
  int sizepe;
  int i;
  static const char t0_type[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  char * ptr;
  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  short unnamed_idx_1;
  emxInit_uint8_T(&data0, 1);
  *info = MPI_Comm_get_parent(&arg);
  sizepe = sizeof(MPI_Comm);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = comm->data->size[0];
  comm->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(comm->data, i);
  for (i = 0; i < sizepe; i++) {
    comm->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = comm->type->size[0] * comm->type->size[1];
  comm->type->size[0] = 1;
  comm->type->size[1] = 8;
  emxEnsureCapacity_char_T(comm->type, i);
  for (i = 0; i < 8; i++) {
    comm->type->data[i] = t0_type[i];
  }

  comm->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    comm->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    emxInit_char_T(&b_msg0, 2);
    ptr = (char *)(msg0);
    sizepe = 0;
    MPI_Error_string(*info, ptr, &sizepe);
    if (1 > sizepe) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)sizepe;
    }

    i = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_msg0, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_msg0->data[i] = (signed char)msg0[i];
    }

    m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }

  *toplevel = true;
}

void mpi_Comm_get_parent_initialize(void)
{
}

void mpi_Comm_get_parent_terminate(void)
{
}
