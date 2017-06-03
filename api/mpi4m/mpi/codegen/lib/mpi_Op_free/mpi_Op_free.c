#include "mpi_Op_free.h"
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

  M2C_error("MPI:RuntimeError", "MPI_Op_free failed with error message %s\n",
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
            "Incorrect data type %s. Expected MPI_Op.\n", &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Op_free(struct0_T *op, int *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  int exitg2;
  int i2;
  boolean_T exitg1;
  emxArray_char_T *b_op;
  static const char cv0[6] = { 'M', 'P', 'I', '_', 'O', 'p' };

  emxArray_uint8_T *data0;
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
      i2 = op->type->size[resultlen];
      if (i2 != 5 * resultlen + 1) {
        exitg2 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(op->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 6)) {
      if (!(op->type->data[resultlen] == cv0[resultlen])) {
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
    emxInit_char_T(&b_op, 2);
    i2 = b_op->size[0] * b_op->size[1];
    b_op->size[0] = 1;
    b_op->size[1] = op->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_op, i2, (int)sizeof(char));
    resultlen = op->type->size[1];
    for (i2 = 0; i2 < resultlen; i2++) {
      b_op->data[b_op->size[0] * i2] = op->type->data[op->type->size[0] * i2];
    }

    b_op->data[b_op->size[0] * op->type->size[1]] = '\x00';
    m2c_error(b_op);
    emxFree_char_T(&b_op);
  }

  emxInit_uint8_T(&data0, 1);
  i2 = data0->size[0];
  data0->size[0] = op->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i2, (int)sizeof(unsigned char));
  resultlen = op->data->size[0];
  for (i2 = 0; i2 < resultlen; i2++) {
    data0->data[i2] = op->data->data[i2];
  }

  t_op = *(MPI_Op*)(&data0->data[0]);
  *info = MPI_Op_free(&t_op);
  *toplevel = true;
  sizepe = sizeof(MPI_Request);
  i2 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i2, (int)sizeof(unsigned char));
  for (i2 = 0; i2 < 11; i2++) {
    t0_type[i2] = cv1[i2];
  }

  i2 = op->data->size[0];
  op->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)op->data, i2, (int)sizeof(unsigned char));
  resultlen = data0->size[0];
  for (i2 = 0; i2 < resultlen; i2++) {
    op->data->data[i2] = data0->data[i2];
  }

  emxFree_uint8_T(&data0);
  i2 = op->type->size[0] * op->type->size[1];
  op->type->size[0] = 1;
  op->type->size[1] = 11;
  emxEnsureCapacity((emxArray__common *)op->type, i2, (int)sizeof(char));
  for (i2 = 0; i2 < 11; i2++) {
    op->type->data[i2] = t0_type[i2];
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
    i2 = c_msg0->size[0] * c_msg0->size[1];
    c_msg0->size[0] = 1;
    c_msg0->size[1] = resultlen;
    emxEnsureCapacity((emxArray__common *)c_msg0, i2, (int)sizeof(unsigned char));
    for (i2 = 0; i2 < resultlen; i2++) {
      c_msg0->data[c_msg0->size[0] * i2] = msg0[i2];
    }

    emxInit_char_T(&d_msg0, 1);
    i2 = d_msg0->size[0];
    d_msg0->size[0] = resultlen;
    emxEnsureCapacity((emxArray__common *)d_msg0, i2, (int)sizeof(char));
    for (i2 = 0; i2 < resultlen; i2++) {
      d_msg0->data[i2] = (signed char)c_msg0->data[i2];
    }

    emxFree_uint8_T(&c_msg0);
    i2 = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = (short)resultlen;
    emxEnsureCapacity((emxArray__common *)b_msg0, i2, (int)sizeof(char));
    resultlen = (short)resultlen;
    for (i2 = 0; i2 < resultlen; i2++) {
      b_msg0->data[b_msg0->size[0] * i2] = d_msg0->data[i2];
    }

    emxFree_char_T(&d_msg0);
    b_m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }
}

void mpi_Op_free_initialize(void)
{
}

void mpi_Op_free_terminate(void)
{
}
