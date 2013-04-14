function msg_error(varargin) %#codegen
%msg_fatal Issue a fatal error message.
%   It takes one or more input arguments.

coder.extrinsic('error');
coder.inline('never');

if isempty(coder.target) || isequal( coder.target, 'mex')
    error( varargin{:});
end

assert( nargin>=1);
if nargin==1 || ~isempty(strfind(varargin{1}, ':'))
    if coder.ismatlabthread
        fmt = coder.opaque( 'const char *', ['"' strrep( varargin{1}, '%s', '%p') '"']);

        coder.ceval( 'mexErrMsgIdAndTxt', ...
            coder.opaque('const char *', '"runtime:Error"'), ...
            fmt, varargin{2:end});
    else
        fmt = coder.opaque( 'const char *', ['"Error\n' strrep( varargin{1}, '%s', '%p') '"']);
        coder.ceval( 'printf', fmt, varargin{2:end});
    end
else
    msgid = coder.opaque( 'const char *', ['"' varargin{1} '"']);
    
    if coder.ismatlabthread
        fmt = coder.opaque( 'const char *', ['"' strrep( varargin{2}, '%s', '%p') '"']);
        coder.ceval( 'mexErrMsgIdAndTxt', msgid, fmt, varargin{3:end});
    else
        fmt = coder.opaque( 'const char *', ['"Error %s\n' strrep( varargin{2}, '%s', '%p') '"']);
        coder.ceval( 'printf', fmt, msgid, varargin{3:end});
    end
end
