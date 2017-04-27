#ifndef CUMATDESTROY_H
#define CUMATDESTROY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuMatDestroy_types.h"

extern void cuMatDestroy(const struct0_T *mat, int *errCode, boolean_T *toplevel);
extern void cuMatDestroy_initialize(void);
extern void cuMatDestroy_terminate(void);

#endif
