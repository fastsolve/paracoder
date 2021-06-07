#ifndef CCS_SOLVE_TRIL_H
#define CCS_SOLVE_TRIL_H

#include "ccs_solve_tril_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void ccs_solve_tril(const CCS_Matrix *L, emxArray_real_T *b);

extern void ccs_solve_tril_initialize(void);

extern void ccs_solve_tril_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
