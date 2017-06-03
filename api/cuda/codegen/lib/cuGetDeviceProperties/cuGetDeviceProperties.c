#include "cuGetDeviceProperties.h"
#include "m2c.h"
#include "cuda4m.h"

static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_char_T(&pStruct->name);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_char_T(&pStruct->name, 2);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("CUDA:RuntimeError", "cudaGetDevice returned error code %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void cuGetDeviceProperties(int dev, struct0_T *prop, int *errCode, boolean_T
  *toplevel)
{
  struct cudaDeviceProp t_prop;
  emxArray_uint8_T *msg0;
  emxArray_char_T *name;
  struct cudaDeviceProp * b_t_prop;
  const char * ptr;
  int i0;
  int len;
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  int maxThreadsDim[3];
  const int * val;
  int maxGridSize[3];
  emxArray_char_T *d_msg0;
  *errCode = cudaGetDeviceProperties(&t_prop, dev);
  *toplevel = true;
  if (*errCode != 0) {
    emxInit_uint8_T(&msg0, 2);
    ptr = cudaGetErrorString(*errCode);
    len = strlen(ptr) + 1;
    i0 = msg0->size[0] * msg0->size[1];
    msg0->size[0] = 1;
    msg0->size[1] = len;
    emxEnsureCapacity((emxArray__common *)msg0, i0, (int)sizeof(unsigned char));
    for (i0 = 0; i0 < len; i0++) {
      msg0->data[i0] = 0;
    }

    memcpy(&msg0->data[0], ptr, len);
    if (1 > len) {
      len = 0;
    }

    emxInit_char_T(&b_msg0, 2);
    emxInit_uint8_T(&c_msg0, 2);
    i0 = c_msg0->size[0] * c_msg0->size[1];
    c_msg0->size[0] = 1;
    c_msg0->size[1] = len;
    emxEnsureCapacity((emxArray__common *)c_msg0, i0, (int)sizeof(unsigned char));
    for (i0 = 0; i0 < len; i0++) {
      c_msg0->data[c_msg0->size[0] * i0] = msg0->data[i0];
    }

    emxFree_uint8_T(&msg0);
    emxInit_char_T(&d_msg0, 1);
    i0 = d_msg0->size[0];
    d_msg0->size[0] = len;
    emxEnsureCapacity((emxArray__common *)d_msg0, i0, (int)sizeof(char));
    for (i0 = 0; i0 < len; i0++) {
      d_msg0->data[i0] = (signed char)c_msg0->data[i0];
    }

    emxFree_uint8_T(&c_msg0);
    i0 = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = len;
    emxEnsureCapacity((emxArray__common *)b_msg0, i0, (int)sizeof(char));
    for (i0 = 0; i0 < len; i0++) {
      b_msg0->data[b_msg0->size[0] * i0] = d_msg0->data[i0];
    }

    emxFree_char_T(&d_msg0);
    m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }

  emxInit_char_T(&name, 2);
  b_t_prop = (&t_prop);
  i0 = name->size[0] * name->size[1];
  name->size[0] = 1;
  name->size[1] = 256;
  emxEnsureCapacity((emxArray__common *)name, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 256; i0++) {
    name->data[i0] = '\x00';
  }

  ptr = b_t_prop->name;
  strcpy(&name->data[0], ptr);
  ptr = b_t_prop->name;
  len = strlen(ptr);
  val = b_t_prop->maxThreadsDim;
  memcpy(maxThreadsDim, val, 12);
  val = b_t_prop->maxGridSize;
  memcpy(maxGridSize, val, 12);
  if (1 > len) {
    len = 0;
  }

  i0 = prop->name->size[0] * prop->name->size[1];
  prop->name->size[0] = 1;
  prop->name->size[1] = len;
  emxEnsureCapacity((emxArray__common *)prop->name, i0, (int)sizeof(char));
  for (i0 = 0; i0 < len; i0++) {
    prop->name->data[prop->name->size[0] * i0] = name->data[i0];
  }

  emxFree_char_T(&name);
  for (i0 = 0; i0 < 3; i0++) {
    prop->maxGridSize[i0] = maxGridSize[i0];
  }

  for (i0 = 0; i0 < 3; i0++) {
    prop->maxThreadsDim[i0] = maxThreadsDim[i0];
  }

  prop->multiProcessorCount = b_t_prop->multiProcessorCount;
  prop->maxThreadsPerMultiProcessor = b_t_prop->maxThreadsPerMultiProcessor;
  prop->maxThreadsPerBlock = b_t_prop->maxThreadsPerBlock;
  prop->warpSize = b_t_prop->warpSize;
  prop->concurrentKernels = b_t_prop->concurrentKernels;
  prop->totalGlobalMem = b_t_prop->totalGlobalMem;
  prop->sharedMemPerBlock = b_t_prop->sharedMemPerBlock;
  prop->sharedMemPerMultiprocessor = b_t_prop->sharedMemPerMultiprocessor;
  prop->totalConstMem = b_t_prop->totalConstMem;
  prop->clockRate = b_t_prop->clockRate;
  prop->asyncEngineCount = b_t_prop->asyncEngineCount;
  prop->computeMode = b_t_prop->computeMode;
  prop->b_major = b_t_prop->major;
  prop->b_minor = b_t_prop->minor;
  prop->isMultiGpuBoard = b_t_prop->isMultiGpuBoard;
  prop->canMapHostMemory = b_t_prop->canMapHostMemory;
  prop->managedMemory = b_t_prop->managedMemory;
  prop->unifiedAddressing = b_t_prop->unifiedAddressing;
  prop->globalL1CacheSupported = b_t_prop->globalL1CacheSupported;
  prop->l2CacheSize = b_t_prop->l2CacheSize;
  prop->regsPerBlock = b_t_prop->regsPerBlock;
  prop->regsPerMultiprocessor = b_t_prop->regsPerMultiprocessor;
  prop->memoryBusWidth = b_t_prop->memoryBusWidth;
  prop->memoryClockRate = b_t_prop->memoryClockRate;
  prop->memPitch = b_t_prop->memPitch;
  prop->textureAlignment = b_t_prop->textureAlignment;
  prop->deviceOverlap = b_t_prop->deviceOverlap;
  prop->kernelExecTimeoutEnabled = b_t_prop->kernelExecTimeoutEnabled;
  prop->integrated = b_t_prop->integrated;
  prop->ECCEnabled = b_t_prop->ECCEnabled;
  prop->pciBusID = b_t_prop->pciBusID;
  prop->tccDriver = b_t_prop->tccDriver;

}

