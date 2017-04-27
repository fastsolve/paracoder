#ifndef CUMATCREATE_H
#define CUMATCREATE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuMatCreate_types.h"

extern void cuMatCreate(int m, int n, int type, struct0_T *mat, int *errCode,
  boolean_T *toplevel);
extern void cuMatCreate_2args(int m, int n, struct0_T *vec, int *errCode,
  boolean_T *toplevel);
extern void cuMatCreate_initialize(void);
extern void cuMatCreate_terminate(void);

#endif
