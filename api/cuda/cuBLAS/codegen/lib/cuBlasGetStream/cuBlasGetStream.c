#include "cuBlasGetStream.h"
#include "m2c.h"
#include "cuda4m.h"

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

  M2C_error("CUDA:RuntimeError", "cublasGetStream returned error code %s\n",
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
            "Incorrect data type %s. Expected cublasHandle_t.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void cuBlasGetStream(const struct0_T *cubHdl, struct0_T *strm, int *errCode,
                     boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_cubHdl;
  static const char cv0[14] = { 'c', 'u', 'b', 'l', 'a', 's', 'H', 'a', 'n', 'd',
    'l', 'e', '_', 't' };

  emxArray_uint8_T *data0;
  int loop_ub;
  cublasHandle_t hdl;
  cudaStream_t t_strm;
  int sizepe;
  char t0_type[12];
  static const char cv1[12] = { 'c', 'u', 'd', 'a', 'S', 't', 'r', 'e', 'a', 'm',
    '_', 't' };

  char * ptr;
  emxArray_char_T *cstr;
  int val;
  int b_val;
  int c_val;
  int d_val;
  int varargin_8;
  static const char cv2[14] = { 'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'e', 'r',
    'r', 'o', 'r', '\x00' };

  static const char cv3[22] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'S', 'U', 'C', 'C', 'E', 'S', 'S', '\x00' };

  static const char cv4[30] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'N', 'O', 'T', '_', 'I', 'N', 'I', 'T', 'I', 'A', 'L',
    'I', 'Z', 'E', 'D', '\x00' };

  static const char cv5[27] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'A', 'L', 'L', 'O', 'C', '_', 'F', 'A', 'I', 'L', 'E',
    'D', '\x00' };

  static const char cv6[28] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'I', 'N', 'V', 'A', 'L', 'I', 'D', '_', 'V', 'A', 'L',
    'U', 'E', '\x00' };

  static const char cv7[28] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'A', 'R', 'C', 'H', '_', 'M', 'I', 'S', 'M', 'A', 'T',
    'C', 'H', '\x00' };

  static const char cv8[28] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'M', 'A', 'P', 'P', 'I', 'N', 'G', '_', 'E', 'R', 'R',
    'O', 'R', '\x00' };

  static const char cv9[31] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'E', 'X', 'E', 'C', 'U', 'T', 'I', 'O', 'N', '_', 'F',
    'A', 'I', 'L', 'E', 'D', '\x00' };

  static const char cv10[29] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T',
    'A', 'T', 'U', 'S', '_', 'I', 'N', 'T', 'E', 'R', 'N', 'A', 'L', '_', 'E',
    'R', 'R', 'O', 'R', '\x00' };

  p = false;
  b_p = false;
  if (cubHdl->type->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (!(cubHdl->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(cubHdl->type->data[k] == cv0[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_cubHdl, 2);
    k = b_cubHdl->size[0] * b_cubHdl->size[1];
    b_cubHdl->size[0] = 1;
    b_cubHdl->size[1] = cubHdl->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_cubHdl, k, sizeof(char));
    loop_ub = cubHdl->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_cubHdl->data[b_cubHdl->size[0] * k] = cubHdl->type->data[cubHdl->
        type->size[0] * k];
    }

    b_cubHdl->data[b_cubHdl->size[0] * cubHdl->type->size[1]] = '\x00';
    m2c_error(b_cubHdl);
    emxFree_char_T(&b_cubHdl);
  }

  emxInit_uint8_T(&data0, 1);
  k = data0->size[0];
  data0->size[0] = cubHdl->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, k, sizeof(unsigned char));
  loop_ub = cubHdl->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data0->data[k] = cubHdl->data->data[k];
  }

  hdl = *(cublasHandle_t*)(&data0->data[0]);
  *errCode = cublasGetStream(hdl, &t_strm);
  sizepe = sizeof(cudaStream_t);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, k, sizeof(unsigned char));
  for (k = 0; k < 12; k++) {
    t0_type[k] = cv1[k];
  }

  k = strm->data->size[0];
  strm->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)strm->data, k, sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (k = 0; k < loop_ub; k++) {
    strm->data->data[k] = data0->data[k];
  }

  emxFree_uint8_T(&data0);
  k = strm->type->size[0] * strm->type->size[1];
  strm->type->size[0] = 1;
  strm->type->size[1] = 12;
  emxEnsureCapacity((emxArray__common *)strm->type, k, sizeof(char));
  for (k = 0; k < 12; k++) {
    strm->type->data[k] = t0_type[k];
  }

  strm->nitems = 1;
  ptr = (char *)(&t_strm);
  for (k = 1; k <= sizepe; k++) {
    strm->data->data[k - 1] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    emxInit_char_T(&cstr, 2);
    k = (CUBLAS_STATUS_SUCCESS);
    loop_ub = (CUBLAS_STATUS_NOT_INITIALIZED);
    sizepe = (CUBLAS_STATUS_ALLOC_FAILED);
    val = (CUBLAS_STATUS_INVALID_VALUE);
    b_val = (CUBLAS_STATUS_ARCH_MISMATCH);
    c_val = (CUBLAS_STATUS_MAPPING_ERROR);
    d_val = (CUBLAS_STATUS_EXECUTION_FAILED);
    varargin_8 = (CUBLAS_STATUS_INTERNAL_ERROR);
    if (k == *errCode) {
      k = 0;
    } else if (loop_ub == *errCode) {
      k = 1;
    } else if (sizepe == *errCode) {
      k = 2;
    } else if (val == *errCode) {
      k = 3;
    } else if (b_val == *errCode) {
      k = 4;
    } else if (c_val == *errCode) {
      k = 5;
    } else if (d_val == *errCode) {
      k = 6;
    } else if (varargin_8 == *errCode) {
      k = 7;
    } else {
      k = -1;
    }

    switch (k) {
     case 0:
      k = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 22;
      emxEnsureCapacity((emxArray__common *)cstr, k, sizeof(char));
      for (k = 0; k < 22; k++) {
        cstr->data[k] = cv3[k];
      }
      break;

     case 1:
      k = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 30;
      emxEnsureCapacity((emxArray__common *)cstr, k, sizeof(char));
      for (k = 0; k < 30; k++) {
        cstr->data[k] = cv4[k];
      }
      break;

     case 2:
      k = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 27;
      emxEnsureCapacity((emxArray__common *)cstr, k, sizeof(char));
      for (k = 0; k < 27; k++) {
        cstr->data[k] = cv5[k];
      }
      break;

     case 3:
      k = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, k, sizeof(char));
      for (k = 0; k < 28; k++) {
        cstr->data[k] = cv6[k];
      }
      break;

     case 4:
      k = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, k, sizeof(char));
      for (k = 0; k < 28; k++) {
        cstr->data[k] = cv7[k];
      }
      break;

     case 5:
      k = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, k, sizeof(char));
      for (k = 0; k < 28; k++) {
        cstr->data[k] = cv8[k];
      }
      break;

     case 6:
      k = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 31;
      emxEnsureCapacity((emxArray__common *)cstr, k, sizeof(char));
      for (k = 0; k < 31; k++) {
        cstr->data[k] = cv9[k];
      }
      break;

     case 7:
      k = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 29;
      emxEnsureCapacity((emxArray__common *)cstr, k, sizeof(char));
      for (k = 0; k < 29; k++) {
        cstr->data[k] = cv10[k];
      }
      break;

     default:
      k = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 14;
      emxEnsureCapacity((emxArray__common *)cstr, k, sizeof(char));
      for (k = 0; k < 14; k++) {
        cstr->data[k] = cv2[k];
      }
      break;
    }

    b_m2c_error(cstr);
    emxFree_char_T(&cstr);
  }

  *toplevel = true;
}

void cuBlasGetStream_initialize(void)
{
}

void cuBlasGetStream_terminate(void)
{
}