void cuGetDeviceProperties_arg0(struct0_T *prop, int *errCode, boolean_T
  *toplevel)
{
  int dev;
  struct cudaDeviceProp t_prop;
  int b_errCode;
  emxArray_uint8_T *msg0;
  emxArray_char_T *name;
  struct cudaDeviceProp * b_t_prop;
  const char * ptr;
  int i2;
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  int maxThreadsDim[3];
  const int * val;
  int maxGridSize[3];
  emxArray_char_T *d_msg0;
  cudaGetDevice(&dev);
  b_errCode = cudaGetDeviceProperties(&t_prop, dev);
  if (b_errCode != 0) {
    emxInit_uint8_T(&msg0, 2);
    ptr = cudaGetErrorString(b_errCode);
    dev = strlen(ptr) + 1;
    i2 = msg0->size[0] * msg0->size[1];
    msg0->size[0] = 1;
    msg0->size[1] = dev;
    emxEnsureCapacity((emxArray__common *)msg0, i2, (int)sizeof(unsigned char));
    for (i2 = 0; i2 < dev; i2++) {
      msg0->data[i2] = 0;
    }

    memcpy(&msg0->data[0], ptr, dev);
    if (1 > dev) {
      dev = 0;
    }

    emxInit_char_T(&b_msg0, 2);
    emxInit_uint8_T(&c_msg0, 2);
    i2 = c_msg0->size[0] * c_msg0->size[1];
    c_msg0->size[0] = 1;
    c_msg0->size[1] = dev;
    emxEnsureCapacity((emxArray__common *)c_msg0, i2, (int)sizeof(unsigned char));
    for (i2 = 0; i2 < dev; i2++) {
      c_msg0->data[c_msg0->size[0] * i2] = msg0->data[i2];
    }

    emxFree_uint8_T(&msg0);
    emxInit_char_T(&d_msg0, 1);
    i2 = d_msg0->size[0];
    d_msg0->size[0] = dev;
    emxEnsureCapacity((emxArray__common *)d_msg0, i2, (int)sizeof(char));
    for (i2 = 0; i2 < dev; i2++) {
      d_msg0->data[i2] = (signed char)c_msg0->data[i2];
    }

    emxFree_uint8_T(&c_msg0);
    i2 = b_msg0->size[0] * b_msg0->size[1];
    b_msg0->size[0] = 1;
    b_msg0->size[1] = dev;
    emxEnsureCapacity((emxArray__common *)b_msg0, i2, (int)sizeof(char));
    for (i2 = 0; i2 < dev; i2++) {
      b_msg0->data[b_msg0->size[0] * i2] = d_msg0->data[i2];
    }

    emxFree_char_T(&d_msg0);
    m2c_error(b_msg0);
    emxFree_char_T(&b_msg0);
  }

  emxInit_char_T(&name, 2);
  b_t_prop = (&t_prop);
  i2 = name->size[0] * name->size[1];
  name->size[0] = 1;
  name->size[1] = 256;
  emxEnsureCapacity((emxArray__common *)name, i2, (int)sizeof(char));
  for (i2 = 0; i2 < 256; i2++) {
    name->data[i2] = '\x00';
  }

  ptr = b_t_prop->name;
  strcpy(&name->data[0], ptr);
  ptr = b_t_prop->name;
  dev = strlen(ptr);
  val = b_t_prop->maxThreadsDim;
  memcpy(maxThreadsDim, val, 12);
  val = b_t_prop->maxGridSize;
  memcpy(maxGridSize, val, 12);
  if (1 > dev) {
    dev = 0;
  }

  i2 = prop->name->size[0] * prop->name->size[1];
  prop->name->size[0] = 1;
  prop->name->size[1] = dev;
  emxEnsureCapacity((emxArray__common *)prop->name, i2, (int)sizeof(char));
  for (i2 = 0; i2 < dev; i2++) {
    prop->name->data[prop->name->size[0] * i2] = name->data[i2];
  }

  emxFree_char_T(&name);
  for (i2 = 0; i2 < 3; i2++) {
    prop->maxGridSize[i2] = maxGridSize[i2];
  }

  for (i2 = 0; i2 < 3; i2++) {
    prop->maxThreadsDim[i2] = maxThreadsDim[i2];
  }

  prop->multiProcessorCount = b_t_prop->multiProcessorCount;
  prop->maxThreadsPerMultiProcessor = b_t_prop->maxThreadsPerMultiProcessor;
  prop->maxThreadsPerBlock = b_t_prop->maxThreadsPerBlock;
  prop->warpSize = b_t_prop->warpSize;
  prop->concurrentKernels = b_t_prop->concurrentKernels;
  prop->totalGlobalMem = b_t_prop->totalGlobalMem;
  prop->sharedMemPerBlock = b_t_prop->sharedMemPerBlock;
  prop->sharedMemPerMultiprocessor = b_t_prop->sharedMemPerMultiprocessor;
  prop->totalConstMem = b_t_prop->totalConstMem;
  prop->clockRate = b_t_prop->clockRate;
  prop->asyncEngineCount = b_t_prop->asyncEngineCount;
  prop->computeMode = b_t_prop->computeMode;
  prop->b_major = b_t_prop->major;
  prop->b_minor = b_t_prop->minor;
  prop->isMultiGpuBoard = b_t_prop->isMultiGpuBoard;
  prop->canMapHostMemory = b_t_prop->canMapHostMemory;
  prop->managedMemory = b_t_prop->managedMemory;
  prop->unifiedAddressing = b_t_prop->unifiedAddressing;
  prop->globalL1CacheSupported = b_t_prop->globalL1CacheSupported;
  prop->l2CacheSize = b_t_prop->l2CacheSize;
  prop->regsPerBlock = b_t_prop->regsPerBlock;
  prop->regsPerMultiprocessor = b_t_prop->regsPerMultiprocessor;
  prop->memoryBusWidth = b_t_prop->memoryBusWidth;
  prop->memoryClockRate = b_t_prop->memoryClockRate;
  prop->memPitch = b_t_prop->memPitch;
  prop->textureAlignment = b_t_prop->textureAlignment;
  prop->deviceOverlap = b_t_prop->deviceOverlap;
  prop->kernelExecTimeoutEnabled = b_t_prop->kernelExecTimeoutEnabled;
  prop->integrated = b_t_prop->integrated;
  prop->ECCEnabled = b_t_prop->ECCEnabled;
  prop->pciBusID = b_t_prop->pciBusID;
  prop->tccDriver = b_t_prop->tccDriver;

  *errCode = b_errCode;
  *toplevel = true;
}

void cuGetDeviceProperties_initialize(void)
{
}

void cuGetDeviceProperties_terminate(void)
{
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}
