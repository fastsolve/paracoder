#include "mpi_Start.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Start error code %d\n", varargin_3);
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
            "Incorrect data type %s. Expected MPI_Request.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void mpi_Start(const struct0_T *req, int *info, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_req;
  static const char cv0[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  emxArray_uint8_T *data;
  int loop_ub;
  MPI_Request t_req;
  p = false;
  b_p = false;
  if (req->type->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(req->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(req->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_req, 2);
    k = b_req->size[0] * b_req->size[1];
    b_req->size[0] = 1;
    b_req->size[1] = req->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_req, k, sizeof(char));
    loop_ub = req->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_req->data[b_req->size[0] * k] = req->type->data[req->type->size[0] * k];
    }

    b_req->data[b_req->size[0] * req->type->size[1]] = '\x00';
    m2c_error(b_req);
    emxFree_char_T(&b_req);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = req->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = req->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = req->data->data[k];
  }

  t_req = *(MPI_Request*)(&data->data[0]);
  *info = MPI_Start(&t_req);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*info != 0) {
    b_m2c_error(*info);
  }
}

void mpi_Start_initialize(void)
{
}

void mpi_Start_terminate(void)
{
}
