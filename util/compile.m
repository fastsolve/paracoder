function compile( varargin)
% Compile MATLAB code using either m2c (if MATLAB Coder exists) or m2mex.
%
%    compile [-m2c|-m2mex|-exe] <other_options> matlabfunc <args>
%
%    The following options can be used:

%     -m2c 
%           Force to use m2c. This is the default.
%     -m2mex 
%           Force to use m2mex.
%     -exe
%           Force to use m2c to build executable.
%
%    The other options are the same as those of m2c and m2mex.

%    You can also use more than one option. E.g.,
%       compile -g -O matlabfunc -args {code.typeof(0,[inf,1],[1,0])}
%
%    Note that if -args is present, it must follow matlabfunc.
%    Unrecognized options will be passed to codegen.
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
[m2exe, args] = match_option( args, '-exe');

if usem2c || m2exe; usem2mex=false; end
if ~usem2mex && ~m2exe; usem2c=true; end

hascodegen = exist('codegen.p', 'file');
command = [cpath '/mex_' func '.m'];

if usem2mex || ~hascodegen && ~exist(command, 'file')
    if usem2c || m2exe
        warning('compile:unsupported', 'Forced to use m2mex.');
    end
    
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

    m2mex(args, [dir func]);
else
    force = match_option( args, '-force');    
    if ~exist(command, 'file') || hascodegen && (usem2c || m2exe || force)
        if usem2c && ~m2exe; 
            addflag = ' -mex';
        elseif ~usem2c && m2exe; 
            addflag = ' -exe';
        else
            addflag = ' -mex -exe';
        end
        m2c([args, addflag], [dir func]);
    else
        if force && exist([dir func '.' mexext], 'file')
            delete([dir func '.' mexext]);
        end
        if exist(command, 'file'); run(command); end
    end
end

clear(func);
