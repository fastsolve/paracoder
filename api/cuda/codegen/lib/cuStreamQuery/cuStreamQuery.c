#include "cuStreamQuery.h"
#include "m2c.h"
#include "mcuda.h"

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
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
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
  int exitg2;
  int i0;
  boolean_T exitg1;
  emxArray_char_T *b_stm;
  static const char cv0[12] = { 'c', 'u', 'd', 'a', 'S', 't', 'r', 'e', 'a', 'm',
    '_', 't' };

  emxArray_uint8_T *data;
  cudaStream_t hdl;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = stm->type->size[k];
      if (i0 != 11 * k + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

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

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_stm, 2);
    i0 = b_stm->size[0] * b_stm->size[1];
    b_stm->size[0] = 1;
    b_stm->size[1] = stm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_stm, i0, (int)sizeof(char));
    k = stm->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_stm->data[b_stm->size[0] * i0] = stm->type->data[stm->type->size[0] * i0];
    }

    b_stm->data[b_stm->size[0] * stm->type->size[1]] = '\x00';
    m2c_error(b_stm);
    emxFree_char_T(&b_stm);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = stm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = stm->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = stm->data->data[i0];
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

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}
