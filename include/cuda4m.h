/*
 * Some kernel macros for CUDA and cuBLAS
 */

#ifndef _CU_KERNEL_
#define _CU_KERNEL_

/* Set M2C_CUDA to false by default. It can be overwritten by m2c options
 * -cuda. When enabled, user must specify the path for CUDA Toolkit. */
#ifndef M2C_CUDA  
#define M2C_CUDA    0
#endif

/* cuBLAS Type constants */
enum CUB_Types { CUB_SINGLE=4, CUB_DOUBLE=8, 
                 CUB_INT8=11, CUB_INT16=12, CUB_INT32=13, CUB_INT64=14, 
                 CUB_UINT8=21, CUB_UINT16=22, CUB_UINT32=23,CUB_UINT64=24, 
                 CUB_CHAR=31, CUB_BOOL=41, CUB_COMPLEX=108, CUB_DOUBLE_COMPLEX=116};

#if __NVCC__
#define CU_SET_THREADS(nBlks, threadsPB)    <<<nBlks, threadsPB>>>
#else
#define CU_SET_THREADS(nBlks, threadsPB)
#endif /* M2C_CUDA && __NVCC__ */

#if M2C_CUDA
#include <cuda_runtime_api.h>
#include "cublas_v2.h"                 

#else

/* CUDA runtime */
typedef int  cudaError_t;
typedef void *cudaStream_t;

inline cudaError_t cudaMalloc(void *a, int sz) { a = NULL; return -1; }
inline cudaError_t cudaFree(void * a) { return -1; }
inline const char *cudaGetErrorString(cudaError_t err) { return NULL; }

inline cudaError_t cudaThreadSynchronize() {return -1; }

struct cudaDeviceProp {
    char name[256];
    size_t totalGlobalMem;
    size_t sharedMemPerBlock;
    int regsPerBlock;
    int warpSize;
    size_t memPitch;
    int maxThreadsPerBlock;
    int maxThreadsDim[3];
    int maxGridSize[3];
    int clockRate;
    size_t totalConstMem;
    int major;
    int minor;
    size_t textureAlignment;
    size_t texturePitchAlignment;
    int deviceOverlap;
    int multiProcessorCount;
    int kernelExecTimeoutEnabled;
    int integrated;
    int canMapHostMemory;
    int computeMode;
    int maxTexture1D;
    int maxTexture1DMipmap;
    int maxTexture1DLinear;
    int maxTexture2D[2];
    int maxTexture2DMipmap[2];
    int maxTexture2DLinear[3];
    int maxTexture2DGather[2];
    int maxTexture3D[3];
    int maxTexture3DAlt[3];
    int maxTextureCubemap;
    int maxTexture1DLayered[2];
    int maxTexture2DLayered[3];
    int maxTextureCubemapLayered[2];
    int maxSurface1D;
    int maxSurface2D[2];
    int maxSurface3D[3];
    int maxSurface1DLayered[2];
    int maxSurface2DLayered[3];
    int maxSurfaceCubemap;
    int maxSurfaceCubemapLayered[2];
    size_t surfaceAlignment;
    int concurrentKernels;
    int ECCEnabled;
    int pciBusID;
    int pciDeviceID;
    int pciDomainID;
    int tccDriver;
    int asyncEngineCount;
    int unifiedAddressing;
    int memoryClockRate;
    int memoryBusWidth;
    int l2CacheSize;
    int maxThreadsPerMultiProcessor;
    int streamPrioritiesSupported;
    int globalL1CacheSupported;
    int localL1CacheSupported;
    size_t sharedMemPerMultiprocessor;
    int regsPerMultiprocessor;
    int managedMemSupported;
    int isMultiGpuBoard;
    int multiGpuBoardGroupID;
};

inline cudaError_t cudaChooseDevice(int *dev, const struct cudaDeviceProp *prop)
{*dev = 0; return -1; }
inline cudaError_t cudaGetDevice(int *dev)
{ *dev = 0; return -1; }
inline cudaError_t cudaGetDeviceProperties(struct cudaDeviceProp *prop, int dev)
{return -1; }

inline cudaError_t cudaStreamCreate(cudaStream_t *pStream)
{ pStream = NULL; return -1; }
inline cudaError_t cudaStreamDestroy(cudaStream_t strm) { return -1; }
inline cudaError_t cudaStreamSynchronize(cudaStream_t  strm) {return -1; }

