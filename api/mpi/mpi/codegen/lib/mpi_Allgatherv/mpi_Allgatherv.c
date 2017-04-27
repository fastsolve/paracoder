#include "mpi_Allgatherv.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(void);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFreeStruct_struct1_T(struct1_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct1_T(struct1_T *pStruct);
static boolean_T isequal(const char varargin_1[6]);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_warn(void);
static void b_m2c_error(void)
{
  M2C_error("mpi_Allgatherv:OutOfBound",
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

  M2C_error("MPI:RuntimeError", "MPI_Allgatherv failed with error message %s\n",
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

  if (!b_p) {
  } else {
    p = true;
  }

  return p;
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

void mpi_Allgatherv(const struct0_T *sptr, int scount, const struct1_T *stype,
                    const struct0_T *rptr, const emxArray_int32_T *rcounts,
                    const emxArray_int32_T *disps, const struct1_T *rtype, const
                    struct1_T *comm, int *info, boolean_T *toplevel)
{
  emxArray_uint8_T *data;
  int size;
  unsigned long b_data;
  boolean_T p;
  const char * ptr;
  boolean_T b_p;
  int resultlen;
  int exitg8;
  int i0;
  int exitg6;
  boolean_T exitg7;
  emxArray_char_T *b_stype;
  static const char cv0[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  boolean_T exitg5;
  emxArray_char_T *c_stype;
  MPI_Datatype datatype;
  char * b_ptr;
  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *b_rtype;
  MPI_Datatype b_datatype;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv1[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm c_comm;
  unsigned char msg0[1024];
  emxArray_uint8_T *varargin_1;
  emxArray_char_T *b_varargin_1;
  emxInit_uint8_T(&data, 1);
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    p = false;
    b_p = false;
    resultlen = 0;
    do {
      exitg8 = 0;
      if (resultlen < 2) {
        i0 = stype->type->size[resultlen];
        if (i0 != 11 * resultlen + 1) {
          exitg8 = 1;
        } else {
          resultlen++;
        }
      } else {
        b_p = true;
        exitg8 = 1;
      }
    } while (exitg8 == 0);

    if (b_p && (!(stype->type->size[1] == 0))) {
      resultlen = 0;
      exitg7 = false;
      while ((!exitg7) && (resultlen < 12)) {
        if (!(stype->type->data[resultlen] == cv0[resultlen])) {
          b_p = false;
          exitg7 = true;
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
      emxInit_char_T(&b_stype, 2);
      i0 = b_stype->size[0] * b_stype->size[1];
      b_stype->size[0] = 1;
      b_stype->size[1] = stype->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_stype, i0, (int)sizeof(char));
      resultlen = stype->type->size[1];
      for (i0 = 0; i0 < resultlen; i0++) {
        b_stype->data[b_stype->size[0] * i0] = stype->type->data[stype->
          type->size[0] * i0];
      }

      b_stype->data[b_stype->size[0] * stype->type->size[1]] = '\x00';
      m2c_error(b_stype);
      emxFree_char_T(&b_stype);
    }

    i0 = data->size[0];
    data->size[0] = stype->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
    resultlen = stype->data->size[0];
    for (i0 = 0; i0 < resultlen; i0++) {
      data->data[i0] = stype->data->data[i0];
    }

    datatype = *(MPI_Datatype*)(&data->data[0]);
    MPI_Type_size(datatype, &size);
    if (sptr->nbytes - sptr->offset < scount * size) {
      b_m2c_error();
    }
  }

  b_data = sptr->data;
  ptr = *(const char **)(&b_data);
  if (sptr->offset != 0) {
    ptr = ptr + sptr->offset;
  }

  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg6 = 0;
    if (resultlen < 2) {
      i0 = stype->type->size[resultlen];
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

  if (b_p && (!(stype->type->size[1] == 0))) {
    resultlen = 0;
    exitg5 = false;
    while ((!exitg5) && (resultlen < 12)) {
      if (!(stype->type->data[resultlen] == cv0[resultlen])) {
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
    emxInit_char_T(&c_stype, 2);
    i0 = c_stype->size[0] * c_stype->size[1];
    c_stype->size[0] = 1;
    c_stype->size[1] = stype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)c_stype, i0, (int)sizeof(char));
    resultlen = stype->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      c_stype->data[c_stype->size[0] * i0] = stype->type->data[stype->type->
        size[0] * i0];
    }

    c_stype->data[c_stype->size[0] * stype->type->size[1]] = '\x00';
    m2c_error(c_stype);
    emxFree_char_T(&c_stype);
  }

  i0 = data->size[0];
  data->size[0] = stype->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  resultlen = stype->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data->data[i0] = stype->data->data[i0];
  }

  datatype = *(MPI_Datatype*)(&data->data[0]);
  b_data = rptr->data;
  b_ptr = *(char **)(&b_data);
  if ((rptr->type->size[1] > 6) && isequal(*(char (*)[6])&rptr->type->data[0]))
  {
    m2c_warn();
  }

  if (rptr->offset != 0) {
    b_ptr = b_ptr + rptr->offset;
  }

  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg4 = 0;
    if (resultlen < 2) {
      i0 = rtype->type->size[resultlen];
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

  if (b_p && (!(rtype->type->size[1] == 0))) {
    resultlen = 0;
    exitg3 = false;
    while ((!exitg3) && (resultlen < 12)) {
      if (!(rtype->type->data[resultlen] == cv0[resultlen])) {
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
    emxInit_char_T(&b_rtype, 2);
    i0 = b_rtype->size[0] * b_rtype->size[1];
    b_rtype->size[0] = 1;
    b_rtype->size[1] = rtype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_rtype, i0, (int)sizeof(char));
    resultlen = rtype->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_rtype->data[b_rtype->size[0] * i0] = rtype->type->data[rtype->type->
        size[0] * i0];
    }

    b_rtype->data[b_rtype->size[0] * rtype->type->size[1]] = '\x00';
    m2c_error(b_rtype);
    emxFree_char_T(&b_rtype);
  }

  i0 = data->size[0];
  data->size[0] = rtype->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  resultlen = rtype->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data->data[i0] = rtype->data->data[i0];
  }

  b_datatype = *(MPI_Datatype*)(&data->data[0]);
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

  if (!b_p) {
  } else {
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

  i0 = data->size[0];
  data->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  resultlen = comm->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data->data[i0] = comm->data->data[i0];
  }

  c_comm = *(MPI_Comm*)(&data->data[0]);
  *info = MPI_Allgatherv(ptr, scount, datatype, b_ptr, &rcounts->data[0],
    &disps->data[0], b_datatype, c_comm);
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
    i0 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = resultlen;
    emxEnsureCapacity((emxArray__common *)varargin_1, i0, (int)sizeof(unsigned
      char));
    for (i0 = 0; i0 < resultlen; i0++) {
      varargin_1->data[varargin_1->size[0] * i0] = msg0[i0];
    }

    emxInit_char_T(&b_varargin_1, 2);
    i0 = b_varargin_1->size[0] * b_varargin_1->size[1];
    b_varargin_1->size[0] = 1;
    b_varargin_1->size[1] = (short)resultlen;
    emxEnsureCapacity((emxArray__common *)b_varargin_1, i0, (int)sizeof(char));
    resultlen = (short)resultlen;
    for (i0 = 0; i0 < resultlen; i0++) {
      b_varargin_1->data[i0] = (signed char)varargin_1->data[i0];
    }

    emxFree_uint8_T(&varargin_1);
    d_m2c_error(b_varargin_1);
    emxFree_char_T(&b_varargin_1);
  }
}

void mpi_Allgatherv_initialize(void)
{
}

void mpi_Allgatherv_terminate(void)
{
}
