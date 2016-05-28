function type = m2c_single %#codegen
% Specifies a single-precison scalar value.
%    m2c_single() specifies a single-precision scalar.
%
% See also m2c_double

type = coder.typeof(single(0));
