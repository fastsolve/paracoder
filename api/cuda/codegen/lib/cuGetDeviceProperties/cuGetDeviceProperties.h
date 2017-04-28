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

#endif
