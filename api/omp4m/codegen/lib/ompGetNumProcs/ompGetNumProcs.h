#ifndef OMPGETNUMPROCS_H
#define OMPGETNUMPROCS_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "ompGetNumProcs_types.h"

extern int ompGetNumProcs(void);
extern void ompGetNumProcs_initialize(void);
extern void ompGetNumProcs_terminate(void);

#endif
