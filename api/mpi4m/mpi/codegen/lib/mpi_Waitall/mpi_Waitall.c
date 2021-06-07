#include "mpi_Waitall.h"
#include "mpi_Waitall_types.h"
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
  M2C_error("MPI:RuntimeError", "MPI_Waitall failed with error message %s\n",
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

void mpi_Waitall(int count, M2C_OpaqueType *reqs, M2C_OpaqueType *stats,
                 int *info, boolean_T *toplevel)
{
  static const char cv[11] = {'M', 'P', 'I', '_', 'R', 'e',
                              'q', 'u', 'e', 's', 't'};
  static const char x2[11] = {'M', 'P', 'I', '_', 'R', 'e',
                              'q', 'u', 'e', 's', 't'};
  static const char cv1[10] = {'M', 'P', 'I', '_', 'S',
                               't', 'a', 't', 'u', 's'};
  MPI_Request *ptr;
  MPI_Status *b_ptr;
  char *c_ptr;
  emxArray_char_T *b_reqs;
  emxArray_real_T *stats0;
  emxArray_uint8_T *reqs0;
  int b_i;
  int i;
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
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 11)) {
      if (!(reqs->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
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
    sizepe = reqs->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_reqs->data[i] = reqs->type->data[i];
    }
    b_reqs->data[reqs->type->size[1]] = '\x00';
    m2c_error(b_reqs);
  }
  emxInit_uint8_T(&reqs0, 1);
  i = reqs0->size[0];
  reqs0->size[0] = reqs->data->size[0];
  emxEnsureCapacity_uint8_T(reqs0, i);
  sizepe = reqs->data->size[0];
  for (i = 0; i < sizepe; i++) {
    reqs0->data[i] = reqs->data->data[i];
  }
  emxInit_real_T(&stats0, 2);
  sizepe = sizeof(MPI_Status);
  i = count * sizepe;
  sizepe = stats0->size[0] * stats0->size[1];
  stats0->size[0] = i;
  stats0->size[1] = i;
  emxEnsureCapacity_real_T(stats0, sizepe);
  sizepe = i * i;
  for (i = 0; i < sizepe; i++) {
    stats0->data[i] = 0.0;
  }
  ptr = (MPI_Request *)(&reqs0->data[0]);
  b_ptr = (MPI_Status *)(&stats0->data[0]);
  *info = MPI_Waitall(count, ptr, b_ptr);
  sizepe = sizeof(MPI_Request);
  sizepe *= count;
  i = stats->data->size[0];
  stats->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(stats->data, i);
  i = reqs->data->size[0];
  reqs->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(reqs->data, i);
  for (i = 0; i < sizepe; i++) {
    reqs->data->data[i] = stats->data->data[i];
  }
  i = reqs->type->size[0] * reqs->type->size[1];
  reqs->type->size[0] = 1;
  reqs->type->size[1] = 11;
  emxEnsureCapacity_char_T(reqs->type, i);
  for (i = 0; i < 11; i++) {
    reqs->type->data[i] = x2[i];
  }
  reqs->nitems = count;
  if (reqs0->size[0] != 0) {
    c_ptr = (char *)(&reqs0->data[0]);
    for (b_i = 0; b_i < sizepe; b_i++) {
      reqs->data->data[b_i] = *(c_ptr);
      c_ptr = c_ptr + 1;
    }
  }
  emxFree_uint8_T(&reqs0);
  sizepe = sizeof(MPI_Status);
  i = sizepe * count;
  sizepe = stats->data->size[0];
  stats->data->size[0] = i;
  emxEnsureCapacity_uint8_T(stats->data, sizepe);
  sizepe = stats->type->size[0] * stats->type->size[1];
  stats->type->size[0] = 1;
  stats->type->size[1] = 10;
  emxEnsureCapacity_char_T(stats->type, sizepe);
  for (sizepe = 0; sizepe < 10; sizepe++) {
    stats->type->data[sizepe] = cv1[sizepe];
  }
  stats->nitems = count;
  if ((stats0->size[0] != 0) && (stats0->size[1] != 0)) {
    c_ptr = (char *)(&stats0->data[0]);
    for (b_i = 0; b_i < i; b_i++) {
      stats->data->data[b_i] = *(c_ptr);
      c_ptr = c_ptr + 1;
    }
  }
  emxFree_real_T(&stats0);
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    c_ptr = (char *)(&msg0[0]);
    sizepe = 0;
    MPI_Error_string(*info, c_ptr, &sizepe);
    if (1 > sizepe) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)sizepe;
    }
    i = b_reqs->size[0] * b_reqs->size[1];
    b_reqs->size[0] = 1;
    b_reqs->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_reqs, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_reqs->data[i] = (signed char)msg0[i];
    }
    b_m2c_error(b_reqs);
  }
  emxFree_char_T(&b_reqs);
  *toplevel = true;
}

void mpi_Waitall_initialize(void)
{
}

void mpi_Waitall_terminate(void)
{
}
