#ifndef CUCHOOSEDEVICE_H
#define CUCHOOSEDEVICE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuChooseDevice_types.h"

extern void cuChooseDevice(const struct0_T *prop, int *dev, int *errCode,
  boolean_T *toplevel);
extern void cuChooseDevice_initialize(void);
extern void cuChooseDevice_terminate(void);

#endif
