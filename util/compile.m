function compile( varargin)
% Compile MATLAB code using either m2c (if codegen exists) or m2mex.
%
%    compile [-g|-O|-O1|-O2|-O3|-c++|-noinf|-acc|-m|-64|-force|-m2c|-m2mex] matlabfunc <args>
%
% The options can be any of the following:
%
%     -O1
%           Enable optimization for MATLAB Coder, disable memory integrity
%           checking (for m2mex only), and pass the -O1 compiler option 
%           to the C compiler to enable basis optimization (for m2c only).
%     -O
%     -O2
%           Enable optimization for MATLAB Coder, disable memory integrity
%           checking (for m2mex only), and pass the -O2 compiler option 
%           to the C compiler to enable nearly all supported optimizations
%           for C that do not involve a space-speed tradeoff (for m2c only).
%     -O3
%           Enable optimization for MATLAB Coder, disable memory integrity
%           checking (for m2mex only), and pass the -O3 compiler option 
%           to the C compiler to enable nearly all supported optimizations
%           for C, including loop unrolling and function inlining (for m2c only).
%     -g
%           Preserve MATLAB code info in C code and compile C functions 
%           in debug mode. It can be used in conjunction with -O, -O1, etc.
%     -c++
%           Generates C++ code instead of C code (m2c only).
%     -noinf
%           Disable support of NonFinite (m2c only).
%     -acc
%           Enable acceleration support (requires m2c and MACC for full features).
%     -m 
%           Map MATLAB files to individual C files (m2c only).
%     -64 
%           Map int32 to int64 (m2c only).
%     -m2c 
%           Force to use m2c.
%     -m2mex 
%           Force to use m2mex.
%     -force
%           Force to rebuild the mex function,
%
%     You can also use more than one option. E.g.,
%       compile -g -O matlabfunc -args {code.typeof(0,[inf,1],[1,0])}
%
%     Note that if -args is present, it must follow matlabfunc.
%     Unrecognized options will be passed to codegen.
%
% See also m2c, m2mex, codegen.

if nargin<1
    help compile; %#ok<MCHLP>
    return;
end

%% Process arguments
func = '';
args = '';

for i=1:length(varargin)
    if isempty(varargin{i})
        continue;
    elseif ~strncmp( strtrim(varargin{i}), '-', 1)
        func = varargin{i};
    elseif isempty(args)
        args = varargin{i};
    else
        args = sprintf('%s %s', args, varargin{i});
    end
end

if isempty(func); 
    error('No function name was specified.');
end

% Split filename into the path and filename
[dir, func] = get_path_of_mfile( func);
cpath = [dir 'codegen/lib/' func];

[usem2mex, args] = match_option( args, '-m2mex');
[usem2c, args] = match_option( args, '-m2c');
if usem2c; usem2mex=false; end

hascodegen = exist('codegen.p', 'file');
command = [cpath '/mex_' func '.m'];

if usem2mex || ~hascodegen && ~exist(command, 'file')
    % Filter out unsupported options
    [~, args] = match_option( args, '-noinf');
    [~, args] = match_option( args, '-m');
    [~, args] = match_option( args, '-64');
    [~, args] = match_option( args, '-c++');
    [opt1, args] = match_option( args, '-O1');
    [opt2, args] = match_option( args, '-O2');
    [opt3, args] = match_option( args, '-O3');
    opt = match_option( args, '-O');
    if ~opt && (opt1 || opt2 || opt3)
        args = strtrim(['-O ' args]);
    end

    if usem2c
        warning('compile:unsupported', 'M2C is not available. Using m2mex instead.');
    end
    m2mex(args, [dir func]);
else
    force = match_option( args, '-force');    
    if ~exist(command, 'file') || hascodegen && (usem2c || force)
        m2c([args, ' -mex'], [dir func]);
    else
        if force && exist([dir func '.' mexext], 'file')
            delete([dir func '.' mexext]);
        end
        if exist(command, 'file'); run(command); end
    end
end

clear(func);
