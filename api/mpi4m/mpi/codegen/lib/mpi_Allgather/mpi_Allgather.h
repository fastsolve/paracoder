#ifndef MPI_ALLGATHER_H
#define MPI_ALLGATHER_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Allgather_types.h"

extern emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size);
extern emxArray_uint8_T *emxCreateND_uint8_T(int numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  int *size);
extern emxArray_uint8_T *emxCreateWrapperND_uint8_T(unsigned char *data, int
  numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_uint8_T *emxCreateWrapper_uint8_T(unsigned char *data, int rows,
  int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern emxArray_uint8_T *emxCreate_uint8_T(int rows, int cols);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxDestroyArray_uint8_T(emxArray_uint8_T *emxArray);
extern void emxDestroy_struct0_T(struct0_T emxArray);
extern void emxDestroy_struct1_T(struct1_T emxArray);
extern void emxInit_struct0_T(struct0_T *pStruct);
extern void emxInit_struct1_T(struct1_T *pStruct);
extern void mpi_Allgather(const struct0_T *sptr, int scount, const struct1_T
  *stype, const struct0_T *rptr, int rcount, const struct1_T *rtype, const
  struct1_T *comm, int *info, boolean_T *toplevel);
extern void mpi_Allgather_initialize(void);
extern void mpi_Allgather_terminate(void);

#endif
