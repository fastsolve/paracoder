#include "mpi_Waitany.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(void);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i0;
  int loop_ub;
  char varargin_4[12];
  static const char b_varargin_4[12] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u',
    'e', 's', 't', '\x00' };

  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  for (i0 = 0; i0 < 12; i0++) {
    varargin_4[i0] = b_varargin_4[i0];
  }

  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            varargin_4);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("MPI:RuntimeError", "MPI_Waitany failed with error message %s\n",
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

static void m2c_error(void)
{
  M2C_error("mpi_Waitany:OutOfBound", "MPI_Request_array is too small.");
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void mpi_Waitany(int count, struct0_T *reqs, int *idx, struct0_T *stat, int
                 *info, boolean_T *toplevel)
{
  int resultlen;
  boolean_T p;
  boolean_T b_p;
  int exitg2;
  int i2;
  boolean_T exitg1;
  emxArray_char_T *b_reqs;
  static const char cv0[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  emxArray_uint8_T *reqs0;
  emxArray_uint8_T *data0;
  MPI_Status stat0;
  MPI_Request * ptr;
  int sizepe;
  char t0_type[10];
  static const char cv1[10] = { 'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u', 's'
  };

  char * b_ptr;
  char t1_type[11];
  static const char x2[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  unsigned char msg0[1024];
  emxArray_uint8_T *varargin_1;
  emxArray_char_T *b_varargin_1;
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    resultlen = sizeof(MPI_Request);
    if (reqs->data->size[0] < count * resultlen) {
      m2c_error();
    }
  }

  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg2 = 0;
    if (resultlen < 2) {
      i2 = reqs->type->size[resultlen];
      if (i2 != 10 * resultlen + 1) {
        exitg2 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(reqs->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 11)) {
      if (!(reqs->type->data[resultlen] == cv0[resultlen])) {
        b_p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_reqs, 2);
    i2 = b_reqs->size[0] * b_reqs->size[1];
    b_reqs->size[0] = 1;
    b_reqs->size[1] = reqs->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_reqs, i2, (int)sizeof(char));
    resultlen = reqs->type->size[1];
    for (i2 = 0; i2 < resultlen; i2++) {
      b_reqs->data[b_reqs->size[0] * i2] = reqs->type->data[reqs->type->size[0] *
        i2];
    }

    b_reqs->data[b_reqs->size[0] * reqs->type->size[1]] = '\x00';
    b_m2c_error(b_reqs);
    emxFree_char_T(&b_reqs);
  }

  emxInit_uint8_T(&reqs0, 1);
  i2 = reqs0->size[0];
  reqs0->size[0] = reqs->data->size[0];
  emxEnsureCapacity((emxArray__common *)reqs0, i2, (int)sizeof(unsigned char));
  resultlen = reqs->data->size[0];
  for (i2 = 0; i2 < resultlen; i2++) {
    reqs0->data[i2] = reqs->data->data[i2];
  }

  emxInit_uint8_T(&data0, 1);

  ptr = (MPI_Request *)(&reqs0->data[0]);
  *info = MPI_Waitany(count, ptr, idx, &stat0);
  *toplevel = true;
  sizepe = sizeof(MPI_Status);
  i2 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i2, (int)sizeof(unsigned char));
  for (i2 = 0; i2 < 10; i2++) {
    t0_type[i2] = cv1[i2];
  }

  i2 = stat->data->size[0];
  stat->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)stat->data, i2, (int)sizeof(unsigned
    char));
  resultlen = data0->size[0];
  for (i2 = 0; i2 < resultlen; i2++) {
    stat->data->data[i2] = data0->data[i2];
  }

  i2 = stat->type->size[0] * stat->type->size[1];
  stat->type->size[0] = 1;
  stat->type->size[1] = 10;
  emxEnsureCapacity((emxArray__common *)stat->type, i2, (int)sizeof(char));
  for (i2 = 0; i2 < 10; i2++) {
    stat->type->data[i2] = t0_type[i2];
  }

  stat->nitems = 1;
  b_ptr = (char *)(&stat0);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    stat->data->data[resultlen - 1] = *(b_ptr);
    b_ptr = b_ptr + 1;
  }

  sizepe = sizeof(MPI_Request);
  i2 = data0->size[0];
  data0->size[0] = sizepe * count;
  emxEnsureCapacity((emxArray__common *)data0, i2, (int)sizeof(unsigned char));
  for (i2 = 0; i2 < 11; i2++) {
    t1_type[i2] = x2[i2];
  }

  i2 = reqs->data->size[0];
  reqs->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)reqs->data, i2, (int)sizeof(unsigned
    char));
  resultlen = data0->size[0];
  for (i2 = 0; i2 < resultlen; i2++) {
    reqs->data->data[i2] = data0->data[i2];
  }

  emxFree_uint8_T(&data0);
  i2 = reqs->type->size[0] * reqs->type->size[1];
  reqs->type->size[0] = 1;
  reqs->type->size[1] = 11;
  emxEnsureCapacity((emxArray__common *)reqs->type, i2, (int)sizeof(char));
  for (i2 = 0; i2 < 11; i2++) {
    reqs->type->data[i2] = t1_type[i2];
  }

  reqs->nitems = count;
  if (!(reqs0->size[0] == 0)) {
    b_ptr = (char *)(&reqs0->data[0]);
    i2 = sizepe * count;
    for (resultlen = 1; resultlen <= i2; resultlen++) {
      reqs->data->data[resultlen - 1] = *(b_ptr);
      b_ptr = b_ptr + 1;
    }
  }

  emxFree_uint8_T(&reqs0);
  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    b_ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, b_ptr, &resultlen);
    if (1 > resultlen) {
      resultlen = 0;
    }

    emxInit_uint8_T(&varargin_1, 2);
    i2 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = resultlen;
    emxEnsureCapacity((emxArray__common *)varargin_1, i2, (int)sizeof(unsigned
      char));
    for (i2 = 0; i2 < resultlen; i2++) {
      varargin_1->data[varargin_1->size[0] * i2] = msg0[i2];
    }

    emxInit_char_T(&b_varargin_1, 2);
    i2 = b_varargin_1->size[0] * b_varargin_1->size[1];
    b_varargin_1->size[0] = 1;
    b_varargin_1->size[1] = (short)resultlen;
    emxEnsureCapacity((emxArray__common *)b_varargin_1, i2, (int)sizeof(char));
    resultlen = (short)resultlen;
    for (i2 = 0; i2 < resultlen; i2++) {
      b_varargin_1->data[i2] = (signed char)varargin_1->data[i2];
    }

    emxFree_uint8_T(&varargin_1);
    c_m2c_error(b_varargin_1);
    emxFree_char_T(&b_varargin_1);
  }
}

void mpi_Waitany_initialize(void)
{
}

void mpi_Waitany_terminate(void)
{
}
