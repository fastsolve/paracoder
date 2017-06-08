#include "mpi_Scatter.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(void);
static void d_m2c_error(void);
static void e_m2c_error(int varargin_3);
static boolean_T isequal(const char varargin_1[6]);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_warn(void);
static int mpi_Type_size(const emxArray_uint8_T *datatype_data, const
  emxArray_char_T *datatype_type);
static void b_m2c_error(const emxArray_char_T *varargin_3)
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
  boolean_T exitg1;
  emxArray_char_T *b_datatype_type;
  static const char cv2[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
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
      if (!(datatype_type->data[k] == cv2[k])) {
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
    b_m2c_error(b_datatype_type);
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

void mpi_Scatter(const struct0_T *sptr, int scount, const struct1_T *stype,
                 const struct0_T *rptr, int rcount, const struct1_T *rtype, int
                 root, const struct1_T *comm, int *info, boolean_T *toplevel)
{
  emxArray_uint8_T *data;
  unsigned long b_data;
  boolean_T p;
  const char * ptr;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  int loop_ub;
  emxArray_char_T *b_stype;
  static const char cv1[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  MPI_Comm c_comm;
  int rank;
  MPI_Datatype datatype;
  char * b_ptr;
  emxArray_char_T *b_rtype;
  MPI_Datatype b_datatype;
  emxArray_char_T *d_comm;
  emxInit_uint8_T(&data, 1);
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    p = false;
    b_p = false;
    if (comm->type->size[1] == 8) {
      b_p = true;
    }

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
        b_comm->data[b_comm->size[0] * k] = comm->type->data[comm->type->size[0]
          * k];
      }

      b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
      m2c_error(b_comm);
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
  if (stype->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(stype->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(stype->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_stype, 2);
    k = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = stype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_stype, k, sizeof(char));
    loop_ub = stype->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_stype->data[b_stype->size[0] * k] = stype->type->data[stype->type->size
        [0] * k];
    }

    b_stype->data[b_stype->size[0] * stype->type->size[1]] = '\x00';
    b_m2c_error(b_stype);
    emxFree_char_T(&b_stype);
  }

  k = data->size[0];
  data->size[0] = stype->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = stype->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = stype->data->data[k];
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
  if (rtype->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(rtype->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(rtype->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_rtype, 2);
    k = b_rtype->size[0] * b_rtype->size[1];
    b_rtype->size[0] = 1;
    b_rtype->size[1] = rtype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_rtype, k, sizeof(char));
    loop_ub = rtype->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_rtype->data[b_rtype->size[0] * k] = rtype->type->data[rtype->type->size
        [0] * k];
    }

    b_rtype->data[b_rtype->size[0] * rtype->type->size[1]] = '\x00';
    b_m2c_error(b_rtype);
    emxFree_char_T(&b_rtype);
  }

  k = data->size[0];
  data->size[0] = rtype->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = rtype->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = rtype->data->data[k];
  }

  b_datatype = *(MPI_Datatype*)(&data->data[0]);
  p = false;
  b_p = false;
  if (comm->type->size[1] == 8) {
    b_p = true;
  }

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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&d_comm, 2);
    k = d_comm->size[0] * d_comm->size[1];
    d_comm->size[0] = 1;
    d_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)d_comm, k, sizeof(char));
    loop_ub = comm->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      d_comm->data[d_comm->size[0] * k] = comm->type->data[comm->type->size[0] *
        k];
    }

    d_comm->data[d_comm->size[0] * comm->type->size[1]] = '\x00';
    m2c_error(d_comm);
    emxFree_char_T(&d_comm);
  }

  k = data->size[0];
  data->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = comm->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = comm->data->data[k];
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
