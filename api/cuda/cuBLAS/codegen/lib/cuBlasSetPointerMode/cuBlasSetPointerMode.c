#include "cuBlasSetPointerMode.h"
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

  M2C_error("cuBlas:RuntimeError",
            "cublasSetPointerMode returned error code %s\n", &b_varargin_3->
            data[0]);
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

void cuBlasSetPointerMode(const struct0_T *hdl, int mode, int *errCode,
  boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_hdl;
  static const char cv0[14] = { 'c', 'u', 'b', 'l', 'a', 's', 'H', 'a', 'n', 'd',
    'l', 'e', '_', 't' };

  emxArray_uint8_T *data;
  int val;
  cublasHandle_t c_hdl;
  emxArray_char_T *cstr;
  int b_val;
  int c_val;
  int d_val;
  int e_val;
  int f_val;
  int varargin_8;
  static const char cv1[14] = { 'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'e', 'r',
    'r', 'o', 'r', '\x00' };

  static const char cv2[22] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'S', 'U', 'C', 'C', 'E', 'S', 'S', '\x00' };

  static const char cv3[30] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'N', 'O', 'T', '_', 'I', 'N', 'I', 'T', 'I', 'A', 'L',
    'I', 'Z', 'E', 'D', '\x00' };

  static const char cv4[27] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'A', 'L', 'L', 'O', 'C', '_', 'F', 'A', 'I', 'L', 'E',
    'D', '\x00' };

  static const char cv5[28] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'I', 'N', 'V', 'A', 'L', 'I', 'D', '_', 'V', 'A', 'L',
    'U', 'E', '\x00' };

  static const char cv6[28] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'A', 'R', 'C', 'H', '_', 'M', 'I', 'S', 'M', 'A', 'T',
    'C', 'H', '\x00' };

  static const char cv7[28] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'M', 'A', 'P', 'P', 'I', 'N', 'G', '_', 'E', 'R', 'R',
    'O', 'R', '\x00' };

  static const char cv8[31] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'E', 'X', 'E', 'C', 'U', 'T', 'I', 'O', 'N', '_', 'F',
    'A', 'I', 'L', 'E', 'D', '\x00' };

  static const char cv9[29] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'I', 'N', 'T', 'E', 'R', 'N', 'A', 'L', '_', 'E', 'R',
    'R', 'O', 'R', '\x00' };

  p = false;
  b_p = false;
  if (hdl->type->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (!(hdl->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(hdl->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_hdl, 2);
    val = b_hdl->size[0] * b_hdl->size[1];
    b_hdl->size[0] = 1;
    b_hdl->size[1] = hdl->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_hdl, val, sizeof(char));
    k = hdl->type->size[1];
    for (val = 0; val < k; val++) {
      b_hdl->data[b_hdl->size[0] * val] = hdl->type->data[hdl->type->size[0] *
        val];
    }

    b_hdl->data[b_hdl->size[0] * hdl->type->size[1]] = '\x00';
    m2c_error(b_hdl);
    emxFree_char_T(&b_hdl);
  }

  emxInit_uint8_T(&data, 1);
  val = data->size[0];
  data->size[0] = hdl->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, val, sizeof(unsigned char));
  k = hdl->data->size[0];
  for (val = 0; val < k; val++) {
    data->data[val] = hdl->data->data[val];
  }

  c_hdl = *(cublasHandle_t*)(&data->data[0]);
  *errCode = cublasSetPointerMode(c_hdl, mode);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    emxInit_char_T(&cstr, 2);
    k = (CUBLAS_STATUS_SUCCESS);
    val = (CUBLAS_STATUS_NOT_INITIALIZED);
    b_val = (CUBLAS_STATUS_ALLOC_FAILED);
    c_val = (CUBLAS_STATUS_INVALID_VALUE);
    d_val = (CUBLAS_STATUS_ARCH_MISMATCH);
    e_val = (CUBLAS_STATUS_MAPPING_ERROR);
    f_val = (CUBLAS_STATUS_EXECUTION_FAILED);
    varargin_8 = (CUBLAS_STATUS_INTERNAL_ERROR);
    if (k == *errCode) {
      k = 0;
    } else if (val == *errCode) {
      k = 1;
    } else if (b_val == *errCode) {
      k = 2;
    } else if (c_val == *errCode) {
      k = 3;
    } else if (d_val == *errCode) {
      k = 4;
    } else if (e_val == *errCode) {
      k = 5;
    } else if (f_val == *errCode) {
      k = 6;
    } else if (varargin_8 == *errCode) {
      k = 7;
    } else {
      k = -1;
    }

    switch (k) {
     case 0:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 22;
      emxEnsureCapacity((emxArray__common *)cstr, val, sizeof(char));
      for (val = 0; val < 22; val++) {
        cstr->data[val] = cv2[val];
      }
      break;

     case 1:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 30;
      emxEnsureCapacity((emxArray__common *)cstr, val, sizeof(char));
      for (val = 0; val < 30; val++) {
        cstr->data[val] = cv3[val];
      }
      break;

     case 2:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 27;
      emxEnsureCapacity((emxArray__common *)cstr, val, sizeof(char));
      for (val = 0; val < 27; val++) {
        cstr->data[val] = cv4[val];
      }
      break;

     case 3:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, val, sizeof(char));
      for (val = 0; val < 28; val++) {
        cstr->data[val] = cv5[val];
      }
      break;

     case 4:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, val, sizeof(char));
      for (val = 0; val < 28; val++) {
        cstr->data[val] = cv6[val];
      }
      break;

     case 5:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, val, sizeof(char));
      for (val = 0; val < 28; val++) {
        cstr->data[val] = cv7[val];
      }
      break;

     case 6:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 31;
      emxEnsureCapacity((emxArray__common *)cstr, val, sizeof(char));
      for (val = 0; val < 31; val++) {
        cstr->data[val] = cv8[val];
      }
      break;

     case 7:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 29;
      emxEnsureCapacity((emxArray__common *)cstr, val, sizeof(char));
      for (val = 0; val < 29; val++) {
        cstr->data[val] = cv9[val];
      }
      break;

     default:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 14;
      emxEnsureCapacity((emxArray__common *)cstr, val, sizeof(char));
      for (val = 0; val < 14; val++) {
        cstr->data[val] = cv1[val];
      }
      break;
    }

    b_m2c_error(cstr);
    emxFree_char_T(&cstr);
  }
}

void cuBlasSetPointerMode_initialize(void)
{
}

void cuBlasSetPointerMode_terminate(void)
{
}
