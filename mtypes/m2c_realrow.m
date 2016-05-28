function type = m2c_realrow(maxlen, vardim) %#codegen
% Specifies a real (double) row vector.
%    m2c_realrow() specifies a variable length row vector.
%
%    m2c_realrow(c) or m2c_realrow(c, false) specifies a fixed-length 
%        row vector with up to c numbers, where c must be a constant.
%
%    m2c_realrow(c, true) specifies a variable-length real row vector with
%         c numbers, where c must be a constant at compile time.
%
% See also m2c_realmat, m2c_realcol, m2c_introw, m2c_intcol, m2c_string

if nargin==0
    type = coder.typeof(0, [1, inf]);
elseif nargin==1 || ~vardim
    type = coder.typeof(0, [1, maxlen]);
else
    type = coder.typeof(0, [1, maxlen], [0, 1]);
end
