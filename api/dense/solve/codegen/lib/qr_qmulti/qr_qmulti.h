#ifndef QR_QMULTI_H
#define QR_QMULTI_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "qr_qmulti_types.h"

extern void qr_qmulti(const emxArray_real_T *A, emxArray_real_T *bs, int ncols,
                      const emxArray_real_T *V);
extern void qr_qmulti_initialize(void);
extern void qr_qmulti_terminate(void);

#endif
