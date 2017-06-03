#ifndef MPI_GET_SIZEOF_H
#define MPI_GET_SIZEOF_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_get_sizeof_types.h"

extern emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  int *size);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions);
extern int mpi_get_sizeof(const emxArray_char_T *typename);
extern void mpi_get_sizeof_initialize(void);
extern void mpi_get_sizeof_terminate(void);

#endif
