function msg_info(varargin) %#codegen
%msg_info Issue an informational message.
%   It takes one or more input arguments.

coder.extrinsic('fprintf');
coder.inline('never');

if isempty(coder.target) || isequal( coder.target, 'mex')
    fprintf(1, varargin{:});
end

assert( nargin>=1);
fmt = coder.opaque( 'const char *', ['"' strrep( varargin{1}, '%s', '%p') '"']);
coder.ceval( 'printf', fmt, varargin{2:end});
