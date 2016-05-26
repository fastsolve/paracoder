function type = m2c_intcol(maxlen, vardim) %#codegen
% Specifies an integer (int32) column vector.
%    m2c_intcol() specifies a variable-length column vector without upper bound.
%
%    m2c_intcol(n) or m2c_intcol(n, false) specifies a fixed-length 
%        column vector with up to n numbers, where n must be a known 
%        constant at compile time.
%
%    m2c_intcol(n, true) specifies a variable-length integer column vector 
%         with n numbers, where n must be a known constant at compile time.
%
% See also m2c_realmat, m2c_realrow, m2c_realcol, m2c_introw, m2c_string

if nargin==0
    type = coder.typeof(int32(0), [inf, 1]);
elseif nargin==1 || ~vardim
    type = coder.typeof(int32(0), [maxlen, 1]);
else
    type = coder.typeof(int32(0), [maxlen, 1], [1, 0]);
end
