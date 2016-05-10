function msg_error(varargin) %#codegen
%msg_error is now m2c_error.
%
% SEE ALSO: m2c_error, m2c_warn, m2c_printf

coder.inline('always');
m2c_error(varargin{:});
