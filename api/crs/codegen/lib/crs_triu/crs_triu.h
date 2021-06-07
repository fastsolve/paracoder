#ifndef CRS_TRIU_H
#define CRS_TRIU_H

#include "crs_triu_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_triu(const CRS_Matrix *A, CRS_Matrix *U);

extern void crs_triu1(const CRS_Matrix *A, int k, CRS_Matrix *U);

extern void crs_triu_initialize(void);

extern void crs_triu_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
