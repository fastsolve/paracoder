#ifndef CRS_TRIL_H
#define CRS_TRIL_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "crs_tril_types.h"

extern void crs_tril(const struct0_T *A, struct0_T *L);
extern void crs_tril1(const struct0_T *A, int k, struct0_T *L);
extern void crs_tril_initialize(void);
extern void crs_tril_terminate(void);

#endif
