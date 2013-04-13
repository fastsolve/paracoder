% Wrapper function for converting Embedded MATLAB into a C library
%         that can be linked with other codes.
% Usage:
%    m2c [-g|-O|-c++|-noinf|-acc|-m|-64|-q|force] matlabfunc <args>
%
%    NOTE: This function requires MATLAB Coder.
%    The options can be any of the following:
%
%     -g
%           Enable error checkings and debegging support.
%     -O
%           Enable optimization (including inlining).
%     -c++
%           Generates C++ code instead of C code.
%     -noinf
%           Disable support of NonFinite (inf and nan. It produces faster codes).
%     -acc
%           Enable acceleration support using multicore and/or GPUs.
%     -m
%           Map MATLAB files to individual C files.
%      -q
%           Quite mode.
%     -64
%           Map int32 to int64.
%     -force
%           Force to rebuild the mex function,
%
%     You can also use more than one option. E.g.,
%       m2c -g -O matlabfunc -args {code.typeof(0,[inf,1],[1,0])}
%
%     Note that if -args is present, it must follow matlabfunc.
%     Unrecognized options will be passed to codegen.
%
% See also compile, m2mex, codegen.
