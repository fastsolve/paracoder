#include "cuStreamQuery.h"
#include "m2c.h"
#include "cuda4m.h"

static void m2c_error(const emxArray_char_T *varargin_3);
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
            "Incorrect data type %s. Expected cudaStream_t.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

int cuStreamQuery(const struct0_T *stm)
{
  int notReady;
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_stm;
  static const char cv0[12] = { 'c', 'u', 'd', 'a', 'S', 't', 'r', 'e', 'a', 'm',
    '_', 't' };

  emxArray_uint8_T *data;
  int loop_ub;
  cudaStream_t hdl;
  p = false;
  b_p = false;
  if (stm->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(stm->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(stm->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_stm, 2);
    k = b_stm->size[0] * b_stm->size[1];
    b_stm->size[0] = 1;
    b_stm->size[1] = stm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_stm, k, sizeof(char));
    loop_ub = stm->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_stm->data[b_stm->size[0] * k] = stm->type->data[stm->type->size[0] * k];
    }

    b_stm->data[b_stm->size[0] * stm->type->size[1]] = '\x00';
    m2c_error(b_stm);
    emxFree_char_T(&b_stm);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = stm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = stm->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = stm->data->data[k];
  }

  hdl = *(cudaStream_t*)(&data->data[0]);
  notReady = cudaStreamQuery(hdl);
  emxFree_uint8_T(&data);
  return notReady;
}

void cuStreamQuery_initialize(void)
{
}

void cuStreamQuery_terminate(void)
{
}