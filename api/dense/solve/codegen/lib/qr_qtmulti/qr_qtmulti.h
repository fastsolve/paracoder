#ifndef QR_QTMULTI_H
#define QR_QTMULTI_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "qr_qtmulti_types.h"

extern void qr_qtmulti(const emxArray_real_T *A, emxArray_real_T *bs, int ncols,
  const emxArray_real_T *V);
extern void qr_qtmulti_initialize(void);
extern void qr_qtmulti_terminate(void);

#endif
