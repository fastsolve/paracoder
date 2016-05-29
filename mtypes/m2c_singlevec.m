function type = m2c_singlevec(maxlen, vardim) %#codegen
% Specifies a single-precision column vector.
%    m2c_singlevec specifies a variable-length column vector.
%
%    m2c_singlevec(c) or m2c_singlevec(c, false) specifies a fixed-length 
%        column vector with up to c numbers, where c must be a constant.
%
%    m2c_singlevec(c, true) specifies a variable-length column vector 
%         with c numbers, where c must be a constant at compile time.
%
% See also m2c_singlemat, m2c_mat, m2c_vec, m2c_string

if nargin==0
    type = coder.typeof(single(0), [inf, 1]);
elseif nargin==1 || ~vardim
    type = coder.typeof(single(0), [maxlen, 1]);
else
    type = coder.typeof(single(0), [maxlen, 1], [1, 0]);
end
