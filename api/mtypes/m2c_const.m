function type = m2c_const(val) %#codegen
% Specifies a constant value.
%    m2c_const(val) specifies a constant.

type = coder.Constant(val);
