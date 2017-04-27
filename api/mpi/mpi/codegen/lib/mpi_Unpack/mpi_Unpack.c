#include "mpi_Unpack.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(void);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static void e_m2c_error(const emxArray_char_T *varargin_3);
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
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(void)
{
  M2C_error("mpi_Send:OutOfBound", "Output buffer is too small.");
}

static void d_m2c_error(const emxArray_char_T *varargin_3)
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
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

static void e_m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("MPI:RuntimeError", "MPI_Unpack failed with error message %s\n",
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
  static const char cv0[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 6)) {
    if (!(varargin_1[k] == cv0[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  return p;
}

static void m2c_error(void)
{
  M2C_error("mpi_Send:OutOfBound", "Input buffer is too small.");
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

void mpi_Unpack(const struct0_T *inbuf, int incount, int *position, const
                struct0_T *outbuf, int packsize, const struct1_T *datatype,
                const struct1_T *comm, int *info, boolean_T *toplevel)
{
  emxArray_uint8_T *data;
  unsigned long b_data;
  const char * ptr;
  int size;
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  char * b_ptr;
  int exitg6;
  int i3;
  int exitg4;
  boolean_T exitg5;
  emxArray_char_T *b_datatype;
  static const char cv1[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  boolean_T exitg3;
  MPI_Datatype c_datatype;
  emxArray_char_T *d_datatype;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm c_comm;
  unsigned char msg0[1024];
  emxArray_uint8_T *varargin_1;
  emxArray_char_T *b_varargin_1;
  emxInit_uint8_T(&data, 1);
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    if (inbuf->nbytes - inbuf->offset < incount) {
      m2c_error();
    }

    p = false;
    b_p = false;
    resultlen = 0;
    do {
      exitg6 = 0;
      if (resultlen < 2) {
        i3 = datatype->type->size[resultlen];
        if (i3 != 11 * resultlen + 1) {
          exitg6 = 1;
        } else {
          resultlen++;
        }
      } else {
        b_p = true;
        exitg6 = 1;
      }
    } while (exitg6 == 0);

    if (b_p && (!(datatype->type->size[1] == 0))) {
      resultlen = 0;
      exitg5 = false;
      while ((!exitg5) && (resultlen < 12)) {
        if (!(datatype->type->data[resultlen] == cv1[resultlen])) {
          b_p = false;
          exitg5 = true;
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
      emxInit_char_T(&b_datatype, 2);
      i3 = b_datatype->size[0] * b_datatype->size[1];
      b_datatype->size[0] = 1;
      b_datatype->size[1] = datatype->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_datatype, i3, (int)sizeof(char));
      resultlen = datatype->type->size[1];
      for (i3 = 0; i3 < resultlen; i3++) {
        b_datatype->data[b_datatype->size[0] * i3] = datatype->type->
          data[datatype->type->size[0] * i3];
      }

      b_datatype->data[b_datatype->size[0] * datatype->type->size[1]] = '\x00';
      b_m2c_error(b_datatype);
      emxFree_char_T(&b_datatype);
    }

    i3 = data->size[0];
    data->size[0] = datatype->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, i3, (int)sizeof(unsigned char));
    resultlen = datatype->data->size[0];
    for (i3 = 0; i3 < resultlen; i3++) {
      data->data[i3] = datatype->data->data[i3];
    }

    c_datatype = *(MPI_Datatype*)(&data->data[0]);
    MPI_Type_size(c_datatype, &size);
    if (outbuf->nbytes - outbuf->offset < packsize * size) {
      c_m2c_error();
    }
  }

  b_data = inbuf->data;
  ptr = *(const char **)(&b_data);
  if (inbuf->offset != 0) {
    ptr = ptr + inbuf->offset;
  }

  b_data = outbuf->data;
  b_ptr = *(char **)(&b_data);
  if ((outbuf->type->size[1] > 6) && isequal(*(char (*)[6])&outbuf->type->data[0]))
  {
    m2c_warn();
  }

  if (outbuf->offset != 0) {
    b_ptr = b_ptr + outbuf->offset;
  }

  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg4 = 0;
    if (resultlen < 2) {
      i3 = datatype->type->size[resultlen];
      if (i3 != 11 * resultlen + 1) {
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

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&d_datatype, 2);
    i3 = d_datatype->size[0] * d_datatype->size[1];
    d_datatype->size[0] = 1;
    d_datatype->size[1] = datatype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)d_datatype, i3, (int)sizeof(char));
    resultlen = datatype->type->size[1];
    for (i3 = 0; i3 < resultlen; i3++) {
      d_datatype->data[d_datatype->size[0] * i3] = datatype->type->data
        [datatype->type->size[0] * i3];
    }

    d_datatype->data[d_datatype->size[0] * datatype->type->size[1]] = '\x00';
    b_m2c_error(d_datatype);
    emxFree_char_T(&d_datatype);
  }

  i3 = data->size[0];
  data->size[0] = datatype->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i3, (int)sizeof(unsigned char));
  resultlen = datatype->data->size[0];
  for (i3 = 0; i3 < resultlen; i3++) {
    data->data[i3] = datatype->data->data[i3];
  }

  c_datatype = *(MPI_Datatype*)(&data->data[0]);
  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg2 = 0;
    if (resultlen < 2) {
      i3 = comm->type->size[resultlen];
      if (i3 != 7 * resultlen + 1) {
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

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_comm, 2);
    i3 = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_comm, i3, (int)sizeof(char));
    resultlen = comm->type->size[1];
    for (i3 = 0; i3 < resultlen; i3++) {
      b_comm->data[b_comm->size[0] * i3] = comm->type->data[comm->type->size[0] *
        i3];
    }

    b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
    d_m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }

  i3 = data->size[0];
  data->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i3, (int)sizeof(unsigned char));
  resultlen = comm->data->size[0];
  for (i3 = 0; i3 < resultlen; i3++) {
    data->data[i3] = comm->data->data[i3];
  }

  c_comm = *(MPI_Comm*)(&data->data[0]);
  *info = MPI_Unpack(ptr, incount, position, b_ptr, packsize, c_datatype, c_comm);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    b_ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, b_ptr, &resultlen);
    if (1 > resultlen) {
      resultlen = 0;
    }

    emxInit_uint8_T(&varargin_1, 2);
    i3 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = resultlen;
    emxEnsureCapacity((emxArray__common *)varargin_1, i3, (int)sizeof(unsigned
      char));
    for (i3 = 0; i3 < resultlen; i3++) {
      varargin_1->data[varargin_1->size[0] * i3] = msg0[i3];
    }

    emxInit_char_T(&b_varargin_1, 2);
    i3 = b_varargin_1->size[0] * b_varargin_1->size[1];
    b_varargin_1->size[0] = 1;
    b_varargin_1->size[1] = (short)resultlen;
    emxEnsureCapacity((emxArray__common *)b_varargin_1, i3, (int)sizeof(char));
    resultlen = (short)resultlen;
    for (i3 = 0; i3 < resultlen; i3++) {
      b_varargin_1->data[i3] = (signed char)varargin_1->data[i3];
    }

    emxFree_uint8_T(&varargin_1);
    e_m2c_error(b_varargin_1);
    emxFree_char_T(&b_varargin_1);
  }
}

void mpi_Unpack_initialize(void)
{
}

void mpi_Unpack_terminate(void)
{
}
