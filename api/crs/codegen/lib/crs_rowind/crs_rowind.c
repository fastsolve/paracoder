#include "crs_rowind.h"
#include "m2c.h"

void crs_rowind(const emxArray_int32_T *rowptr, const emxArray_int32_T *js,
                emxArray_int32_T *is)
{
  unsigned int unnamed_idx_0;
  int nrows;
  int i;
  int j;
  unnamed_idx_0 = (unsigned int)js->size[0];
  nrows = is->size[0];
  is->size[0] = (int)unnamed_idx_0;
  emxEnsureCapacity_int32_T(is, nrows);
  nrows = rowptr->size[0] - 1;
  for (i = 1; i <= nrows; i++) {
    for (j = rowptr->data[i - 1]; j < rowptr->data[i]; j++) {
      is->data[j - 1] = i;
    }
  }
}

void crs_rowind_initialize(void)
{
}

void crs_rowind_terminate(void)
{
}
