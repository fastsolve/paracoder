#include "mpi_Startall.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static void m2c_error(void);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  int i1;
  char varargin_4[12];
  static const char b_varargin_4[12] = "MPI_Request";
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  for (i1 = 0; i1 < 12; i1++) {
    varargin_4[i1] = b_varargin_4[i1];
  }

  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            varargin_4);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Startall error code %d\n", varargin_3);
}

static void m2c_error(void)
{
  M2C_error("mpi_Startall:OutOfBound",
            "Message size is larger than variable size.");
}

void mpi_Startall(int count, const struct0_T *reqs, int *info, boolean_T
                  *toplevel)
{
  int n;
  boolean_T p;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_reqs;
  MPI_Request * ptr;
  int i;
  static const char cv[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  n = sizeof(MPI_Request);
  if (reqs->data->size[0] < count * n) {
    m2c_error();
  }

  p = (reqs->type->size[1] == 11);
  if (p && (reqs->type->size[1] != 0)) {
    n = 0;
    exitg1 = false;
    while ((!exitg1) && (n < 11)) {
      if (!(reqs->type->data[n] == cv[n])) {
        p = false;
        exitg1 = true;
      } else {
        n++;
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
    n = reqs->type->size[1];
    for (i = 0; i < n; i++) {
      b_reqs->data[i] = reqs->type->data[i];
    }

    b_reqs->data[reqs->type->size[1]] = '\x00';
    b_m2c_error(b_reqs);
    emxFree_char_T(&b_reqs);
  }

  ptr = (MPI_Request *)(&reqs->data->data[0]);
  *info = MPI_Startall(count, ptr);
  *toplevel = true;
  if (*info != 0) {
    c_m2c_error(*info);
  }
}

void mpi_Startall_initialize(void)
{
}

void mpi_Startall_terminate(void)
{
}
