function y = cuBlockIdx_y
% Return the variable blockIdx.y

y = int32(0);
if ~coder.target('rtw'); return; end

coder.inline('always');
coder.cinclude('cuda_runtime_api.h');

y = coder.ceval(' ', coder.opaque('int', 'blockIdx.y'));
