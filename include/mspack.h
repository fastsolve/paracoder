/*
 * Some kernel macros for sparse matrices
 */

#ifndef _MSP_KERNEL_
#define _MSP_KERNEL_

/* Set M2C_MKL to false by default. Can be overwritten by m2c options -mkl. */
#ifndef M2C_MKL  
#define M2C_MKL    0
#endif

/* Set M2C_BLAS to false by default. Can be overwritten by m2c options -blas. */
#ifndef M2C_BLAS
#if M2C_MKL
#define M2C_BLAS    1
#else
#define M2C_BLAS    0
#endif
#endif

#if M2C_MKL
#include "mkl_cblas.h"
#include "mkl_spblas.h"
#elif M2C_BLAS
#include "cblas.h"
#else

#define cblas_sdsdot(N, alpha, X, incX, Y, incY)     0
#define cblas_ddsdot(N, alpha, X, incX, Y, incY)     0

#define cblas_sdot(N, X, incX, Y, incY)              0
#define cblas_ddot(N, X, incX, Y, incY)              0

#define cblas_cdotu_sub(N, X, incX, Y, incY, dotu)
#define cblas_cdotc_sub(N, X, incX, Y, incY, dotc)

#define cblas_zdotu_sub(N, X, incX, Y, incY, dotu)
#define cblas_zdotc_sub(N, X, incX, Y, incY, dotc)

#endif /* M2C_BLAS */

#include "mcuda.h"

#if M2C_CUDA

#include "cusparse.h"

#else

/* cuSparse*/
typedef enum {CUSPARSE_STATUS_SUCCESS, CUSPARSE_STATUS_NOT_INITIALIZED,
        CUSPARSE_STATUS_ALLOC_FAILED, CUSPARSE_STATUS_INVALID_VALUE,
        CUSPARSE_STATUS_ARCH_MISMATCH, CUSPARSE_STATUS_MAPPING_ERROR,
        CUSPARSE_STATUS_EXECUTION_FAILED, CUSPARSE_STATUS_INTERNAL_ERROR, 
        CUSPARSE_STATUS_MATRIX_TYPE_NOT_SUPPORTED} cusparseStatus_t;
typedef enum {CUSPARSE_POINTER_MODE_HOST, 
        CUSPARSE_POINTER_MODE_DEVICE} cusparsePointerMode_t;

typedef enum {CUSPARSE_DIAG_TYPE_NON_UNIT, CUSPARSE_DIAG_TYPE_UNIT} 
        cusparseDiagType_t;
typedef enum {CUSPARSE_FILL_MODE_LOWER, CUSPARSE_FILL_MODE_UPPER} 
        cusparseFillMode_t;
typedef enum {CUSPARSE_INDEX_BASE_ZERO, CUSPARSE_INDEX_BASE_ONE} 
        cusparseIndexBase_t;
typedef enum {CUSPARSE_MATRIX_TYPE_GENERAL, CUSPARSE_MATRIX_TYPE_SYMMETRIC,
        CUSPARSE_MATRIX_TYPE_HERMITIAN, CUSPARSE_MATRIX_TYPE_TRIANGULAR}
        cusparseMatrixType_t;
typedef enum {CUSPARSE_DIRECTION_ROW, CUSPARSE_DIRECTION_COLUMN} 
        cusparseDirection_t;
        typedef enum {CUSPARSE_OPERATION_NON_TRANSPOSE, CUSPARSE_OPERATION_TRANSPOSE,
        CUSPARSE_OPERATION_CONJUGATE_TRANSPOSE} cusparseOperation_t;
        
typedef void *       cusparseHandle_t;

typedef struct { 
    cusparseMatrixType_t MatrixType; 
    cusparseFillMode_t FillMode; 
    cusparseDiagType_t DiagType; 
    cusparseIndexBase_t IndexBase; }
cusparseMatDescr_t;

inline cusparseStatus_t
cusparseCreate(cusparseHandle_t *hdl) { hdl=NULL; return -1; }
inline cusparseStatus_t 
cusparseDestroy(cusparseHandle_t hdl) { return -1; }

inline cusparseStatus_t 
cusparseSetStream(cusparseHandle_t hdl, cudaStream_t strm) { return -1; }

inline cusparseStatus_t cusparseGetPointerMode(cusparseHandle_t handle, 
        cusparsePointerMode_t *mode)
{ *mode = CUSPARSE_POINTER_MODE_HOST; return -1; }
inline cusparseStatus_t cusparseSetPointerMode(cusparseHandle_t handle, 
        cusparsePointerMode_t mode)
{ return -1; }

#endif /* M2C_CUDA for cusparse */

#endif
