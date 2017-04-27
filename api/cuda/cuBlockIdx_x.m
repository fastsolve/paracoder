function x = cuBlockIdx_x
% Return the variable blockIdx.x

x = int32(0);
if ~coder.target('rtw'); return; end

coder.inline('always');
coder.cinclude('cuda_runtime_api.h');

x = coder.ceval(' ', coder.opaque('int', 'blockIdx.x'));
