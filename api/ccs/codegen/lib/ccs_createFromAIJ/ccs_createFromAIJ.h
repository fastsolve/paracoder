#ifndef CCS_CREATEFROMAIJ_H
#define CCS_CREATEFROMAIJ_H

#include "ccs_createFromAIJ_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void ccs_create1(const emxArray_int32_T *is, const emxArray_int32_T *js,
                        const emxArray_real_T *vs, int ni, int nj,
                        struct0_T *A);

extern void ccs_createFromAIJ(const emxArray_int32_T *rows,
                              const emxArray_int32_T *cols,
                              const emxArray_real_T *vs, struct0_T *A);

extern void ccs_createFromAIJ_initialize(void);

extern void ccs_createFromAIJ_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
