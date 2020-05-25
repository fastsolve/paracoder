#ifndef CRS_TRIU_H
#define CRS_TRIU_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_triu_types.h"

extern void crs_triu(const struct0_T *A, struct0_T *U);
extern void crs_triu1(const struct0_T *A, int k, struct0_T *U);
extern void crs_triu_initialize(void);
extern void crs_triu_terminate(void);

#endif
