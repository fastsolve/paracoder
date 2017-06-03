#ifndef MPI_COMM_SPAWN_H
#define MPI_COMM_SPAWN_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Comm_spawn_types.h"

extern emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size);
extern emxArray_int32_T *emxCreateND_int32_T(int numDimensions, int *size);
extern emxArray_uint8_T *emxCreateND_uint8_T(int numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  int *size);
extern emxArray_int32_T *emxCreateWrapperND_int32_T(int *data, int numDimensions,
  int *size);
extern emxArray_uint8_T *emxCreateWrapperND_uint8_T(unsigned char *data, int
  numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_int32_T *emxCreateWrapper_int32_T(int *data, int rows, int cols);
extern emxArray_uint8_T *emxCreateWrapper_uint8_T(unsigned char *data, int rows,
  int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern emxArray_int32_T *emxCreate_int32_T(int rows, int cols);
extern emxArray_uint8_T *emxCreate_uint8_T(int rows, int cols);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxDestroyArray_int32_T(emxArray_int32_T *emxArray);
extern void emxDestroyArray_uint8_T(emxArray_uint8_T *emxArray);
extern void emxDestroy_struct0_T(struct0_T emxArray);
extern void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions);
extern void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_struct0_T(struct0_T *pStruct);
extern void mpi_Comm_spawn(const emxArray_char_T *command, const struct0_T *argv,
  int maxprocs, const struct0_T *mpiinfo, int root, const struct0_T *comm,
  struct0_T *intercomm, emxArray_int32_T *errcodes, int *info, boolean_T
  *toplevel);
extern void mpi_Comm_spawn_initialize(void);
extern void mpi_Comm_spawn_terminate(void);

#endif
