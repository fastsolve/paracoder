#ifndef QR_QMULTI_H
#define QR_QMULTI_H

#include "qr_qmulti_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void qr_qmulti(const emxArray_real_T *A, emxArray_real_T *bs, int ncols,
                      const emxArray_real_T *V);

extern void qr_qmulti_2args(const emxArray_real_T *A, emxArray_real_T *bs);

extern void qr_qmulti_3args(const emxArray_real_T *A, emxArray_real_T *bs,
                            int ncols);

extern void qr_qmulti_initialize(void);

extern void qr_qmulti_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
