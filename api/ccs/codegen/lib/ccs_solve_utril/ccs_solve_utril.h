#ifndef CCS_SOLVE_UTRIL_H
#define CCS_SOLVE_UTRIL_H

#include "ccs_solve_utril_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void ccs_solve_utril(const CCS_Matrix *L, emxArray_real_T *b);

extern void ccs_solve_utril_3args(const CCS_Matrix *L, emxArray_real_T *b,
                                  int offset);

extern void ccs_solve_utril_initialize(void);

extern void ccs_solve_utril_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
