#ifndef COMPUTE_QTB_H
#define COMPUTE_QTB_H

#include "compute_qtb_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void compute_qtb(const emxArray_real_T *Q, emxArray_real_T *bs,
                        int ncols);

extern void compute_qtb_initialize(void);

extern void compute_qtb_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
