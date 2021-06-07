#ifndef QR_QTMULTI_H
#define QR_QTMULTI_H

#include "qr_qtmulti_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void qr_qtmulti(const emxArray_real_T *A, emxArray_real_T *bs, int ncols,
                       const emxArray_real_T *V);

extern void qr_qtmulti_2args(const emxArray_real_T *A, emxArray_real_T *bs);

extern void qr_qtmulti_3args(const emxArray_real_T *A, emxArray_real_T *bs,
                             int ncols);

extern void qr_qtmulti_initialize(void);

extern void qr_qtmulti_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
