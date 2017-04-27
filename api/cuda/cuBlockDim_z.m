function z = cuBlockDim_z
% Return the variable blockDim.z

z = int32(1);
if ~coder.target('rtw'); return; end

coder.inline('always');
coder.cinclude('cuda_runtime_api.h');

z = coder.ceval(' ', coder.opaque('int', 'blockDim.z'));
