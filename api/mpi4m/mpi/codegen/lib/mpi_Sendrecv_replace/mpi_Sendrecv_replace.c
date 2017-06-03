#include "mpi_Sendrecv_replace.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(void);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFreeStruct_struct1_T(struct1_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct1_T(struct1_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_warn(void);
static void b_m2c_error(void)
{
  M2C_error("mpi_Sendrecv_replace:OutOfBound",
            "Message size is larger than variable size.");
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

  M2C_error("MPI:RuntimeError",
            "MPI_Sendrecv_replace failed with error message %s\n",
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

static void m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
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

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void emxInit_struct1_T(struct1_T *pStruct)
{
  emxInitStruct_struct1_T(pStruct);
}

void mpi_Sendrecv_replace(const struct0_T *ptr, int count, const struct1_T
  *datatype, int dst, int stag, int src, int rtag, const struct1_T *comm,
  struct1_T *stat, int *info, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  int sizepe;
  MPI_Status stat0;
  unsigned long data;
  boolean_T p;
  char * b_ptr;
  boolean_T b_p;
  int resultlen;
  int exitg7;
  boolean_T exitg5;
  int i0;
  static const signed char iv0[6] = { 1, 2, 3, 4, 5, 6 };

  static const char cv0[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  int exitg4;
  boolean_T exitg6;
  emxArray_char_T *b_datatype;
  static const char cv1[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  boolean_T exitg3;
  emxArray_char_T *c_datatype;
  MPI_Datatype d_datatype;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm c_comm;
  char t0_type[10];
  static const char cv3[10] = { 'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u', 's'
  };

  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  emxInit_uint8_T(&data0, 1);
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    p = false;
    b_p = false;
    resultlen = 0;
    do {
      exitg7 = 0;
      if (resultlen < 2) {
        i0 = datatype->type->size[resultlen];
        if (i0 != 11 * resultlen + 1) {
          exitg7 = 1;
        } else {
          resultlen++;
        }
      } else {
        b_p = true;
        exitg7 = 1;
      }
    } while (exitg7 == 0);

    if (b_p && (!(datatype->type->size[1] == 0))) {
      resultlen = 0;
      exitg6 = false;
      while ((!exitg6) && (resultlen < 12)) {
        if (!(datatype->type->data[resultlen] == cv1[resultlen])) {
          b_p = false;
          exitg6 = true;
        } else {
          resultlen++;
        }
      }
    }

    if (b_p) {
      p = true;
    }

    if (!p) {
      emxInit_char_T(&b_datatype, 2);
      i0 = b_datatype->size[0] * b_datatype->size[1];
      b_datatype->size[0] = 1;
      b_datatype->size[1] = datatype->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_datatype, i0, (int)sizeof(char));
      resultlen = datatype->type->size[1];
      for (i0 = 0; i0 < resultlen; i0++) {
        b_datatype->data[b_datatype->size[0] * i0] = datatype->type->
          data[datatype->type->size[0] * i0];
      }

      b_datatype->data[b_datatype->size[0] * datatype->type->size[1]] = '\x00';
      m2c_error(b_datatype);
      emxFree_char_T(&b_datatype);
    }

    i0 = data0->size[0];
    data0->size[0] = datatype->data->size[0];
    emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
    resultlen = datatype->data->size[0];
    for (i0 = 0; i0 < resultlen; i0++) {
      data0->data[i0] = datatype->data->data[i0];
    }

    d_datatype = *(MPI_Datatype*)(&data0->data[0]);
    MPI_Type_size(d_datatype, &sizepe);
    if (ptr->nbytes - ptr->offset < count * sizepe) {
      b_m2c_error();
    }
  }

  data = ptr->data;
  b_ptr = *(char **)(&data);
  if (ptr->type->size[1] > 6) {
    p = false;
    b_p = true;
    resultlen = 0;
    exitg5 = false;
    while ((!exitg5) && (resultlen < 6)) {
      if (!(ptr->type->data[iv0[resultlen] - 1] == cv0[resultlen])) {
        b_p = false;
        exitg5 = true;
      } else {
        resultlen++;
      }
    }

    if (b_p) {
      p = true;
    }

    if (p) {
      m2c_warn();
    }
  }

  if (ptr->offset != 0) {
    b_ptr = b_ptr + ptr->offset;
  }

  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg4 = 0;
    if (resultlen < 2) {
      i0 = datatype->type->size[resultlen];
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

  if (b_p && (!(datatype->type->size[1] == 0))) {
    resultlen = 0;
    exitg3 = false;
    while ((!exitg3) && (resultlen < 12)) {
      if (!(datatype->type->data[resultlen] == cv1[resultlen])) {
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
    emxInit_char_T(&c_datatype, 2);
    i0 = c_datatype->size[0] * c_datatype->size[1];
    c_datatype->size[0] = 1;
    c_datatype->size[1] = datatype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)c_datatype, i0, (int)sizeof(char));
    resultlen = datatype->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      c_datatype->data[c_datatype->size[0] * i0] = datatype->type->data
        [datatype->type->size[0] * i0];
    }

    c_datatype->data[c_datatype->size[0] * datatype->type->size[1]] = '\x00';
    m2c_error(c_datatype);
    emxFree_char_T(&c_datatype);
  }

  i0 = data0->size[0];
  data0->size[0] = datatype->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  resultlen = datatype->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data0->data[i0] = datatype->data->data[i0];
  }

  d_datatype = *(MPI_Datatype*)(&data0->data[0]);
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
      if (!(comm->type->data[resultlen] == cv2[resultlen])) {
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

  i0 = data0->size[0];
  data0->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  resultlen = comm->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data0->data[i0] = comm->data->data[i0];
  }

  c_comm = *(MPI_Comm*)(&data0->data[0]);
  *info = MPI_Sendrecv_replace(b_ptr, count, d_datatype, dst, stag, src, rtag,
    c_comm, &stat0);
  *toplevel = true;
  sizepe = sizeof(MPI_Status);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 10; i0++) {
    t0_type[i0] = cv3[i0];
  }

  i0 = stat->data->size[0];
  stat->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)stat->data, i0, (int)sizeof(unsigned
    char));
  resultlen = data0->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    stat->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = stat->type->size[0] * stat->type->size[1];
  stat->type->size[0] = 1;
  stat->type->size[1] = 10;
  emxEnsureCapacity((emxArray__common *)stat->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 10; i0++) {
    stat->type->data[i0] = t0_type[i0];
  }

  stat->nitems = 1;
  b_ptr = (char *)(&stat0);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    stat->data->data[resultlen - 1] = *(b_ptr);
    b_ptr = b_ptr + 1;
  }

  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    b_ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, b_ptr, &resultlen);
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

void mpi_Sendrecv_replace_initialize(void)
{
}

void mpi_Sendrecv_replace_terminate(void)
{
}
