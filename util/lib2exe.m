function lib2exe(funcname, ldflags, opflags, args)
% Generate a main function for a C library created by m2c.
% It also generates a MATLAB script 'ld_fname.m for building
% the generated file. Before calling this script, m2c should
% have been called on the function, or codegen should be present.
% The generated C file and build script are located in 
% codegen/lib/funcname.
%
% The -g option will enable debugging for the ld command.
%
% See also m2c, lib2mex.

lib2mex_exe(funcname, ldflags, opflags, args, true);
