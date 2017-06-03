#include "mpi_Alltoallw.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFreeStruct_struct1_T(struct1_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct1_T(struct1_T *pStruct);
static boolean_T isequal(const char varargin_1[6]);
static void m2c_error(void);
static void m2c_warn(void);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i1;
  int loop_ub;
  char varargin_4[13];
  static const char b_varargin_4[13] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a',
    't', 'y', 'p', 'e', '\x00' };

  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  for (i1 = 0; i1 < 13; i1++) {
    varargin_4[i1] = b_varargin_4[i1];
  }

  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            varargin_4);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
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
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

static void d_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i3;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i3 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i3, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_varargin_3->data[i3] = varargin_3->data[i3];
  }

  M2C_error("MPI:RuntimeError", "MPI_Alltoallw failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_char_T(&pStruct->type);
}

static void emxFreeStruct_struct1_T(struct1_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_char_T(&pStruct->type, 2);
}

static void emxInitStruct_struct1_T(struct1_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
}

static boolean_T isequal(const char varargin_1[6])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv2[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 6)) {
    if (!(varargin_1[k] == cv2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static void m2c_error(void)
{
  M2C_error("mpi_Alltoallw:NoInPlace",
            "MPI_Alltoallw does not support in-place communication.");
}

static void m2c_warn(void)
{
  M2C_warn("m2c_opaque_ptr:ConstPtr",
           "Discarding the const modifier of an m2c_opaque_ptr.");
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxDestroy_struct1_T(struct1_T emxArray)
{
  emxFreeStruct_struct1_T(&emxArray);
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void emxInit_struct1_T(struct1_T *pStruct)
{
  emxInitStruct_struct1_T(pStruct);
}

void mpi_Alltoallw(const struct0_T *sptr, const emxArray_int32_T *scounts, const
                   emxArray_int32_T *sdisps, const struct1_T *stypes, const
                   struct0_T *rptr, const emxArray_int32_T *rcounts, const
                   emxArray_int32_T *rdisps, const struct1_T *rtypes, const
                   struct1_T *comm, int *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  int exitg6;
  int i0;
  boolean_T exitg5;
  emxArray_char_T *b_stypes;
  static const char cv0[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *b_rtypes;
  emxArray_uint8_T *rtypes0;
  emxArray_uint8_T *stypes0;
  unsigned long data;
  const char * ptr;
  MPI_Datatype * b_ptr;
  char * c_ptr;
  MPI_Datatype * d_ptr;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv1[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *b_data;
  MPI_Comm c_comm;
  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    p = false;
    b_p = true;
    if (!(sptr->data == rptr->data)) {
      b_p = false;
    }

    if (b_p) {
      p = true;
    }

    if (p) {
      m2c_error();
    }
  }

  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg6 = 0;
    if (resultlen < 2) {
      i0 = stypes->type->size[resultlen];
      if (i0 != 11 * resultlen + 1) {
        exitg6 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg6 = 1;
    }
  } while (exitg6 == 0);

  if (b_p && (!(stypes->type->size[1] == 0))) {
    resultlen = 0;
    exitg5 = false;
    while ((!exitg5) && (resultlen < 12)) {
      if (!(stypes->type->data[resultlen] == cv0[resultlen])) {
        b_p = false;
        exitg5 = true;
      } else {
        resultlen++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_stypes, 2);
    i0 = b_stypes->size[0] * b_stypes->size[1];
    b_stypes->size[0] = 1;
    b_stypes->size[1] = stypes->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_stypes, i0, (int)sizeof(char));
    resultlen = stypes->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_stypes->data[b_stypes->size[0] * i0] = stypes->type->data[stypes->
        type->size[0] * i0];
    }

    b_stypes->data[b_stypes->size[0] * stypes->type->size[1]] = '\x00';
    b_m2c_error(b_stypes);
    emxFree_char_T(&b_stypes);
  }

  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg4 = 0;
    if (resultlen < 2) {
      i0 = rtypes->type->size[resultlen];
      if (i0 != 11 * resultlen + 1) {
        exitg4 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(rtypes->type->size[1] == 0))) {
    resultlen = 0;
    exitg3 = false;
    while ((!exitg3) && (resultlen < 12)) {
      if (!(rtypes->type->data[resultlen] == cv0[resultlen])) {
        b_p = false;
        exitg3 = true;
      } else {
        resultlen++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_rtypes, 2);
    i0 = b_rtypes->size[0] * b_rtypes->size[1];
    b_rtypes->size[0] = 1;
    b_rtypes->size[1] = rtypes->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_rtypes, i0, (int)sizeof(char));
    resultlen = rtypes->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_rtypes->data[b_rtypes->size[0] * i0] = rtypes->type->data[rtypes->
        type->size[0] * i0];
    }

    b_rtypes->data[b_rtypes->size[0] * rtypes->type->size[1]] = '\x00';
    b_m2c_error(b_rtypes);
    emxFree_char_T(&b_rtypes);
  }

  emxInit_uint8_T(&rtypes0, 1);
  i0 = rtypes0->size[0];
  rtypes0->size[0] = rtypes->data->size[0];
  emxEnsureCapacity((emxArray__common *)rtypes0, i0, (int)sizeof(unsigned char));
  resultlen = rtypes->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    rtypes0->data[i0] = rtypes->data->data[i0];
  }

  emxInit_uint8_T(&stypes0, 1);
  i0 = stypes0->size[0];
  stypes0->size[0] = stypes->data->size[0];
  emxEnsureCapacity((emxArray__common *)stypes0, i0, (int)sizeof(unsigned char));
  resultlen = stypes->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    stypes0->data[i0] = stypes->data->data[i0];
  }

  data = sptr->data;
  ptr = *(const char **)(&data);
  if (sptr->offset != 0) {
    ptr = ptr + sptr->offset;
  }

  b_ptr = (MPI_Datatype *)(&stypes0->data[0]);
  data = rptr->data;
  c_ptr = *(char **)(&data);
  if ((rptr->type->size[1] > 6) && isequal(*(char (*)[6])&rptr->type->data[0]))
  {
    m2c_warn();
  }

  if (rptr->offset != 0) {
    c_ptr = c_ptr + rptr->offset;
  }

  d_ptr = (MPI_Datatype *)(&rtypes0->data[0]);
  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg2 = 0;
    if (resultlen < 2) {
      i0 = comm->type->size[resultlen];
      if (i0 != 7 * resultlen + 1) {
        exitg2 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(comm->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 8)) {
      if (!(comm->type->data[resultlen] == cv1[resultlen])) {
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
    emxInit_char_T(&b_comm, 2);
    i0 = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_comm, i0, (int)sizeof(char));
    resultlen = comm->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_comm->data[b_comm->size[0] * i0] = comm->type->data[comm->type->size[0] *
        i0];
    }

    b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
    c_m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }

  emxInit_uint8_T(&b_data, 1);
  i0 = b_data->size[0];
  b_data->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)b_data, i0, (int)sizeof(unsigned char));
  resultlen = comm->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    b_data->data[i0] = comm->data->data[i0];
  }

  c_comm = *(MPI_Comm*)(&b_data->data[0]);
  *info = MPI_Alltoallw(ptr, &scounts->data[0], &sdisps->data[0], b_ptr, c_ptr,
                        &rcounts->data[0], &rdisps->data[0], d_ptr, c_comm);

  *toplevel = true;
  emxFree_uint8_T(&b_data);
  emxFree_uint8_T(&rtypes0);
  emxFree_uint8_T(&stypes0);
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
    i0 = c_msg0->size[0] * c_msg0->size[1];
    c_msg0->size[0] = 1;
    c_msg0->size[1] = resultlen;
    emxEnsureCapacity((emxArray__common *)c_msg0, i0, (int)sizeof(unsigned char));
    for (i0 = 0; i0 < resultlen; i0++) {
      c_msg0->data[c_msg0->size[0] * i0] = msg0[i0];
    }

    emxInit_char_T(&d_msg0, 1);
    i0 = d_msg0->size[0];
    d_msg0->size[0] = resultlen;
    emxEnsureCapacity((emxArray__common *)d_msg0, i0, (int)sizeof(char));
    for (i0 = 0; i0 < resultlen; i0++) {
      d_msg0->data[i0] = (signed char)c_msg0->data[i0];
    }

    emxFree_uint8_T(&c_msg0);
    i0 = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = (short)resultlen;
    emxEnsureCapacity((emxArray__common *)b_msg0, i0, (int)sizeof(char));
    resultlen = (short)resultlen;
    for (i0 = 0; i0 < resultlen; i0++) {
      b_msg0->data[b_msg0->size[0] * i0] = d_msg0->data[i0];
    }

    emxFree_char_T(&d_msg0);
    d_m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }
}

void mpi_Alltoallw_initialize(void)
{
}

void mpi_Alltoallw_terminate(void)
{
}
