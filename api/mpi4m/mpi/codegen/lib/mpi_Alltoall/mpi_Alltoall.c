#include "mpi_Alltoall.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(void);
static void d_m2c_error(void);
static void e_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFreeStruct_struct1_T(struct1_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct1_T(struct1_T *pStruct);
static boolean_T isequal(const char varargin_1[6]);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_warn(void);
static int mpi_Comm_size(const emxArray_uint8_T *comm_data, const
  emxArray_char_T *comm_type);
static int mpi_Type_size(const emxArray_uint8_T *datatype_data, const
  emxArray_char_T *datatype_type);
static void b_m2c_error(const emxArray_char_T *varargin_3)
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
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(void)
{
  M2C_error("mpi_Alltoall:OutOfBound",
            "Message size is larger than variable size.");
}

static void d_m2c_error(void)
{
  M2C_error("mpi_Alltoall:NoInPlace",
            "MPI_Alltoall does not support in-place communication.");
}

static void e_m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("MPI:RuntimeError", "MPI_Alltoall failed with error message %s\n",
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

static void m2c_warn(void)
{
  M2C_warn("m2c_opaque_ptr:ConstPtr",
           "Discarding the const modifier of an m2c_opaque_ptr.");
}

static int mpi_Comm_size(const emxArray_uint8_T *comm_data, const
  emxArray_char_T *comm_type)
{
  int size;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i1;
  boolean_T exitg1;
  emxArray_char_T *b_comm_type;
  static const char cv2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data;
  MPI_Comm comm;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i1 = comm_type->size[k];
      if (i1 != 7 * k + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(comm_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(comm_type->data[k] == cv2[k])) {
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
    emxInit_char_T(&b_comm_type, 2);
    i1 = b_comm_type->size[0] * b_comm_type->size[1];
    b_comm_type->size[0] = 1;
    b_comm_type->size[1] = comm_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_comm_type, i1, (int)sizeof(char));
    k = comm_type->size[1];
    for (i1 = 0; i1 < k; i1++) {
      b_comm_type->data[b_comm_type->size[0] * i1] = comm_type->data
        [comm_type->size[0] * i1];
    }

    b_comm_type->data[b_comm_type->size[0] * comm_type->size[1]] = '\x00';
    m2c_error(b_comm_type);
    emxFree_char_T(&b_comm_type);
  }

  emxInit_uint8_T(&data, 1);
  i1 = data->size[0];
  data->size[0] = comm_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i1, (int)sizeof(unsigned char));
  k = comm_data->size[0];
  for (i1 = 0; i1 < k; i1++) {
    data->data[i1] = comm_data->data[i1];
  }

  comm = *(MPI_Comm*)(&data->data[0]);
  MPI_Comm_size(comm, &size);
  emxFree_uint8_T(&data);
  return size;
}

static int mpi_Type_size(const emxArray_uint8_T *datatype_data, const
  emxArray_char_T *datatype_type)
{
  int size;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i3;
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
      i3 = datatype_type->size[k];
      if (i3 != 11 * k + 1) {
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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_datatype_type, 2);
    i3 = b_datatype_type->size[0] * b_datatype_type->size[1];
    b_datatype_type->size[0] = 1;
    b_datatype_type->size[1] = datatype_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_datatype_type, i3, (int)sizeof(char));
    k = datatype_type->size[1];
    for (i3 = 0; i3 < k; i3++) {
      b_datatype_type->data[b_datatype_type->size[0] * i3] = datatype_type->
        data[datatype_type->size[0] * i3];
    }

    b_datatype_type->data[b_datatype_type->size[0] * datatype_type->size[1]] =
      '\x00';
    b_m2c_error(b_datatype_type);
    emxFree_char_T(&b_datatype_type);
  }

  emxInit_uint8_T(&data, 1);
  i3 = data->size[0];
  data->size[0] = datatype_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i3, (int)sizeof(unsigned char));
  k = datatype_data->size[0];
  for (i3 = 0; i3 < k; i3++) {
    data->data[i3] = datatype_data->data[i3];
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

void mpi_Alltoall(const struct0_T *sptr, int scount, const struct1_T *stype,
                  const struct0_T *rptr, int rcount, const struct1_T *rtype,
                  const struct1_T *comm, int *info, boolean_T *toplevel)
{
  int nprocs;
  unsigned long data;
  const char * ptr;
  boolean_T p;
  boolean_T b_p;
  int exitg6;
  int i0;
  boolean_T exitg5;
  emxArray_char_T *b_stype;
  static const char cv0[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_uint8_T *b_data;
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
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    nprocs = mpi_Comm_size(comm->data, comm->type);
    if ((sptr->nbytes - sptr->offset < scount * nprocs * mpi_Type_size
         (stype->data, stype->type)) || (rptr->nbytes - rptr->offset < rcount *
         nprocs * mpi_Type_size(rtype->data, rtype->type))) {
      c_m2c_error();
    }

    p = false;
    b_p = true;
    if (!(sptr->data == rptr->data)) {
      b_p = false;
    }

    if (b_p) {
      p = true;
    }

    if (p) {
      d_m2c_error();
    }
  }

  data = sptr->data;
  ptr = *(const char **)(&data);
  if (sptr->offset != 0) {
    ptr = ptr + sptr->offset;
  }

  p = false;
  b_p = false;
  nprocs = 0;
  do {
    exitg6 = 0;
    if (nprocs < 2) {
      i0 = stype->type->size[nprocs];
      if (i0 != 11 * nprocs + 1) {
        exitg6 = 1;
      } else {
        nprocs++;
      }
    } else {
      b_p = true;
      exitg6 = 1;
    }
  } while (exitg6 == 0);

  if (b_p && (!(stype->type->size[1] == 0))) {
    nprocs = 0;
    exitg5 = false;
    while ((!exitg5) && (nprocs < 12)) {
      if (!(stype->type->data[nprocs] == cv0[nprocs])) {
        b_p = false;
        exitg5 = true;
      } else {
        nprocs++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_stype, 2);
    i0 = b_stype->size[0] * b_stype->size[1];
    b_stype->size[0] = 1;
    b_stype->size[1] = stype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_stype, i0, (int)sizeof(char));
    nprocs = stype->type->size[1];
    for (i0 = 0; i0 < nprocs; i0++) {
      b_stype->data[b_stype->size[0] * i0] = stype->type->data[stype->type->
        size[0] * i0];
    }

    b_stype->data[b_stype->size[0] * stype->type->size[1]] = '\x00';
    b_m2c_error(b_stype);
    emxFree_char_T(&b_stype);
  }

  emxInit_uint8_T(&b_data, 1);
  i0 = b_data->size[0];
  b_data->size[0] = stype->data->size[0];
  emxEnsureCapacity((emxArray__common *)b_data, i0, (int)sizeof(unsigned char));
  nprocs = stype->data->size[0];
  for (i0 = 0; i0 < nprocs; i0++) {
    b_data->data[i0] = stype->data->data[i0];
  }

  datatype = *(MPI_Datatype*)(&b_data->data[0]);
  data = rptr->data;
  b_ptr = *(char **)(&data);
  if ((rptr->type->size[1] > 6) && isequal(*(char (*)[6])&rptr->type->data[0]))
  {
    m2c_warn();
  }

  if (rptr->offset != 0) {
    b_ptr = b_ptr + rptr->offset;
  }

  p = false;
  b_p = false;
  nprocs = 0;
  do {
    exitg4 = 0;
    if (nprocs < 2) {
      i0 = rtype->type->size[nprocs];
      if (i0 != 11 * nprocs + 1) {
        exitg4 = 1;
      } else {
        nprocs++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(rtype->type->size[1] == 0))) {
    nprocs = 0;
    exitg3 = false;
    while ((!exitg3) && (nprocs < 12)) {
      if (!(rtype->type->data[nprocs] == cv0[nprocs])) {
        b_p = false;
        exitg3 = true;
      } else {
        nprocs++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_rtype, 2);
    i0 = b_rtype->size[0] * b_rtype->size[1];
    b_rtype->size[0] = 1;
    b_rtype->size[1] = rtype->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_rtype, i0, (int)sizeof(char));
    nprocs = rtype->type->size[1];
    for (i0 = 0; i0 < nprocs; i0++) {
      b_rtype->data[b_rtype->size[0] * i0] = rtype->type->data[rtype->type->
        size[0] * i0];
    }

    b_rtype->data[b_rtype->size[0] * rtype->type->size[1]] = '\x00';
    b_m2c_error(b_rtype);
    emxFree_char_T(&b_rtype);
  }

  i0 = b_data->size[0];
  b_data->size[0] = rtype->data->size[0];
  emxEnsureCapacity((emxArray__common *)b_data, i0, (int)sizeof(unsigned char));
  nprocs = rtype->data->size[0];
  for (i0 = 0; i0 < nprocs; i0++) {
    b_data->data[i0] = rtype->data->data[i0];
  }

  b_datatype = *(MPI_Datatype*)(&b_data->data[0]);
  p = false;
  b_p = false;
  nprocs = 0;
  do {
    exitg2 = 0;
    if (nprocs < 2) {
      i0 = comm->type->size[nprocs];
      if (i0 != 7 * nprocs + 1) {
        exitg2 = 1;
      } else {
        nprocs++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(comm->type->size[1] == 0))) {
    nprocs = 0;
    exitg1 = false;
    while ((!exitg1) && (nprocs < 8)) {
      if (!(comm->type->data[nprocs] == cv1[nprocs])) {
        b_p = false;
        exitg1 = true;
      } else {
        nprocs++;
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
    nprocs = comm->type->size[1];
    for (i0 = 0; i0 < nprocs; i0++) {
      b_comm->data[b_comm->size[0] * i0] = comm->type->data[comm->type->size[0] *
        i0];
    }

    b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
    m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }

  i0 = b_data->size[0];
  b_data->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)b_data, i0, (int)sizeof(unsigned char));
  nprocs = comm->data->size[0];
  for (i0 = 0; i0 < nprocs; i0++) {
    b_data->data[i0] = comm->data->data[i0];
  }

  c_comm = *(MPI_Comm*)(&b_data->data[0]);
  *info = MPI_Alltoall(ptr, scount, datatype, b_ptr, rcount, b_datatype, c_comm);
  *toplevel = true;
  emxFree_uint8_T(&b_data);
  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    b_ptr = (char *)(msg0);
    nprocs = 0;
    MPI_Error_string(*info, b_ptr, &nprocs);
    if (1 > nprocs) {
      nprocs = 0;
    }

    emxInit_char_T(&b_msg0, 2);
    emxInit_uint8_T(&c_msg0, 2);
    i0 = c_msg0->size[0] * c_msg0->size[1];
    c_msg0->size[0] = 1;
    c_msg0->size[1] = nprocs;
    emxEnsureCapacity((emxArray__common *)c_msg0, i0, (int)sizeof(unsigned char));
    for (i0 = 0; i0 < nprocs; i0++) {
      c_msg0->data[c_msg0->size[0] * i0] = msg0[i0];
    }

    emxInit_char_T(&d_msg0, 1);
    i0 = d_msg0->size[0];
    d_msg0->size[0] = nprocs;
    emxEnsureCapacity((emxArray__common *)d_msg0, i0, (int)sizeof(char));
    for (i0 = 0; i0 < nprocs; i0++) {
      d_msg0->data[i0] = (signed char)c_msg0->data[i0];
    }

    emxFree_uint8_T(&c_msg0);
    i0 = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = (short)nprocs;
    emxEnsureCapacity((emxArray__common *)b_msg0, i0, (int)sizeof(char));
    nprocs = (short)nprocs;
    for (i0 = 0; i0 < nprocs; i0++) {
      b_msg0->data[b_msg0->size[0] * i0] = d_msg0->data[i0];
    }

    emxFree_char_T(&d_msg0);
    e_m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }
}

void mpi_Alltoall_initialize(void)
{
}

void mpi_Alltoall_terminate(void)
{
}
