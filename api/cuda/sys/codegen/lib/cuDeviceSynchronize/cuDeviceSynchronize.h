#ifndef CUDEVICESYNCHRONIZE_H
#define CUDEVICESYNCHRONIZE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuDeviceSynchronize_types.h"

extern void cuDeviceSynchronize(int *errCode, boolean_T *toplevel);
extern void cuDeviceSynchronize_initialize(void);
extern void cuDeviceSynchronize_terminate(void);

#endif
