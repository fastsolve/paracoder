#include "mpi_Group_excl.h"
#include "mpi_Group_excl_types.h"
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
  M2C_error("MPI:RuntimeError", "MPI_Group_excl failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(void)
{
  M2C_error("mpi_Group_excl:OutOfBound", "ranks array is too small.");
}

void mpi_Group_excl(const M2C_OpaqueType *group, int n,
                    const emxArray_int32_T *ranks, M2C_OpaqueType *newgroup,
                    int *info, boolean_T *toplevel)
{
  static const char cv[9] = {'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p'};
  static const char x2[9] = {'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p'};
  MPI_Group arg;
  MPI_Group obj;
  char *ptr;
  emxArray_char_T *b_group;
  int i;
  int sizepe;
  short unnamed_idx_1;
  unsigned char msg0[1024];
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  if (ranks->size[0] < n) {
    m2c_error();
  }
  p = false;
  if (group->type->size[1] == 9) {
    p = true;
  }
  if (p && (group->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 9)) {
      if (!(group->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  b_p = (int)p;
  emxInit_char_T(&b_group, 2);
  if (!b_p) {
    i = b_group->size[0] * b_group->size[1];
    b_group->size[0] = 1;
    b_group->size[1] = group->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_group, i);
    sizepe = group->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_group->data[i] = group->type->data[i];
    }
    b_group->data[group->type->size[1]] = '\x00';
    b_m2c_error(b_group);
  }
  obj = *(MPI_Group *)(&group->data->data[0]);
  *info = MPI_Group_excl(obj, n, &ranks->data[0], &arg);
  sizepe = sizeof(MPI_Group);
  i = newgroup->data->size[0];
  newgroup->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(newgroup->data, i);
  i = newgroup->type->size[0] * newgroup->type->size[1];
  newgroup->type->size[0] = 1;
  newgroup->type->size[1] = 9;
  emxEnsureCapacity_char_T(newgroup->type, i);
  for (i = 0; i < 9; i++) {
    newgroup->type->data[i] = x2[i];
  }
  newgroup->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    newgroup->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    ptr = (char *)(&msg0[0]);
    sizepe = 0;
    MPI_Error_string(*info, ptr, &sizepe);
    if (1 > sizepe) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)sizepe;
    }
    i = b_group->size[0] * b_group->size[1];
    b_group->size[0] = 1;
    b_group->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_group, i);
    sizepe = unnamed_idx_1;
    for (i = 0; i < sizepe; i++) {
      b_group->data[i] = (signed char)msg0[i];
    }
    c_m2c_error(b_group);
  }
  emxFree_char_T(&b_group);
  *toplevel = true;
}

void mpi_Group_excl_initialize(void)
{
}

void mpi_Group_excl_terminate(void)
{
}
