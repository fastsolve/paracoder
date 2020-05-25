#ifndef COMPUTE_QTB_H
#define COMPUTE_QTB_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "compute_qtb_types.h"

extern void compute_qtb(const emxArray_real_T *Q, emxArray_real_T *bs, int ncols);
extern void compute_qtb_initialize(void);
extern void compute_qtb_terminate(void);

#endif
