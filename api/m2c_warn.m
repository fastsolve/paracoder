function m2c_warn(varargin) %#codegen
%m2c_warn Issue a warning message.
% 
% m2c_warn(msg);
% m2c_warn(fmt, null_terminated_char, number, ...);
% m2c_warn(msg_id, fmt, null_terminated_char, number, ...);
%
% Note that the character strings associated with %s in the format must
% be null-terminated character strings.
%
% Example usage:
%    m2c_warn('Warning message in a constant string does not need to be null-terminated.');
%    m2c_warn('Warning ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]);
%    m2c_warn('warning:ID', 'ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]);
%
% SEE ALSO: m2c_print, m2c_error

coder.inline('never');

if isempty(coder.target)
    warning(varargin{:});
elseif ~m2c_par_target('gpu')
    if isequal(coder.target, 'mex')
        cmd = 'mexWarnMsgIdAndTxt';
    else
        coder.cinclude('m2c.h');
        cmd = 'M2C_warn';
    end
    
    if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2})
        fmt = coder.opaque('const char *', ['"' varargin{1} '"']);
        
        coder.ceval(cmd, ...
                    coder.opaque('const char *', '"runtime:Warning"'), ...
                    fmt, varargin{2:end});
    else
        msgid = coder.opaque('const char *', ['"' varargin{1} '"']);
        
        fmt = coder.opaque('const char *', ['"' varargin{2} '"']);
        coder.ceval(cmd, msgid, fmt, varargin{3:end});
    end
else
    coder.cinclude('m2c.h');
    cmd = 'M2C_printf';
    
    if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2})
        fmt = coder.opaque('const char *', ['"' varargin{1} '"']);
        
        coder.ceval(cmd, ...
                    fmt, varargin{2:end});
    else
        fmt = coder.opaque('const char *', ['"' varargin{2} '"']);
        coder.ceval(cmd, fmt, varargin{3:end});
    end
end
