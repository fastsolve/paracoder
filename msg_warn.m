function msg_warn(varargin) %#codegen
%msg_warn Issue a warning message.
%   It takes one or two input arguments.

coder.extrinsic('warning');

if isempty(coder.target)
    warning( varargin{:});
end

assert( nargin<=2);
if isequal( coder.target, 'mex')
    if nargin==1
        warning( varargin{1});
    else
        warning( varargin{1}, varargin{2});
    end
elseif nargin==1
    errstr = [varargin{1} char(0)];
    coder.ceval( 'printf', coder.opaque('const char *', '"%s\n"'), coder.rref(errstr));
else
    errstr = [varargin{2} char(0)];
    coder.ceval( 'printf', coder.opaque('const char *', '"%s\n%s\n"'), coder.rref(msgid), coder.rref(errstr));
end
