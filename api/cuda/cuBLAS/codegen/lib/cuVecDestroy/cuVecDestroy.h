#ifndef CUVECDESTROY_H
#define CUVECDESTROY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuVecDestroy_types.h"

extern void cuVecDestroy(struct0_T *vec, int *errCode, boolean_T *toplevel);
extern void cuVecDestroy_initialize(void);
extern void cuVecDestroy_terminate(void);

#endif
