function type = m2c_dims(maxlen, vardim) %#codegen
% Specifies an integer (int32) row vector. Useful for size specification.
%    m2c_dims() specifies a variable-length column vector.
%
%    m2c_dims(c) or m2c_dims(c, false) specifies a fixed-length 
%        column vector with up to c numbers, where c must be a constant.
%
%    m2c_dims(c, true) specifies a variable-length integer column vector 
%         with c numbers, where c must be a constant at compile time.
%
% See also m2c_intmat, m2c_intvec, m2c_string

if nargin==0
    type = coder.typeof(int32(0), [1, inf]);
elseif nargin==1 || ~vardim
    type = coder.typeof(int32(0), [1, maxlen]);
else
    type = coder.typeof(int32(0), [1, maxlen], [0, 1]);
end
