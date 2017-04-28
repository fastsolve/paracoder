#include "mpi_Reduce.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(void);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(void);
static void e_m2c_error(const emxArray_char_T *varargin_3);
static void f_m2c_error(const emxArray_char_T *varargin_3);
static boolean_T isequal(const char varargin_1[6]);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_warn(void);
static int mpi_Type_size(const emxArray_uint8_T *datatype_data, const
  emxArray_char_T *datatype_type);
static void b_m2c_error(void)
{
  M2C_error("mpi_Reduce:OutOfBound", "Message is larger than send buffer size.");
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

static void d_m2c_error(void)
{
  M2C_error("mpi_Reduce:OutOfBound", "Message is larger than receive buffer.");
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Op.\n", &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void f_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i3;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i3 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i3, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_varargin_3->data[i3] = varargin_3->data[i3];
  }

  M2C_error("MPI:RuntimeError", "MPI_Reduce failed with error message %s\n",
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

  if (b_p) {
    p = true;
  }

  return p;
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
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
  boolean_T exitg1;
  emxArray_char_T *b_datatype_type;
  static const char cv3[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_uint8_T *data;
  int loop_ub;
  MPI_Datatype datatype;
  p = false;
  b_p = false;
  if (datatype_type->size[1] == 12) {
    b_p = true;
  }

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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_datatype_type, 2);
    k = b_datatype_type->size[0] * b_datatype_type->size[1];
    b_datatype_type->size[0] = 1;
    b_datatype_type->size[1] = datatype_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_datatype_type, k, sizeof(char));
    loop_ub = datatype_type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_datatype_type->data[b_datatype_type->size[0] * k] = datatype_type->
        data[datatype_type->size[0] * k];
    }

    b_datatype_type->data[b_datatype_type->size[0] * datatype_type->size[1]] =
      '\x00';
    m2c_error(b_datatype_type);
    emxFree_char_T(&b_datatype_type);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = datatype_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = datatype_data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = datatype_data->data[k];
  }

  datatype = *(MPI_Datatype*)(&data->data[0]);
  MPI_Type_size(datatype, &size);
  emxFree_uint8_T(&data);
  return size;
}

void mpi_Reduce(const struct0_T *sptr, const struct0_T *rptr, int count, const
                struct1_T *datatype, const struct1_T *op, int root, const
                struct1_T *comm, int *info, boolean_T *toplevel)
{
  emxArray_uint8_T *data;
  unsigned long b_data;
  const char * ptr;
  boolean_T p;
  boolean_T b_p;
  char * b_ptr;
  int resultlen;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  int loop_ub;
  MPI_Comm c_comm;
  int rank;
  emxArray_char_T *b_datatype;
  static const char cv1[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  MPI_Datatype c_datatype;
  emxArray_char_T *b_op;
  static const char cv2[6] = { 'M', 'P', 'I', '_', 'O', 'p' };

  MPI_Op obj;
  emxArray_char_T *d_comm;
  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  emxInit_uint8_T(&data, 1);
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    if (sptr->nbytes - sptr->offset < count * mpi_Type_size(datatype->data,
         datatype->type)) {
      b_m2c_error();
    }

    p = false;
    b_p = false;
    if (comm->type->size[1] == 8) {
      b_p = true;
    }

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

    resultlen = data->size[0];
    data->size[0] = comm->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, resultlen, sizeof(unsigned char));
    loop_ub = comm->data->size[0];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      data->data[resultlen] = comm->data->data[resultlen];
    }

    c_comm = *(MPI_Comm*)(&data->data[0]);
    MPI_Comm_rank(c_comm, &rank);
    if ((rank == root) && (rptr->nbytes - rptr->offset < count * mpi_Type_size
                           (datatype->data, datatype->type))) {
      d_m2c_error();
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
  if (datatype->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(datatype->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(datatype->type->data[resultlen] == cv1[resultlen])) {
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
    emxInit_char_T(&b_datatype, 2);
    resultlen = b_datatype->size[0] * b_datatype->size[1];
    b_datatype->size[0] = 1;
    b_datatype->size[1] = datatype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_datatype, resultlen, sizeof(char));
    loop_ub = datatype->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_datatype->data[b_datatype->size[0] * resultlen] = datatype->type->
        data[datatype->type->size[0] * resultlen];
    }

    b_datatype->data[b_datatype->size[0] * datatype->type->size[1]] = '\x00';
    m2c_error(b_datatype);
    emxFree_char_T(&b_datatype);
  }

  resultlen = data->size[0];
  data->size[0] = datatype->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, resultlen, sizeof(unsigned char));
  loop_ub = datatype->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data->data[resultlen] = datatype->data->data[resultlen];
  }

  c_datatype = *(MPI_Datatype*)(&data->data[0]);
  p = false;
  b_p = false;
  if (op->type->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(op->type->size[1] == 0))) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 6)) {
      if (!(op->type->data[resultlen] == cv2[resultlen])) {
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
    emxInit_char_T(&b_op, 2);
    resultlen = b_op->size[0] * b_op->size[1];
    b_op->size[0] = 1;
    b_op->size[1] = op->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_op, resultlen, sizeof(char));
    loop_ub = op->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_op->data[b_op->size[0] * resultlen] = op->type->data[op->type->size[0] *
        resultlen];
    }

    b_op->data[b_op->size[0] * op->type->size[1]] = '\x00';
    e_m2c_error(b_op);
    emxFree_char_T(&b_op);
  }

  resultlen = data->size[0];
  data->size[0] = op->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, resultlen, sizeof(unsigned char));
  loop_ub = op->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data->data[resultlen] = op->data->data[resultlen];
  }

  obj = *(MPI_Op*)(&data->data[0]);
  p = false;
  b_p = false;
  if (comm->type->size[1] == 8) {
    b_p = true;
  }

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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&d_comm, 2);
    resultlen = d_comm->size[0] * d_comm->size[1];
    d_comm->size[0] = 1;
    d_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)d_comm, resultlen, sizeof(char));
    loop_ub = comm->type->size[1];
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      d_comm->data[d_comm->size[0] * resultlen] = comm->type->data[comm->
        type->size[0] * resultlen];
    }

    d_comm->data[d_comm->size[0] * comm->type->size[1]] = '\x00';
    c_m2c_error(d_comm);
    emxFree_char_T(&d_comm);
  }

  resultlen = data->size[0];
  data->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, resultlen, sizeof(unsigned char));
  loop_ub = comm->data->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    data->data[resultlen] = comm->data->data[resultlen];
  }

  c_comm = *(MPI_Comm*)(&data->data[0]);
  *info = MPI_Reduce(ptr, b_ptr, count, c_datatype, obj, root, c_comm);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    b_ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, b_ptr, &resultlen);
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
    f_m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }
}

void mpi_Reduce_initialize(void)
{
}

void mpi_Reduce_terminate(void)
{
}
