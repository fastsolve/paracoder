#include "cuMatCopySubToGPU.h"
#include "m2c.h"
#include "cuda4m.h"

static void b_m2c_error(void);
static void c_m2c_error(void);
static void cuBlasGetErrorString(int errCode, emxArray_char_T *cstr);
static void d_m2c_error(int varargin_3);
static void e_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct1_T(struct1_T *pStruct);
static void emxInitStruct_struct1_T(struct1_T *pStruct);
static void f_m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(void);
static void b_m2c_error(void)
{
  M2C_error("cuMatCopyToGPU:SizeMismatch", "Target matrix is too small.");
}

static void c_m2c_error(void)
{
  M2C_error("cuMatCopyToGPU:SizeMismatch", "Sourcd matrix is too small.");
}

static void cuBlasGetErrorString(int errCode, emxArray_char_T *cstr)
{
  int varargin_1;
  int varargin_2;
  int varargin_3;
  int varargin_4;
  int varargin_5;
  int varargin_6;
  int varargin_7;
  int varargin_8;
  static const char cv0[14] = { 'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'e', 'r',
    'r', 'o', 'r', '\x00' };

  static const char cv1[22] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'S', 'U', 'C', 'C', 'E', 'S', 'S', '\x00' };

  static const char cv2[30] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'N', 'O', 'T', '_', 'I', 'N', 'I', 'T', 'I', 'A', 'L',
    'I', 'Z', 'E', 'D', '\x00' };

  static const char cv3[27] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'A', 'L', 'L', 'O', 'C', '_', 'F', 'A', 'I', 'L', 'E',
    'D', '\x00' };

  static const char cv4[28] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'I', 'N', 'V', 'A', 'L', 'I', 'D', '_', 'V', 'A', 'L',
    'U', 'E', '\x00' };

  static const char cv5[28] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'A', 'R', 'C', 'H', '_', 'M', 'I', 'S', 'M', 'A', 'T',
    'C', 'H', '\x00' };

  static const char cv6[28] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'M', 'A', 'P', 'P', 'I', 'N', 'G', '_', 'E', 'R', 'R',
    'O', 'R', '\x00' };

  static const char cv7[31] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'E', 'X', 'E', 'C', 'U', 'T', 'I', 'O', 'N', '_', 'F',
    'A', 'I', 'L', 'E', 'D', '\x00' };

  static const char cv8[29] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'I', 'N', 'T', 'E', 'R', 'N', 'A', 'L', '_', 'E', 'R',
    'R', 'O', 'R', '\x00' };

  varargin_1 = (CUBLAS_STATUS_SUCCESS);
  varargin_2 = (CUBLAS_STATUS_NOT_INITIALIZED);
  varargin_3 = (CUBLAS_STATUS_ALLOC_FAILED);
  varargin_4 = (CUBLAS_STATUS_INVALID_VALUE);
  varargin_5 = (CUBLAS_STATUS_ARCH_MISMATCH);
  varargin_6 = (CUBLAS_STATUS_MAPPING_ERROR);
  varargin_7 = (CUBLAS_STATUS_EXECUTION_FAILED);
  varargin_8 = (CUBLAS_STATUS_INTERNAL_ERROR);
  if (varargin_1 == errCode) {
    varargin_1 = 0;
  } else if (varargin_2 == errCode) {
    varargin_1 = 1;
  } else if (varargin_3 == errCode) {
    varargin_1 = 2;
  } else if (varargin_4 == errCode) {
    varargin_1 = 3;
  } else if (varargin_5 == errCode) {
    varargin_1 = 4;
  } else if (varargin_6 == errCode) {
    varargin_1 = 5;
  } else if (varargin_7 == errCode) {
    varargin_1 = 6;
  } else if (varargin_8 == errCode) {
    varargin_1 = 7;
  } else {
    varargin_1 = -1;
  }

  switch (varargin_1) {
   case 0:
    varargin_1 = cstr->size[0] * cstr->size[1];
    cstr->size[0] = 1;
    cstr->size[1] = 22;
    emxEnsureCapacity((emxArray__common *)cstr, varargin_1, (int)sizeof(char));
    for (varargin_1 = 0; varargin_1 < 22; varargin_1++) {
      cstr->data[varargin_1] = cv1[varargin_1];
    }
    break;

   case 1:
    varargin_1 = cstr->size[0] * cstr->size[1];
    cstr->size[0] = 1;
    cstr->size[1] = 30;
    emxEnsureCapacity((emxArray__common *)cstr, varargin_1, (int)sizeof(char));
    for (varargin_1 = 0; varargin_1 < 30; varargin_1++) {
      cstr->data[varargin_1] = cv2[varargin_1];
    }
    break;

   case 2:
    varargin_1 = cstr->size[0] * cstr->size[1];
    cstr->size[0] = 1;
    cstr->size[1] = 27;
    emxEnsureCapacity((emxArray__common *)cstr, varargin_1, (int)sizeof(char));
    for (varargin_1 = 0; varargin_1 < 27; varargin_1++) {
      cstr->data[varargin_1] = cv3[varargin_1];
    }
    break;

   case 3:
    varargin_1 = cstr->size[0] * cstr->size[1];
    cstr->size[0] = 1;
    cstr->size[1] = 28;
    emxEnsureCapacity((emxArray__common *)cstr, varargin_1, (int)sizeof(char));
    for (varargin_1 = 0; varargin_1 < 28; varargin_1++) {
      cstr->data[varargin_1] = cv4[varargin_1];
    }
    break;

   case 4:
    varargin_1 = cstr->size[0] * cstr->size[1];
    cstr->size[0] = 1;
    cstr->size[1] = 28;
    emxEnsureCapacity((emxArray__common *)cstr, varargin_1, (int)sizeof(char));
    for (varargin_1 = 0; varargin_1 < 28; varargin_1++) {
      cstr->data[varargin_1] = cv5[varargin_1];
    }
    break;

   case 5:
    varargin_1 = cstr->size[0] * cstr->size[1];
    cstr->size[0] = 1;
    cstr->size[1] = 28;
    emxEnsureCapacity((emxArray__common *)cstr, varargin_1, (int)sizeof(char));
    for (varargin_1 = 0; varargin_1 < 28; varargin_1++) {
      cstr->data[varargin_1] = cv6[varargin_1];
    }
    break;

   case 6:
    varargin_1 = cstr->size[0] * cstr->size[1];
    cstr->size[0] = 1;
    cstr->size[1] = 31;
    emxEnsureCapacity((emxArray__common *)cstr, varargin_1, (int)sizeof(char));
    for (varargin_1 = 0; varargin_1 < 31; varargin_1++) {
      cstr->data[varargin_1] = cv7[varargin_1];
    }
    break;

   case 7:
    varargin_1 = cstr->size[0] * cstr->size[1];
    cstr->size[0] = 1;
    cstr->size[1] = 29;
    emxEnsureCapacity((emxArray__common *)cstr, varargin_1, (int)sizeof(char));
    for (varargin_1 = 0; varargin_1 < 29; varargin_1++) {
      cstr->data[varargin_1] = cv8[varargin_1];
    }
    break;

   default:
    varargin_1 = cstr->size[0] * cstr->size[1];
    cstr->size[0] = 1;
    cstr->size[1] = 14;
    emxEnsureCapacity((emxArray__common *)cstr, varargin_1, (int)sizeof(char));
    for (varargin_1 = 0; varargin_1 < 14; varargin_1++) {
      cstr->data[varargin_1] = cv0[varargin_1];
    }
    break;
  }
}

