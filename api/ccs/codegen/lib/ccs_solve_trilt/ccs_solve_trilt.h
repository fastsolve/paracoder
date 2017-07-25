#ifndef CCS_SOLVE_TRILT_H
#define CCS_SOLVE_TRILT_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "ccs_solve_trilt_types.h"

extern void ccs_solve_trilt(const struct0_T *L, emxArray_real_T *b);
extern void ccs_solve_trilt_initialize(void);
extern void ccs_solve_trilt_terminate(void);

#endif
