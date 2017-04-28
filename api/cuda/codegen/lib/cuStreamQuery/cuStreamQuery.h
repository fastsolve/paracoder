#ifndef CUSTREAMQUERY_H
#define CUSTREAMQUERY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuStreamQuery_types.h"

extern int cuStreamQuery(const struct0_T *stm);
extern void cuStreamQuery_initialize(void);
extern void cuStreamQuery_terminate(void);

#endif
