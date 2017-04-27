function ptr = m2c_opaque_ptr_const(var, type, offset) %#codegen
% Creates a read-only pointer to the given variable, to be passed to a C function.
%
% The only difference between this function and m2c_opaque_ptr is that
% it uses 'const char *' instead of 'char *' as the default type.
%
% See m2c_opaque_ptr for more detail.

coder.inline('always');

if isempty(coder.target)
    error('m2c_opaque_ptr_const:shadow', ['The M function should have been ' ...
        'shadowed by the mex file, which was missing.' ...
        'Please rebuild th.']);
end

if nargin<2; type = 'const char *'; end
if nargin<3; offset = int32(0); end

ptr = m2c_opaque_ptr(var, type, offset, true);
