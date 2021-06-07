#include "mpi_Group_compare.h"
#include "mpi_Group_compare_types.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);

static boolean_T isequal(const emxArray_char_T *varargin_1);

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
  M2C_error("MPI:RuntimeError",
            "MPI_Group_compare failed with error message %s\n",
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
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Group.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Group_compare(const M2C_OpaqueType *group1,
                       const M2C_OpaqueType *group2, int *result, int *info,
                       boolean_T *toplevel)
{
  MPI_Group b_obj;
  MPI_Group obj;
  emxArray_char_T *b_group1;
  int i;
  int resultlen;
  unsigned char msg0[1024];
  char *ptr;
  short unnamed_idx_1;
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
    m2c_error(b_group1);
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
    m2c_error(b_group1);
  }
  b_obj = *(MPI_Group *)(&group2->data->data[0]);
  *info = MPI_Group_compare(obj, b_obj, result);
  *toplevel = true;
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
    b_m2c_error(b_group1);
  }
  emxFree_char_T(&b_group1);
}

void mpi_Group_compare_initialize(void)
{
}

void mpi_Group_compare_terminate(void)
{
}
