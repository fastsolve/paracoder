#ifndef CCS_SOLVE_TRIU_H
#define CCS_SOLVE_TRIU_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "ccs_solve_triu_types.h"

extern void ccs_solve_triu(const struct0_T *U, emxArray_real_T *b);
extern void ccs_solve_triu_initialize(void);
extern void ccs_solve_triu_terminate(void);

#endif
