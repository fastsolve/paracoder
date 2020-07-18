#ifndef CCS_SOLVE_TRILT_H
#define CCS_SOLVE_TRILT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "ccs_solve_trilt_types.h"

extern void ccs_solve_trilt(const CCS_Matrix *L, emxArray_real_T *b);
extern void ccs_solve_trilt_initialize(void);
extern void ccs_solve_trilt_terminate(void);

#endif
