#ifndef SOLVE_GETRS_H
#define SOLVE_GETRS_H

#include "rtwtypes.h"
#include "solve_getrs_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void solve_getrs(const emxArray_real_T *A, emxArray_real_T *b);

extern void solve_getrs_3args(const emxArray_real_T *A, emxArray_real_T *b,
                              int n);

extern void solve_getrs_4args(const emxArray_real_T *A, emxArray_real_T *b,
                              int n, int offset);

extern void solve_getrs_initialize(void);

extern void solve_getrs_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
