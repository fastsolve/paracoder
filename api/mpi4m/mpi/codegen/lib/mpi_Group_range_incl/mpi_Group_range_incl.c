#include "mpi_Group_range_incl.h"
#include "m2c.h"
#include "mpi.h"
#include "mpi4m.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static MPI_Group m2c_castdata(const emxArray_uint8_T *data);
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
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Group.\n", &b_varargin_3->
            data[0]);
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

  M2C_error("MPI:RuntimeError",
            "MPI_Group_range_incl failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static MPI_Group m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Group*)(&data->data[0]);
}

static void m2c_error(void)
{
  M2C_error("mpi_Group_range_incl:OutOfBound", "ranges array is too small.");
}

void mpi_Group_range_incl(const M2C_OpaqueType *group, int n, const
  emxArray_int32_T *ranges, M2C_OpaqueType *newgroup, int *info, boolean_T
  *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_group;
  int i;
  static const char cv[9] = { 'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p' };

  emxArray_uint8_T *data0;
  MPI_Group obj;
  int32_triple * ptr;
  MPI_Group arg;
  static const char x2[9] = { 'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p' };

  char * b_ptr;
  unsigned char msg0[1024];
  short unnamed_idx_1;
  if (ranges->size[0] < 3 * n) {
    m2c_error();
  }

  p = (group->type->size[1] == 9);
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

  emxInit_uint8_T(&data0, 1);
  obj = m2c_castdata(group->data);
  ptr = (int32_triple *)(&ranges->data[0]);
  *info = MPI_Group_range_incl(obj, n, ptr, &arg);
  sizepe = sizeof(MPI_Group);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = newgroup->data->size[0];
  newgroup->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(newgroup->data, i);
  for (i = 0; i < sizepe; i++) {
    newgroup->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = newgroup->type->size[0] * newgroup->type->size[1];
  newgroup->type->size[0] = 1;
  newgroup->type->size[1] = 9;
  emxEnsureCapacity_char_T(newgroup->type, i);
  for (i = 0; i < 9; i++) {
    newgroup->type->data[i] = x2[i];
  }

  newgroup->nitems = 1;
  b_ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    newgroup->data->data[i] = *(b_ptr);
    b_ptr = b_ptr + 1;
  }

  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    b_ptr = (char *)(msg0);
    sizepe = 0;
    MPI_Error_string(*info, b_ptr, &sizepe);
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

void mpi_Group_range_incl_initialize(void)
{
}

void mpi_Group_range_incl_terminate(void)
{
}
