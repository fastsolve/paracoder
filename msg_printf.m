function msg_printf(varargin) %#codegen
%msg_printf is now m2c_printf
%
% SEE ALSO: m2c_printf, m2c_error, m2c_warn

coder.inline('always');
m2c_printf(varargin{:});
