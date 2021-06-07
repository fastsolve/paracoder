#ifndef MPI_BUFFER_ATTACH_TYPES_H
#define MPI_BUFFER_ATTACH_TYPES_H

#include "rtwtypes.h"

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T
struct emxArray_char_T {
  char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif
#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T
typedef struct emxArray_char_T emxArray_char_T;
#endif

#ifndef typedef_M2C_OpaquePtrType
#define typedef_M2C_OpaquePtrType
typedef struct {
  unsigned long data;
  emxArray_char_T *type;
  int nbytes;
  int offset;
} M2C_OpaquePtrType;
#endif

#endif
