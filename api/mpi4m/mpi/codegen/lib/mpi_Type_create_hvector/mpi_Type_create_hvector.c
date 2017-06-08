#include "mpi_Type_create_hvector.h"
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
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
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
            "MPI_Type_create_hvector failed with error message %s\n",
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
            "Incorrect data type %s. Expected MPI_Aint.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Type_create_hvector(int count, int blocklen, const struct0_T *stride,
  const struct0_T *oldtype, struct0_T *newtype, int *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_stride;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'A', 'i', 'n', 't' };

  emxArray_uint8_T *data0;
  int loop_ub;
  MPI_Aint output;
  emxArray_char_T *b_oldtype;
  static const char cv1[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  MPI_Datatype datatype;
  MPI_Datatype newtype0;
  int sizepe;
  char t0_type[12];
  static const char x2[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  char * ptr;
  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  p = false;
  b_p = false;
  if (stride->type->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(stride->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 8)) {
      if (!(stride->type->data[resultlen] == cv0[resultlen])) {
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
    emxInit_char_T(&b_stride, 2);
    resultlen = b_stride->size[0] * b_stride->size[1];
    b_stride->size[0] = 1;
    b_stride->size[1] = stride->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_stride, resultlen, sizeof(char));
    loop_ub = stride->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_stride->data[b_stride->size[0] * resultlen] = stride->type->data
        [stride->type->size[0] * resultlen];
    }

    b_stride->data[b_stride->size[0] * stride->type->size[1]] = '\x00';
    m2c_error(b_stride);
    emxFree_char_T(&b_stride);
  }

  emxInit_uint8_T(&data0, 1);
  resultlen = data0->size[0];
  data0->size[0] = stride->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, resultlen, sizeof(unsigned char));
  loop_ub = stride->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = stride->data->data[resultlen];
  }

  output = *(MPI_Aint*)(&data0->data[0]);
  p = false;
  b_p = false;
  if (oldtype->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(oldtype->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(oldtype->type->data[resultlen] == cv1[resultlen])) {
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
    emxInit_char_T(&b_oldtype, 2);
    resultlen = b_oldtype->size[0] * b_oldtype->size[1];
    b_oldtype->size[0] = 1;
    b_oldtype->size[1] = oldtype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_oldtype, resultlen, sizeof(char));
    loop_ub = oldtype->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_oldtype->data[b_oldtype->size[0] * resultlen] = oldtype->type->
        data[oldtype->type->size[0] * resultlen];
    }

    b_oldtype->data[b_oldtype->size[0] * oldtype->type->size[1]] = '\x00';
    b_m2c_error(b_oldtype);
    emxFree_char_T(&b_oldtype);
  }

  resultlen = data0->size[0];
  data0->size[0] = oldtype->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, resultlen, sizeof(unsigned char));
  loop_ub = oldtype->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = oldtype->data->data[resultlen];
  }

  datatype = *(MPI_Datatype*)(&data0->data[0]);
  *info = MPI_Type_create_hvector(count, blocklen, output, datatype, &newtype0);
  sizepe = sizeof(MPI_Datatype);
  resultlen = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, resultlen, sizeof(unsigned char));
  for (resultlen = 0; resultlen < 12; resultlen++) {
    t0_type[resultlen] = x2[resultlen];
  }

  resultlen = newtype->data->size[0];
  newtype->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)newtype->data, resultlen, sizeof
                    (unsigned char));
  loop_ub = data0->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    newtype->data->data[resultlen] = data0->data[resultlen];
  }

  emxFree_uint8_T(&data0);
  resultlen = newtype->type->size[0] * newtype->type->size[1];
  newtype->type->size[0] = 1;
  newtype->type->size[1] = 12;
  emxEnsureCapacity((emxArray__common *)newtype->type, resultlen, sizeof(char));
  for (resultlen = 0; resultlen < 12; resultlen++) {
    newtype->type->data[resultlen] = t0_type[resultlen];
  }

  newtype->nitems = 1;
  ptr = (char *)(&newtype0);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    newtype->data->data[resultlen - 1] = *(ptr);
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
    c_m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }

  *toplevel = true;
}

void mpi_Type_create_hvector_initialize(void)
{
}

void mpi_Type_create_hvector_terminate(void)
{
}