static void d_m2c_error(int varargin_3)
{
  M2C_error("cuGetSizePerElement:WrongType", "Unknow data type %d.\n",
            varargin_3);
}

static void e_m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("CUDA:RuntimeError", "cublasSetMatrix returned error code %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void emxFreeStruct_struct1_T(struct1_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct1_T(struct1_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
}

static void f_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected cudaStream_t.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(void)
{
  M2C_error("cuMatCopyToGPU:TypeMismatch", "Real and complex numbers mismatch.");
}

void cuMatCopySubToGPU(int nrows, int ncols, const emxArray_real_T *mat, const
  struct0_T *cuMat, int *errCode, boolean_T *toplevel)
{
  int sizepe;
  void * ptr;
  unsigned long data;
  void * output;
  emxArray_char_T *r0;
  *toplevel = true;
  if ((cuMat->type != 8) && (cuMat->type != 4)) {
    m2c_error();
  } else if ((nrows > mat->size[0]) || (ncols > mat->size[0])) {
    b_m2c_error();
  } else {
    if ((nrows > cuMat->dims[0]) || (ncols > cuMat->dims[1])) {
      c_m2c_error();
    }
  }

  if ((cuMat->type == 8) || (cuMat->type == 108) || (cuMat->type == 14) ||
      (cuMat->type == 24)) {
    sizepe = 8;
  } else if ((cuMat->type == 4) || (cuMat->type == 13) || (cuMat->type == 23)) {
    sizepe = 4;
  } else if ((cuMat->type == 12) || (cuMat->type == 22)) {
    sizepe = 2;
  } else if ((cuMat->type == 11) || (cuMat->type == 21)) {
    sizepe = 1;
  } else if (cuMat->type == 116) {
    sizepe = 16;
  } else {
    d_m2c_error(cuMat->type);
    sizepe = 0;
  }

  ptr = (void *)(&mat->data[0]);
  data = cuMat->data;
  output = *(void **)(&data);
  *errCode = cublasSetMatrix(nrows, ncols, sizepe, ptr, mat->size[0], output,
    cuMat->dims[0]);
  if (*errCode != 0) {
    emxInit_char_T(&r0, 2);
    cuBlasGetErrorString(*errCode, r0);
    e_m2c_error(r0);
    emxFree_char_T(&r0);
  }
}

