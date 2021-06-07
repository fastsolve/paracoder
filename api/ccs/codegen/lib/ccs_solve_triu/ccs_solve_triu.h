#ifndef CCS_SOLVE_TRIU_H
#define CCS_SOLVE_TRIU_H

#include "ccs_solve_triu_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void ccs_solve_triu(const CCS_Matrix *U, emxArray_real_T *b);

extern void ccs_solve_triu_initialize(void);

extern void ccs_solve_triu_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
