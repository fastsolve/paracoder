#ifndef CUGETDEVICE_H
#define CUGETDEVICE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuGetDevice_types.h"

extern void cuGetDevice(int *dev, int *errCode, boolean_T *toplevel);
extern void cuGetDevice_initialize(void);
extern void cuGetDevice_terminate(void);

#endif
