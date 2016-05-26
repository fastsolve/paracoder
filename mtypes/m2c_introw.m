function type = m2c_introw(maxlen, vardim) %#codegen
% Specifies an integer (int32) row vector.
%    m2c_introw() specifies a variable length row vector without upper bound.
%
%    m2c_introw(n) or m2c_introw(n, false) specifies a fixed-length 
%        row vector with up to n numbers, where n must be a known constant 
%        at compile time.
%
%    m2c_introw(n, true) specifies a variable-length integer row vector 
%         with n numbers, where n must be a known constant at compile time.
%
% See also m2c_realmat, m2c_realrow, m2c_realcol, m2c_intcol, m2c_string

if nargin==0
    type = coder.typeof(int32(0), [1, inf]);
elseif nargin==1 || ~vardim
    type = coder.typeof(int32(0), [1, maxlen]);
else
    type = coder.typeof(int32(0), [1, maxlen], [0, 1]);
end
