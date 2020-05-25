#include "mpi_Buffer_attach.h"
#include "m2c.h"
#include "mpi.h"
#include <string.h>

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(void);
static void m2c_warn(void);
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
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error("MPI:RuntimeError",
            "MPI_Buffer_attach failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_error(void)
{
  M2C_error("mpi_Buffer_attach:OutOfBound",
            "Message size is larger than variable size.");
}

static void m2c_warn(void)
{
  M2C_warn("m2c_opaque_ptr:ConstPtr",
           "Discarding the const modifier of an m2c_opaque_ptr.");
}

void mpi_Buffer_attach(const struct0_T *ptr, int size, int *info, boolean_T
  *toplevel)
{
  char * b_ptr;
  boolean_T p;
  int resultlen;
  boolean_T exitg1;
  boolean_T b_p;
  static const char cv[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  unsigned char msg0[1024];
  emxArray_char_T *b_msg0;
  short unnamed_idx_1;
  int i;
  if (ptr->nbytes - ptr->offset < size) {
    m2c_error();
  }

  b_ptr = *(char **)(&ptr->data);
  if (ptr->type->size[1] > 6) {
    p = true;
    resultlen = 0;
    exitg1 = false;
    while ((!exitg1) && (resultlen < 6)) {
      if (!(ptr->type->data[resultlen] == cv[resultlen])) {
        p = false;
        exitg1 = true;
      } else {
        resultlen++;
      }
    }

    b_p = (int)p;
    if (b_p) {
      m2c_warn();
    }
  }

  if (ptr->offset != 0) {
    b_ptr = b_ptr + ptr->offset;
  }

  *info = MPI_Buffer_attach(b_ptr, size);
  *toplevel = true;
  if (*info != 0) {
    memset(&msg0[0], 0, 1024U * sizeof(unsigned char));
    emxInit_char_T(&b_msg0, 2);
    b_ptr = (char *)(msg0);
    resultlen = 0;
    MPI_Error_string(*info, b_ptr, &resultlen);
    if (1 > resultlen) {
      unnamed_idx_1 = 0;
    } else {
      unnamed_idx_1 = (short)resultlen;
    }

    i = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = unnamed_idx_1;
    emxEnsureCapacity_char_T(b_msg0, i);
    resultlen = unnamed_idx_1;
    for (i = 0; i < resultlen; i++) {
      b_msg0->data[i] = (signed char)msg0[i];
    }

    b_m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }
}

void mpi_Buffer_attach_initialize(void)
{
}

void mpi_Buffer_attach_terminate(void)
{
}
