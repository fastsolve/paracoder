#include "mpi_Comm_get_parent.h"
#include "m2c.h"
#include "mpi.h"

static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("MPI:RuntimeError",
            "MPI_Comm_get_parent failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void mpi_Comm_get_parent(struct0_T *comm, int *info, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  MPI_Comm comm0;
  int sizepe;
  int resultlen;
  char t0_type[8];
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  int loop_ub;
  char * ptr;
  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  emxInit_uint8_T(&data0, 1);
  *info = MPI_Comm_get_parent(&comm0);
  *toplevel = true;
  sizepe = sizeof(MPI_Comm);
  resultlen = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, resultlen, (int)sizeof(unsigned
    char));
  for (resultlen = 0; resultlen < 8; resultlen++) {
    t0_type[resultlen] = cv0[resultlen];
  }

  resultlen = comm->data->size[0];
  comm->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)comm->data, resultlen, (int)sizeof
                    (unsigned char));
  loop_ub = data0->size[0];
  for (resultlen = 0; resultlen < loop_ub; resultlen++) {
    comm->data->data[resultlen] = data0->data[resultlen];
  }

  emxFree_uint8_T(&data0);
  resultlen = comm->type->size[0] * comm->type->size[1];
  comm->type->size[0] = 1;
  comm->type->size[1] = 8;
  emxEnsureCapacity((emxArray__common *)comm->type, resultlen, (int)sizeof(char));
  for (resultlen = 0; resultlen < 8; resultlen++) {
    comm->type->data[resultlen] = t0_type[resultlen];
  }

  comm->nitems = 1;
  ptr = (char *)(&comm0);
  for (resultlen = 1; resultlen <= sizepe; resultlen++) {
    comm->data->data[resultlen - 1] = *(ptr);
    ptr = ptr + 1;
  }

  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, ptr, &resultlen);
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
    emxEnsureCapacity((emxArray__common *)c_msg0, resultlen, (int)sizeof
                      (unsigned char));
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      c_msg0->data[c_msg0->size[0] * resultlen] = msg0[resultlen];
    }

    emxInit_char_T(&d_msg0, 1);
    resultlen = d_msg0->size[0];
    d_msg0->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)d_msg0, resultlen, (int)sizeof(char));
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      d_msg0->data[resultlen] = (signed char)c_msg0->data[resultlen];
    }

    emxFree_uint8_T(&c_msg0);
    resultlen = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = (short)loop_ub;
    emxEnsureCapacity((emxArray__common *)b_msg0, resultlen, (int)sizeof(char));
    loop_ub = (short)loop_ub;
    for (resultlen = 0; resultlen < loop_ub; resultlen++) {
      b_msg0->data[b_msg0->size[0] * resultlen] = d_msg0->data[resultlen];
    }

    emxFree_char_T(&d_msg0);
    m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }
}

void mpi_Comm_get_parent_initialize(void)
{
}

void mpi_Comm_get_parent_terminate(void)
{
}
