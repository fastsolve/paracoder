function writeFevalScript(funcname, mpath, ~)
% Generate a script for building the standalone executable.

% Place the script in the same directory as the M file.
outfile = [mpath 'feval_' funcname '.m'];
clear(outfile);

filestr = sprintf('%s\n', ...
    ['function varargout = feval_' funcname '(varargin)'], ...
    '% Invoke the CUDA kernel function by passing variables using feval.', '',...
    ['dir = fileparts(which(''feval_' funcname '.m''));'], ...
    ['func = parallel.gpu.CUDAKernel([dir ''/' funcname '.ptx''], [dir ''/' funcname  '.c'']);'], ...
    'varargout{:} = feval(func, varargin{:});');

writeFile(outfile, filestr);

end
