#ifndef CCS_SOLVE_UTRILT_H
#define CCS_SOLVE_UTRILT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "ccs_solve_utrilt_types.h"

extern void ccs_solve_utrilt(const struct0_T *L, emxArray_real_T *b);
extern void ccs_solve_utrilt_3args(const struct0_T *U, emxArray_real_T *b, int
  offset);
extern void ccs_solve_utrilt_initialize(void);
extern void ccs_solve_utrilt_terminate(void);

#endif
