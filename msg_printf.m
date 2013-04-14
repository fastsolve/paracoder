function msg_printf(varargin) %#codegen
%msg_printf Issue an informational message.
%   It takes one or more input arguments.
% Note that if you use %s in the format, the character string must be
% null-terminated. 

coder.extrinsic('fprintf');
coder.inline('never');

if isempty(coder.target) || isequal( coder.target, 'mex')
    fprintf(1, varargin{:});
end

assert( nargin>=1);
fmt = coder.opaque( 'const char *', ['"' varargin{1} '"']);
coder.ceval( 'printf', fmt, varargin{2:end});
