#include "cuStreamHandleCreate.h"
#include "m2c.h"
#include "cuda4m.h"

static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("CUDA:RuntimeError", "cudaStreamCreate returned error code %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void cuStreamHandleCreate(struct0_T *stm, int *errCode, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  cudaStream_t t_stm;
  int sizepe;
  int i0;
  char t0_type[12];
  static const char cv0[12] = { 'c', 'u', 'd', 'a', 'S', 't', 'r', 'e', 'a', 'm',
    '_', 't' };

  int len;
  char * ptr;
  emxArray_uint8_T *msg0;
  const char * b_ptr;
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  emxInit_uint8_T(&data0, 1);
  *errCode = cudaStreamCreate(&t_stm);
  sizepe = sizeof(cudaStream_t);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, sizeof(unsigned char));
  for (i0 = 0; i0 < 12; i0++) {
    t0_type[i0] = cv0[i0];
  }

  i0 = stm->data->size[0];
  stm->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)stm->data, i0, sizeof(unsigned char));
  len = data0->size[0];
  for (i0 = 0; i0 < len; i0++) {
    stm->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = stm->type->size[0] * stm->type->size[1];
  stm->type->size[0] = 1;
  stm->type->size[1] = 12;
  emxEnsureCapacity((emxArray__common *)stm->type, i0, sizeof(char));
  for (i0 = 0; i0 < 12; i0++) {
    stm->type->data[i0] = t0_type[i0];
  }

  stm->nitems = 1;
  ptr = (char *)(&t_stm);
  for (len = 1; len <= sizepe; len++) {
    stm->data->data[len - 1] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    emxInit_uint8_T(&msg0, 2);
    b_ptr = cudaGetErrorString(*errCode);
    len = strlen(b_ptr) + 1;
    i0 = msg0->size[0] * msg0->size[1];
    msg0->size[0] = 1;
    msg0->size[1] = len;
    emxEnsureCapacity((emxArray__common *)msg0, i0, sizeof(unsigned char));
    for (i0 = 0; i0 < len; i0++) {
      msg0->data[i0] = 0;
    }

    memcpy(&msg0->data[0], b_ptr, len);
    if (1 > len) {
      len = 0;
    }

    emxInit_char_T(&b_msg0, 2);
    emxInit_uint8_T(&c_msg0, 2);
    i0 = c_msg0->size[0] * c_msg0->size[1];
    c_msg0->size[0] = 1;
    c_msg0->size[1] = len;
    emxEnsureCapacity((emxArray__common *)c_msg0, i0, sizeof(unsigned char));
    for (i0 = 0; i0 < len; i0++) {
      c_msg0->data[c_msg0->size[0] * i0] = msg0->data[i0];
    }

    emxFree_uint8_T(&msg0);
    emxInit_char_T(&d_msg0, 1);
    i0 = d_msg0->size[0];
    d_msg0->size[0] = len;
    emxEnsureCapacity((emxArray__common *)d_msg0, i0, sizeof(char));
    for (i0 = 0; i0 < len; i0++) {
      d_msg0->data[i0] = (signed char)c_msg0->data[i0];
    }

    emxFree_uint8_T(&c_msg0);
    i0 = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = len;
    emxEnsureCapacity((emxArray__common *)b_msg0, i0, sizeof(char));
    for (i0 = 0; i0 < len; i0++) {
      b_msg0->data[b_msg0->size[0] * i0] = d_msg0->data[i0];
    }

    emxFree_char_T(&d_msg0);
    m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }

  *toplevel = true;
}

void cuStreamHandleCreate_initialize(void)
{
}

void cuStreamHandleCreate_terminate(void)
{
}
