#ifndef CUSTREAMSYNCHRONIZE_H
#define CUSTREAMSYNCHRONIZE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuStreamSynchronize_types.h"

extern void cuStreamSynchronize(const struct0_T *stm, int *errCode, boolean_T
  *toplevel);
extern void cuStreamSynchronize_initialize(void);
extern void cuStreamSynchronize_terminate(void);

#endif
