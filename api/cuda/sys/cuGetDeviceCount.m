function [n, errCode, toplevel] = cuGetDeviceCount %#codegen
%Returns the number of devices that are available for execution.
%
% [n, errCode] = cuGetDeviceCount
%
% The eror code is checked automatically when cuGetDevice is a top-level
% function or is compiled with debugging.
%
% See also cuSetDevice, cuGetDevice, cuGetDeviceProperties, cuChooseDevice


%#codegen -args {}

n = int32(0);
errCode = int32(-1);
if isempty(coder.target); return; end

coder.inline('always');

errCode = coder.ceval('cudaGetDeviceCount', coder.wref(n));

toplevel = nargout>2;
if errCode && (toplevel || nargout<2 && m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cudaGetDeviceCount returned error code %s\n', cuGetErrorString(errCode));
end
