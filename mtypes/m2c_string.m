function type = m2c_string(maxlen, vardim) %#codegen
% Specifies a character string.
%    m2c_string() specifies a variable length string without upper bound.
%
%    m2c_string(n) or m2c_string(n, true) specifies a fixed-length 
%        string with up to n characters, where n must be a known constant 
%        at compile time.
%
%    m2c_string(n, false) specifies a variable-length string with n
%        characters, where n must be a known constant at compile time.
%
% See also m2c_doublemat, m2c_doublevec, m2c_intmat, m2c_intvec

if nargin==0 || maxlen==inf
    type = coder.typeof(char(0), [1, inf]);
elseif nargin==1 || ~vardim
    type = coder.typeof(char(0), [1, maxlen]);
else
    type = coder.typeof(char(0), [1, maxlen], [0, 1]);
end
