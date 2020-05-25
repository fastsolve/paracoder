#ifndef RESCALE_MATRIX_H
#define RESCALE_MATRIX_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "rescale_matrix_types.h"

extern void rescale_matrix(emxArray_real_T *V, int ncols, emxArray_real_T *ts);
extern void rescale_matrix_initialize(void);
extern void rescale_matrix_terminate(void);

#endif
