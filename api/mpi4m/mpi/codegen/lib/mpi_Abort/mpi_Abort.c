#include "mpi_Abort.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(void);
static void b_m2c_error(const emxArray_char_T *varargin_3)
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

static void m2c_error(void)
{
  M2C_error("MMPI:MPI_Abort", "MPI_Abort was called");
}

int mpi_Abort(const struct0_T *comm, int errorcode)
{
  int info;
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data;
  int loop_ub;
  MPI_Comm c_comm;
  info = 0;
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    m2c_error();
  } else {
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
      b_m2c_error(b_comm);
      emxFree_char_T(&b_comm);
    }

    emxInit_uint8_T(&data, 1);
    k = data->size[0];
    data->size[0] = comm->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
    loop_ub = comm->data->size[0];
    for (k = 0; k < loop_ub; k++) {
      data->data[k] = comm->data->data[k];
    }

    c_comm = *(MPI_Comm*)(&data->data[0]);
    info = MPI_Abort(c_comm, errorcode);
    emxFree_uint8_T(&data);
  }

  return info;
}

void mpi_Abort_initialize(void)
{
}

void mpi_Abort_terminate(void)
{
}
