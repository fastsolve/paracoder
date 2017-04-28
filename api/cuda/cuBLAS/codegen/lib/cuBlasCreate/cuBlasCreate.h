#ifndef CUBLASCREATE_H
#define CUBLASCREATE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuBlasCreate_types.h"

extern void cuBlasCreate(struct0_T *hdl, int *errCode, boolean_T *toplevel);
extern void cuBlasCreate_initialize(void);
extern void cuBlasCreate_terminate(void);

#endif
