#ifndef CUGETDEVICEPROPERTIES_TYPES_H
#define CUGETDEVICEPROPERTIES_TYPES_H
#include "rtwtypes.h"
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
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

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T

struct emxArray_uint8_T
{
  unsigned char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif

#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T

typedef struct emxArray_uint8_T emxArray_uint8_T;

#endif

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  emxArray_char_T *name;
  int multiProcessorCount;
  int maxThreadsPerMultiProcessor;
  int maxThreadsPerBlock;
  int warpSize;
  int concurrentKernels;
  unsigned long totalGlobalMem;
  unsigned long sharedMemPerBlock;
  unsigned long sharedMemPerMultiprocessor;
  unsigned long totalConstMem;
  int clockRate;
  int asyncEngineCount;
  int computeMode;
  int b_major;
  int b_minor;
  int maxGridSize[3];
  int maxThreadsDim[3];
  int isMultiGpuBoard;
  int canMapHostMemory;
  int managedMemory;
  int unifiedAddressing;
  int globalL1CacheSupported;
  int l2CacheSize;
  int regsPerBlock;
  int regsPerMultiprocessor;
  int memoryBusWidth;
  int memoryClockRate;
  unsigned long memPitch;
  unsigned long textureAlignment;
  int deviceOverlap;
  int kernelExecTimeoutEnabled;
  int integrated;
  int ECCEnabled;
  int pciBusID;
  int tccDriver;
} struct0_T;

#endif
#endif
