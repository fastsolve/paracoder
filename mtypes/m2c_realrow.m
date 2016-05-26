function type = m2c_realrow(maxlen, vardim) %#codegen
% Specifies a real (double) row vector.
%    m2c_realrow() specifies a variable length row vector without upper bound.
%
%    m2c_realrow(n) or m2c_realrow(n, false) specifies a fixed-length 
%        row vector with up to n numbers, where n must be a known constant 
%        at compile time.
%
%    m2c_realrow(n, true) specifies a variable-length real row vector with
%         n numbers, where n must be a known constant at compile time.
%
% See also m2c_realmat, m2c_realcol, m2c_introw, m2c_intcol, m2c_string

if nargin==0
    type = coder.typeof(0, [1, inf]);
elseif nargin==1 || ~vardim
    type = coder.typeof(0, [1, maxlen]);
else
    type = coder.typeof(0, [1, maxlen], [0, 1]);
end
