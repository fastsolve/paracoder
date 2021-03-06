#ifndef CUGETDEVICEPROPERTIES_H
#define CUGETDEVICEPROPERTIES_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuGetDeviceProperties_types.h"

extern void cuGetDeviceProperties(int dev, struct0_T *prop, int *errCode,
  boolean_T *toplevel);
extern void cuGetDeviceProperties_arg0(struct0_T *prop, int *errCode, boolean_T *
  toplevel);
extern void cuGetDeviceProperties_initialize(void);
extern void cuGetDeviceProperties_terminate(void);
extern emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  int *size);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxDestroy_struct0_T(struct0_T emxArray);
extern void emxInit_struct0_T(struct0_T *pStruct);

#endif
