function [dev, errCode, toplevel] = cuChooseDevice(prop) %#codegen
%Returns the device which has properties that best match the given prop.
%
% [dev, errCode] = cuChooseDevice(prop)
%
% The eror code is checked automatically when cuGetDevice is a top-level
% function or is compiled with debugging.
%
% See also cuGetDeviceCount, cuGetDevice, cuSetDevice,
% cuGetDeviceProperties

%#codegen -args {CudaDeviceProp}

errCode = int32(-1);
dev = int32(0);
if isempty(coder.target);
    return;
end

coder.inline('always');

t_prop = CudaDeviceProp(prop);
errCode = coder.ceval('cudaChooseDevice', coder.wref(dev), coder.rref(t_prop));

toplevel = nargout>2;
if errCode && (toplevel || nargout<2 && m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cudaChooseDevice returned error code %s\n', ...
        cuGetErrorString(errCode));
end
