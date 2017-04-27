function [dev, errCode, toplevel] = cuGetDevice %#codegen
%Returns the device on which the active host thread executes the device code.
%
% [dev, errCode] = cuGetDevice
%
% The eror code is checked automatically when cuGetDevice is a top-level
% function or is compiled with debugging.
%
% See also cuGetDeviceCount, cuSetDevice, cuGetDeviceProperties, cuChooseDevice

%#codegen -args {}

dev = int32(-1);
errCode = int32(-1);
if isempty(coder.target); return; end

coder.inline('always');
errCode = coder.ceval('cudaGetDevice', coder.wref(dev));

toplevel = nargout>2;
if errCode && (toplevel || nargout<2 && m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cudaGetDevice returned error code %s\n', ...
        cuGetErrorString(errCode));
end
