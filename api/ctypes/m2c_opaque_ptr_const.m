function ptr = m2c_opaque_ptr_const(var, type, offset) %#codegen
% Creates a read-only pointer to the given variable, to be passed to a C function.
%
% The only difference between this function and m2c_opaque_ptr is that
% it uses 'const char *' instead of 'char *' as the default type.
%
% See m2c_opaque_ptr for more detail.

coder.inline('always');

if isempty(coder.target)
    dir = fileparts(which('m2c_opaque_ptr_const.m'));
    if exist('OCTAVE_VERSION', 'builtin')
        mex([dir '/m2c_opaque_ptr_const.c'], '-o', ...
            [dir '/m2c_opaque_ptr_const.' mexext]);
    else
        mex([dir '/m2c_opaque_ptr_const.c'], '-outdir', dir);
    end
    
    if nargin==0
        ptr = m2c_opaque_ptr_type;
        return;
    else
        error('m2c_opaque_ptr_const:shadow', ['The M function should have been ' ...
            'shadowed by the mex file, which was missing. I have rebuilt the mex file.' ...
            'Please try to rerun your last function again.']);
    end
end

if nargin<2; type = 'const char *'; end
if nargin<3; offset = int32(0); end

ptr = m2c_opaque_ptr(var, type, offset, true);
