#ifndef CCS_SOLVE_UTRIU_H
#define CCS_SOLVE_UTRIU_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "ccs_solve_utriu_types.h"

extern void ccs_solve_utriu(const CCS_Matrix *U, emxArray_real_T *b);
extern void ccs_solve_utriu_3args(const CCS_Matrix *U, emxArray_real_T *b, int
  offset);
extern void ccs_solve_utriu_initialize(void);
extern void ccs_solve_utriu_terminate(void);

#endif
