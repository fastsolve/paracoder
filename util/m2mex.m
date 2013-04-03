function m2mex(varargin)
% Wrapper function for compiling MATLAB into a MEX function.
% Usage:
%           m2mex <codegen_options> matlabfunc <args>
% where options are those for codegen.
%    The options can be any of the following -O -g -64 -mpi -omp -force.
%
%     -force
%           Force to rebuild the mex function
%     -g
%           Enable debegging support.
%
%     -mpi
%           Enable support of MPI
%
%     -omp
%           Enable support of OpenMP (only parfor constructs built-in MATLAB)
%
%     -noinf
%           Disable support of NonFinite (inf and nan)
%
%     -O
%           Enable optimization (including inlining)
%
%     -64
%           Change map int32 to int64.
%
%     You can also use more than one option. E.g.,
%           m2mex matlabfunc -args {code.typeof(0,[inf,1],[1,0])}
%     Note that if -args present, it must follow matlabfunc.
%     Unrecognized options will be passed to codegen.
%
% See also compile, m2c, cg2mex, codegen.
