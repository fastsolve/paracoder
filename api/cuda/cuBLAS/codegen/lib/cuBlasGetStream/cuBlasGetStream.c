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
  int varargin_2;
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
  int varargin_4;
  int varargin_5;
  int varargin_6;
  int varargin_7;
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
      varargin_2 = cubHdl->type->size[k];
      if (varargin_2 != 13 * k + 1) {
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

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_cubHdl, 2);
    varargin_2 = b_cubHdl->size[0] * b_cubHdl->size[1];
    b_cubHdl->size[0] = 1;
    b_cubHdl->size[1] = cubHdl->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_cubHdl, varargin_2, (int)sizeof(char));
    k = cubHdl->type->size[1];
    for (varargin_2 = 0; varargin_2 < k; varargin_2++) {
      b_cubHdl->data[b_cubHdl->size[0] * varargin_2] = cubHdl->type->data
        [cubHdl->type->size[0] * varargin_2];
    }

    b_cubHdl->data[b_cubHdl->size[0] * cubHdl->type->size[1]] = '\x00';
    m2c_error(b_cubHdl);
    emxFree_char_T(&b_cubHdl);
  }

  emxInit_uint8_T(&data0, 1);
  varargin_2 = data0->size[0];
  data0->size[0] = cubHdl->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, varargin_2, (int)sizeof(unsigned
    char));
  k = cubHdl->data->size[0];
  for (varargin_2 = 0; varargin_2 < k; varargin_2++) {
    data0->data[varargin_2] = cubHdl->data->data[varargin_2];
  }

  hdl = *(cublasHandle_t*)(&data0->data[0]);
  *errCode = cublasGetStream(hdl, &t_strm);
  sizepe = sizeof(cudaStream_t);
  varargin_2 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, varargin_2, (int)sizeof(unsigned
    char));
  for (varargin_2 = 0; varargin_2 < 12; varargin_2++) {
    t0_type[varargin_2] = cv1[varargin_2];
  }

  varargin_2 = strm->data->size[0];
  strm->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)strm->data, varargin_2, (int)sizeof
                    (unsigned char));
  k = data0->size[0];
  for (varargin_2 = 0; varargin_2 < k; varargin_2++) {
    strm->data->data[varargin_2] = data0->data[varargin_2];
  }

  emxFree_uint8_T(&data0);
  varargin_2 = strm->type->size[0] * strm->type->size[1];
  strm->type->size[0] = 1;
  strm->type->size[1] = 12;
  emxEnsureCapacity((emxArray__common *)strm->type, varargin_2, (int)sizeof(char));
  for (varargin_2 = 0; varargin_2 < 12; varargin_2++) {
    strm->type->data[varargin_2] = t0_type[varargin_2];
  }

  strm->nitems = 1;
  ptr = (char *)(&t_strm);
  for (k = 1; k <= sizepe; k++) {
    strm->data->data[k - 1] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    k = (CUBLAS_STATUS_SUCCESS);
    varargin_2 = (CUBLAS_STATUS_NOT_INITIALIZED);
    sizepe = (CUBLAS_STATUS_ALLOC_FAILED);
    varargin_4 = (CUBLAS_STATUS_INVALID_VALUE);
    varargin_5 = (CUBLAS_STATUS_ARCH_MISMATCH);
    varargin_6 = (CUBLAS_STATUS_MAPPING_ERROR);
    varargin_7 = (CUBLAS_STATUS_EXECUTION_FAILED);
    varargin_8 = (CUBLAS_STATUS_INTERNAL_ERROR);
    p = (k == *errCode);
    if (p) {
      k = 0;
    } else {
      p = (varargin_2 == *errCode);
      if (p) {
        k = 1;
      } else {
        p = (sizepe == *errCode);
        if (p) {
          k = 2;
        } else {
          p = (varargin_4 == *errCode);
          if (p) {
            k = 3;
          } else {
            p = (varargin_5 == *errCode);
            if (p) {
              k = 4;
            } else {
              p = (varargin_6 == *errCode);
              if (p) {
                k = 5;
              } else {
                p = (varargin_7 == *errCode);
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
      varargin_2 = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 22;
      emxEnsureCapacity((emxArray__common *)cstr, varargin_2, (int)sizeof(char));
      for (varargin_2 = 0; varargin_2 < 22; varargin_2++) {
        cstr->data[varargin_2] = cv3[varargin_2];
      }
      break;

     case 1:
      varargin_2 = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 30;
      emxEnsureCapacity((emxArray__common *)cstr, varargin_2, (int)sizeof(char));
      for (varargin_2 = 0; varargin_2 < 30; varargin_2++) {
        cstr->data[varargin_2] = cv4[varargin_2];
      }
      break;

     case 2:
      varargin_2 = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 27;
      emxEnsureCapacity((emxArray__common *)cstr, varargin_2, (int)sizeof(char));
      for (varargin_2 = 0; varargin_2 < 27; varargin_2++) {
        cstr->data[varargin_2] = cv5[varargin_2];
      }
      break;

     case 3:
      varargin_2 = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, varargin_2, (int)sizeof(char));
      for (varargin_2 = 0; varargin_2 < 28; varargin_2++) {
        cstr->data[varargin_2] = cv6[varargin_2];
      }
      break;

     case 4:
      varargin_2 = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, varargin_2, (int)sizeof(char));
      for (varargin_2 = 0; varargin_2 < 28; varargin_2++) {
        cstr->data[varargin_2] = cv7[varargin_2];
      }
      break;

     case 5:
      varargin_2 = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 28;
      emxEnsureCapacity((emxArray__common *)cstr, varargin_2, (int)sizeof(char));
      for (varargin_2 = 0; varargin_2 < 28; varargin_2++) {
        cstr->data[varargin_2] = cv8[varargin_2];
      }
      break;

     case 6:
      varargin_2 = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 31;
      emxEnsureCapacity((emxArray__common *)cstr, varargin_2, (int)sizeof(char));
      for (varargin_2 = 0; varargin_2 < 31; varargin_2++) {
        cstr->data[varargin_2] = cv9[varargin_2];
      }
      break;

     case 7:
      varargin_2 = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 29;
      emxEnsureCapacity((emxArray__common *)cstr, varargin_2, (int)sizeof(char));
      for (varargin_2 = 0; varargin_2 < 29; varargin_2++) {
        cstr->data[varargin_2] = cv10[varargin_2];
      }
      break;

     default:
      varargin_2 = cstr->size[0] * cstr->size[1];
      cstr->size[0] = 1;
      cstr->size[1] = 14;
      emxEnsureCapacity((emxArray__common *)cstr, varargin_2, (int)sizeof(char));
      for (varargin_2 = 0; varargin_2 < 14; varargin_2++) {
        cstr->data[varargin_2] = cv2[varargin_2];
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
