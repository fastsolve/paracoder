#include "mpi_Reduce_scatter.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(void);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(void);
static void e_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFreeStruct_struct1_T(struct1_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct1_T(struct1_T *pStruct);
static void f_m2c_error(const emxArray_char_T *varargin_3);
static boolean_T isequal(const char varargin_1[6]);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_warn(void);
static int mpi_Type_size(const emxArray_uint8_T *datatype_data, const
  emxArray_char_T *datatype_type);
static double rt_roundd(double u);
static double sum(const emxArray_int32_T *x);
static void b_m2c_error(void)
{
  M2C_error("mpi_Reduce_scatter:OutOfBound", "Send buffer is too small.");
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

static void d_m2c_error(void)
{
  M2C_error("mpi_Reduce_scatter:OutOfBound", "Receive buffer is too small.");
}

static void e_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i4;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i4 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i4, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_varargin_3->data[i4] = varargin_3->data[i4];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Op.\n", &b_varargin_3->data[0]);
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

static void f_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i5;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i5 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i5, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_varargin_3->data[i5] = varargin_3->data[i5];
  }

  M2C_error("MPI:RuntimeError",
            "MPI_Reduce_scatter failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static boolean_T isequal(const char varargin_1[6])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv4[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 6)) {
    if (!(varargin_1[k] == cv4[k])) {
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
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_warn(void)
{
  M2C_warn("m2c_opaque_ptr:ConstPtr",
           "Discarding the const modifier of an m2c_opaque_ptr.");
}

static int mpi_Type_size(const emxArray_uint8_T *datatype_data, const
  emxArray_char_T *datatype_type)
{
  int size;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i1;
  boolean_T exitg1;
  emxArray_char_T *b_datatype_type;
  static const char cv3[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_uint8_T *data;
  MPI_Datatype datatype;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i1 = datatype_type->size[k];
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

  if (b_p && (!(datatype_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(datatype_type->data[k] == cv3[k])) {
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
    emxInit_char_T(&b_datatype_type, 2);
    i1 = b_datatype_type->size[0] * b_datatype_type->size[1];
    b_datatype_type->size[0] = 1;
    b_datatype_type->size[1] = datatype_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_datatype_type, i1, (int)sizeof(char));
    k = datatype_type->size[1];
    for (i1 = 0; i1 < k; i1++) {
      b_datatype_type->data[b_datatype_type->size[0] * i1] = datatype_type->
        data[datatype_type->size[0] * i1];
    }

    b_datatype_type->data[b_datatype_type->size[0] * datatype_type->size[1]] =
      '\x00';
    m2c_error(b_datatype_type);
    emxFree_char_T(&b_datatype_type);
  }

  emxInit_uint8_T(&data, 1);
  i1 = data->size[0];
  data->size[0] = datatype_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i1, (int)sizeof(unsigned char));
  k = datatype_data->size[0];
  for (i1 = 0; i1 < k; i1++) {
    data->data[i1] = datatype_data->data[i1];
  }

  datatype = *(MPI_Datatype*)(&data->data[0]);
  MPI_Type_size(datatype, &size);
  emxFree_uint8_T(&data);
  return size;
}

static double rt_roundd(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static double sum(const emxArray_int32_T *x)
{
  double y;
  int k;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= x->size[0]; k++) {
      y += (double)x->data[k - 1];
    }
  }

  return y;
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

void mpi_Reduce_scatter(const struct0_T *sptr, const struct0_T *rptr, const
  emxArray_int32_T *rcounts, const struct1_T *datatype, const struct1_T *op,
  const struct1_T *comm, int *info, boolean_T *toplevel)
{
  emxArray_uint8_T *data;
  int b_rcounts[1];
  unsigned long b_data;
  const char * ptr;
  emxArray_int32_T c_rcounts;
  double a;
  char * b_ptr;
  int sizepe;
  int rank;
  boolean_T p;
  boolean_T b_p;
  int resultlen;
  int exitg8;
  int exitg6;
  int i0;
  boolean_T exitg7;
  boolean_T exitg5;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_char_T *b_datatype;
  static const char cv1[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  MPI_Comm c_comm;
  MPI_Datatype c_datatype;
  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *b_op;
  static const char cv2[6] = { 'M', 'P', 'I', '_', 'O', 'p' };

  MPI_Op obj;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *d_comm;
  unsigned char msg0[1024];
  emxArray_uint8_T *varargin_1;
  emxArray_char_T *b_varargin_1;
  emxInit_uint8_T(&data, 1);
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    b_rcounts[0] = rcounts->size[0] * rcounts->size[1];
    c_rcounts = *rcounts;
    c_rcounts.size = (int *)&b_rcounts;
    c_rcounts.numDimensions = 1;
    a = sum(&c_rcounts);
    sizepe = mpi_Type_size(datatype->data, datatype->type);
    if (sptr->nbytes - sptr->offset < (int)rt_roundd(a * (double)sizepe)) {
      b_m2c_error();
    } else {
      p = false;
      b_p = false;
      resultlen = 0;
      do {
        exitg8 = 0;
        if (resultlen < 2) {
          i0 = comm->type->size[resultlen];
          if (i0 != 7 * resultlen + 1) {
            exitg8 = 1;
          } else {
            resultlen++;
          }
        } else {
          b_p = true;
          exitg8 = 1;
        }
      } while (exitg8 == 0);

      if (b_p && (!(comm->type->size[1] == 0))) {
        resultlen = 0;
        exitg7 = false;
        while ((!exitg7) && (resultlen < 8)) {
          if (!(comm->type->data[resultlen] == cv0[resultlen])) {
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
        emxInit_char_T(&b_comm, 2);
        i0 = b_comm->size[0] * b_comm->size[1];
        b_comm->size[0] = 1;
        b_comm->size[1] = comm->type->size[1] + 1;
        emxEnsureCapacity((emxArray__common *)b_comm, i0, (int)sizeof(char));
        resultlen = comm->type->size[1];
        for (i0 = 0; i0 < resultlen; i0++) {
          b_comm->data[b_comm->size[0] * i0] = comm->type->data[comm->type->
            size[0] * i0];
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
      MPI_Comm_rank(c_comm, &rank);
      if (rptr->nbytes - rptr->offset < rcounts->data[rank] * sizepe) {
        d_m2c_error();
      }
    }
  }

  b_data = sptr->data;
  ptr = *(const char **)(&b_data);
  if (sptr->offset != 0) {
    ptr = ptr + sptr->offset;
  }

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
    exitg6 = 0;
    if (resultlen < 2) {
      i0 = datatype->type->size[resultlen];
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
    i0 = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = datatype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_datatype, i0, (int)sizeof(char));
    resultlen = datatype->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_datatype->data[b_datatype->size[0] * i0] = datatype->type->data
        [datatype->type->size[0] * i0];
    }

    b_datatype->data[b_datatype->size[0] * datatype->type->size[1]] = '\x00';
    m2c_error(b_datatype);
    emxFree_char_T(&b_datatype);
  }

  i0 = data->size[0];
  data->size[0] = datatype->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  resultlen = datatype->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data->data[i0] = datatype->data->data[i0];
  }

  c_datatype = *(MPI_Datatype*)(&data->data[0]);
  p = false;
  b_p = false;
  resultlen = 0;
  do {
    exitg4 = 0;
    if (resultlen < 2) {
      i0 = op->type->size[resultlen];
      if (i0 != 5 * resultlen + 1) {
        exitg4 = 1;
      } else {
        resultlen++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(op->type->size[1] == 0))) {
    resultlen = 0;
    exitg3 = false;
    while ((!exitg3) && (resultlen < 6)) {
      if (!(op->type->data[resultlen] == cv2[resultlen])) {
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
    emxInit_char_T(&b_op, 2);
    i0 = b_op->size[0] * b_op->size[1];
    b_op->size[0] = 1;
    b_op->size[1] = op->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_op, i0, (int)sizeof(char));
    resultlen = op->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_op->data[b_op->size[0] * i0] = op->type->data[op->type->size[0] * i0];
    }

    b_op->data[b_op->size[0] * op->type->size[1]] = '\x00';
    e_m2c_error(b_op);
    emxFree_char_T(&b_op);
  }

  i0 = data->size[0];
  data->size[0] = op->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  resultlen = op->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data->data[i0] = op->data->data[i0];
  }

  obj = *(MPI_Op*)(&data->data[0]);
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
      if (!(comm->type->data[resultlen] == cv0[resultlen])) {
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
    emxInit_char_T(&d_comm, 2);
    i0 = d_comm->size[0] * d_comm->size[1];
    d_comm->size[0] = 1;
    d_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)d_comm, i0, (int)sizeof(char));
    resultlen = comm->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      d_comm->data[d_comm->size[0] * i0] = comm->type->data[comm->type->size[0] *
        i0];
    }

    d_comm->data[d_comm->size[0] * comm->type->size[1]] = '\x00';
    c_m2c_error(d_comm);
    emxFree_char_T(&d_comm);
  }

  i0 = data->size[0];
  data->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  resultlen = comm->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data->data[i0] = comm->data->data[i0];
  }

  c_comm = *(MPI_Comm*)(&data->data[0]);
  *info = MPI_Reduce_scatter(ptr, b_ptr, &rcounts->data[0], c_datatype, obj,
    c_comm);
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
    f_m2c_error(b_varargin_1);
    emxFree_char_T(&b_varargin_1);
  }
}

void mpi_Reduce_scatter_initialize(void)
{
}

void mpi_Reduce_scatter_terminate(void)
{
}
