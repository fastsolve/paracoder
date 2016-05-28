function type = m2c_real32col(maxlen, vardim) %#codegen
% Specifies a single-precision column vector.
%    m2c_real32col specifies a variable-length column vector.
%
%    m2c_real32col(c) or m2c_real32col(c, false) specifies a fixed-length 
%        column vector with up to c numbers, where c must be a constant.
%
%    m2c_real32col(c, true) specifies a variable-length real32 column vector 
%         with c numbers, where c must be a constant at compile time.
%
% See also m2c_real32mat, m2c_real32row, m2c_realrow, m2c_realcol, m2c_string

if nargin==0
    type = coder.typeof(single(0), [inf, 1]);
elseif nargin==1 || ~vardim
    type = coder.typeof(single(0), [maxlen, 1]);
else
    type = coder.typeof(single(0), [maxlen, 1], [1, 0]);
end
