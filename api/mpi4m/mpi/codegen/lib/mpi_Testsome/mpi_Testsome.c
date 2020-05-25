#include "mpi_Testsome.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(void);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  int i1;
  char varargin_4[12];
  static const char b_varargin_4[12] = "MPI_Request";
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  for (i1 = 0; i1 < 12; i1++) {
    varargin_4[i1] = b_varargin_4[i1];
  }

  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            varargin_4);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("MPI:RuntimeError", "MPI_Testsome failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(void)
{
  M2C_error("mpi_Testsome:OutOfBound", "MPI_Request_array is too small.");
}

void mpi_Testsome(int count, struct0_T *reqs, emxArray_int32_T *idxs, struct0_T *
                  stats, int *info, boolean_T *toplevel)
{
  int n;
  int i;
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_reqs;
  static const char cv[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  emxArray_uint8_T *reqs0;
  emxArray_real_T *stats0;
  emxArray_uint8_T *data0;
  MPI_Request * ptr;
  MPI_Status * b_ptr;
  static const char x2[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  char * c_ptr;
  static const char t1_type[10] = { 'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u',
    's' };

  unsigned char msg0[1024];
  short unnamed_idx_1;
  n = sizeof(MPI_Request);
  if (reqs->data->size[0] < count * n) {
    m2c_error();
  }

  i = idxs->size[0];
  idxs->size[0] = count;
  emxEnsureCapacity_int32_T(idxs, i);
  for (i = 0; i < count; i++) {
    idxs->data[i] = 0;
  }

  p = (reqs->type->size[1] == 11);
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
    b_m2c_error(b_reqs);
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

  emxInit_uint8_T(&data0, 1);

  ptr = (MPI_Request *)(&reqs0->data[0]);
  b_ptr = (MPI_Status *)(&stats0->data[0]);
  *info = MPI_Testsome(count, ptr, &n, &idxs->data[0], b_ptr);
  sizepe = sizeof(MPI_Request);
  sizepe *= count;
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = reqs->data->size[0];
  reqs->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(reqs->data, i);
  for (i = 0; i < sizepe; i++) {
    reqs->data->data[i] = data0->data[i];
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
    for (i = 0; i < sizepe; i++) {
      reqs->data->data[i] = *(c_ptr);
      c_ptr = c_ptr + 1;
    }
  }

  emxFree_uint8_T(&reqs0);
  sizepe = sizeof(MPI_Status);
  sizepe *= count;
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = stats->data->size[0];
  stats->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(stats->data, i);
  for (i = 0; i < sizepe; i++) {
    stats->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = stats->type->size[0] * stats->type->size[1];
  stats->type->size[0] = 1;
  stats->type->size[1] = 10;
  emxEnsureCapacity_char_T(stats->type, i);
  for (i = 0; i < 10; i++) {
    stats->type->data[i] = t1_type[i];
  }

  stats->nitems = count;
  if ((stats0->size[0] != 0) && (stats0->size[1] != 0)) {
    c_ptr = (char *)(&stats0->data[0]);
    for (i = 0; i < sizepe; i++) {
      stats->data->data[i] = *(c_ptr);
      c_ptr = c_ptr + 1;
    }
  }

  emxFree_real_T(&stats0);
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    c_ptr = (char *)(msg0);
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

    c_m2c_error(b_reqs);
  }

  emxFree_char_T(&b_reqs);
  i = idxs->size[0];
  if (1 > n) {
    idxs->size[0] = 0;
  } else {
    idxs->size[0] = n;
  }

  emxEnsureCapacity_int32_T(idxs, i);
  *toplevel = true;
}

void mpi_Testsome_initialize(void)
{
}

void mpi_Testsome_terminate(void)
{
}
