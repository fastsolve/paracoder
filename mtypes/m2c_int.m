function type = m2c_int %#codegen
% Specifies an integer (int32) scalar.
%    m2c_int() specifies an integer scalar.
%
% See also m2c_real

type = coder.typeof(int32(0));
