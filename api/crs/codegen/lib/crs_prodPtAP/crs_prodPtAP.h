#ifndef CRS_PRODPTAP_H
#define CRS_PRODPTAP_H

#include "crs_prodPtAP_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_prodPtAP(const CRS_Matrix *A, const CRS_Matrix *P,
                         CRS_Matrix *B);

extern void crs_prodPtAP_initialize(void);

extern void crs_prodPtAP_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