void cuMatCopySubToGPU_async(int nrows, int ncols, const emxArray_real_T *mat,
  const struct0_T *cuMat, const struct1_T *strm, int *errCode, boolean_T
  *toplevel)
{
  int sizepe;
  void * ptr;
  unsigned long data;
  void * output;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i1;
  boolean_T exitg1;
  emxArray_char_T *b_strm;
  static const char cv9[12] = { 'c', 'u', 'd', 'a', 'S', 't', 'r', 'e', 'a', 'm',
    '_', 't' };

  emxArray_uint8_T *b_data;
  cudaStream_t hdl;
  emxArray_char_T *r1;
  if ((cuMat->type != 8) && (cuMat->type != 4)) {
    m2c_error();
  } else if ((nrows > mat->size[0]) || (ncols > mat->size[0])) {
    b_m2c_error();
  } else {
    if ((nrows > cuMat->dims[0]) || (ncols > cuMat->dims[1])) {
      c_m2c_error();
    }
  }

  if ((cuMat->type == 8) || (cuMat->type == 108) || (cuMat->type == 14) ||
      (cuMat->type == 24)) {
    sizepe = 8;
  } else if ((cuMat->type == 4) || (cuMat->type == 13) || (cuMat->type == 23)) {
    sizepe = 4;
  } else if ((cuMat->type == 12) || (cuMat->type == 22)) {
    sizepe = 2;
  } else if ((cuMat->type == 11) || (cuMat->type == 21)) {
    sizepe = 1;
  } else if (cuMat->type == 116) {
    sizepe = 16;
  } else {
    d_m2c_error(cuMat->type);
    sizepe = 0;
  }

  ptr = (void *)(&mat->data[0]);
  data = cuMat->data;
  output = *(void **)(&data);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i1 = strm->type->size[k];
      if (i1 != 11 * k + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(strm->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(strm->type->data[k] == cv9[k])) {
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
    emxInit_char_T(&b_strm, 2);
    i1 = b_strm->size[0] * b_strm->size[1];
    b_strm->size[0] = 1;
    b_strm->size[1] = strm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_strm, i1, (int)sizeof(char));
    k = strm->type->size[1];
    for (i1 = 0; i1 < k; i1++) {
      b_strm->data[b_strm->size[0] * i1] = strm->type->data[strm->type->size[0] *
        i1];
    }

    b_strm->data[b_strm->size[0] * strm->type->size[1]] = '\x00';
    f_m2c_error(b_strm);
    emxFree_char_T(&b_strm);
  }

  emxInit_uint8_T(&b_data, 1);
  i1 = b_data->size[0];
  b_data->size[0] = strm->data->size[0];
  emxEnsureCapacity((emxArray__common *)b_data, i1, (int)sizeof(unsigned char));
  k = strm->data->size[0];
  for (i1 = 0; i1 < k; i1++) {
    b_data->data[i1] = strm->data->data[i1];
  }

  hdl = *(cudaStream_t*)(&b_data->data[0]);
  *errCode = cublasSetMatrixAsync(nrows, ncols, sizepe, ptr, mat->size[0],
    output, cuMat->dims[0], hdl);
  emxFree_uint8_T(&b_data);
  if (*errCode != 0) {
    emxInit_char_T(&r1, 2);
    cuBlasGetErrorString(*errCode, r1);
    e_m2c_error(r1);
    emxFree_char_T(&r1);
  }

  *toplevel = true;
}

void cuMatCopySubToGPU_initialize(void)
{
}

void cuMatCopySubToGPU_terminate(void)
{
}

void emxDestroy_struct1_T(struct1_T emxArray)
{
  emxFreeStruct_struct1_T(&emxArray);
}

void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T(pEmxArray, numDimensions);
}

void emxInit_struct1_T(struct1_T *pStruct)
{
  emxInitStruct_struct1_T(pStruct);
}
