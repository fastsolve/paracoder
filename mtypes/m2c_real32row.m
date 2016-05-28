function type = m2c_real32row(maxlen, vardim) %#codegen
% Specifies a single-precision row vector.
%    m2c_real32row specifies a variable-length row vector.
%
%    m2c_real32row(c) or m2c_real32row(c, false) specifies a fixed-length 
%        row vector with up to c numbers, where c must be a constant.
%
%    m2c_real32row(c, true) specifies a variable-length real32 row vector 
%         with c numbers, where c must be a constant at compile time.
%
% See also m2c_real32mat, m2c_real32col, m2c_realmat, m2c_realrow, m2c_string

if nargin==0
    type = coder.typeof(single(0), [1, inf]);
elseif nargin==1 || ~vardim
    type = coder.typeof(single(0), [1, maxlen]);
else
    type = coder.typeof(single(0), [1, maxlen], [0, 1]);
end
