#ifndef CCS_SOLVE_UTRIUT_H
#define CCS_SOLVE_UTRIUT_H

#include "ccs_solve_utriut_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void ccs_solve_utril_3args(const CCS_Matrix *L, emxArray_real_T *b,
                                  int offset);

extern void ccs_solve_utriut(const CCS_Matrix *U, emxArray_real_T *b);

extern void ccs_solve_utriut_initialize(void);

extern void ccs_solve_utriut_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
