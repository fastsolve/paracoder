function [errCode, toplevel] = cuSetDevice(dev) %#codegen
%Sets the device on which the active host thread executes the device code.
%
%    errCode = cuSetDevice(dev)
%
% The eror code is checked automatically when cuSetDevice is a top-level
% function or is compiled with debugging.
%
% See also cuGetDeviceCount, cuGetDevice, cuGetDeviceProperties, cuChooseDevice


%#codegen -args {int32(0)}

errCode = int32(-1);
if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');

errCode = coder.ceval('cudaSetDevice', dev);

toplevel = nargout>1;
if errCode && (toplevel || nargout<1 && m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cudaSetDevice returned error code %s\n', ...
        cuGetErrorString(errCode));
end
