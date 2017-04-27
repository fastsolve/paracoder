function [prop, errCode, toplevel] = cuGetDeviceProperties(dev) %#codegen
%Returns the properties of device dev.
%
% [prop, errCode] = cuGetDeviceProperties
% [prop, errCode] = cuGetDeviceProperties(dev)
%
% If dev is not specified, then the current device used by the host thread
% will be used.
%
% The eror code is checked automatically when cuGetDevice is a top-level
% function or is compiled with debugging.
%
% See also cuGetDeviceCount, cuGetDevice, cuSetDevice, cuChooseDevice

%#codegen -args {int32(0)} cuGetDeviceProperties_arg0 -args {}

if nargin<1;
    dev = cuGetDevice;
end
errCode = int32(-1);
if isempty(coder.target);
    prop = [];
    return;
end

coder.inline('always');

t_prop = coder.opaque('struct cudaDeviceProp');
errCode = coder.ceval('cudaGetDeviceProperties', coder.wref(t_prop), dev);

toplevel = nargout>2;
if errCode && (toplevel || nargout<2 && m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cudaGetDevice returned error code %s\n', ...
        cuGetErrorString(errCode));
end

if ~isempty(coder.target) && ~toplevel
    prop = t_prop;
else
    prop = CudaDeviceProp(t_prop, 'wrap');
end
