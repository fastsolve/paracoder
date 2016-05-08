function compile(varargin)
% Compile MATLAB code using either m2c (if MATLAB Coder exists) or m2mex.
%
%    compile [-m2c|-m2mex] <other_options> matlabfunc <args>
%
%    The following options can be used:
%
%     -m2c 
%           Force to use m2c. This is the default.
%     -m2mex 
%           Force to use m2mex.
%
%    The other options are the same as those of m2c and m2mex.
%
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

switch varargin{1}
    case '-m2mex'
        m2mex(varargin{2:end});
    case '-m2c'
        m2c('-mex', varargin{2:end});
    otherwise
        m2c('-mex', varargin{:});
end
end
