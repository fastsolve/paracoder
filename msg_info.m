function msg_info(varargin) %#codegen
%msg_info Issue an informational message.
%   It takes one or two input arguments.

coder.extrinsic('fprintf');

if isempty(coder.target)
    fprintf(1, varargin{:});
end

assert( nargin<=2);
if isequal( coder.target, 'mex')
    if nargin==1
        fprintf( int32(1), varargin{1});
    else
        fprintf( int32(1), varargin{1}, varargin{2});
    end
elseif nargin==1
    errstr = [varargin{1} char(0)];
    coder.ceval( 'printf', coder.opaque('const char *', '"%s\n"'), coder.rref(errstr));
else
    msgid = [varargin{1} char(0)];
    errstr = [varargin{2} char(0)];
    coder.ceval( 'printf', coder.opaque('const char *', '"%s\n%s\n"'), coder.rref(msgid), coder.rref(errstr)); 
end
