#include "mpi_Group_translate_ranks.h"
#include "mpi_Group_translate_ranks_types.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(const emxArray_char_T *varargin_3);

static boolean_T isequal(const emxArray_char_T *varargin_1);

static void m2c_error(void);

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
  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Group.\n",
            &b_varargin_3->data[0]);
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
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error("MPI:RuntimeError",
            "MPI_Group_translate_ranks failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static boolean_T isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[9] = {'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p'};
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }
  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return b_p || p;
}

static void m2c_error(void)
{
  M2C_error("MPI_Group_translate_ranks:OutOfBound",
            "ranks1 array is too small.");
}

void mpi_Group_translate_ranks(const M2C_OpaqueType *group1, int n,
                               const emxArray_int32_T *ranks1,
                               const M2C_OpaqueType *group2,
                               emxArray_int32_T *ranks2, int *info,
                               boolean_T *toplevel)
{
  MPI_Group b_obj;
  MPI_Group obj;
  emxArray_char_T *b_group1;
  emxArray_int32_T *b_ranks1;
  emxArray_int32_T *b_ranks2;
  int i;
  int resultlen;
  unsigned char msg0[1024];
  char *ptr;
  short unnamed_idx_1;
  if (ranks1->size[0] < n) {
    m2c_error();
  }
  i = ranks2->size[0];
  ranks2->size[0] = n;
  emxEnsureCapacity_int32_T(ranks2, i);
  for (i = 0; i < n; i++) {
    ranks2->data[i] = 0;
  }
  emxInit_int32_T(&b_ranks1, 1);
  i = b_ranks1->size[0];
  b_ranks1->size[0] = ranks1->size[0];
  emxEnsureCapacity_int32_T(b_ranks1, i);
  resultlen = ranks1->size[0];
  for (i = 0; i < resultlen; i++) {
    b_ranks1->data[i] = ranks1->data[i];
  }
  emxInit_int32_T(&b_ranks2, 1);
  i = b_ranks2->size[0];
  b_ranks2->size[0] = n;
  emxEnsureCapacity_int32_T(b_ranks2, i);
  for (i = 0; i < n; i++) {
    b_ranks2->data[i] = 0;
  }
  emxInit_char_T(&b_group1, 2);
  if (!isequal(group1->type)) {
    i = b_group1->size[0] * b_group1->size[1];
    b_group1->size[0] = 1;
    b_group1->size[1] = group1->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_group1, i);
    resultlen = group1->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_group1->data[i] = group1->type->data[i];
    }
    b_group1->data[group1->type->size[1]] = '\x00';
    b_m2c_error(b_group1);
  }
  obj = *(MPI_Group *)(&group1->data->data[0]);
  if (!isequal(group2->type)) {
    i = b_group1->size[0] * b_group1->size[1];
    b_group1->size[0] = 1;
    b_group1->size[1] = group2->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_group1, i);
    resultlen = group2->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_group1->data[i] = group2->type->data[i];
    }
    b_group1->data[group2->type->size[1]] = '\x00';
    b_m2c_error(b_group1);
  }
  b_obj = *(MPI_Group *)(&group2->data->data[0]);
  *info = MPI_Group_translate_ranks(obj, n, &b_ranks1->data[0], b_obj,
                                    &b_ranks2->data[0]);
  emxFree_int32_T(&b_ranks2);
  emxFree_int32_T(&b_ranks1);
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    ptr = (char *)(&msg0[0]);
    resultlen = 0;
    MPI_Error_string(*info, ptr, &resultlen);
    if (1 > resultlen) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)resultlen;
    }
    i = b_group1->size[0] * b_group1->size[1];
    b_group1->size[0] = 1;
    b_group1->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_group1, i);
    resultlen = unnamed_idx_1;
    for (i = 0; i < resultlen; i++) {
      b_group1->data[i] = (signed char)msg0[i];
    }
    c_m2c_error(b_group1);
  }
  emxFree_char_T(&b_group1);
  *toplevel = true;
}

void mpi_Group_translate_ranks_initialize(void)
{
}

void mpi_Group_translate_ranks_terminate(void)
{
}
