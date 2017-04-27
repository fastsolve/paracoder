#ifndef CUSETDEVICE_H
#define CUSETDEVICE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuSetDevice_types.h"

extern void cuSetDevice(int dev, int *errCode, boolean_T *toplevel);
extern void cuSetDevice_initialize(void);
extern void cuSetDevice_terminate(void);

#endif
