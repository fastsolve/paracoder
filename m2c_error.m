function m2c_error(varargin) %#codegen
%m2c_error Issue a fatal error message.
% 
% m2c_error(msg);
% m2c_error(fmt, null_terminated_char, number, ...);
% m2c_error(msg_id, fmt, null_terminated_char, number, ...);
%
% Note that the character strings associated with %s in the format must
% be null-terminated character strings.
%
% Example usage:
%    m2c_error('Error message in a constant string does not need to be null-terminated.');
%    m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]);
%    m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]);
%
% SEE ALSO: m2c_print, m2c_warn

coder.inline('never');

if isempty(coder.target)
    error(varargin{:});
else
    if isequal(coder.target, 'mex')
        cmd = 'mexErrMsgIdAndTxt';
    else
        cmd = 'M2C_error';
    end
    
    if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2})
        fmt = coder.opaque('const char *', ['"' varargin{1} '"']);
        
        coder.ceval(cmd, ...
                    coder.opaque('const char *', '"runtime:Error"'), ...
                    fmt, varargin{2:end});
    else
        msgid = coder.opaque('const char *', ['"' varargin{1} '"']);
        
        fmt = coder.opaque('const char *', ['"' varargin{2} '"']);
        coder.ceval(cmd, msgid, fmt, varargin{3:end});
    end
end