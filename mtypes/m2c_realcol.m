function type = m2c_realcol(maxlen, vardim) %#codegen
% Specifies an real column vector.
%    m2c_realcol specifies a variable-length column vector without upper bound.
%
%    m2c_realcol(n) or m2c_realcol(n, false) specifies a fixed-length 
%        column vector with up to n numbers, where n must be a 
%        constant at compile time.
%
%    m2c_realcol(n, true) specifies a variable-length real column vector 
%         with n numbers, where n must be a constant at compile
%         time.
%
% See also m2c_realmat, m2c_realrow, m2c_introw, m2c_intcol, m2c_string

if nargin==0
    type = coder.typeof(0, [inf, 1]);
elseif nargin==1 || ~vardim
    type = coder.typeof(0, [maxlen, 1]);
else
    type = coder.typeof(0, [maxlen, 1], [1, 0]);
end
