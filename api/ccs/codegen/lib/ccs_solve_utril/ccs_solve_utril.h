#ifndef CCS_SOLVE_UTRIL_H
#define CCS_SOLVE_UTRIL_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "ccs_solve_utril_types.h"

extern void ccs_solve_utril(const struct0_T *L, emxArray_real_T *b);
extern void ccs_solve_utril_3args(const struct0_T *L, emxArray_real_T *b, int
  offset);
extern void ccs_solve_utril_initialize(void);
extern void ccs_solve_utril_terminate(void);

#endif
