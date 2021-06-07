#ifndef CCS_SOLVE_TRIUT_H
#define CCS_SOLVE_TRIUT_H

#include "ccs_solve_triut_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void ccs_solve_triut(const CCS_Matrix *U, emxArray_real_T *b);

extern void ccs_solve_triut_initialize(void);

extern void ccs_solve_triut_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
