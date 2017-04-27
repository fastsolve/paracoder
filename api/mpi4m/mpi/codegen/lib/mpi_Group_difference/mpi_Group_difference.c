#include "mpi_Group_difference.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("MPI:RuntimeError",
            "MPI_Group_difference failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
}

static void m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Group.\n", &b_varargin_3->
            data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void mpi_Group_difference(const struct0_T *group1, const struct0_T *group2,
  struct0_T *newgroup, int *info, boolean_T *toplevel)
{
  MPI_Group newgroup0;
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  int exitg4;
  int i0;
  boolean_T exitg3;
  emxArray_char_T *b_group1;
  static const char cv0[9] = { 'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p' };

  emxArray_uint8_T *data0;
  MPI_Group obj;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_group2;
  MPI_Group b_obj;
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
    exitg4 = 0;
    if (resultlen < 2) {
      i0 = group1->type->size[resultlen];
      if (i0 != (resultlen << 3) + 1) {
        exitg4 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(group1->type->size[1] == 0))) {
    resultlen = 0;
    exitg3 = false;
    while ((!exitg3) && (resultlen < 9)) {
      if (!(group1->type->data[resultlen] == cv0[resultlen])) {
        b_p = false;
        exitg3 = true;
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
    emxInit_char_T(&b_group1, 2);
    i0 = b_group1->size[0] * b_group1->size[1];
    b_group1->size[0] = 1;
    b_group1->size[1] = group1->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_group1, i0, (int)sizeof(char));
    resultlen = group1->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_group1->data[b_group1->size[0] * i0] = group1->type->data[group1->
        type->size[0] * i0];
    }

    b_group1->data[b_group1->size[0] * group1->type->size[1]] = '\x00';
    m2c_error(b_group1);
    emxFree_char_T(&b_group1);
  }

  emxInit_uint8_T(&data0, 1);
  i0 = data0->size[0];
  data0->size[0] = group1->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  resultlen = group1->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data0->data[i0] = group1->data->data[i0];
  }

  obj = *(MPI_Group*)(&data0->data[0]);
  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg2 = 0;
    if (resultlen < 2) {
      i0 = group2->type->size[resultlen];
      if (i0 != (resultlen << 3) + 1) {
        exitg2 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

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

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_group2, 2);
    i0 = b_group2->size[0] * b_group2->size[1];
    b_group2->size[0] = 1;
    b_group2->size[1] = group2->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_group2, i0, (int)sizeof(char));
    resultlen = group2->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_group2->data[b_group2->size[0] * i0] = group2->type->data[group2->
        type->size[0] * i0];
    }

    b_group2->data[b_group2->size[0] * group2->type->size[1]] = '\x00';
    m2c_error(b_group2);
    emxFree_char_T(&b_group2);
  }

  i0 = data0->size[0];
  data0->size[0] = group2->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  resultlen = group2->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data0->data[i0] = group2->data->data[i0];
  }

  b_obj = *(MPI_Group*)(&data0->data[0]);
  *info = MPI_Group_difference(obj, b_obj, &newgroup0);
  *toplevel = true;
  sizepe = sizeof(MPI_Group);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 9; i0++) {
    t0_type[i0] = x2[i0];
  }

  i0 = newgroup->data->size[0];
  newgroup->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)newgroup->data, i0, (int)sizeof(unsigned
    char));
  resultlen = data0->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    newgroup->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = newgroup->type->size[0] * newgroup->type->size[1];
  newgroup->type->size[0] = 1;
  newgroup->type->size[1] = 9;
  emxEnsureCapacity((emxArray__common *)newgroup->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 9; i0++) {
    newgroup->type->data[i0] = t0_type[i0];
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
      resultlen = 0;
    }

    emxInit_uint8_T(&varargin_1, 2);
    i0 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = resultlen;
    emxEnsureCapacity((emxArray__common *)varargin_1, i0, (int)sizeof(unsigned
      char));
    for (i0 = 0; i0 < resultlen; i0++) {
      varargin_1->data[varargin_1->size[0] * i0] = msg0[i0];
    }

    emxInit_char_T(&b_varargin_1, 2);
    i0 = b_varargin_1->size[0] * b_varargin_1->size[1];
    b_varargin_1->size[0] = 1;
    b_varargin_1->size[1] = (short)resultlen;
    emxEnsureCapacity((emxArray__common *)b_varargin_1, i0, (int)sizeof(char));
    resultlen = (short)resultlen;
    for (i0 = 0; i0 < resultlen; i0++) {
      b_varargin_1->data[i0] = (signed char)varargin_1->data[i0];
    }

    emxFree_uint8_T(&varargin_1);
    b_m2c_error(b_varargin_1);
    emxFree_char_T(&b_varargin_1);
  }
}

void mpi_Group_difference_initialize(void)
{
}

void mpi_Group_difference_terminate(void)
{
}
