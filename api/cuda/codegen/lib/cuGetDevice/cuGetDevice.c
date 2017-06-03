#include "cuGetDevice.h"
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("CUDA:RuntimeError", "cudaGetDevice returned error code %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void cuGetDevice(int *dev, int *errCode, boolean_T *toplevel)
{
  emxArray_uint8_T *msg0;
  const char * ptr;
  int len;
  int i0;
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  *errCode = cudaGetDevice(dev);
  *toplevel = true;
  if (*errCode != 0) {
    emxInit_uint8_T(&msg0, 2);
    ptr = cudaGetErrorString(*errCode);
    len = strlen(ptr) + 1;
    i0 = msg0->size[0] * msg0->size[1];
    msg0->size[0] = 1;
    msg0->size[1] = len;
    emxEnsureCapacity((emxArray__common *)msg0, i0, (int)sizeof(unsigned char));
    for (i0 = 0; i0 < len; i0++) {
      msg0->data[i0] = 0;
    }

    memcpy(&msg0->data[0], ptr, len);
    if (1 > len) {
      len = 0;
    }

    emxInit_char_T(&b_msg0, 2);
    emxInit_uint8_T(&c_msg0, 2);
    i0 = c_msg0->size[0] * c_msg0->size[1];
    c_msg0->size[0] = 1;
    c_msg0->size[1] = len;
    emxEnsureCapacity((emxArray__common *)c_msg0, i0, (int)sizeof(unsigned char));
    for (i0 = 0; i0 < len; i0++) {
      c_msg0->data[c_msg0->size[0] * i0] = msg0->data[i0];
    }

    emxFree_uint8_T(&msg0);
    emxInit_char_T(&d_msg0, 1);
    i0 = d_msg0->size[0];
    d_msg0->size[0] = len;
    emxEnsureCapacity((emxArray__common *)d_msg0, i0, (int)sizeof(char));
    for (i0 = 0; i0 < len; i0++) {
      d_msg0->data[i0] = (signed char)c_msg0->data[i0];
    }

    emxFree_uint8_T(&c_msg0);
    i0 = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = len;
    emxEnsureCapacity((emxArray__common *)b_msg0, i0, (int)sizeof(char));
    for (i0 = 0; i0 < len; i0++) {
      b_msg0->data[b_msg0->size[0] * i0] = d_msg0->data[i0];
    }

    emxFree_char_T(&d_msg0);
    m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }
}

void cuGetDevice_initialize(void)
{
}

void cuGetDevice_terminate(void)
{
}
