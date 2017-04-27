#ifndef MPI_SCAN_H
#define MPI_SCAN_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Scan_types.h"

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
extern void mpi_Scan(const struct0_T *sptr, const struct0_T *rptr, int count,
                     const struct1_T *datatype, const struct1_T *op, const
                     struct1_T *comm, int *info, boolean_T *toplevel);
extern void mpi_Scan_initialize(void);
extern void mpi_Scan_terminate(void);

#endif
