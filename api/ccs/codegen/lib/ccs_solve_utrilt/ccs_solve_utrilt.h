#ifndef CCS_SOLVE_UTRILT_H
#define CCS_SOLVE_UTRILT_H

#include "ccs_solve_utrilt_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void ccs_solve_utrilt(const CCS_Matrix *L, emxArray_real_T *b);

extern void ccs_solve_utrilt_3args(const CCS_Matrix *U, emxArray_real_T *b,
                                   int offset);

extern void ccs_solve_utrilt_initialize(void);

extern void ccs_solve_utrilt_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
