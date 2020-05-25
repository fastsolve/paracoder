#include "crs_rowind.h"
#include "m2c.h"

void crs_rowind(const emxArray_int32_T *rowptr, const emxArray_int32_T *js,
                emxArray_int32_T *is)
{
  int i;
  int nrows;
  int b_i;
  int i1;
  int j;
  i = is->size[0];
  is->size[0] = js->size[0];
  emxEnsureCapacity_int32_T(is, i);
  nrows = rowptr->size[0];
  for (b_i = 0; b_i <= nrows - 2; b_i++) {
    i = rowptr->data[b_i];
    i1 = rowptr->data[b_i + 1] - 1;
    for (j = i; j <= i1; j++) {
      is->data[j - 1] = b_i + 1;
    }
  }
}

void crs_rowind_initialize(void)
{
}

void crs_rowind_terminate(void)
{
}
