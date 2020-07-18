#include "mpi_Intercomm_merge.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);
static MPI_Comm m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
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
            "MPI_Intercomm_merge failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static MPI_Comm m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Comm*)(&data->data[0]);
}

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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Intercomm_merge(const M2C_OpaqueType *intercomm, int high,
  M2C_OpaqueType *newcomm, int *info, boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_intercomm;
  int i;
  static const char cv[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data0;
  MPI_Comm comm;
  MPI_Comm arg;
  static const char x2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  char * ptr;
  unsigned char msg0[1024];
  short unnamed_idx_1;
  p = (intercomm->type->size[1] == 8);
  if (p && (intercomm->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (!(intercomm->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_intercomm, 2);
  if (!b_p) {
    i = b_intercomm->size[0] * b_intercomm->size[1];
    b_intercomm->size[0] = 1;
    b_intercomm->size[1] = intercomm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_intercomm, i);
    sizepe = intercomm->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_intercomm->data[i] = intercomm->type->data[i];
    }

    b_intercomm->data[intercomm->type->size[1]] = '\x00';
    m2c_error(b_intercomm);
  }

  emxInit_uint8_T(&data0, 1);
  comm = m2c_castdata(intercomm->data);
  *info = MPI_Intercomm_merge(comm, high, &arg);
  sizepe = sizeof(MPI_Comm);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = newcomm->data->size[0];
  newcomm->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(newcomm->data, i);
  for (i = 0; i < sizepe; i++) {
    newcomm->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = newcomm->type->size[0] * newcomm->type->size[1];
  newcomm->type->size[0] = 1;
  newcomm->type->size[1] = 8;
  emxEnsureCapacity_char_T(newcomm->type, i);
  for (i = 0; i < 8; i++) {
    newcomm->type->data[i] = x2[i];
  }

  newcomm->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    newcomm->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    ptr = (char *)(msg0);
    sizepe = 0;
    MPI_Error_string(*info, ptr, &sizepe);
    if (1 > sizepe) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)sizepe;
    }

    i = b_intercomm->size[0] * b_intercomm->size[1];
    b_intercomm->size[0] = 1;
    b_intercomm->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_intercomm, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_intercomm->data[i] = (signed char)msg0[i];
    }

    b_m2c_error(b_intercomm);
  }

  emxFree_char_T(&b_intercomm);
  *toplevel = true;
}

void mpi_Intercomm_merge_initialize(void)
{
}

void mpi_Intercomm_merge_terminate(void)
{
}
