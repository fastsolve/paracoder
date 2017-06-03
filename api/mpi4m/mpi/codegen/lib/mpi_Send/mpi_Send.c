#include "mpi_Send.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(void);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFreeStruct_struct1_T(struct1_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct1_T(struct1_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(void)
{
  M2C_error("mpi_Send:OutOfBound", "Message size is larger than variable size.");
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

static void d_m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Send error code %d\n", varargin_3);
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

void mpi_Send(const struct0_T *ptr, int count, const struct1_T *datatype, int
              dest, int tag, const struct1_T *comm, int *info, boolean_T
              *toplevel)
{
  emxArray_uint8_T *data;
  int size;
  unsigned long b_data;
  const char * b_ptr;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg6;
  int i0;
  int exitg4;
  boolean_T exitg5;
  emxArray_char_T *b_datatype;
  static const char cv0[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  boolean_T exitg3;
  emxArray_char_T *c_datatype;
  MPI_Datatype d_datatype;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv1[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm c_comm;
  emxInit_uint8_T(&data, 1);
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    p = false;
    b_p = false;
    k = 0;
    do {
      exitg6 = 0;
      if (k < 2) {
        i0 = datatype->type->size[k];
        if (i0 != 11 * k + 1) {
          exitg6 = 1;
        } else {
          k++;
        }
      } else {
        b_p = true;
        exitg6 = 1;
      }
    } while (exitg6 == 0);

    if (b_p && (!(datatype->type->size[1] == 0))) {
      k = 0;
      exitg5 = false;
      while ((!exitg5) && (k < 12)) {
        if (!(datatype->type->data[k] == cv0[k])) {
          b_p = false;
          exitg5 = true;
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
      i0 = b_datatype->size[0] * b_datatype->size[1];
      b_datatype->size[0] = 1;
      b_datatype->size[1] = datatype->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_datatype, i0, (int)sizeof(char));
      k = datatype->type->size[1];
      for (i0 = 0; i0 < k; i0++) {
        b_datatype->data[b_datatype->size[0] * i0] = datatype->type->
          data[datatype->type->size[0] * i0];
      }

      b_datatype->data[b_datatype->size[0] * datatype->type->size[1]] = '\x00';
      m2c_error(b_datatype);
      emxFree_char_T(&b_datatype);
    }

    i0 = data->size[0];
    data->size[0] = datatype->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
    k = datatype->data->size[0];
    for (i0 = 0; i0 < k; i0++) {
      data->data[i0] = datatype->data->data[i0];
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
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i0 = datatype->type->size[k];
      if (i0 != 11 * k + 1) {
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(datatype->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 12)) {
      if (!(datatype->type->data[k] == cv0[k])) {
        b_p = false;
        exitg3 = true;
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
    i0 = c_datatype->size[0] * c_datatype->size[1];
    c_datatype->size[0] = 1;
    c_datatype->size[1] = datatype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)c_datatype, i0, (int)sizeof(char));
    k = datatype->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      c_datatype->data[c_datatype->size[0] * i0] = datatype->type->data
        [datatype->type->size[0] * i0];
    }

    c_datatype->data[c_datatype->size[0] * datatype->type->size[1]] = '\x00';
    m2c_error(c_datatype);
    emxFree_char_T(&c_datatype);
  }

  i0 = data->size[0];
  data->size[0] = datatype->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = datatype->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = datatype->data->data[i0];
  }

  d_datatype = *(MPI_Datatype*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = comm->type->size[k];
      if (i0 != 7 * k + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

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
    i0 = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_comm, i0, (int)sizeof(char));
    k = comm->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
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
  k = comm->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = comm->data->data[i0];
  }

  c_comm = *(MPI_Comm*)(&data->data[0]);
  *info = MPI_Send(b_ptr, count, d_datatype, dest, tag, c_comm);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*info != 0) {
    d_m2c_error(*info);
  }
}

void mpi_Send_initialize(void)
{
}

void mpi_Send_terminate(void)
{
}
