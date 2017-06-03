#include "cuChooseDevice.h"
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

  M2C_error("CUDA:RuntimeError", "cudaChooseDevice returned error code %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void cuChooseDevice(const struct0_T *prop, int *dev, int *errCode, boolean_T
                    *toplevel)
{
  emxArray_char_T *name;
  struct cudaDeviceProp prop_obj;
  struct cudaDeviceProp * t_prop;
  int i0;
  int len;
  char * val;
  int maxThreadsDim[3];
  int * b_val;
  emxArray_uint8_T *msg0;
  const char * ptr;
  emxArray_char_T *b_msg0;
  emxArray_uint8_T *c_msg0;
  emxArray_char_T *d_msg0;
  emxInit_char_T(&name, 2);
  t_prop = (&prop_obj);
  t_prop->multiProcessorCount = prop->multiProcessorCount;
  t_prop->maxThreadsPerMultiProcessor = prop->maxThreadsPerMultiProcessor;
  t_prop->maxThreadsPerBlock = prop->maxThreadsPerBlock;
  t_prop->warpSize = prop->warpSize;
  t_prop->concurrentKernels = prop->concurrentKernels;
  t_prop->totalGlobalMem = prop->totalGlobalMem;
  t_prop->sharedMemPerBlock = prop->sharedMemPerBlock;
  t_prop->sharedMemPerMultiprocessor = prop->sharedMemPerMultiprocessor;
  t_prop->totalConstMem = prop->totalConstMem;
  t_prop->clockRate = prop->clockRate;
  t_prop->asyncEngineCount = prop->asyncEngineCount;
  t_prop->major = prop->b_major;
  t_prop->minor = prop->b_minor;
  t_prop->computeMode = prop->computeMode;
  t_prop->isMultiGpuBoard = prop->isMultiGpuBoard;
  t_prop->canMapHostMemory = prop->canMapHostMemory;
  t_prop->managedMemory = prop->managedMemory;
  t_prop->unifiedAddressing = prop->unifiedAddressing;
  t_prop->globalL1CacheSupported = prop->globalL1CacheSupported;
  t_prop->l2CacheSize = prop->l2CacheSize;
  t_prop->regsPerBlock = prop->regsPerBlock;
  t_prop->regsPerMultiprocessor = prop->regsPerMultiprocessor;
  t_prop->memoryBusWidth = prop->memoryBusWidth;
  t_prop->memoryClockRate = prop->memoryClockRate;
  t_prop->memPitch = prop->memPitch;
  t_prop->textureAlignment = prop->textureAlignment;
  t_prop->deviceOverlap = prop->deviceOverlap;
  t_prop->kernelExecTimeoutEnabled = prop->kernelExecTimeoutEnabled;
  t_prop->integrated = prop->integrated;
  t_prop->ECCEnabled = prop->ECCEnabled;
  t_prop->pciBusID = prop->pciBusID;
  t_prop->tccDriver = prop->tccDriver;
  i0 = name->size[0] * name->size[1];
  name->size[0] = 1;
  name->size[1] = prop->name->size[1] + 1;
  emxEnsureCapacity((emxArray__common *)name, i0, (int)sizeof(char));
  len = prop->name->size[1];
  for (i0 = 0; i0 < len; i0++) {
    name->data[name->size[0] * i0] = prop->name->data[prop->name->size[0] * i0];
  }

  name->data[name->size[0] * prop->name->size[1]] = '\x00';
  val = t_prop->name;
  strcpy(val, &name->data[0]);
  emxFree_char_T(&name);
  for (i0 = 0; i0 < 3; i0++) {
    maxThreadsDim[i0] = prop->maxThreadsDim[i0];
  }

  b_val = t_prop->maxThreadsDim;
  memcpy(b_val, maxThreadsDim, 12);
  for (i0 = 0; i0 < 3; i0++) {
    maxThreadsDim[i0] = prop->maxGridSize[i0];
  }

  b_val = t_prop->maxGridSize;
  memcpy(b_val, maxThreadsDim, 12);
  *errCode = cudaChooseDevice(dev, &prop_obj);
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
}

void cuChooseDevice_initialize(void)
{
}

void cuChooseDevice_terminate(void)
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
