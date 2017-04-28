#include "mpi_Testsome.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, sizeof(char));
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("MPI:RuntimeError", "MPI_Testsome failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(void)
{
  M2C_error("mpi_Testsome:OutOfBound", "MPI_Request_array is too small.");
}

void mpi_Testsome(int count, struct0_T *reqs, emxArray_int32_T *idxs, struct0_T *
                  stats, int *info, boolean_T *toplevel)
{
  int i2;
  int n;
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_reqs;
  static const char cv0[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  emxArray_uint8_T *reqs0;
  emxArray_real_T *stats0;
  emxArray_uint8_T *data0;
  MPI_Request * ptr;
  MPI_Status * b_ptr;
  int sizepe;
  char t0_type[11];
  static const char x2[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  char * c_ptr;
  char t1_type[10];
  static const char cv1[10] = { 'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u', 's'
  };

  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    n = sizeof(MPI_Request);
    if (reqs->data->size[0] < count * n) {
      m2c_error();
    }
  }

  i2 = idxs->size[0];
  idxs->size[0] = count;
  emxEnsureCapacity((emxArray__common *)idxs, i2, sizeof(int));
  for (i2 = 0; i2 < count; i2++) {
    idxs->data[i2] = 0;
  }

  p = false;
  b_p = false;
  if (reqs->type->size[1] == 11) {
    b_p = true;
  }

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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_reqs, 2);
    i2 = b_reqs->size[0] * b_reqs->size[1];
    b_reqs->size[0] = 1;
    b_reqs->size[1] = reqs->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_reqs, i2, sizeof(char));
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
  emxEnsureCapacity((emxArray__common *)reqs0, i2, sizeof(unsigned char));
  resultlen = reqs->data->size[0];
  for (i2 = 0; i2 < resultlen; i2++) {
    reqs0->data[i2] = reqs->data->data[i2];
  }

  emxInit_real_T(&stats0, 2);
  resultlen = sizeof(MPI_Status);
  i2 = count * resultlen;
  resultlen = stats0->size[0] * stats0->size[1];
  stats0->size[0] = i2;
  stats0->size[1] = i2;
  emxEnsureCapacity((emxArray__common *)stats0, resultlen, sizeof(double));
  resultlen = i2 * i2;
  for (i2 = 0; i2 < resultlen; i2++) {
    stats0->data[i2] = 0.0;
  }

  emxInit_uint8_T(&data0, 1);

  ptr = (MPI_Request *)(&reqs0->data[0]);
  b_ptr = (MPI_Status *)(&stats0->data[0]);
  *info = MPI_Testsome(count, ptr, &n, &idxs->data[0], b_ptr);
  sizepe = sizeof(MPI_Request);
  i2 = data0->size[0];
  data0->size[0] = sizepe * count;
  emxEnsureCapacity((emxArray__common *)data0, i2, sizeof(unsigned char));
  for (i2 = 0; i2 < 11; i2++) {
    t0_type[i2] = x2[i2];
  }

  i2 = reqs->data->size[0];
  reqs->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)reqs->data, i2, sizeof(unsigned char));
  resultlen = data0->size[0];
  for (i2 = 0; i2 < resultlen; i2++) {
    reqs->data->data[i2] = data0->data[i2];
  }

  i2 = reqs->type->size[0] * reqs->type->size[1];
  reqs->type->size[0] = 1;
  reqs->type->size[1] = 11;
  emxEnsureCapacity((emxArray__common *)reqs->type, i2, sizeof(char));
  for (i2 = 0; i2 < 11; i2++) {
    reqs->type->data[i2] = t0_type[i2];
  }

  reqs->nitems = count;
  if (!(reqs0->size[0] == 0)) {
    c_ptr = (char *)(&reqs0->data[0]);
    i2 = sizepe * count;
    for (resultlen = 1; resultlen <= i2; resultlen++) {
      reqs->data->data[resultlen - 1] = *(c_ptr);
      c_ptr = c_ptr + 1;
    }
  }

  emxFree_uint8_T(&reqs0);
  sizepe = sizeof(MPI_Status);
  i2 = data0->size[0];
  data0->size[0] = sizepe * count;
  emxEnsureCapacity((emxArray__common *)data0, i2, sizeof(unsigned char));
  for (i2 = 0; i2 < 10; i2++) {
    t1_type[i2] = cv1[i2];
  }

  i2 = stats->data->size[0];
  stats->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)stats->data, i2, sizeof(unsigned char));
  resultlen = data0->size[0];
  for (i2 = 0; i2 < resultlen; i2++) {
    stats->data->data[i2] = data0->data[i2];
  }

  emxFree_uint8_T(&data0);
  i2 = stats->type->size[0] * stats->type->size[1];
  stats->type->size[0] = 1;
  stats->type->size[1] = 10;
  emxEnsureCapacity((emxArray__common *)stats->type, i2, sizeof(char));
  for (i2 = 0; i2 < 10; i2++) {
    stats->type->data[i2] = t1_type[i2];
  }

  stats->nitems = count;
  if (!((stats0->size[0] == 0) || (stats0->size[1] == 0))) {
    c_ptr = (char *)(&stats0->data[0]);
    i2 = sizepe * count;
    for (resultlen = 1; resultlen <= i2; resultlen++) {
      stats->data->data[resultlen - 1] = *(c_ptr);
      c_ptr = c_ptr + 1;
    }
  }

  emxFree_real_T(&stats0);
  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    c_ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, c_ptr, &resultlen);
    if (1 > resultlen) {
      resultlen = 0;
    }

    emxInit_char_T(&b_msg0, 2);
    emxInit_uint8_T(&c_msg0, 2);
    i2 = c_msg0->size[0] * c_msg0->size[1];
    c_msg0->size[0] = 1;
    c_msg0->size[1] = resultlen;
    emxEnsureCapacity((emxArray__common *)c_msg0, i2, sizeof(unsigned char));
    for (i2 = 0; i2 < resultlen; i2++) {
      c_msg0->data[c_msg0->size[0] * i2] = msg0[i2];
    }

    emxInit_char_T(&d_msg0, 1);
    i2 = d_msg0->size[0];
    d_msg0->size[0] = resultlen;
    emxEnsureCapacity((emxArray__common *)d_msg0, i2, sizeof(char));
    for (i2 = 0; i2 < resultlen; i2++) {
      d_msg0->data[i2] = (signed char)c_msg0->data[i2];
    }

    emxFree_uint8_T(&c_msg0);
    i2 = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = (short)resultlen;
    emxEnsureCapacity((emxArray__common *)b_msg0, i2, sizeof(char));
    resultlen = (short)resultlen;
    for (i2 = 0; i2 < resultlen; i2++) {
      b_msg0->data[b_msg0->size[0] * i2] = d_msg0->data[i2];
    }

    emxFree_char_T(&d_msg0);
    c_m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }

  i2 = idxs->size[0];
  if (1 > n) {
    idxs->size[0] = 0;
  } else {
    idxs->size[0] = n;
  }

  emxEnsureCapacity((emxArray__common *)idxs, i2, sizeof(int));
  *toplevel = true;
}

void mpi_Testsome_initialize(void)
{
}

void mpi_Testsome_terminate(void)
{
}