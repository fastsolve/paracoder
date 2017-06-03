#include "cuBlasGetStream.h"
#include "m2c.h"
#include "cuda4m.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
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

  M2C_error("CUDA:RuntimeError", "cublasGetStream returned error code %s\n",
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
            "Incorrect data type %s. Expected cublasHandle_t.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void cuBlasGetStream(const struct0_T *cubHdl, struct0_T *strm, int *errCode,
                     boolean_T *toplevel)
{
  cudaStream_t t_strm;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int val;
  boolean_T exitg1;
  emxArray_char_T *b_cubHdl;
  static const char cv0[14] = { 'c', 'u', 'b', 'l', 'a', 's', 'H', 'a', 'n', 'd',
    'l', 'e', '_', 't' };

  emxArray_uint8_T *data0;
  cublasHandle_t hdl;
  int sizepe;
  char t0_type[12];
  static const char cv1[12] = { 'c', 'u', 'd', 'a', 'S', 't', 'r', 'e', 'a', 'm',
    '_', 't' };

  char * ptr;
  int b_val;
  int c_val;
  int d_val;
  int e_val;
  int varargin_8;
  emxArray_char_T *cstr;
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

  *toplevel = true;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      val = cubHdl->type->size[k];
      if (val != 13 * k + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

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
    val = b_cubHdl->size[0] * b_cubHdl->size[1];
    b_cubHdl->size[0] = 1;
    b_cubHdl->size[1] = cubHdl->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_cubHdl, val, (int)sizeof(char));
    k = cubHdl->type->size[1];
    for (val = 0; val < k; val++) {
      b_cubHdl->data[b_cubHdl->size[0] * val] = cubHdl->type->data[cubHdl->
        type->size[0] * val];
    }

    b_cubHdl->data[b_cubHdl->size[0] * cubHdl->type->size[1]] = '\x00';
    m2c_error(b_cubHdl);
    emxFree_char_T(&b_cubHdl);
  }

  emxInit_uint8_T(&data0, 1);
  val = data0->size[0];
  data0->size[0] = cubHdl->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, val, (int)sizeof(unsigned char));
  k = cubHdl->data->size[0];
  for (val = 0; val < k; val++) {
    data0->data[val] = cubHdl->data->data[val];
  }

  hdl = *(cublasHandle_t*)(&data0->data[0]);
  *errCode = cublasGetStream(hdl, &t_strm);
  sizepe = sizeof(cudaStream_t);
  val = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, val, (int)sizeof(unsigned char));
  for (val = 0; val < 12; val++) {
    t0_type[val] = cv1[val];
  }

  val = strm->data->size[0];
  strm->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)strm->data, val, (int)sizeof(unsigned
    char));
  k = data0->size[0];
  for (val = 0; val < k; val++) {
    strm->data->data[val] = data0->data[val];
  }

  emxFree_uint8_T(&data0);
  val = strm->type->size[0] * strm->type->size[1];
  strm->type->size[0] = 1;
  strm->type->size[1] = 12;
  emxEnsureCapacity((emxArray__common *)strm->type, val, (int)sizeof(char));
  for (val = 0; val < 12; val++) {
    strm->type->data[val] = t0_type[val];
  }

  strm->nitems = 1;
  ptr = (char *)(&t_strm);
  for (k = 1; k <= sizepe; k++) {
    strm->data->data[k - 1] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    k = (CUBLAS_STATUS_SUCCESS);
    val = (CUBLAS_STATUS_NOT_INITIALIZED);
    sizepe = (CUBLAS_STATUS_ALLOC_FAILED);
    b_val = (CUBLAS_STATUS_INVALID_VALUE);
    c_val = (CUBLAS_STATUS_ARCH_MISMATCH);
    d_val = (CUBLAS_STATUS_MAPPING_ERROR);
    e_val = (CUBLAS_STATUS_EXECUTION_FAILED);
    varargin_8 = (CUBLAS_STATUS_INTERNAL_ERROR);
    p = (k == *errCode);
    if (p) {
      k = 0;
    } else {
      p = (val == *errCode);
      if (p) {
        k = 1;
      } else {
        p = (sizepe == *errCode);
        if (p) {
          k = 2;
        } else {
          p = (b_val == *errCode);
          if (p) {
            k = 3;
          } else {
            p = (c_val == *errCode);
            if (p) {
              k = 4;
            } else {
              p = (d_val == *errCode);
              if (p) {
                k = 5;
              } else {
                p = (e_val == *errCode);
                if (p) {
                  k = 6;
                } else {
                  p = (varargin_8 == *errCode);
                  if (p) {
                    k = 7;
                  } else {
                    k = -1;
                  }
                }
              }
            }
          }
        }
      }
    }

    emxInit_char_T(&cstr, 2);
    switch (k) {
     case 0:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 22;
      emxEnsureCapacity((emxArray__common *)cstr, val, (int)sizeof(char));
      for (val = 0; val < 22; val++) {
        cstr->data[val] = cv3[val];
      }
      break;

     case 1:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 30;
      emxEnsureCapacity((emxArray__common *)cstr, val, (int)sizeof(char));
      for (val = 0; val < 30; val++) {
        cstr->data[val] = cv4[val];
      }
      break;

     case 2:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 27;
      emxEnsureCapacity((emxArray__common *)cstr, val, (int)sizeof(char));
      for (val = 0; val < 27; val++) {
        cstr->data[val] = cv5[val];
      }
      break;

     case 3:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, val, (int)sizeof(char));
      for (val = 0; val < 28; val++) {
        cstr->data[val] = cv6[val];
      }
      break;

     case 4:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, val, (int)sizeof(char));
      for (val = 0; val < 28; val++) {
        cstr->data[val] = cv7[val];
      }
      break;

     case 5:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, val, (int)sizeof(char));
      for (val = 0; val < 28; val++) {
        cstr->data[val] = cv8[val];
      }
      break;

     case 6:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 31;
      emxEnsureCapacity((emxArray__common *)cstr, val, (int)sizeof(char));
      for (val = 0; val < 31; val++) {
        cstr->data[val] = cv9[val];
      }
      break;

     case 7:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 29;
      emxEnsureCapacity((emxArray__common *)cstr, val, (int)sizeof(char));
      for (val = 0; val < 29; val++) {
        cstr->data[val] = cv10[val];
      }
      break;

     default:
      val = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 14;
      emxEnsureCapacity((emxArray__common *)cstr, val, (int)sizeof(char));
      for (val = 0; val < 14; val++) {
        cstr->data[val] = cv2[val];
      }
      break;
    }

    b_m2c_error(cstr);
    emxFree_char_T(&cstr);
  }
}

void cuBlasGetStream_initialize(void)
{
}

void cuBlasGetStream_terminate(void)
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
