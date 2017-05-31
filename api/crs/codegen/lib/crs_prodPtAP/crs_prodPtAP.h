#ifndef CRS_PRODPTAP_H
#define CRS_PRODPTAP_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "crs_prodPtAP_types.h"

extern void crs_prodPtAP(const struct0_T *A, const struct0_T *P, struct0_T *B);
extern void crs_prodPtAP_initialize(void);
extern void crs_prodPtAP_terminate(void);

#endif
