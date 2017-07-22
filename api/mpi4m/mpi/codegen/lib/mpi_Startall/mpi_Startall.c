#include "mpi_Startall.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static void m2c_error(void);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i0;
  int loop_ub;
  char varargin_4[12];
  static const char b_varargin_4[12] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u',
    'e', 's', 't', '\x00' };

  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i0);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  for (i0 = 0; i0 < 12; i0++) {
    varargin_4[i0] = b_varargin_4[i0];
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
  emxArray_uint8_T *output;
  boolean_T p;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_reqs;
  static const char cv0[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  int loop_ub;
  MPI_Request * ptr;
  n = sizeof(MPI_Request);
  if (reqs->data->size[0] < count * n) {
    m2c_error();
  }

  emxInit_uint8_T(&output, 1);
  p = false;
  b_p = false;
  if (reqs->type->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(reqs->type->size[1] == 0))) {
    n = 0;
    exitg1 = false;
    while ((!exitg1) && (n < 11)) {
      if (!(reqs->type->data[n] == cv0[n])) {
        b_p = false;
        exitg1 = true;
      } else {
        n++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_reqs, 2);
    n = b_reqs->size[0] * b_reqs->size[1];
    b_reqs->size[0] = 1;
    b_reqs->size[1] = reqs->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_reqs, n);
    loop_ub = reqs->type->size[1];
    for (n = 0; n < loop_ub; n++) {
      b_reqs->data[b_reqs->size[0] * n] = reqs->type->data[reqs->type->size[0] *
        n];
    }

    b_reqs->data[b_reqs->size[0] * reqs->type->size[1]] = '\x00';
    b_m2c_error(b_reqs);
    emxFree_char_T(&b_reqs);
  }

  n = output->size[0];
  output->size[0] = reqs->data->size[0];
  emxEnsureCapacity_uint8_T(output, n);
  loop_ub = reqs->data->size[0];
  for (n = 0; n < loop_ub; n++) {
    output->data[n] = reqs->data->data[n];
  }

  ptr = (MPI_Request *)(&output->data[0]);
  *info = MPI_Startall(count, ptr);
  *toplevel = true;
  emxFree_uint8_T(&output);
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
