#ifndef CCS_SOLVE_UTRIUT_H
#define CCS_SOLVE_UTRIUT_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "ccs_solve_utriut_types.h"

extern void ccs_solve_utril_3args(const struct0_T *L, emxArray_real_T *b, int
  offset);
extern void ccs_solve_utriut(const struct0_T *U, emxArray_real_T *b);
extern void ccs_solve_utriut_initialize(void);
extern void ccs_solve_utriut_terminate(void);

#endif
