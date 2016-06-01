function m2c_printf(varargin) %#codegen
%m2c_printf Issue an informational message.
% 
% m2c_printf(msg);
% m2c_printf(fmt, null_terminated_char, number, ...);
%
% Note that the character strings associated with %s in the format must
% be null-terminated character strings.
%
% Example usage:
%    m2c_printf('Message in a constant string does not need to be null-terminated.');
%    m2c_printf('Msg ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]);
%
% SEE ALSO: m2c_error, m2c_warn

coder.inline('never');

if isempty(coder.target)
    fprintf(1, varargin{:});
else
    if isequal(coder.target, 'mex')
        cmd = 'mexPrintf';
    else
        coder.cinclude('m2c.h');
        cmd = 'M2C_printf';
    end
    assert(nargin>=1);
    fmt = coder.opaque('const char *', ['"' varargin{1} '"']);
    coder.ceval(cmd, fmt, varargin{2:end});
end
