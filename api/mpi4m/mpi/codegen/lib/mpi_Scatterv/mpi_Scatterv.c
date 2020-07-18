#include "mpi_Scatterv.h"
#include "m2c.h"
#include "mpi.h"

static MPI_Comm b_m2c_castdata(const emxArray_uint8_T *data);
static void b_m2c_error(void);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(int varargin_3);
static MPI_Datatype m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_warn(void);
static MPI_Comm b_m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Comm*)(&data->data[0]);
}

static void b_m2c_error(void)
{
  M2C_error("mpi_Scatterv:OutOfBound",
            "Message size is larger than variable size.");
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
  emxFree_char_T(&b_varargin_3);
}

static void d_m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Scatterv error code %d\n", varargin_3);
}

static MPI_Datatype m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Datatype*)(&data->data[0]);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
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

void mpi_Scatterv(const M2C_OpaquePtrType *sptr, const emxArray_int32_T *scounts,
                  const emxArray_int32_T *disps, const M2C_OpaqueType *stype,
                  const M2C_OpaquePtrType *rptr, int rcount, const
                  M2C_OpaqueType *rtype, int root, const M2C_OpaqueType *comm,
                  int *info, boolean_T *toplevel)
{
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_rtype;
  int i;
  static const char cv[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  MPI_Datatype datatype;
  int size;
  const char * ptr;
  MPI_Datatype b_datatype;
  static const char cv1[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm b_comm;
  char * b_ptr;
  static const char cv2[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  p = (rtype->type->size[1] == 12);
  if (p && (rtype->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(rtype->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_rtype, 2);
  if (!b_p) {
    i = b_rtype->size[0] * b_rtype->size[1];
    b_rtype->size[0] = 1;
    b_rtype->size[1] = rtype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_rtype, i);
    k = rtype->type->size[1];
    for (i = 0; i < k; i++) {
      b_rtype->data[i] = rtype->type->data[i];
    }

    b_rtype->data[rtype->type->size[1]] = '\x00';
    m2c_error(b_rtype);
  }

  datatype = m2c_castdata(rtype->data);
  MPI_Type_size(datatype, &size);
  if (rptr->nbytes - rptr->offset < rcount * size) {
    b_m2c_error();
  }

  ptr = *(const char **)(&sptr->data);
  if (sptr->offset != 0) {
    ptr = ptr + sptr->offset;
  }

  p = (stype->type->size[1] == 12);
  if (p && (stype->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(stype->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_rtype->size[0] * b_rtype->size[1];
    b_rtype->size[0] = 1;
    b_rtype->size[1] = stype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_rtype, i);
    k = stype->type->size[1];
    for (i = 0; i < k; i++) {
      b_rtype->data[i] = stype->type->data[i];
    }

    b_rtype->data[stype->type->size[1]] = '\x00';
    m2c_error(b_rtype);
  }

  datatype = m2c_castdata(stype->data);
  p = (rtype->type->size[1] == 12);
  if (p && (rtype->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(rtype->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_rtype->size[0] * b_rtype->size[1];
    b_rtype->size[0] = 1;
    b_rtype->size[1] = rtype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_rtype, i);
    k = rtype->type->size[1];
    for (i = 0; i < k; i++) {
      b_rtype->data[i] = rtype->type->data[i];
    }

    b_rtype->data[rtype->type->size[1]] = '\x00';
    m2c_error(b_rtype);
  }

  b_datatype = m2c_castdata(rtype->data);
  p = (comm->type->size[1] == 8);
  if (p && (comm->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(comm->type->data[k] == cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_rtype->size[0] * b_rtype->size[1];
    b_rtype->size[0] = 1;
    b_rtype->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_rtype, i);
    k = comm->type->size[1];
    for (i = 0; i < k; i++) {
      b_rtype->data[i] = comm->type->data[i];
    }

    b_rtype->data[comm->type->size[1]] = '\x00';
    c_m2c_error(b_rtype);
  }

  emxFree_char_T(&b_rtype);
  b_comm = b_m2c_castdata(comm->data);
  b_ptr = *(char **)(&rptr->data);
  if (rptr->type->size[1] > 6) {
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(rptr->type->data[k] == cv2[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    b_p = (int)p;
    if (b_p) {
      m2c_warn();
    }
  }

  if (rptr->offset != 0) {
    b_ptr = b_ptr + rptr->offset;
  }

  *info = MPI_Scatterv(ptr, &scounts->data[0], &disps->data[0], datatype, b_ptr,
                       rcount, b_datatype, root, b_comm);
  *toplevel = true;
  if (*info != 0) {
    d_m2c_error(*info);
  }
}

void mpi_Scatterv_initialize(void)
{
}

void mpi_Scatterv_terminate(void)
{
}
