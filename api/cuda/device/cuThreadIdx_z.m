function z = cuThreadIdx_z
% Return the variable threadIdx.z

z = int32(0);
if ~coder.target('rtw'); return; end

coder.inline('always');
coder.cinclude('cuda_runtime_api.h');

z = coder.ceval(' ', coder.opaque('int', 'threadIdx.z'));
