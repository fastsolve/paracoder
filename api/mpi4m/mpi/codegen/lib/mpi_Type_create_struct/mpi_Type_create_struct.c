#include "mpi_Type_create_struct.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i1;
  int loop_ub;
  char varargin_4[13];
  static const char b_varargin_4[13] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a',
    't', 'y', 'p', 'e', '\x00' };

  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  for (i1 = 0; i1 < 13; i1++) {
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
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("MPI:RuntimeError",
            "MPI_Type_create_struct failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i0;
  int loop_ub;
  char varargin_4[9];
  static const char b_varargin_4[9] = { 'M', 'P', 'I', '_', 'A', 'i', 'n', 't',
    '\x00' };

  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  for (i0 = 0; i0 < 9; i0++) {
    varargin_4[i0] = b_varargin_4[i0];
  }

  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            varargin_4);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Type_create_struct(int count, const emxArray_int32_T *blocklens, const
  struct0_T *indices, const struct0_T *oldtypes, struct0_T *newtype, int *info,
  boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_indices;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'A', 'i', 'n', 't' };

  emxArray_uint8_T *indices0;
  int loop_ub;
  emxArray_char_T *b_oldtypes;
  static const char cv1[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_uint8_T *oldtypes0;
  MPI_Aint * ptr;
  MPI_Datatype * b_ptr;
  MPI_Datatype newtype0;
  int sizepe;
  char t0_type[12];
  static const char x2[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  char * c_ptr;
  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  p = false;
  b_p = false;
  if (indices->type->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(indices->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 8)) {
      if (!(indices->type->data[resultlen] == cv0[resultlen])) {
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
    emxInit_char_T(&b_indices, 2);
    resultlen = b_indices->size[0] * b_indices->size[1];
    b_indices->size[0] = 1;
    b_indices->size[1] = indices->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_indices, resultlen, sizeof(char));
    loop_ub = indices->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_indices->data[b_indices->size[0] * resultlen] = indices->type->
        data[indices->type->size[0] * resultlen];
    }

    b_indices->data[b_indices->size[0] * indices->type->size[1]] = '\x00';
    m2c_error(b_indices);
    emxFree_char_T(&b_indices);
  }

  emxInit_uint8_T(&indices0, 1);
  resultlen = indices0->size[0];
  indices0->size[0] = indices->data->size[0];
  emxEnsureCapacity((emxArray__common *)indices0, resultlen, sizeof(unsigned
    char));
  loop_ub = indices->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    indices0->data[resultlen] = indices->data->data[resultlen];
  }

  p = false;
  b_p = false;
  if (oldtypes->type->size[1] == 12) {
    b_p = true;
  }

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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_oldtypes, 2);
    resultlen = b_oldtypes->size[0] * b_oldtypes->size[1];
    b_oldtypes->size[0] = 1;
    b_oldtypes->size[1] = oldtypes->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_oldtypes, resultlen, sizeof(char));
    loop_ub = oldtypes->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_oldtypes->data[b_oldtypes->size[0] * resultlen] = oldtypes->type->
        data[oldtypes->type->size[0] * resultlen];
    }

    b_oldtypes->data[b_oldtypes->size[0] * oldtypes->type->size[1]] = '\x00';
    b_m2c_error(b_oldtypes);
    emxFree_char_T(&b_oldtypes);
  }

  emxInit_uint8_T(&oldtypes0, 1);
  resultlen = oldtypes0->size[0];
  oldtypes0->size[0] = oldtypes->data->size[0];
  emxEnsureCapacity((emxArray__common *)oldtypes0, resultlen, sizeof(unsigned
    char));
  loop_ub = oldtypes->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    oldtypes0->data[resultlen] = oldtypes->data->data[resultlen];
  }

  ptr = (MPI_Aint *)(&indices0->data[0]);
  b_ptr = (MPI_Datatype *)(&oldtypes0->data[0]);
  *info = MPI_Type_create_struct(count, &blocklens->data[0], ptr, b_ptr,
    &newtype0);

  sizepe = sizeof(MPI_Datatype);
  resultlen = indices0->size[0];
  indices0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)indices0, resultlen, sizeof(unsigned
    char));
  emxFree_uint8_T(&oldtypes0);
  for (resultlen = 0; resultlen < 12; resultlen++) {
    t0_type[resultlen] = x2[resultlen];
  }

  resultlen = newtype->data->size[0];
  newtype->data->size[0] = indices0->size[0];
  emxEnsureCapacity((emxArray__common *)newtype->data, resultlen, sizeof
                    (unsigned char));
  loop_ub = indices0->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    newtype->data->data[resultlen] = indices0->data[resultlen];
  }

  emxFree_uint8_T(&indices0);
  resultlen = newtype->type->size[0] * newtype->type->size[1];
  newtype->type->size[0] = 1;
  newtype->type->size[1] = 12;
  emxEnsureCapacity((emxArray__common *)newtype->type, resultlen, sizeof(char));
  for (resultlen = 0; resultlen < 12; resultlen++) {
    newtype->type->data[resultlen] = t0_type[resultlen];
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
    c_m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }

  *toplevel = true;
}

void mpi_Type_create_struct_initialize(void)
{
}

void mpi_Type_create_struct_terminate(void)
{
}
