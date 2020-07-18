#ifndef CRS_PRODPTAP_H
#define CRS_PRODPTAP_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_prodPtAP_types.h"

extern void crs_prodPtAP(const CRS_Matrix *A, const CRS_Matrix *P, CRS_Matrix *B);
extern void crs_prodPtAP_initialize(void);
extern void crs_prodPtAP_terminate(void);

#endif
