#include "mpi_Group_free.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("MPI:RuntimeError", "MPI_Group_free failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Group.\n", &b_varargin_3->
            data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Group_free(struct0_T *group, int *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  int exitg2;
  int i2;
  boolean_T exitg1;
  emxArray_char_T *b_group;
  static const char cv0[9] = { 'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p' };

  emxArray_uint8_T *data0;
  MPI_Group t_group;
  int sizepe;
  char t0_type[9];
  static const char x2[9] = { 'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p' };

  char * ptr;
  unsigned char msg0[1024];
  emxArray_uint8_T *varargin_1;
  emxArray_char_T *b_varargin_1;
  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg2 = 0;
    if (resultlen < 2) {
      i2 = group->type->size[resultlen];
      if (i2 != (resultlen << 3) + 1) {
        exitg2 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(group->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 9)) {
      if (!(group->type->data[resultlen] == cv0[resultlen])) {
        b_p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_group, 2);
    i2 = b_group->size[0] * b_group->size[1];
    b_group->size[0] = 1;
    b_group->size[1] = group->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_group, i2, (int)sizeof(char));
    resultlen = group->type->size[1];
    for (i2 = 0; i2 < resultlen; i2++) {
      b_group->data[b_group->size[0] * i2] = group->type->data[group->type->
        size[0] * i2];
    }

    b_group->data[b_group->size[0] * group->type->size[1]] = '\x00';
    m2c_error(b_group);
    emxFree_char_T(&b_group);
  }

  emxInit_uint8_T(&data0, 1);
  i2 = data0->size[0];
  data0->size[0] = group->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i2, (int)sizeof(unsigned char));
  resultlen = group->data->size[0];
  for (i2 = 0; i2 < resultlen; i2++) {
    data0->data[i2] = group->data->data[i2];
  }

  t_group = *(MPI_Group*)(&data0->data[0]);
  *info = MPI_Group_free(&t_group);
  *toplevel = true;
  sizepe = sizeof(MPI_Group);
  i2 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i2, (int)sizeof(unsigned char));
  for (i2 = 0; i2 < 9; i2++) {
    t0_type[i2] = x2[i2];
  }

  i2 = group->data->size[0];
  group->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)group->data, i2, (int)sizeof(unsigned
    char));
  resultlen = data0->size[0];
  for (i2 = 0; i2 < resultlen; i2++) {
    group->data->data[i2] = data0->data[i2];
  }

  emxFree_uint8_T(&data0);
  i2 = group->type->size[0] * group->type->size[1];
  group->type->size[0] = 1;
  group->type->size[1] = 9;
  emxEnsureCapacity((emxArray__common *)group->type, i2, (int)sizeof(char));
  for (i2 = 0; i2 < 9; i2++) {
    group->type->data[i2] = t0_type[i2];
  }

  group->nitems = 1;
  ptr = (char *)(&t_group);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    group->data->data[resultlen - 1] = *(ptr);
    ptr = ptr + 1;
  }

  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, ptr, &resultlen);
    if (1 > resultlen) {
      resultlen = 0;
    }

    emxInit_uint8_T(&varargin_1, 2);
    i2 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = resultlen;
    emxEnsureCapacity((emxArray__common *)varargin_1, i2, (int)sizeof(unsigned
      char));
    for (i2 = 0; i2 < resultlen; i2++) {
      varargin_1->data[varargin_1->size[0] * i2] = msg0[i2];
    }

    emxInit_char_T(&b_varargin_1, 2);
    i2 = b_varargin_1->size[0] * b_varargin_1->size[1];
    b_varargin_1->size[0] = 1;
    b_varargin_1->size[1] = (short)resultlen;
    emxEnsureCapacity((emxArray__common *)b_varargin_1, i2, (int)sizeof(char));
    resultlen = (short)resultlen;
    for (i2 = 0; i2 < resultlen; i2++) {
      b_varargin_1->data[i2] = (signed char)varargin_1->data[i2];
    }

    emxFree_uint8_T(&varargin_1);
    b_m2c_error(b_varargin_1);
    emxFree_char_T(&b_varargin_1);
  }
}

void mpi_Group_free_initialize(void)
{
}

void mpi_Group_free_terminate(void)
{
}
