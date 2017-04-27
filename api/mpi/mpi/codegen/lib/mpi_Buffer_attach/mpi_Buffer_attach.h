#ifndef MPI_BUFFER_ATTACH_H
#define MPI_BUFFER_ATTACH_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Buffer_attach_types.h"

extern emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  int *size);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxDestroy_struct0_T(struct0_T emxArray);
extern void emxInit_struct0_T(struct0_T *pStruct);
extern void mpi_Buffer_attach(const struct0_T *ptr, int size, int *info,
  boolean_T *toplevel);
extern void mpi_Buffer_attach_initialize(void);
extern void mpi_Buffer_attach_terminate(void);

#endif
