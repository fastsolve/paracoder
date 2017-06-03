#include "cuBlasCreate.h"
#include "m2c.h"
#include "cuda4m.h"

static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);

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

  M2C_error("CUDA:RuntimeError", "cublasCreate returned error code %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void cuBlasCreate(struct0_T *hdl, int *errCode, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  cublasHandle_t t_hdl;
  int sizepe;
  int i;
  char t0_type[14];
  static const char cv0[14] = { 'c', 'u', 'b', 'l', 'a', 's', 'H', 'a', 'n', 'd',
    'l', 'e', '_', 't' };

  int loop_ub;
  char * ptr;
  int val;
  int b_val;
  int c_val;
  int d_val;
  int varargin_8;
  boolean_T result;
  emxArray_char_T *cstr;
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

  emxInit_uint8_T(&data0, 1);
  *errCode = cublasCreate(&t_hdl);
  *toplevel = true;
  sizepe = sizeof(cublasHandle_t);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i, (int)sizeof(unsigned char));
  for (i = 0; i < 14; i++) {
    t0_type[i] = cv0[i];
  }

  i = hdl->data->size[0];
  hdl->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)hdl->data, i, (int)sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (i = 0; i < loop_ub; i++) {
    hdl->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = hdl->type->size[0] * hdl->type->size[1];
  hdl->type->size[0] = 1;
  hdl->type->size[1] = 14;
  emxEnsureCapacity((emxArray__common *)hdl->type, i, (int)sizeof(char));
  for (i = 0; i < 14; i++) {
    hdl->type->data[i] = t0_type[i];
  }

  hdl->nitems = 1;
  ptr = (char *)(&t_hdl);
  for (i = 1; i <= sizepe; i++) {
    hdl->data->data[i - 1] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    i = (CUBLAS_STATUS_SUCCESS);
    loop_ub = (CUBLAS_STATUS_NOT_INITIALIZED);
    sizepe = (CUBLAS_STATUS_ALLOC_FAILED);
    val = (CUBLAS_STATUS_INVALID_VALUE);
    b_val = (CUBLAS_STATUS_ARCH_MISMATCH);
    c_val = (CUBLAS_STATUS_MAPPING_ERROR);
    d_val = (CUBLAS_STATUS_EXECUTION_FAILED);
    varargin_8 = (CUBLAS_STATUS_INTERNAL_ERROR);
    result = (i == *errCode);
    if (result) {
      i = 0;
    } else {
      result = (loop_ub == *errCode);
      if (result) {
        i = 1;
      } else {
        result = (sizepe == *errCode);
        if (result) {
          i = 2;
        } else {
          result = (val == *errCode);
          if (result) {
            i = 3;
          } else {
            result = (b_val == *errCode);
            if (result) {
              i = 4;
            } else {
              result = (c_val == *errCode);
              if (result) {
                i = 5;
              } else {
                result = (d_val == *errCode);
                if (result) {
                  i = 6;
                } else {
                  result = (varargin_8 == *errCode);
                  if (result) {
                    i = 7;
                  } else {
                    i = -1;
                  }
                }
              }
            }
          }
        }
      }
    }

    emxInit_char_T(&cstr, 2);
    switch (i) {
     case 0:
      i = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 22;
      emxEnsureCapacity((emxArray__common *)cstr, i, (int)sizeof(char));
      for (i = 0; i < 22; i++) {
        cstr->data[i] = cv2[i];
      }
      break;

     case 1:
      i = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 30;
      emxEnsureCapacity((emxArray__common *)cstr, i, (int)sizeof(char));
      for (i = 0; i < 30; i++) {
        cstr->data[i] = cv3[i];
      }
      break;

     case 2:
      i = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 27;
      emxEnsureCapacity((emxArray__common *)cstr, i, (int)sizeof(char));
      for (i = 0; i < 27; i++) {
        cstr->data[i] = cv4[i];
      }
      break;

     case 3:
      i = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, i, (int)sizeof(char));
      for (i = 0; i < 28; i++) {
        cstr->data[i] = cv5[i];
      }
      break;

     case 4:
      i = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, i, (int)sizeof(char));
      for (i = 0; i < 28; i++) {
        cstr->data[i] = cv6[i];
      }
      break;

     case 5:
      i = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, i, (int)sizeof(char));
      for (i = 0; i < 28; i++) {
        cstr->data[i] = cv7[i];
      }
      break;

     case 6:
      i = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 31;
      emxEnsureCapacity((emxArray__common *)cstr, i, (int)sizeof(char));
      for (i = 0; i < 31; i++) {
        cstr->data[i] = cv8[i];
      }
      break;

     case 7:
      i = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 29;
      emxEnsureCapacity((emxArray__common *)cstr, i, (int)sizeof(char));
      for (i = 0; i < 29; i++) {
        cstr->data[i] = cv9[i];
      }
      break;

     default:
      i = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 14;
      emxEnsureCapacity((emxArray__common *)cstr, i, (int)sizeof(char));
      for (i = 0; i < 14; i++) {
        cstr->data[i] = cv1[i];
      }
      break;
    }

    m2c_error(cstr);
    emxFree_char_T(&cstr);
  }
}

void cuBlasCreate_initialize(void)
{
}

void cuBlasCreate_terminate(void)
{
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}
