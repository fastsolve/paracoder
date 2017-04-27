function [mat, errCode, toplevel] = cuMatCreate(m, n, type)
%Creates a matrix on a CUDA device.
%
%  [mat, errCode] = cuMatCreate(m, n, [type]) creates a matrix of
%  size m-by-n on CUDA, where type can be MCU_DOUBLE, MCU_SINGLE,
%  MCU_COMPLEX, or MCU_DOUBLE_COMPLEX, MCU_INT*, or MCU_UINT*. If 
%  not specified, then type is MCU_DOUBLE.
%
%  SEE ALSO: cuMatDestroy, cuMatCopyToGPU, cuMatCopyFromGPU

%#codegen -args {int32(0), int32(0), int32(0)}
%#codegen cuMatCreate_2args -args {int32(0), int32(0)}

toplevel = nargout>2;

if nargin<3; type = MCU_DOUBLE; end

sizepe = mcuGetSizePerElement(type);
t_mat = coder.opaque('void *');
errCode = int32(0);  %#ok<NASGU>
errCode = coder.ceval('cudaMalloc', coder.wref(t_mat), m*n*sizepe);

if errCode && (toplevel || m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cudaMalloc returned error code %s\n',...
        cuGetErrorString(errCode));
end

mat = CuMat(t_mat, type, m, n, 'wrap');

end
