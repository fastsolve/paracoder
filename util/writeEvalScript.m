function writeEvalScript(funcname, mpath, cpath, ~)
% Generate a script for building the standalone executable.

mfile = [mpath funcname '.m'];
m_args = extractMfileArgs(mfile);

% Place the script in the same directory as the M file.
outfile = [mpath 'eval_' funcname '_ptx.m'];
clear(outfile);

if cpath(1)~='/' && cpath(1)~='\'
    cpath = [pwd '/' cpath]; % User absolute path
end

if isempty(m_args.output)
    outputs = '';
elseif length(m_args.output) == 1
    outputs = [m_args.output{1} ' = '];
else
    outputs = sprintf('%s, ', m_args.output{:});
    outputs = ['[' outputs(1:end-2) '] = '];
end


inputs = sprintf('%s, ', m_args.input{:});
inputs = inputs(1:end-2);


filestr = sprintf('%s\n', ...
    ['function ' outputs 'eval_' funcname '_ptx(' inputs ')'], ...
    '% Invoke the CUDA kernel function by passing variables using feval.', '',...
    ['func = parallel.gpu.CUDAKernel(''' cpath funcname '.ptx'', ...'], ...
    ['    ''' cpath funcname  '.c'');'], ...
    [outputs 'feval(func, ' inputs ');']);

writeFile(outfile, filestr);

end
