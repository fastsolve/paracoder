#include "mpi_Ssend.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(void);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(void)
{
  M2C_error("mpi_Ssend:OutOfBound", "Message size is larger than variable size.");
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

static void d_m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Ssend error code %d\n", varargin_3);
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

void mpi_Ssend(const struct0_T *ptr, int count, const struct1_T *datatype, int
               dest, int tag, const struct1_T *comm, int *info, boolean_T
               *toplevel)
{
  emxArray_uint8_T *data;
  unsigned long b_data;
  boolean_T p;
  const char * b_ptr;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_datatype;
  static const char cv0[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  int loop_ub;
  emxArray_char_T *c_datatype;
  MPI_Datatype d_datatype;
  int size;
  emxArray_char_T *b_comm;
  static const char cv1[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm c_comm;
  emxInit_uint8_T(&data, 1);
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    p = false;
    b_p = false;
    if (datatype->type->size[1] == 12) {
      b_p = true;
    }

    if (b_p && (!(datatype->type->size[1] == 0))) {
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 12)) {
        if (!(datatype->type->data[k] == cv0[k])) {
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
      emxInit_char_T(&b_datatype, 2);
      k = b_datatype->size[0] * b_datatype->size[1];
      b_datatype->size[0] = 1;
      b_datatype->size[1] = datatype->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_datatype, k, sizeof(char));
      loop_ub = datatype->type->size[1];
      for (k = 0; k < loop_ub; k++) {
        b_datatype->data[b_datatype->size[0] * k] = datatype->type->
          data[datatype->type->size[0] * k];
      }

      b_datatype->data[b_datatype->size[0] * datatype->type->size[1]] = '\x00';
      m2c_error(b_datatype);
      emxFree_char_T(&b_datatype);
    }

    k = data->size[0];
    data->size[0] = datatype->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
    loop_ub = datatype->data->size[0];
    for (k = 0; k < loop_ub; k++) {
      data->data[k] = datatype->data->data[k];
    }

    d_datatype = *(MPI_Datatype*)(&data->data[0]);
    MPI_Type_size(d_datatype, &size);
    if (ptr->nbytes - ptr->offset < count * size) {
      b_m2c_error();
    }
  }

  b_data = ptr->data;
  b_ptr = *(const char **)(&b_data);
  if (ptr->offset != 0) {
    b_ptr = b_ptr + ptr->offset;
  }

  p = false;
  b_p = false;
  if (datatype->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(datatype->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(datatype->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&c_datatype, 2);
    k = c_datatype->size[0] * c_datatype->size[1];
    c_datatype->size[0] = 1;
    c_datatype->size[1] = datatype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)c_datatype, k, sizeof(char));
    loop_ub = datatype->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      c_datatype->data[c_datatype->size[0] * k] = datatype->type->data
        [datatype->type->size[0] * k];
    }

    c_datatype->data[c_datatype->size[0] * datatype->type->size[1]] = '\x00';
    m2c_error(c_datatype);
    emxFree_char_T(&c_datatype);
  }

  k = data->size[0];
  data->size[0] = datatype->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = datatype->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = datatype->data->data[k];
  }

  d_datatype = *(MPI_Datatype*)(&data->data[0]);
  p = false;
  b_p = false;
  if (comm->type->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(comm->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(comm->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_comm, 2);
    k = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_comm, k, sizeof(char));
    loop_ub = comm->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_comm->data[b_comm->size[0] * k] = comm->type->data[comm->type->size[0] *
        k];
    }

    b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
    c_m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }

  k = data->size[0];
  data->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = comm->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = comm->data->data[k];
  }

  c_comm = *(MPI_Comm*)(&data->data[0]);
  *info = MPI_Ssend(b_ptr, count, d_datatype, dest, tag, c_comm);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*info != 0) {
    d_m2c_error(*info);
  }
}

void mpi_Ssend_initialize(void)
{
}

void mpi_Ssend_terminate(void)
{
}
