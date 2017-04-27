#include "cuMatCreate.h"
#include "m2c.h"
#include "mcuda.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(int varargin_3);
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

  M2C_error("CUDA:RuntimeError", "cudaMalloc returned error code %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(int varargin_3)
{
  M2C_error("cuGetSizePerElement:WrongType", "Unknow data type %d.\n",
            varargin_3);
}

void cuMatCreate(int m, int n, int type, struct0_T *mat, int *errCode, boolean_T
                 *toplevel)
{
  int sizepe;
  void * t_mat;
  emxArray_uint8_T *msg0;
  const char * ptr;
  int i0;
  emxArray_uint8_T *varargin_1;
  emxArray_char_T *b_varargin_1;
  *toplevel = true;
  if ((type == 8) || (type == 108) || (type == 14) || (type == 24)) {
    sizepe = 8;
  } else if ((type == 4) || (type == 13) || (type == 23)) {
    sizepe = 4;
  } else if ((type == 12) || (type == 22)) {
    sizepe = 2;
  } else if ((type == 11) || (type == 21)) {
    sizepe = 1;
  } else if (type == 116) {
    sizepe = 16;
  } else {
    m2c_error(type);
    sizepe = 0;
  }

  *errCode = cudaMalloc(&t_mat, m * n * sizepe);
  if (*errCode != 0) {
    emxInit_uint8_T(&msg0, 2);
    ptr = cudaGetErrorString(*errCode);
    sizepe = strlen(ptr) + 1;
    i0 = msg0->size[0] * msg0->size[1];
    msg0->size[0] = 1;
    msg0->size[1] = sizepe;
    emxEnsureCapacity((emxArray__common *)msg0, i0, (int)sizeof(unsigned char));
    for (i0 = 0; i0 < sizepe; i0++) {
      msg0->data[i0] = 0;
    }

    memcpy(&msg0->data[0], ptr, sizepe);
    if (1 > sizepe) {
      sizepe = 0;
    }

    emxInit_uint8_T(&varargin_1, 2);
    i0 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = sizepe;
    emxEnsureCapacity((emxArray__common *)varargin_1, i0, (int)sizeof(unsigned
      char));
    for (i0 = 0; i0 < sizepe; i0++) {
      varargin_1->data[varargin_1->size[0] * i0] = msg0->data[i0];
    }

    emxFree_uint8_T(&msg0);
    emxInit_char_T(&b_varargin_1, 2);
    i0 = b_varargin_1->size[0] * b_varargin_1->size[1];
    b_varargin_1->size[0] = 1;
    b_varargin_1->size[1] = sizepe;
    emxEnsureCapacity((emxArray__common *)b_varargin_1, i0, (int)sizeof(char));
    for (i0 = 0; i0 < sizepe; i0++) {
      b_varargin_1->data[i0] = (signed char)varargin_1->data[i0];
    }

    emxFree_uint8_T(&varargin_1);
    b_m2c_error(b_varargin_1);
    emxFree_char_T(&b_varargin_1);
  }

  mat->type = type;
  mat->dims[0] = m;
  mat->dims[1] = n;
  mat->data = *(uint64_T *)(&t_mat);
}

void cuMatCreate_2args(int m, int n, struct0_T *vec, int *errCode, boolean_T
  *toplevel)
{
  void * t_mat;
  emxArray_uint8_T *msg0;
  const char * ptr;
  int len;
  int i2;
  emxArray_uint8_T *varargin_1;
  emxArray_char_T *b_varargin_1;
  *errCode = cudaMalloc(&t_mat, m * n << 3);
  if (*errCode != 0) {
    emxInit_uint8_T(&msg0, 2);
    ptr = cudaGetErrorString(*errCode);
    len = strlen(ptr) + 1;
    i2 = msg0->size[0] * msg0->size[1];
    msg0->size[0] = 1;
    msg0->size[1] = len;
    emxEnsureCapacity((emxArray__common *)msg0, i2, (int)sizeof(unsigned char));
    for (i2 = 0; i2 < len; i2++) {
      msg0->data[i2] = 0;
    }

    memcpy(&msg0->data[0], ptr, len);
    if (1 > len) {
      len = 0;
    }

    emxInit_uint8_T(&varargin_1, 2);
    i2 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = len;
    emxEnsureCapacity((emxArray__common *)varargin_1, i2, (int)sizeof(unsigned
      char));
    for (i2 = 0; i2 < len; i2++) {
      varargin_1->data[varargin_1->size[0] * i2] = msg0->data[i2];
    }

    emxFree_uint8_T(&msg0);
    emxInit_char_T(&b_varargin_1, 2);
    i2 = b_varargin_1->size[0] * b_varargin_1->size[1];
    b_varargin_1->size[0] = 1;
    b_varargin_1->size[1] = len;
    emxEnsureCapacity((emxArray__common *)b_varargin_1, i2, (int)sizeof(char));
    for (i2 = 0; i2 < len; i2++) {
      b_varargin_1->data[i2] = (signed char)varargin_1->data[i2];
    }

    emxFree_uint8_T(&varargin_1);
    b_m2c_error(b_varargin_1);
    emxFree_char_T(&b_varargin_1);
  }

  vec->type = 8;
  vec->dims[0] = m;
  vec->dims[1] = n;
  vec->data = *(uint64_T *)(&t_mat);
  *toplevel = true;
}

void cuMatCreate_initialize(void)
{
}

void cuMatCreate_terminate(void)
{
}
