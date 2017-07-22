#include "mpi_Graph_create.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(void);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(void);
static void b_m2c_error(void)
{
  M2C_error("mpi_Graph_create:OutOfBound", "edges array is too small.");
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
  emxEnsureCapacity_char_T(b_varargin_3, i1);
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
  emxEnsureCapacity_char_T(b_varargin_3, i2);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("MPI:RuntimeError",
            "MPI_Graph_create failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(void)
{
  M2C_error("mpi_Graph_create:OutOfBound", "index array is too small.");
}

void mpi_Graph_create(const struct0_T *comm, int nnodes, const emxArray_int32_T *
                      b_index, const emxArray_int32_T *edges, int reorder,
                      struct0_T *newcomm, int *info, boolean_T *toplevel)
{
  int i0;
  double y;
  int resultlen;
  boolean_T p;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data0;
  MPI_Comm c_comm;
  MPI_Comm newcomm0;
  int sizepe;
  char t0_type[8];
  static const char x2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  char * ptr;
  unsigned char msg0[1024];
  emxArray_uint8_T *b_msg0;
  emxArray_char_T *c_msg0;
  if (b_index->size[0] < nnodes) {
    m2c_error();
  }

  if (1 > nnodes) {
    i0 = 0;
  } else {
    i0 = nnodes;
  }

  if (i0 == 0) {
    y = 0.0;
  } else {
    y = b_index->data[0];
    for (resultlen = 2; resultlen <= i0; resultlen++) {
      y += (double)b_index->data[resultlen - 1];
    }
  }

  if (edges->size[0] < y) {
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

  emxInit_char_T(&b_comm, 2);
  if (!p) {
    i0 = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm, i0);
    resultlen = comm->type->size[1];
    for (i0 = 0; i0 < resultlen; i0++) {
      b_comm->data[b_comm->size[0] * i0] = comm->type->data[comm->type->size[0] *
        i0];
    }

    b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
    c_m2c_error(b_comm);
  }

  emxInit_uint8_T(&data0, 1);
  i0 = data0->size[0];
  data0->size[0] = comm->data->size[0];
  emxEnsureCapacity_uint8_T(data0, i0);
  resultlen = comm->data->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    data0->data[i0] = comm->data->data[i0];
  }

  c_comm = *(MPI_Comm*)(&data0->data[0]);
  *info = MPI_Graph_create(c_comm, nnodes, &b_index->data[0], &edges->data[0],
    reorder, &newcomm0);
  sizepe = sizeof(MPI_Comm);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i0);
  for (i0 = 0; i0 < 8; i0++) {
    t0_type[i0] = x2[i0];
  }

  i0 = newcomm->data->size[0];
  newcomm->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(newcomm->data, i0);
  resultlen = data0->size[0];
  for (i0 = 0; i0 < resultlen; i0++) {
    newcomm->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = newcomm->type->size[0] * newcomm->type->size[1];
  newcomm->type->size[0] = 1;
  newcomm->type->size[1] = 8;
  emxEnsureCapacity_char_T(newcomm->type, i0);
  for (i0 = 0; i0 < 8; i0++) {
    newcomm->type->data[i0] = t0_type[i0];
  }

  newcomm->nitems = 1;
  ptr = (char *)(&newcomm0);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    newcomm->data->data[resultlen - 1] = *(ptr);
    ptr = ptr + 1;
  }

  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, ptr, &resultlen);
    if (1 > resultlen) {
      resultlen = 0;
    }

    emxInit_uint8_T(&b_msg0, 2);
    i0 = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = resultlen;
    emxEnsureCapacity_uint8_T(b_msg0, i0);
    for (i0 = 0; i0 < resultlen; i0++) {
      b_msg0->data[b_msg0->size[0] * i0] = msg0[i0];
    }

    emxInit_char_T(&c_msg0, 1);
    i0 = c_msg0->size[0];
    c_msg0->size[0] = resultlen;
    emxEnsureCapacity_char_T(c_msg0, i0);
    for (i0 = 0; i0 < resultlen; i0++) {
      c_msg0->data[i0] = (signed char)b_msg0->data[i0];
    }

    emxFree_uint8_T(&b_msg0);
    i0 = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = (short)resultlen;
    emxEnsureCapacity_char_T(b_comm, i0);
    resultlen = (short)resultlen;
    for (i0 = 0; i0 < resultlen; i0++) {
      b_comm->data[b_comm->size[0] * i0] = c_msg0->data[i0];
    }

    emxFree_char_T(&c_msg0);
    d_m2c_error(b_comm);
  }

  emxFree_char_T(&b_comm);
  *toplevel = true;
}

void mpi_Graph_create_initialize(void)
{
}

void mpi_Graph_create_terminate(void)
{
}
