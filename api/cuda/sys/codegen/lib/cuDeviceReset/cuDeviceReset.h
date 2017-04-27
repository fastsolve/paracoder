#ifndef CUDEVICERESET_H
#define CUDEVICERESET_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuDeviceReset_types.h"

extern void cuDeviceReset(int *errCode, boolean_T *toplevel);
extern void cuDeviceReset_initialize(void);
extern void cuDeviceReset_terminate(void);

#endif
