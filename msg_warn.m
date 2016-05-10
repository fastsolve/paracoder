function msg_warn(varargin) %#codegen
%msg_warn is now m2c_warn.
%
% SEE ALSO: m2c_warn, m2c_error, m2c_printf

coder.inline('always');
m2c_warn(varargin{:});
