#ifndef CRS_PRODAB_H
#define CRS_PRODAB_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_prodAB_types.h"

extern void crs_prodAB(const CRS_Matrix *A, const CRS_Matrix *B, CRS_Matrix *C);
extern void crs_prodAB_initialize(void);
extern void crs_prodAB_terminate(void);

#endif
