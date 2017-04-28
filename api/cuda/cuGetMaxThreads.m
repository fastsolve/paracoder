function [nthreads,threadsPB] = cuGetMaxThreads
%Returns a recommended values for the maximum number concurrent threads and
% threads per block.
%   [nthreads,threadsPB] = cuGetMaxThreads
%
%This function can only be called on the host.

%#codegen -args {}

nthreads = int32(1);
threadsPB = int32(1);
if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.cinclude('cuda4m.h');

[dev, ~] = cuGetDevice;
[prop, ~] = cuGetDeviceProperties(dev);

t_prop = coder.opaque('struct cudaDeviceProp *'); %#ok<NASGU>
t_prop = coder.ceval(' ', coder.rref(prop));
nthreads = m2c_get_cstruct_field(t_prop, 'multiProcessorCount', 'int32') * ...
    m2c_get_cstruct_field(t_prop, 'maxThreadsPerMultiProcessor', 'int32');
% Set threads per block to the warp size.
threadsPB = m2c_get_cstruct_field(t_prop, 'warpSize', 'int32');
m2c_rref(prop);
