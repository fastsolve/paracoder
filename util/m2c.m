function m2c(varargin)
% Wrapper function for converting Embedded MATLAB into a C library
%         that can be linked with other code.
% Usage:
%    m2c <options> matlabfunc <args>
%
%    The options can be any of the following -O -g -m -64 -mpi -omp -noinf.
%
%     -g 
%           Enable debegging support.
%
%     -m 
%           Map MATLAB files to individual C files
%
%     -mpi
%           Enable support of MPI (requires MMPI)
%
%     -omp
%           Enable support of OpenMP (requires MOMP)
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
%           m2c matlabfunc -args {code.typeof(0,[inf,1],[1,0])}
%     Note that if -args present, it must follow matlabfunc.
%     Unrecognized options will be passed to codegen.
%
% See also compile, m2mex, codegen.
