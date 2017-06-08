#ifndef CRS_PRODAB_H
#define CRS_PRODAB_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "crs_prodAB_types.h"

extern void crs_prodAB(const struct0_T *A, const struct0_T *B, struct0_T *C);
extern void crs_prodAB_initialize(void);
extern void crs_prodAB_terminate(void);

#endif
