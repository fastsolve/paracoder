#include "mpi_Alltoallw.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static boolean_T isequal(const char varargin_1[6]);
static void m2c_error(void);
static void m2c_warn(void);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i0;
  int loop_ub;
  char varargin_4[13];
  static const char b_varargin_4[13] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a',
    't', 'y', 'p', 'e', '\x00' };

  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  for (i0 = 0; i0 < 13; i0++) {
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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

static void d_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("MPI:RuntimeError", "MPI_Alltoallw failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
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

void mpi_Alltoallw(const struct0_T *sptr, const emxArray_int32_T *scounts, const
                   emxArray_int32_T *sdisps, const struct1_T *stypes, const
                   struct0_T *rptr, const emxArray_int32_T *rcounts, const
                   emxArray_int32_T *rdisps, const struct1_T *rtypes, const
                   struct1_T *comm, int *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_stypes;
  static const char cv0[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_uint8_T *stypes0;
  int loop_ub;
  emxArray_char_T *b_rtypes;
  emxArray_uint8_T *rtypes0;
  unsigned long data;
  const char * ptr;
  MPI_Datatype * b_ptr;
  char * c_ptr;
  MPI_Datatype * d_ptr;
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
  if (stypes->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(stypes->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(stypes->type->data[resultlen] == cv0[resultlen])) {
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
    emxInit_char_T(&b_stypes, 2);
    resultlen = b_stypes->size[0] * b_stypes->size[1];
    b_stypes->size[0] = 1;
    b_stypes->size[1] = stypes->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_stypes, resultlen, sizeof(char));
    loop_ub = stypes->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_stypes->data[b_stypes->size[0] * resultlen] = stypes->type->data
        [stypes->type->size[0] * resultlen];
    }

    b_stypes->data[b_stypes->size[0] * stypes->type->size[1]] = '\x00';
    b_m2c_error(b_stypes);
    emxFree_char_T(&b_stypes);
  }

  emxInit_uint8_T(&stypes0, 1);
  resultlen = stypes0->size[0];
  stypes0->size[0] = stypes->data->size[0];
  emxEnsureCapacity((emxArray__common *)stypes0, resultlen, sizeof(unsigned char));
  loop_ub = stypes->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    stypes0->data[resultlen] = stypes->data->data[resultlen];
  }

  p = false;
  b_p = false;
  if (rtypes->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(rtypes->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(rtypes->type->data[resultlen] == cv0[resultlen])) {
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
    emxInit_char_T(&b_rtypes, 2);
    resultlen = b_rtypes->size[0] * b_rtypes->size[1];
    b_rtypes->size[0] = 1;
    b_rtypes->size[1] = rtypes->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_rtypes, resultlen, sizeof(char));
    loop_ub = rtypes->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_rtypes->data[b_rtypes->size[0] * resultlen] = rtypes->type->data
        [rtypes->type->size[0] * resultlen];
    }

    b_rtypes->data[b_rtypes->size[0] * rtypes->type->size[1]] = '\x00';
    b_m2c_error(b_rtypes);
    emxFree_char_T(&b_rtypes);
  }

  emxInit_uint8_T(&rtypes0, 1);
  resultlen = rtypes0->size[0];
  rtypes0->size[0] = rtypes->data->size[0];
  emxEnsureCapacity((emxArray__common *)rtypes0, resultlen, sizeof(unsigned char));
  loop_ub = rtypes->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    rtypes0->data[resultlen] = rtypes->data->data[resultlen];
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
  if (comm->type->size[1] == 8) {
    b_p = true;
  }

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
    resultlen = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_comm, resultlen, sizeof(char));
    loop_ub = comm->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_comm->data[b_comm->size[0] * resultlen] = comm->type->data[comm->
        type->size[0] * resultlen];
    }

    b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
    c_m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }

  emxInit_uint8_T(&b_data, 1);
  resultlen = b_data->size[0];
  b_data->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)b_data, resultlen, sizeof(unsigned char));
  loop_ub = comm->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    b_data->data[resultlen] = comm->data->data[resultlen];
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
      loop_ub = 0;
    } else {
      loop_ub = resultlen;
    }

    emxInit_char_T(&b_msg0, 2);
    emxInit_uint8_T(&c_msg0, 2);
    resultlen = c_msg0->size[0] * c_msg0->size[1];
    c_msg0->size[0] = 1;
    c_msg0->size[1] = loop_ub;
    emxEnsureCapacity((emxArray__common *)c_msg0, resultlen, sizeof(unsigned
      char));
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      c_msg0->data[c_msg0->size[0] * resultlen] = msg0[resultlen];
    }

    emxInit_char_T(&d_msg0, 1);
    resultlen = d_msg0->size[0];
    d_msg0->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)d_msg0, resultlen, sizeof(char));
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      d_msg0->data[resultlen] = (signed char)c_msg0->data[resultlen];
    }

    emxFree_uint8_T(&c_msg0);
    resultlen = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = (short)loop_ub;
    emxEnsureCapacity((emxArray__common *)b_msg0, resultlen, sizeof(char));
    loop_ub = (short)loop_ub;
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_msg0->data[b_msg0->size[0] * resultlen] = d_msg0->data[resultlen];
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
