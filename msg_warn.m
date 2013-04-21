function msg_warn(varargin) %#codegen
%msg_warn Issue a warning message.
%   It takes one or more input arguments.
% Note that if you use %s in the format, the character string must be
% null-terminated. 

coder.extrinsic('warning');
coder.inline('never');

if isempty(coder.target) || isequal( coder.target, 'mex')
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
