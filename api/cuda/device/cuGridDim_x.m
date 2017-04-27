function x = cuGridDim_x
% Return the variable gridDim.x

x = int32(1);
if ~coder.target('rtw'); return; end

coder.inline('always');
coder.cinclude('cuda_runtime_api.h');

x = coder.ceval(' ', coder.opaque('int', 'gridDim.x'));
