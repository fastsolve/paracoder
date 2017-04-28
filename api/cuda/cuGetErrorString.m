function msg = cuGetErrorString(errcode)
%Returns a string for a given error code.
%
% msg = cuGetErrorString(errcode)
%
% C interface:
%     const char *cuGetErrorString(int errorcode)

coder.inline('always');
coder.cinclude('cuda4m.h');

ptr = coder.opaque('const char *'); %#ok<NASGU>
ptr = coder.ceval('cudaGetErrorString', errcode);

len = int32(0); %#ok<NASGU>
len = coder.ceval('strlen', ptr);

msg0 = zeros(1, len+1, 'uint8');
coder.ceval('memcpy', coder.ref(msg0), ptr, len+1);

msg = char(msg0(1:len+1));