/* cuBLAS */
typedef enum {CUBLAS_STATUS_SUCCESS, CUBLAS_STATUS_NOT_INITIALIZED,
        CUBLAS_STATUS_ALLOC_FAILED, CUBLAS_STATUS_INVALID_VALUE,
        CUBLAS_STATUS_ARCH_MISMATCH, CUBLAS_STATUS_MAPPING_ERROR,
        CUBLAS_STATUS_EXECUTION_FAILED, CUBLAS_STATUS_INTERNAL_ERROR} cublasStatus_t;
typedef enum {CUBLAS_POINTER_MODE_HOST, CUBLAS_POINTER_MODE_DEVICE} cublasPointerMode_t;
typedef enum {CUBLAS_ATOMICS_NOT_ALLOWED, CUBLAS_ATOMICS_ALLOWED} cublasAtomicsMode_t;

typedef void *       cublasHandle_t;
typedef creal32_T    cuComplex;
typedef creal64_T    cuDoubleComplex;

inline cublasStatus_t cublasCreate(cublasHandle_t *hdl) { hdl=NULL; return -1; }
inline cublasStatus_t cublasDestroy(cublasHandle_t hdl) { return -1; }

inline cublasStatus_t cublasGetPointerMode(cublasHandle_t handle, 
        cublasPointerMode_t *mode)
{ *mode = CUBLAS_POINTER_MODE_HOST; return -1; }
inline cublasStatus_t cublasSetPointerMode(cublasHandle_t handle, 
        cublasPointerMode_t mode) { return -1; }

inline cublasStatus_t cublasGetAtomicsMode(cublasHandle_t handle, 
        cublasAtomicsMode_t *mode)
{ *mode = CUBLAS_ATOMICS_NOT_ALLOWED; return -1; }
inline cublasStatus_t cublasSetAtomicsMode(cublasHandle_t handle, 
        cublasAtomicsMode_t mode) { return -1; }

inline cublasStatus_t cublasSetStream(cublasHandle_t hdl, cudaStream_t  strm)
{return -1; }
inline cublasStatus_t cublasGetStream(cublasHandle_t  strm, cudaStream_t *p)
{ *p = NULL; return -1; }

inline cublasStatus_t cublasSetVector(int n, int elemSize, 
        const void *hostPtr, int incx, void *devicePtr, int incy)
{ return -1; }
inline cublasStatus_t cublasSetVectorAsync(int n, int elemSize, 
        const void *hostPtr, int incx, void *devicePtr, int incy, cudaStream_t stream)
{ return -1; }

inline cublasStatus_t cublasGetVector(int n, int elemSize, 
        const void *hostPtr, int incx, void *devicePtr, int incy) 
{ return -1; }
inline cublasStatus_t cublasGetVectorAsync(int n, int elemSize, 
        const void *hostPtr, int incx, void *devicePtr, int incy, cudaStream_t stream)
{ return -1; }

inline cublasStatus_t cublasGetMatrix(int rows, int cols, int elemSize, 
        const void *A, int lda, void *B, int ldb)
{ return -1; }
inline cublasStatus_t cublasGetMatrixAsync(int rows, int cols, int elemSize, 
        const void *A, int lda, void *B, int ldb, cudaStream_t stream)
{return -1; }
inline cublasStatus_t cublasSetMatrix(int rows, int cols, int elemSize, 
        const void *A, int lda, void *B, int ldb)
{return -1; }
inline cublasStatus_t cublasSetMatrixAsync(int rows, int cols, int elemSize, 
        const void *A, int lda, void *B, int ldb, cudaStream_t stream)
{return -1; }

inline int cublasSdot(cublasHandle_t handle, int n,
        const void *x, int incx, void *y, int incy, float *result)
{ *result = 0; return -1; }
inline int cublasDdot(cublasHandle_t handle, int n,
        const void *x, int incx, void *y, int incy, double *result)
{ *result = 0; return -1; }

#define cublasCdotu(handle, n, x, incx, y, incy, result)   -1
#define cublasCdotc(handle, n, x, incx, y, incy, result)   -1

#define cublasZdotu(handle, n, x, incx, y, incy, result)   -1
#define cublasZdotc(handle, n, x, incx, y, incy, result)   -1

#endif /* M2C_CUDA */

inline void CHKCUERR(cudaError_t ierr, const char *func) {
    if (ierr) {
        M2C_error("m2c:CudaRuntimeError", "%s failed with error message %s",
            func, cudaGetErrorString(ierr));
    }
}

#endif
