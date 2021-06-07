#ifndef CRS_TRIL_H
#define CRS_TRIL_H

#include "crs_tril_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_tril(const CRS_Matrix *A, CRS_Matrix *L);

extern void crs_tril1(const CRS_Matrix *A, int k, CRS_Matrix *L);

extern void crs_tril_initialize(void);

extern void crs_tril_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
