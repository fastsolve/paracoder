function ptr = m2c_opaque_ptr_const( var, type, offset) %#codegen
% Creates an opaque object for a read-only pointer to a given variable,
% to be passed to a C function. The function behaves differently within
% MATLAB and in code generation.
%
% The only difference between this function and m2c_opaque_ptr is that it
% does not unshare the objects, so it can lead to better memory efficiency.
%
% See also m2c_opaque_obj, m2c_opaque_array, m2c_opaque_ptr

coder.inline('always');

if isempty(coder.target)
    dir = fileparts(which('m2c_opaque_ptr_const.m'));
    if exist('octave_config_info', 'builtin')
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

if nargin<2; type = 'void *'; end
if nargin<3; offset = int32(0); end

ptr = m2c_opaque_ptr(var, type, offset, true);
