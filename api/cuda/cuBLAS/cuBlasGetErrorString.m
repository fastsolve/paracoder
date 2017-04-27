function cstr = cuBlasGetErrorString(errCode)
switch errCode
    case CUBLAS_STATUS_SUCCESS
        cstr = ['CUBLAS_STATUS_SUCCESS' char(0)];
    case CUBLAS_STATUS_NOT_INITIALIZED
        cstr = ['CUBLAS_STATUS_NOT_INITIALIZED' char(0)];
    case CUBLAS_STATUS_ALLOC_FAILED
        cstr = ['CUBLAS_STATUS_ALLOC_FAILED' char(0)];
    case CUBLAS_STATUS_INVALID_VALUE
        cstr = ['CUBLAS_STATUS_INVALID_VALUE' char(0)];
    case CUBLAS_STATUS_ARCH_MISMATCH
        cstr = ['CUBLAS_STATUS_ARCH_MISMATCH' char(0)];
    case CUBLAS_STATUS_MAPPING_ERROR
        cstr = ['CUBLAS_STATUS_MAPPING_ERROR' char(0)];
    case CUBLAS_STATUS_EXECUTION_FAILED
        cstr = ['CUBLAS_STATUS_EXECUTION_FAILED' char(0)];
    case CUBLAS_STATUS_INTERNAL_ERROR
        cstr = ['CUBLAS_STATUS_INTERNAL_ERROR' char(0)];
    otherwise
        cstr = ['Unknown error' char(0)];
end
