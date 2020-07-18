#include "mpi_Test.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);
static MPI_Request m2c_castdata(const emxArray_uint8_T *data);
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

  M2C_error("MPI:RuntimeError", "MPI_Test failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static MPI_Request m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Request*)(&data->data[0]);
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
            "Incorrect data type %s. Expected MPI_Request.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Test(M2C_OpaqueType *req, int *flag, M2C_OpaqueType *stat, int *info,
              boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_req;
  int i;
  static const char cv[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  emxArray_uint8_T *data0;
  MPI_Request arg;
  MPI_Status b_arg;
  static const char x2[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  char * ptr;
  emxArray_uint8_T *b_data0;
  static const char t1_type[10] = { 'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u',
    's' };

  unsigned char msg0[1024];
  short unnamed_idx_1;
  p = (req->type->size[1] == 11);
  if (p && (req->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 11)) {
      if (!(req->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_req, 2);
  if (!b_p) {
    i = b_req->size[0] * b_req->size[1];
    b_req->size[0] = 1;
    b_req->size[1] = req->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_req, i);
    sizepe = req->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_req->data[i] = req->type->data[i];
    }

    b_req->data[req->type->size[1]] = '\x00';
    m2c_error(b_req);
  }

  emxInit_uint8_T(&data0, 1);
  arg = m2c_castdata(req->data);
  *info = MPI_Test(&arg, flag, &b_arg);
  sizepe = sizeof(MPI_Request);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = req->data->size[0];
  req->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(req->data, i);
  for (i = 0; i < sizepe; i++) {
    req->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = req->type->size[0] * req->type->size[1];
  req->type->size[0] = 1;
  req->type->size[1] = 11;
  emxEnsureCapacity_char_T(req->type, i);
  for (i = 0; i < 11; i++) {
    req->type->data[i] = x2[i];
  }

  req->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    req->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  emxInit_uint8_T(&b_data0, 1);
  sizepe = sizeof(MPI_Status);
  i = b_data0->size[0];
  b_data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(b_data0, i);
  i = stat->data->size[0];
  stat->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(stat->data, i);
  for (i = 0; i < sizepe; i++) {
    stat->data->data[i] = b_data0->data[i];
  }

  emxFree_uint8_T(&b_data0);
  i = stat->type->size[0] * stat->type->size[1];
  stat->type->size[0] = 1;
  stat->type->size[1] = 10;
  emxEnsureCapacity_char_T(stat->type, i);
  for (i = 0; i < 10; i++) {
    stat->type->data[i] = t1_type[i];
  }

  stat->nitems = 1;
  ptr = (char *)(&b_arg);
  for (i = 0; i < sizepe; i++) {
    stat->data->data[i] = *(ptr);
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

    i = b_req->size[0] * b_req->size[1];
    b_req->size[0] = 1;
    b_req->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_req, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_req->data[i] = (signed char)msg0[i];
    }

    b_m2c_error(b_req);
  }

  emxFree_char_T(&b_req);
  *toplevel = true;
}

void mpi_Test_initialize(void)
{
}

void mpi_Test_terminate(void)
{
}
