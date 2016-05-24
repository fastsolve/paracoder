function [addr, sizepe] = m2c_ptr2bytes(cptr) %#codegen
%m2c_ptr2bytes Convert the value of the pointer address stored in to a stream of bytes.
%   [addr, len] = m2c_ptr2bytes(ptr)
%
% Note that addr is always a column vector of size 8-by-1. The
% argument len stores the number of bytes in the pointer.

coder.inline('always');
addr = zeros(8, 1, 'uint8');

sizepe = int32(0);
sizepe = coder.ceval('sizeof', coder.opaque('ctype','void *'));

ptr = coder.opaque('char *', 'NULL');
ptr = coder.ceval('(char *)', coder.rref(cptr));
for i=int32(1):sizepe
    obj.data(i) = coder.ceval('*', ptr);
    ptr = m2c_offset_ptr(ptr, int32(1));
end
end
