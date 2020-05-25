#ifndef CRS_DIAG_H
#define CRS_DIAG_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_diag_types.h"

extern void crs_diag(const struct0_T *A, emxArray_real_T *D);
extern void crs_diag1(const struct0_T *A, int k, emxArray_real_T *D);
extern void crs_diag_initialize(void);
extern void crs_diag_terminate(void);

#endif
