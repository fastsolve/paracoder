#include "mpi_Op_create.h"
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

  M2C_error("MPI:RuntimeError", "MPI_Op_create failed with error message %s\n",
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
            "Incorrect data type %s. Expected MPI_User_function *.\n",
            &b_varargin_3->data[0]);
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

void mpi_Op_create(const struct0_T *func, int commute, struct0_T *op, int *info,
                   boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  int exitg2;
  int i0;
  boolean_T exitg1;
  emxArray_char_T *b_func;
  static const char cv0[19] = { 'M', 'P', 'I', '_', 'U', 's', 'e', 'r', '_', 'f',
    'u', 'n', 'c', 't', 'i', 'o', 'n', ' ', '*' };

  emxArray_uint8_T *data0;
  MPI_User_function * t_func;
  MPI_Op t_op;
  int sizepe;
  char t0_type[11];
  static const char cv1[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  char * ptr;
  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg2 = 0;
    if (resultlen < 2) {
      i0 = func->type->size[resultlen];
      if (i0 != 18 * resultlen + 1) {
        exitg2 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(func->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 19)) {
      if (!(func->type->data[resultlen] == cv0[resultlen])) {
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
    emxInit_char_T(&b_func, 2);
    i0 = b_func->size[0] * b_func->size[1];
    b_func->size[0] = 1;
    b_func->size[1] = func->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_func, i0, (int)sizeof(char));
    resultlen = func->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_func->data[b_func->size[0] * i0] = func->type->data[func->type->size[0] *
        i0];
    }

    b_func->data[b_func->size[0] * func->type->size[1]] = '\x00';
    m2c_error(b_func);
    emxFree_char_T(&b_func);
  }

  emxInit_uint8_T(&data0, 1);
  i0 = data0->size[0];
  data0->size[0] = func->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  resultlen = func->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data0->data[i0] = func->data->data[i0];
  }

  t_func = *(MPI_User_function **)(&data0->data[0]);
  *info = MPI_Op_create(t_func, commute, &t_op);
  *toplevel = true;
  sizepe = sizeof(MPI_Request);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 11; i0++) {
    t0_type[i0] = cv1[i0];
  }

  i0 = op->data->size[0];
  op->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)op->data, i0, (int)sizeof(unsigned char));
  resultlen = data0->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    op->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = op->type->size[0] * op->type->size[1];
  op->type->size[0] = 1;
  op->type->size[1] = 11;
  emxEnsureCapacity((emxArray__common *)op->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 11; i0++) {
    op->type->data[i0] = t0_type[i0];
  }

  op->nitems = 1;
  ptr = (char *)(&t_op);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    op->data->data[resultlen - 1] = *(ptr);
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

    emxInit_char_T(&b_msg0, 2);
    emxInit_uint8_T(&c_msg0, 2);
    i0 = c_msg0->size[0] * c_msg0->size[1];
    c_msg0->size[0] = 1;
    c_msg0->size[1] = resultlen;
    emxEnsureCapacity((emxArray__common *)c_msg0, i0, (int)sizeof(unsigned char));
    for (i0 = 0; i0 < resultlen; i0++) {
      c_msg0->data[c_msg0->size[0] * i0] = msg0[i0];
    }

    emxInit_char_T(&d_msg0, 1);
    i0 = d_msg0->size[0];
    d_msg0->size[0] = resultlen;
    emxEnsureCapacity((emxArray__common *)d_msg0, i0, (int)sizeof(char));
    for (i0 = 0; i0 < resultlen; i0++) {
      d_msg0->data[i0] = (signed char)c_msg0->data[i0];
    }

    emxFree_uint8_T(&c_msg0);
    i0 = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = (short)resultlen;
    emxEnsureCapacity((emxArray__common *)b_msg0, i0, (int)sizeof(char));
    resultlen = (short)resultlen;
    for (i0 = 0; i0 < resultlen; i0++) {
      b_msg0->data[b_msg0->size[0] * i0] = d_msg0->data[i0];
    }

    emxFree_char_T(&d_msg0);
    b_m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }
}

void mpi_Op_create_initialize(void)
{
}

void mpi_Op_create_terminate(void)
{
}
