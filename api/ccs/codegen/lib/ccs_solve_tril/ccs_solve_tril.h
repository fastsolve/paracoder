#ifndef CCS_SOLVE_TRIL_H
#define CCS_SOLVE_TRIL_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "ccs_solve_tril_types.h"

extern void ccs_solve_tril(const struct0_T *L, emxArray_real_T *b);
extern void ccs_solve_tril_initialize(void);
extern void ccs_solve_tril_terminate(void);

#endif
