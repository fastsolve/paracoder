#include "mpi_Get_count.h"
#include "mpi_Get_count_types.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(const emxArray_char_T *varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Datatype.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
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
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error("MPI:RuntimeError", "MPI_Get_count failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
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
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Status.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Get_count(const M2C_OpaqueType *stat, const M2C_OpaqueType *datatype,
                   int *count, int *info, boolean_T *toplevel)
{
  static const char cv1[12] = {'M', 'P', 'I', '_', 'D', 'a',
                               't', 'a', 't', 'y', 'p', 'e'};
  static const char cv[10] = {'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u', 's'};
  MPI_Datatype b_datatype;
  MPI_Status t_stat;
  emxArray_char_T *b_stat;
  int i;
  int resultlen;
  unsigned char msg0[1024];
  char *ptr;
  short unnamed_idx_1;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (stat->type->size[1] == 10) {
    p = true;
  }
  if (p && (stat->type->size[1] != 0)) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 10)) {
      if (!(stat->type->data[resultlen] == cv[resultlen])) {
        p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }
  b_p = (int)p;
  emxInit_char_T(&b_stat, 2);
  if (!b_p) {
    i = b_stat->size[0] * b_stat->size[1];
    b_stat->size[0] = 1;
    b_stat->size[1] = stat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stat, i);
    resultlen = stat->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_stat->data[i] = stat->type->data[i];
    }
    b_stat->data[stat->type->size[1]] = '\x00';
    m2c_error(b_stat);
  }
  t_stat = *(MPI_Status *)(&stat->data->data[0]);
  p = false;
  if (datatype->type->size[1] == 12) {
    p = true;
  }
  if (p && (datatype->type->size[1] != 0)) {
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 12)) {
      if (!(datatype->type->data[resultlen] == cv1[resultlen])) {
        p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    i = b_stat->size[0] * b_stat->size[1];
    b_stat->size[0] = 1;
    b_stat->size[1] = datatype->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stat, i);
    resultlen = datatype->type->size[1];
    for (i = 0; i < resultlen; i++) {
      b_stat->data[i] = datatype->type->data[i];
    }
    b_stat->data[datatype->type->size[1]] = '\x00';
    b_m2c_error(b_stat);
  }
  b_datatype = *(MPI_Datatype *)(&datatype->data->data[0]);
  *info = MPI_Get_count(&t_stat, b_datatype, count);
  *toplevel = true;
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    ptr = (char *)(&msg0[0]);
    resultlen = 0;
    MPI_Error_string(*info, ptr, &resultlen);
    if (1 > resultlen) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)resultlen;
    }
    i = b_stat->size[0] * b_stat->size[1];
    b_stat->size[0] = 1;
    b_stat->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_stat, i);
    resultlen = unnamed_idx_1;
    for (i = 0; i < resultlen; i++) {
      b_stat->data[i] = (signed char)msg0[i];
    }
    c_m2c_error(b_stat);
  }
  emxFree_char_T(&b_stat);
}

void mpi_Get_count_initialize(void)
{
}

void mpi_Get_count_terminate(void)
{
}
