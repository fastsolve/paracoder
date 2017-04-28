#ifndef CUBLASGETENUM_H
#define CUBLASGETENUM_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuBlasGetEnum_types.h"

extern int cuBlasGetEnum(const emxArray_char_T *str);
extern void cuBlasGetEnum_initialize(void);
extern void cuBlasGetEnum_terminate(void);

#endif
