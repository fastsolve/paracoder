% Wrapper function for compiling M-files into a MEX function.
% Usage:
%       m2mex [-c|-g|-O|-omp|-force] matlabfunc <args>
%    where <args> are sepcifications for codegen in the format of -args...
%
%    The options can be any of the following:
%     -c
%           Generate C/C++ code and perform post-processing, without
%           building the mex file.
%     -g
%           Compiles MEX functions in debug mode, with optimization turned off.
%     -O
%           Enable optimization (including inlining).
%     -omp
%           Enable support of OpenMP. This only enables converting
%           parfor in MATLAB into OpenMP code in C. To use the full
%           features of OpenMP, you need M2C and MOMP.
%     -force
%           Force to rebuild the mex function,
%
%     You can also use more than one option. For example,
%       m2mex -O -g matlabfunc -args {code.typeof(0,[inf,1],[1,0])}
%
%     Note that if -args is present, it must follow matlabfunc.
%     Unrecognized options will be passed to codegen.
%
% See also compile, m2c, codegen.
