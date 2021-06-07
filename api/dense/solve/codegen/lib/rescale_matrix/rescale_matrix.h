#ifndef RESCALE_MATRIX_H
#define RESCALE_MATRIX_H

#include "rescale_matrix_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void rescale_matrix(emxArray_real_T *V, int ncols, emxArray_real_T *ts);

extern void rescale_matrix_initialize(void);

extern void rescale_matrix_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
