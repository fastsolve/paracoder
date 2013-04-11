function compile( varargin)
% Compile MATLAB code using either m2c (if codegen exists) or m2mex.
%
%    compile [-g|-O|-noinf|-omp|-m|-64|-force|-m2c|-m2mex] matlabfunc <args>
%
% The options can be any of the following:
%
%     -g
%           Enable error checkings and debegging support.
%     -O
%           Enable optimization (including inlining).
%     -noinf
%           Disable support of NonFinite (m2c only).
%     -omp
%           Enable OpenMP support (requires m2c and MOMP for full features).
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

    if usem2c
        warning('compile:unsupported', 'M2C is not available. Using m2mex instead.');
    end
    m2mex(args, [dir func]);
else
    [force, args] = match_option( args, '-force');    
    if ~exist(command, 'file') || hascodegen && force
        m2c([args, ' -q'], [dir func]);
    end
    if exist(command, 'file'); run(command); end
end

clear(func);