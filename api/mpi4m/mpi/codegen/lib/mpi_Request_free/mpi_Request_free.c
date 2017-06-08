#include "mpi_Request_free.h"
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
            "MPI_Request_free failed with error message %s\n",
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
            "Incorrect data type %s. Expected MPI_Request.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Request_free(struct0_T *req, int *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_req;
  static const char cv0[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  emxArray_uint8_T *data0;
  int loop_ub;
  MPI_Request t_req;
  int sizepe;
  char t0_type[11];
  static const char x2[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  char * ptr;
  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  p = false;
  b_p = false;
  if (req->type->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(req->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 11)) {
      if (!(req->type->data[resultlen] == cv0[resultlen])) {
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
    emxInit_char_T(&b_req, 2);
    resultlen = b_req->size[0] * b_req->size[1];
    b_req->size[0] = 1;
    b_req->size[1] = req->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_req, resultlen, sizeof(char));
    loop_ub = req->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_req->data[b_req->size[0] * resultlen] = req->type->data[req->type->size
        [0] * resultlen];
    }

    b_req->data[b_req->size[0] * req->type->size[1]] = '\x00';
    m2c_error(b_req);
    emxFree_char_T(&b_req);
  }

  emxInit_uint8_T(&data0, 1);
  resultlen = data0->size[0];
  data0->size[0] = req->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, resultlen, sizeof(unsigned char));
  loop_ub = req->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data0->data[resultlen] = req->data->data[resultlen];
  }

  t_req = *(MPI_Request*)(&data0->data[0]);
  *info = MPI_Request_free(&t_req);
  *toplevel = true;
  sizepe = sizeof(MPI_Request);
  resultlen = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, resultlen, sizeof(unsigned char));
  for (resultlen = 0; resultlen < 11; resultlen++) {
    t0_type[resultlen] = x2[resultlen];
  }

  resultlen = req->data->size[0];
  req->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)req->data, resultlen, sizeof(unsigned
    char));
  loop_ub = data0->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    req->data->data[resultlen] = data0->data[resultlen];
  }

  emxFree_uint8_T(&data0);
  resultlen = req->type->size[0] * req->type->size[1];
  req->type->size[0] = 1;
  req->type->size[1] = 11;
  emxEnsureCapacity((emxArray__common *)req->type, resultlen, sizeof(char));
  for (resultlen = 0; resultlen < 11; resultlen++) {
    req->type->data[resultlen] = t0_type[resultlen];
  }

  req->nitems = 1;
  ptr = (char *)(&t_req);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    req->data->data[resultlen - 1] = *(ptr);
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
}

void mpi_Request_free_initialize(void)
{
}

void mpi_Request_free_terminate(void)
{
}
