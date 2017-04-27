#include "mpi_Type_create_struct.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  char varargin_4[13];
  static const char b_varargin_4[13] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a',
    't', 'y', 'p', 'e', '\x00' };

  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  for (i2 = 0; i2 < 13; i2++) {
    varargin_4[i2] = b_varargin_4[i2];
  }

  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            varargin_4);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i3;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i3 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i3, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_varargin_3->data[i3] = varargin_3->data[i3];
  }

  M2C_error("MPI:RuntimeError",
            "MPI_Type_create_struct failed with error message %s\n",
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
  char varargin_4[9];
  static const char b_varargin_4[9] = { 'M', 'P', 'I', '_', 'A', 'i', 'n', 't',
    '\x00' };

  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  for (i1 = 0; i1 < 9; i1++) {
    varargin_4[i1] = b_varargin_4[i1];
  }

  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            varargin_4);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void mpi_Type_create_struct(int count, const emxArray_int32_T *blocklens, const
  struct0_T *indices, const struct0_T *oldtypes, struct0_T *newtype, int *info,
  boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  int exitg4;
  int i0;
  boolean_T exitg3;
  emxArray_char_T *b_indices;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'A', 'i', 'n', 't' };

  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_oldtypes;
  static const char cv1[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_uint8_T *data0;
  emxArray_uint8_T *indices0;
  MPI_Datatype newtype0;
  MPI_Aint * ptr;
  MPI_Datatype * b_ptr;
  int sizepe;
  char t0_type[12];
  static const char x2[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  char * c_ptr;
  unsigned char msg0[1024];
  emxArray_uint8_T *varargin_1;
  emxArray_char_T *b_varargin_1;
  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg4 = 0;
    if (resultlen < 2) {
      i0 = indices->type->size[resultlen];
      if (i0 != 7 * resultlen + 1) {
        exitg4 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(indices->type->size[1] == 0))) {
    resultlen = 0;
    exitg3 = false;
    while ((!exitg3) && (resultlen < 8)) {
      if (!(indices->type->data[resultlen] == cv0[resultlen])) {
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
    emxInit_char_T(&b_indices, 2);
    i0 = b_indices->size[0] * b_indices->size[1];
    b_indices->size[0] = 1;
    b_indices->size[1] = indices->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_indices, i0, (int)sizeof(char));
    resultlen = indices->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_indices->data[b_indices->size[0] * i0] = indices->type->data
        [indices->type->size[0] * i0];
    }

    b_indices->data[b_indices->size[0] * indices->type->size[1]] = '\x00';
    m2c_error(b_indices);
    emxFree_char_T(&b_indices);
  }

  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg2 = 0;
    if (resultlen < 2) {
      i0 = oldtypes->type->size[resultlen];
      if (i0 != 11 * resultlen + 1) {
        exitg2 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(oldtypes->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(oldtypes->type->data[resultlen] == cv1[resultlen])) {
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
    emxInit_char_T(&b_oldtypes, 2);
    i0 = b_oldtypes->size[0] * b_oldtypes->size[1];
    b_oldtypes->size[0] = 1;
    b_oldtypes->size[1] = oldtypes->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_oldtypes, i0, (int)sizeof(char));
    resultlen = oldtypes->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_oldtypes->data[b_oldtypes->size[0] * i0] = oldtypes->type->data
        [oldtypes->type->size[0] * i0];
    }

    b_oldtypes->data[b_oldtypes->size[0] * oldtypes->type->size[1]] = '\x00';
    b_m2c_error(b_oldtypes);
    emxFree_char_T(&b_oldtypes);
  }

  emxInit_uint8_T(&data0, 1);
  i0 = data0->size[0];
  data0->size[0] = oldtypes->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  resultlen = oldtypes->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data0->data[i0] = oldtypes->data->data[i0];
  }

  emxInit_uint8_T(&indices0, 1);
  i0 = indices0->size[0];
  indices0->size[0] = indices->data->size[0];
  emxEnsureCapacity((emxArray__common *)indices0, i0, (int)sizeof(unsigned char));
  resultlen = indices->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    indices0->data[i0] = indices->data->data[i0];
  }

  ptr = (MPI_Aint *)(&indices0->data[0]);
  b_ptr = (MPI_Datatype *)(&data0->data[0]);
  *info = MPI_Type_create_struct(count, &blocklens->data[0], ptr, b_ptr,
    &newtype0);

  *toplevel = true;
  sizepe = sizeof(MPI_Datatype);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  emxFree_uint8_T(&indices0);
  for (i0 = 0; i0 < 12; i0++) {
    t0_type[i0] = x2[i0];
  }

  i0 = newtype->data->size[0];
  newtype->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)newtype->data, i0, (int)sizeof(unsigned
    char));
  resultlen = data0->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    newtype->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = newtype->type->size[0] * newtype->type->size[1];
  newtype->type->size[0] = 1;
  newtype->type->size[1] = 12;
  emxEnsureCapacity((emxArray__common *)newtype->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 12; i0++) {
    newtype->type->data[i0] = t0_type[i0];
  }

  newtype->nitems = 1;
  c_ptr = (char *)(&newtype0);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    newtype->data->data[resultlen - 1] = *(c_ptr);
    c_ptr = c_ptr + 1;
  }

  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    c_ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, c_ptr, &resultlen);
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
    c_m2c_error(b_varargin_1);
    emxFree_char_T(&b_varargin_1);
  }
}

void mpi_Type_create_struct_initialize(void)
{
}

void mpi_Type_create_struct_terminate(void)
{
}
