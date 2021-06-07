#ifndef CCS_SOLVE_UTRIU_TYPES_H
#define CCS_SOLVE_UTRIU_TYPES_H

#include "rtwtypes.h"

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif

#ifndef typedef_CCS_Matrix
#define typedef_CCS_Matrix
typedef struct {
  emxArray_int32_T *col_ptr;
  emxArray_int32_T *row_ind;
  emxArray_real_T *val;
  int nrows;
  int ncols;
} CCS_Matrix;
#endif

#endif
