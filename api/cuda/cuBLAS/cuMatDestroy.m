function [errCode, toplevel] = cuMatDestroy(mat)
%Destroys a dense matrix on a CUDA device.
%
%  errCode = cuMatDestroy(mat)
%  mat - Handle to matrix
%
%  SEE ALSO: cuMatCreate

%#codegen -args {CuMat}

errCode = int32(-1);  %#ok<NASGU>
toplevel = nargout>1;

errCode = coder.ceval('cudaFree', CuMat(mat, 'void *'));

if errCode && (toplevel || m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cudaFree returned error code %s\n', cuGetErrorString(errCode));
end
end
