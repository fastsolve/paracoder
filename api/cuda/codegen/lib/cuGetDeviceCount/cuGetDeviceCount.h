#ifndef CUGETDEVICECOUNT_H
#define CUGETDEVICECOUNT_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuGetDeviceCount_types.h"

extern void cuGetDeviceCount(int *n, int *errCode, boolean_T *toplevel);
extern void cuGetDeviceCount_initialize(void);
extern void cuGetDeviceCount_terminate(void);

#endif
