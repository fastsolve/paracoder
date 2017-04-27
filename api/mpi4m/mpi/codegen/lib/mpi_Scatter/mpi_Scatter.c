#include "mpi_Scatter.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(void);
static void d_m2c_error(void);
static void e_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFreeStruct_struct1_T(struct1_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct1_T(struct1_T *pStruct);
static boolean_T isequal(const char varargin_1[6]);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_warn(void);
static int mpi_Type_size(const emxArray_uint8_T *datatype_data, const
  emxArray_char_T *datatype_type);
static void b_m2c_error(const emxArray_char_T *varargin_3)
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
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(void)
{
  M2C_error("mpi_Scatter:OutOfBound", "Message is larger than send buffer size.");
}

static void d_m2c_error(void)
{
  M2C_error("mpi_Scatter:OutOfBound", "Message is larger than receive buffer.");
}

static void e_m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Scatter error code %d\n", varargin_3);
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
  static const char cv3[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 6)) {
    if (!(varargin_1[k] == cv3[k])) {
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
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
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
  int i2;
  boolean_T exitg1;
  emxArray_char_T *b_datatype_type;
  static const char cv2[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_uint8_T *data;
  MPI_Datatype datatype;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i2 = datatype_type->size[k];
      if (i2 != 11 * k + 1) {
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
      if (!(datatype_type->data[k] == cv2[k])) {
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
    i2 = b_datatype_type->size[0] * b_datatype_type->size[1];
    b_datatype_type->size[0] = 1;
    b_datatype_type->size[1] = datatype_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_datatype_type, i2, (int)sizeof(char));
    k = datatype_type->size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_datatype_type->data[b_datatype_type->size[0] * i2] = datatype_type->
        data[datatype_type->size[0] * i2];
    }

    b_datatype_type->data[b_datatype_type->size[0] * datatype_type->size[1]] =
      '\x00';
    b_m2c_error(b_datatype_type);
    emxFree_char_T(&b_datatype_type);
  }

  emxInit_uint8_T(&data, 1);
  i2 = data->size[0];
  data->size[0] = datatype_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i2, (int)sizeof(unsigned char));
  k = datatype_data->size[0];
  for (i2 = 0; i2 < k; i2++) {
    data->data[i2] = datatype_data->data[i2];
  }

  datatype = *(MPI_Datatype*)(&data->data[0]);
  MPI_Type_size(datatype, &size);
  emxFree_uint8_T(&data);
  return size;
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

void mpi_Scatter(const struct0_T *sptr, int scount, const struct1_T *stype,
                 const struct0_T *rptr, int rcount, const struct1_T *rtype, int
                 root, const struct1_T *comm, int *info, boolean_T *toplevel)
{
  emxArray_uint8_T *data;
  int rank;
  unsigned long b_data;
  boolean_T p;
  const char * ptr;
  boolean_T b_p;
  int k;
  int exitg8;
  int i0;
  int exitg6;
  boolean_T exitg7;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  boolean_T exitg5;
  emxArray_char_T *b_stype;
  static const char cv1[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  MPI_Comm c_comm;
  MPI_Datatype datatype;
  char * b_ptr;
  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *b_rtype;
  MPI_Datatype b_datatype;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *d_comm;
  emxInit_uint8_T(&data, 1);
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    p = false;
    b_p = false;
    k = 0;
    do {
      exitg8 = 0;
      if (k < 2) {
        i0 = comm->type->size[k];
        if (i0 != 7 * k + 1) {
          exitg8 = 1;
        } else {
          k++;
        }
      } else {
        b_p = true;
        exitg8 = 1;
      }
    } while (exitg8 == 0);

    if (b_p && (!(comm->type->size[1] == 0))) {
      k = 0;
      exitg7 = false;
      while ((!exitg7) && (k < 8)) {
        if (!(comm->type->data[k] == cv0[k])) {
          b_p = false;
          exitg7 = true;
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
      emxInit_char_T(&b_comm, 2);
      i0 = b_comm->size[0] * b_comm->size[1];
      b_comm->size[0] = 1;
      b_comm->size[1] = comm->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_comm, i0, (int)sizeof(char));
      k = comm->type->size[1];
      for (i0 = 0; i0 < k; i0++) {
        b_comm->data[b_comm->size[0] * i0] = comm->type->data[comm->type->size[0]
          * i0];
      }

      b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
      m2c_error(b_comm);
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
    MPI_Comm_rank(c_comm, &rank);
    if ((rank == root) && (sptr->nbytes - sptr->offset < scount * mpi_Type_size
                           (stype->data, stype->type))) {
      c_m2c_error();
    }

    if (rptr->nbytes - rptr->offset < rcount * mpi_Type_size(rtype->data,
         rtype->type)) {
      d_m2c_error();
    }
  }

  b_data = sptr->data;
  ptr = *(const char **)(&b_data);
  if (sptr->offset != 0) {
    ptr = ptr + sptr->offset;
  }

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg6 = 0;
    if (k < 2) {
      i0 = stype->type->size[k];
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

  if (b_p && (!(stype->type->size[1] == 0))) {
    k = 0;
    exitg5 = false;
    while ((!exitg5) && (k < 12)) {
      if (!(stype->type->data[k] == cv1[k])) {
        b_p = false;
        exitg5 = true;
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
    emxInit_char_T(&b_stype, 2);
    i0 = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = stype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_stype, i0, (int)sizeof(char));
    k = stype->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_stype->data[b_stype->size[0] * i0] = stype->type->data[stype->type->
        size[0] * i0];
    }

    b_stype->data[b_stype->size[0] * stype->type->size[1]] = '\x00';
    b_m2c_error(b_stype);
    emxFree_char_T(&b_stype);
  }

  i0 = data->size[0];
  data->size[0] = stype->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = stype->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
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
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i0 = rtype->type->size[k];
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

  if (b_p && (!(rtype->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 12)) {
      if (!(rtype->type->data[k] == cv1[k])) {
        b_p = false;
        exitg3 = true;
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
    emxInit_char_T(&b_rtype, 2);
    i0 = b_rtype->size[0] * b_rtype->size[1];
    b_rtype->size[0] = 1;
    b_rtype->size[1] = rtype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_rtype, i0, (int)sizeof(char));
    k = rtype->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_rtype->data[b_rtype->size[0] * i0] = rtype->type->data[rtype->type->
        size[0] * i0];
    }

    b_rtype->data[b_rtype->size[0] * rtype->type->size[1]] = '\x00';
    b_m2c_error(b_rtype);
    emxFree_char_T(&b_rtype);
  }

  i0 = data->size[0];
  data->size[0] = rtype->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = rtype->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = rtype->data->data[i0];
  }

  b_datatype = *(MPI_Datatype*)(&data->data[0]);
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
      if (!(comm->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&d_comm, 2);
    i0 = d_comm->size[0] * d_comm->size[1];
    d_comm->size[0] = 1;
    d_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)d_comm, i0, (int)sizeof(char));
    k = comm->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      d_comm->data[d_comm->size[0] * i0] = comm->type->data[comm->type->size[0] *
        i0];
    }

    d_comm->data[d_comm->size[0] * comm->type->size[1]] = '\x00';
    m2c_error(d_comm);
    emxFree_char_T(&d_comm);
  }

  i0 = data->size[0];
  data->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = comm->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = comm->data->data[i0];
  }

  c_comm = *(MPI_Comm*)(&data->data[0]);
  *info = MPI_Scatter(ptr, scount, datatype, b_ptr, rcount, b_datatype, root,
                      c_comm);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*info != 0) {
    e_m2c_error(*info);
  }
}

void mpi_Scatter_initialize(void)
{
}

void mpi_Scatter_terminate(void)
{
}
