function type = m2c_doublevec(maxlen, vardim) %#codegen
% Specifies a real column vector.
%    m2c_doublevec specifies a variable-length column vector.
%
%    m2c_doublevec(c) or m2c_doublevec(c, false) specifies a fixed-length 
%        column vector with up to c numbers, where c must be a constant.
%
%    m2c_doublevec(c, true) specifies a variable-length real column vector 
%         with c numbers, where c must be a constant at compile time.
%
% See also m2c_doublemat, m2c_intmat, m2c_intvec, m2c_string

if nargin==0
    type = coder.typeof(0, [inf, 1]);
elseif nargin==1 || ~vardim
    type = coder.typeof(0, [maxlen, 1]);
else
    type = coder.typeof(0, [maxlen, 1], [1, 0]);
end
