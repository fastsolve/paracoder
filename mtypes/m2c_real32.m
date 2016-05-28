function type = m2c_real32 %#codegen
% Specifies a single-precison scalar value.
%    m2c_real32() specifies a single-precision scalar.
%
% See also m2c_real

type = coder.typeof(single(0));
