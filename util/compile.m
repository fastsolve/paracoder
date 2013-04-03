function compile( varargin)
% Compile MATLAB code using either m2c (if codegen exists) or m2mex.
% Example usage:
%     compile options filename
%
%    The options can be any of the following -O -g -64 -mpi -noinf.
%
%     -g 
%           Enable debegging support.
%
%     -mpi
%           Enable support of MPI
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
%           compile matlabfunc -args {code.typeof(0,[inf,1],[1,0])}
%     Note that if -args present, it must follow matlabfunc.
%     Unrecognized options will be passed to codegen.
%
% See also m2mex, m2c
