#ifndef CRS_TRANSP_H
#define CRS_TRANSP_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_transp_types.h"

extern void crs_transp(const CRS_Matrix *A, CRS_Matrix *At);
extern void crs_transp_initialize(void);
extern void crs_transp_terminate(void);

#endif
