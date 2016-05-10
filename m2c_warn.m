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


coder.extrinsic('warning');
coder.inline('never');

if coder.target('MATLAB') || isequal( coder.target, 'mex')
    warning( varargin{:});
elseif nargin==1 || ischar( varargin{1}) && ~ischar(varargin{2})
    if coder.ismatlabthread
        fmt = coder.opaque( 'const char *', ['"' varargin{1} '"']);
        
        coder.ceval( 'mexWarnMsgIdAndTxt', ...
            coder.opaque('const char *', '"runtime:Warning"'), ...
            fmt, varargin{2:end});
    else
        fmt = coder.opaque( 'const char *', ['"Warning\n' varargin{1} '"']);
        coder.ceval( 'printf', fmt, varargin{2:end});
    end
else
    msgid = coder.opaque( 'const char *', ['"' varargin{1} '"']);
    
    if coder.ismatlabthread
        fmt = coder.opaque( 'const char *', ['"' varargin{2} '"']);
        coder.ceval( 'mexWarnMsgIdAndTxt', msgid, fmt, varargin{3:end});
    else
        fmt = coder.opaque( 'const char *', ['"Warning %s\n' varargin{2} '"']);
        coder.ceval( 'printf', fmt, msgid, varargin{3:end});
    end
end
