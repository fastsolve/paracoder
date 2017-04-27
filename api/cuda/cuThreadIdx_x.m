function x = cuThreadIdx_x
% Return the variable threadIdx.x

x = int32(0);
if ~coder.target('rtw'); return; end

coder.inline('always');
coder.cinclude('cuda_runtime_api.h');

x = coder.ceval(' ', coder.opaque('int', 'threadIdx.x'));
