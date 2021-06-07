#ifndef CRS_TRANSP_H
#define CRS_TRANSP_H

#include "crs_transp_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_transp(const CRS_Matrix *A, CRS_Matrix *At);

extern void crs_transp_initialize(void);

extern void crs_transp_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
