#ifndef CCS_SOLVE_TRILT_H
#define CCS_SOLVE_TRILT_H

#include "ccs_solve_trilt_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void ccs_solve_trilt(const CCS_Matrix *L, emxArray_real_T *b);

extern void ccs_solve_trilt_initialize(void);

extern void ccs_solve_trilt_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
