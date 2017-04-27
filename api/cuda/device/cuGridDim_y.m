function y = cuGridDim_y
% Return the variable gridDim.y

y = int32(1);
if ~coder.target('rtw'); return; end

coder.inline('always');
coder.cinclude('cuda_runtime_api.h');

y = coder.ceval(' ', coder.opaque('int', 'gridDim.y'));
