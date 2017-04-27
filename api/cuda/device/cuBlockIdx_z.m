function z = cuBlockIdx_z
% Return the variable blockIdx.z

z = int32(0);
if ~coder.target('rtw'); return; end

coder.inline('always');
coder.cinclude('cuda_runtime_api.h');

z = coder.ceval(' ', coder.opaque('int', 'blockIdx.z'));
