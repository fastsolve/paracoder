#include "mpi_Startall.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(void);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i1;
  int loop_ub;
  char varargin_4[12];
  static const char b_varargin_4[12] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u',
    'e', 's', 't', '\x00' };

  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
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

static void m2c_error(void)
{
  M2C_error("mpi_Startall:OutOfBound",
            "Message size is larger than variable size.");
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void mpi_Startall(int count, const struct0_T *reqs, int *info, boolean_T
                  *toplevel)
{
  int n;
  boolean_T p;
  boolean_T b_p;
  int exitg2;
  int i0;
  boolean_T exitg1;
  emxArray_char_T *b_reqs;
  static const char cv0[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  emxArray_uint8_T *output;
  MPI_Request * ptr;
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    n = sizeof(MPI_Request);
    if (reqs->data->size[0] < count * n) {
      m2c_error();
    }
  }

  p = false;
  b_p = false;
  n = 0;
  do {
    exitg2 = 0;
    if (n < 2) {
      i0 = reqs->type->size[n];
      if (i0 != 10 * n + 1) {
        exitg2 = 1;
      } else {
        n++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

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

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_reqs, 2);
    i0 = b_reqs->size[0] * b_reqs->size[1];
    b_reqs->size[0] = 1;
    b_reqs->size[1] = reqs->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_reqs, i0, (int)sizeof(char));
    n = reqs->type->size[1];
    for (i0 = 0; i0 < n; i0++) {
      b_reqs->data[b_reqs->size[0] * i0] = reqs->type->data[reqs->type->size[0] *
        i0];
    }

    b_reqs->data[b_reqs->size[0] * reqs->type->size[1]] = '\x00';
    b_m2c_error(b_reqs);
    emxFree_char_T(&b_reqs);
  }

  emxInit_uint8_T(&output, 1);
  i0 = output->size[0];
  output->size[0] = reqs->data->size[0];
  emxEnsureCapacity((emxArray__common *)output, i0, (int)sizeof(unsigned char));
  n = reqs->data->size[0];
  for (i0 = 0; i0 < n; i0++) {
    output->data[i0] = reqs->data->data[i0];
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
