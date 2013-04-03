function msg_error(varargin) %#codegen
%msg_fatal Issue a fatal error message.
%   It takes one or two input arguments.

coder.extrinsic('error');

if isempty(coder.target)
    dbstop if error;
    error( varargin{:});
end

assert( nargin<=2);
if isequal( coder.target, 'mex')
    if nargin==1
        error( varargin{1});
    else
        error( varargin{1}, varargin{2});
    end
elseif nargin==1
    msgid = ['runtime:UnknownError', char(0)];
    errstr = [varargin{1} char(0)];
    if coder.ismatlabthread
        coder.ceval( 'mexErrMsgIdAndTxt', coder.rref(msgid), coder.rref(errstr));
    else
        coder.ceval( 'printf', coder.opaque('const char *', '"%s\n"'), coder.rref(errstr));
        coder.ceval( 'abort');
    end
else
    msgid = [varargin{1} char(0)];
    errstr = [varargin{2} char(0)];
    if coder.ismatlabthread
        coder.ceval( 'mexErrMsgIdAndTxt', coder.rref(msgid), coder.rref(errstr));
    else
        coder.ceval( 'printf', coder.opaque('const char *', '"%s\n%s\n"'), coder.rref(msgid), coder.rref(errstr));
        coder.ceval( 'abort');
    end
end
