#include "mpi_Waitany.h"
#include "mpi_Waitany_types.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);

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
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error("MPI:RuntimeError", "MPI_Waitany failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  static const char b_varargin_4[12] = "MPI_Request";
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  char varargin_4[12];
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  for (i = 0; i < 12; i++) {
    varargin_4[i] = b_varargin_4[i];
  }
  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            &varargin_4[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Waitany(int count, M2C_OpaqueType *reqs, int *idx,
                 M2C_OpaqueType *stat, int *info, boolean_T *toplevel)
{
  static const char cv[11] = {'M', 'P', 'I', '_', 'R', 'e',
                              'q', 'u', 'e', 's', 't'};
  static const char x2[11] = {'M', 'P', 'I', '_', 'R', 'e',
                              'q', 'u', 'e', 's', 't'};
  static const char cv1[10] = {'M', 'P', 'I', '_', 'S',
                               't', 'a', 't', 'u', 's'};
  MPI_Request *ptr;
  MPI_Status arg;
  char *b_ptr;
  emxArray_char_T *b_reqs;
  emxArray_uint8_T *reqs0;
  int i;
  int resultlen;
  int sizepe;
  short unnamed_idx_1;
  unsigned char msg0[1024];
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (reqs->type->size[1] == 11) {
    p = true;
  }
  if (p && (reqs->type->size[1] != 0)) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 11)) {
      if (!(reqs->type->data[resultlen] == cv[resultlen])) {
        p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }
  b_p = (int)p;
  emxInit_char_T(&b_reqs, 2);
  if (!b_p) {
    i = b_reqs->size[0] * b_reqs->size[1];
    b_reqs->size[0] = 1;
    b_reqs->size[1] = reqs->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_reqs, i);
    resultlen = reqs->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_reqs->data[i] = reqs->type->data[i];
    }
    b_reqs->data[reqs->type->size[1]] = '\x00';
    m2c_error(b_reqs);
  }
  emxInit_uint8_T(&reqs0, 1);
  i = reqs0->size[0];
  reqs0->size[0] = reqs->data->size[0];
  emxEnsureCapacity_uint8_T(reqs0, i);
  resultlen = reqs->data->size[0];
  for (i = 0; i < resultlen; i++) {
    reqs0->data[i] = reqs->data->data[i];
  }
  ptr = (MPI_Request *)(&reqs0->data[0]);
  *info = MPI_Waitany(count, ptr, idx, &arg);
  sizepe = sizeof(MPI_Status);
  i = reqs->data->size[0];
  reqs->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(reqs->data, i);
  i = stat->data->size[0];
  stat->data->size[0] = reqs->data->size[0];
  emxEnsureCapacity_uint8_T(stat->data, i);
  resultlen = reqs->data->size[0];
  for (i = 0; i < resultlen; i++) {
    stat->data->data[i] = reqs->data->data[i];
  }
  i = stat->type->size[0] * stat->type->size[1];
  stat->type->size[0] = 1;
  stat->type->size[1] = 10;
  emxEnsureCapacity_char_T(stat->type, i);
  for (i = 0; i < 10; i++) {
    stat->type->data[i] = cv1[i];
  }
  stat->nitems = 1;
  b_ptr = (char *)(&arg);
  for (resultlen = 0; resultlen < sizepe; resultlen++) {
    stat->data->data[resultlen] = *(b_ptr);
    b_ptr = b_ptr + 1;
  }
  sizepe = sizeof(MPI_Request);
  i = sizepe * count;
  resultlen = reqs->data->size[0];
  reqs->data->size[0] = i;
  emxEnsureCapacity_uint8_T(reqs->data, resultlen);
  resultlen = reqs->type->size[0] * reqs->type->size[1];
  reqs->type->size[0] = 1;
  reqs->type->size[1] = 11;
  emxEnsureCapacity_char_T(reqs->type, resultlen);
  for (resultlen = 0; resultlen < 11; resultlen++) {
    reqs->type->data[resultlen] = x2[resultlen];
  }
  reqs->nitems = count;
  if (reqs0->size[0] != 0) {
    b_ptr = (char *)(&reqs0->data[0]);
    for (resultlen = 0; resultlen < i; resultlen++) {
      reqs->data->data[resultlen] = *(b_ptr);
      b_ptr = b_ptr + 1;
    }
  }
  emxFree_uint8_T(&reqs0);
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    b_ptr = (char *)(&msg0[0]);
    resultlen = 0;
    MPI_Error_string(*info, b_ptr, &resultlen);
    if (1 > resultlen) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)resultlen;
    }
    i = b_reqs->size[0] * b_reqs->size[1];
    b_reqs->size[0] = 1;
    b_reqs->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_reqs, i);
    resultlen = unnamed_idx_1;
    for (i = 0; i < resultlen; i++) {
      b_reqs->data[i] = (signed char)msg0[i];
    }
    b_m2c_error(b_reqs);
  }
  emxFree_char_T(&b_reqs);
  *toplevel = true;
}

void mpi_Waitany_initialize(void)
{
}

void mpi_Waitany_terminate(void)
{
}
