#include "mpi_Group_difference.h"
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("MPI:RuntimeError",
            "MPI_Group_difference failed with error message %s\n",
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Group.\n", &b_varargin_3->
            data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Group_difference(const struct0_T *group1, const struct0_T *group2,
  struct0_T *newgroup, int *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_group1;
  static const char cv0[9] = { 'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p' };

  emxArray_uint8_T *data0;
  int loop_ub;
  MPI_Group obj;
  emxArray_char_T *b_group2;
  MPI_Group b_obj;
  MPI_Group newgroup0;
  int sizepe;
  char t0_type[9];
  static const char x2[9] = { 'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p' };

  char * ptr;
  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  p = false;
  b_p = false;
  if (group1->type->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(group1->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 9)) {
      if (!(group1->type->data[resultlen] == cv0[resultlen])) {
        b_p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_group1, 2);
    resultlen = b_group1->size[0] * b_group1->size[1];
    b_group1->size[0] = 1;
    b_group1->size[1] = group1->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_group1, resultlen, sizeof(char));
    loop_ub = group1->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_group1->data[b_group1->size[0] * resultlen] = group1->type->data
        [group1->type->size[0] * resultlen];
    }

    b_group1->data[b_group1->size[0] * group1->type->size[1]] = '\x00';
    m2c_error(b_group1);
    emxFree_char_T(&b_group1);
  }

  emxInit_uint8_T(&data0, 1);
  resultlen = data0->size[0];
  data0->size[0] = group1->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, resultlen, sizeof(unsigned char));
  loop_ub = group1->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = group1->data->data[resultlen];
  }

  obj = *(MPI_Group*)(&data0->data[0]);
  p = false;
  b_p = false;
  if (group2->type->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(group2->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 9)) {
      if (!(group2->type->data[resultlen] == cv0[resultlen])) {
        b_p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_group2, 2);
    resultlen = b_group2->size[0] * b_group2->size[1];
    b_group2->size[0] = 1;
    b_group2->size[1] = group2->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_group2, resultlen, sizeof(char));
    loop_ub = group2->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_group2->data[b_group2->size[0] * resultlen] = group2->type->data
        [group2->type->size[0] * resultlen];
    }

    b_group2->data[b_group2->size[0] * group2->type->size[1]] = '\x00';
    m2c_error(b_group2);
    emxFree_char_T(&b_group2);
  }

  resultlen = data0->size[0];
  data0->size[0] = group2->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, resultlen, sizeof(unsigned char));
  loop_ub = group2->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = group2->data->data[resultlen];
  }

  b_obj = *(MPI_Group*)(&data0->data[0]);
  *info = MPI_Group_difference(obj, b_obj, &newgroup0);
  sizepe = sizeof(MPI_Group);
  resultlen = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, resultlen, sizeof(unsigned char));
  for (resultlen = 0; resultlen < 9; resultlen++) {
    t0_type[resultlen] = x2[resultlen];
  }

  resultlen = newgroup->data->size[0];
  newgroup->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)newgroup->data, resultlen, sizeof
                    (unsigned char));
  loop_ub = data0->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    newgroup->data->data[resultlen] = data0->data[resultlen];
  }

  emxFree_uint8_T(&data0);
  resultlen = newgroup->type->size[0] * newgroup->type->size[1];
  newgroup->type->size[0] = 1;
  newgroup->type->size[1] = 9;
  emxEnsureCapacity((emxArray__common *)newgroup->type, resultlen, sizeof(char));
  for (resultlen = 0; resultlen < 9; resultlen++) {
    newgroup->type->data[resultlen] = t0_type[resultlen];
  }

  newgroup->nitems = 1;
  ptr = (char *)(&newgroup0);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    newgroup->data->data[resultlen - 1] = *(ptr);
    ptr = ptr + 1;
  }

  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, ptr, &resultlen);
    if (1 > resultlen) {
      loop_ub = 0;
    } else {
      loop_ub = resultlen;
    }

    emxInit_char_T(&b_msg0, 2);
    emxInit_uint8_T(&c_msg0, 2);
    resultlen = c_msg0->size[0] * c_msg0->size[1];
    c_msg0->size[0] = 1;
    c_msg0->size[1] = loop_ub;
    emxEnsureCapacity((emxArray__common *)c_msg0, resultlen, sizeof(unsigned
      char));
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      c_msg0->data[c_msg0->size[0] * resultlen] = msg0[resultlen];
    }

    emxInit_char_T(&d_msg0, 1);
    resultlen = d_msg0->size[0];
    d_msg0->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)d_msg0, resultlen, sizeof(char));
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      d_msg0->data[resultlen] = (signed char)c_msg0->data[resultlen];
    }

    emxFree_uint8_T(&c_msg0);
    resultlen = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = (short)loop_ub;
    emxEnsureCapacity((emxArray__common *)b_msg0, resultlen, sizeof(char));
    loop_ub = (short)loop_ub;
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_msg0->data[b_msg0->size[0] * resultlen] = d_msg0->data[resultlen];
    }

    emxFree_char_T(&d_msg0);
    b_m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }

  *toplevel = true;
}

void mpi_Group_difference_initialize(void)
{
}

void mpi_Group_difference_terminate(void)
{
}
