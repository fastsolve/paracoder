#include "mpi_Test_cancelled.h"
#include "mpi_Test_cancelled_types.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);

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
  M2C_error("MPI:RuntimeError",
            "MPI_Test_cancelled failed with error message %s\n",
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

void mpi_Test_cancelled(const M2C_OpaqueType *stat, int *flag, int *info,
                        boolean_T *toplevel)
{
  static const char cv[10] = {'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u', 's'};
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
  *info = MPI_Test_cancelled(&t_stat, flag);
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
    b_m2c_error(b_stat);
  }
  emxFree_char_T(&b_stat);
}

void mpi_Test_cancelled_initialize(void)
{
}

void mpi_Test_cancelled_terminate(void)
{
}
