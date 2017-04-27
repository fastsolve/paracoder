function z = cuGridDim_z
% Return the variable gridDim.z

z = int32(1);
if ~coder.target('rtw'); return; end

coder.inline('always');
coder.cinclude('cuda_runtime_api.h');

z = coder.ceval(' ', coder.opaque('int', 'gridDim.z'));
