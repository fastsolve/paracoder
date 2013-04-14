function msg_warn(varargin) %#codegen
%msg_warn Issue a warning message.
%   It takes one or more input arguments.

coder.extrinsic('warning');
coder.inline('never');

if isempty(coder.target) || isequal( coder.target, 'mex')
    warning( varargin{:});
end

assert( nargin>=1);
if nargin==1 || ~isempty(strfind(varargin{1}, ':'))
    if coder.ismatlabthread
        fmt = coder.opaque( 'const char *', ['"' strrep( varargin{1}, '%s', '%p') '"']);
        
        coder.ceval( 'mexWarnMsgIdAndTxt', ...
            coder.opaque('const char *', '"runtime:Warning"'), ...
            fmt, varargin{2:end});
    else
        fmt = coder.opaque( 'const char *', ['"Warning\n' strrep( varargin{1}, '%s', '%p') '"']);
        coder.ceval( 'printf', fmt, varargin{2:end});
    end
else
    msgid = coder.opaque( 'const char *', ['"' varargin{1} '"']);
    
    if coder.ismatlabthread
        fmt = coder.opaque( 'const char *', ['"' strrep( varargin{2}, '%s', '%p') '"']);
        coder.ceval( 'mexWarnMsgIdAndTxt', msgid, fmt, varargin{3:end});
    else
        fmt = coder.opaque( 'const char *', ['"Warning %s\n' strrep( varargin{2}, '%s', '%p') '"']);
        coder.ceval( 'printf', fmt, msgid, varargin{3:end});
    end
end
