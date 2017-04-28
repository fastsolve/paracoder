function val = cuBlasGetEnum(str) %#codegen
% Obtains the value of an enumerate number in cuBLAS
%
%  val = cuBlasGetEnum(str)
%
% SEE ALSO: cuBlasGetErrorString

%#codegen -args {m2c_string}

coder.cinclude('cuda4m.h');

val = int32(0);
switch str
    case 'CUBLAS_POINTER_MODE_HOST'
        val = coder.ceval(' ', coder.opaque('int',  'CUBLAS_POINTER_MODE_HOST'));
    case 'CUBLAS_POINTER_MODE_DEVICE'
        val = coder.ceval(' ', coder.opaque('int',  'CUBLAS_POINTER_MODE_DEVICE'));
    case 'CUBLAS_ATOMICS_NOT_ALLOWED'
        val = coder.ceval(' ', coder.opaque('int',  'CUBLAS_ATOMICS_NOT_ALLOWED'));        
    case 'CUBLAS_ATOMICS_ALLOWED'
        val = coder.ceval(' ', coder.opaque('int',  'CUBLAS_ATOMICS_ALLOWED'));
    case 'CUBLAS_STATUS_SUCCESS'
        val = coder.ceval(' ', coder.opaque('int',  'CUBLAS_STATUS_SUCCESS'));
    case 'CUBLAS_STATUS_NOT_INITIALIZED'
        val = coder.ceval(' ', coder.opaque('int',  'CUBLAS_STATUS_NOT_INITIALIZED'));
    case 'CUBLAS_STATUS_ALLOC_FAILED'
        val = coder.ceval(' ', coder.opaque('int',  'CUBLAS_STATUS_ALLOC_FAILED'));
    case 'CUBLAS_STATUS_INVALID_VALUE'
        val = coder.ceval(' ', coder.opaque('int',  'CUBLAS_STATUS_INVALID_VALUE'));
    case 'CUBLAS_STATUS_ARCH_MISMATCH'
        val = coder.ceval(' ', coder.opaque('int',  'CUBLAS_STATUS_ARCH_MISMATCH'));
    case 'CUBLAS_STATUS_MAPPING_ERROR'
        val = coder.ceval(' ', coder.opaque('int',  'CUBLAS_STATUS_MAPPING_ERROR'));
    case 'CUBLAS_STATUS_EXECUTION_FAILED'
        val = coder.ceval(' ', coder.opaque('int',  'CUBLAS_STATUS_EXECUTION_FAILED'));
    case 'CUBLAS_STATUS_INTERNAL_ERROR'
        val = coder.ceval(' ', coder.opaque('int',  'CUBLAS_STATUS_INTERNAL_ERROR'));
    otherwise
        val = int32(-1);
end
