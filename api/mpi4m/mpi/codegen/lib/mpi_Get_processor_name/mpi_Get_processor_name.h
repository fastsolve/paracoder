#ifndef MPI_GET_PROCESSOR_NAME_H
#define MPI_GET_PROCESSOR_NAME_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Get_processor_name_types.h"

extern emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  int *size);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions);
extern void mpi_Get_processor_name(emxArray_char_T *name, int *info, boolean_T
  *toplevel);
extern void mpi_Get_processor_name_initialize(void);
extern void mpi_Get_processor_name_terminate(void);

#endif
