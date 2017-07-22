#ifndef QR_RESCALE_H
#define QR_RESCALE_H
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "qr_rescale_types.h"

extern void qr_rescale(emxArray_real_T *A, int ncols, double tol, int *rnk,
  emxArray_real_T *V);
extern void qr_rescale_initialize(void);
extern void qr_rescale_terminate(void);

#endif
