#include "mpi_Startall.h"
#include "mpi_Startall_types.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Startall error code %d\n", varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  static const char b_varargin_4[12] = "MPI_Request";
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  char varargin_4[12];
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  for (i = 0; i < 12; i++) {
    varargin_4[i] = b_varargin_4[i];
  }
  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            &varargin_4[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Startall(int count, const M2C_OpaqueType *reqs, int *info,
                  boolean_T *toplevel)
{
  static const char cv[11] = {'M', 'P', 'I', '_', 'R', 'e',
                              'q', 'u', 'e', 's', 't'};
  MPI_Request *ptr;
  emxArray_char_T *b_reqs;
  int i;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (reqs->type->size[1] == 11) {
    p = true;
  }
  if (p && (reqs->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(reqs->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_reqs, 2);
    i = b_reqs->size[0] * b_reqs->size[1];
    b_reqs->size[0] = 1;
    b_reqs->size[1] = reqs->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_reqs, i);
    k = reqs->type->size[1];
    for (i = 0; i < k; i++) {
      b_reqs->data[i] = reqs->type->data[i];
    }
    b_reqs->data[reqs->type->size[1]] = '\x00';
    m2c_error(b_reqs);
    emxFree_char_T(&b_reqs);
  }
  ptr = (MPI_Request *)(&reqs->data->data[0]);
  *info = MPI_Startall(count, ptr);
  *toplevel = true;
  if (*info != 0) {
    b_m2c_error(*info);
  }
}

void mpi_Startall_initialize(void)
{
}

void mpi_Startall_terminate(void)
{
}
