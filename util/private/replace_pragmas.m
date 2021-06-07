function [cfile_str, hfile_str, parmode] = ...
    replace_pragmas(cfile_str, hfile_str, m2c_opts)
%replace_pragmas
%  This is a plugin for post_codegen.

parmode = '';
if m2c_opts.withNvcc
    if contains(cfile_str, 'threadIdx.x')
        if contains(cfile_str, '#pragma cuda')
            parmode = 'cuda';
        else
            parmode = 'cuda-kernel';
        end
    else
        warning('m2c:NonCudaKernel', ...
            'Function %s does not appear to be a valid CUDA kernel function.', ...
            m2c_opts.funcName{1});
    end
end

cfile_str = regexprep(cfile_str, '\n#ref\([^\)]+\);', '');

%% Process pragma
prag = '\n#pragma[^\n]+';
statement = '(\n|\n[^#{}\n][^\n]*)';

% Remove empty brackets
pat = '(\n#[^#{}\n]+)\(\s*\)(;\n)';
while ~isempty(regexp(cfile_str, pat, 'once'))
    cfile_str = regexprep(cfile_str, pat, '$1$2');
end

% filter out .data and ->data in the declarations of shared variables
shared = regexp(cfile_str, '(\n#\+\+ shared\([^\)]+\))', 'tokens');
for i=1:length(shared)
    cfile_str = strrep(cfile_str, shared{i}{1}, regexprep(shared{i}{1}, '(\.|->)data\[0\]', ''));
end

% Process reduction operators
pat = '(\n#\+\+ reduction)([^\n]+:)\(([^\)]+\))';
while ~isempty(regexp(cfile_str, pat, 'once'))
    cfile_str = regexprep(cfile_str, pat, '$1($2$3');
end

% Process atomic directive
%(\s[\+\-\*\/])(\s([^;]+)
pat = '(\n#pragma momp atomic;\s+)([^;=]+\s)=(\s[^;=]+;)';
while ~isempty(regexp(cfile_str, pat, 'once'))
    [tokens, substr] = regexp(cfile_str, pat, 'tokens', 'match', 'once');
    lhs = regexprep(tokens{2}, '\s', '');
    substr1 = regexprep([tokens{3}], '\s', '');
    
    n = length(lhs);
    if strncmp(substr1, lhs, n)
        substr1 = ['=' substr1(n+1:end)];
        substr1 = regexprep(substr1, '=(\+|\-|\*|\/|\&\&|\|\|\&|\|)', ' $1= ');
    end
    
    cfile_str = strrep(cfile_str, substr, [tokens{1} tokens{2} substr1]);
end

while true
    bbegin = '\n#\{[\w\s]*\(\s*\)[^\n]*';
    pragcont = '\n#\+\+[^\n]*';
    changed = false;
    
    % Move statements between  #{ and "#pragma ++" to in front of #{
    pat = ['(' bbegin ';)(' statement ')+(' pragcont ')'];
    while ~isempty(regexp(cfile_str, pat, 'once'))
        cfile_str = regexprep(cfile_str, pat, '$2$1$3');
        changed = true;
    end
    
    % Switch statements #{ and "#++"
    pat = ['(' bbegin ')\s*(' pragcont ')'];
    while ~isempty(regexp(cfile_str, pat, 'once'))
        cfile_str = regexprep(cfile_str, pat, '$2$1');
        changed = true;
    end
    if ~changed; break; end
end

% Move statements between #pragma and #++ before #pragma
pat = ['(' prag ');(' statement ')+#\+\+\s*'];
while ~isempty(regexp(cfile_str, pat, 'once'))
    cfile_str = regexprep(cfile_str, pat, '$2$1 ');
end

% Remove default(none) if default(shared) is defined.
pat = ['(' prag ') default\(none\)([^\n]+default\(\w+\))'];
while ~isempty(regexp(cfile_str, pat, 'once'))
    cfile_str = regexprep(cfile_str, pat, '$1$2');
end

% Remove semicolon
pat = '(\n#[^\n]+);(\n)';
while ~isempty(regexp(cfile_str, pat, 'once'))
    cfile_str = regexprep(cfile_str, pat, '$1$2');
end

pragmas = regexp(cfile_str, ['(' prag ')'], 'tokens');
% filter out & in the pragma
for i=1:length(pragmas)
    cfile_str = strrep(cfile_str, pragmas{i}{1}, regexprep(pragmas{i}{1}, '&', ''));
end

% Switch statements "#pragma momp for" and #{
pragfor = '\n#pragma momp\s+(parallel\s+)?for[^\n]*';
bbegin = '\n#\{[\w\s]*\(\s*\)[^\n]*';
pat = ['(' pragfor ')\s*(' bbegin ')'];
while ~isempty(regexp(cfile_str, pat, 'once'))
    cfile_str = regexprep(cfile_str, pat, '$2$1 ');
end

% Switch simple statements between "#pragma momp [parallel] for" and "for"
simplestatements = '(\n|\n[^#{}\n][^\n{}]*)';
forbegin = '\n\s+for\s*\(';
pat = ['(' pragfor ')(' simplestatements ')+(' forbegin ')'];
while ~isempty(regexp(cfile_str, pat, 'once'))
    cfile_str = regexprep(cfile_str, pat, '$2$1$3');
end

% Fix the condition in for-loops
var = '\s*\w+\s*';
part1 =  ['(' pragfor forbegin '[^;]+;' var ')'];
part2 = ['(' var ')'];
part3 = '(<=?)';
part4 = '\s*([^;\s]+)\s*';
cfile_str = regexprep(cfile_str, [part1 '\+' part2 part3 part4 ';'], '$1$3($4)-($2);');
cfile_str = regexprep(cfile_str, {'(\n)#\{\s*for\(\s*\);','(\n)#\}\s*for\(\s*\);'}, {'',''});
cfile_str = regexprep(cfile_str, {'(\n)#\{\s*parfor\(\s*\);','(\n)#\}\s*parfor\(\s*\);'}, {'',''});

% Move emxFree and *emxInit_*_T after "#}(parallel)"
pat = '(\n+[ \t]+(emxFree_|[a-z]?_?emxInit_)\w+\([&\w\s,]+\);)\s*(\n#\}\s*parallel\(\s*\);)';
while ~isempty(regexp(cfile_str, pat, 'once'))
    cfile_str = regexprep(cfile_str, pat, '$2$1');
end

%% Process kernel functions
if m2c_opts.withCuda && isequal(parmode, 'cuda-kernel')
    [cfile_str, hfile_str]= replace_cuda_kernel(cfile_str, hfile_str, m2c_opts);
end

%% Process begin_region and end_region
cfile_str = regexprep(cfile_str, '\n+#\{\s*(parallel|section|sections|master|single|critical)\(\)\n+#\}\s*\1\(\)', '\n  {}');

if m2c_opts.enableInline
    parregion = ['(\n+)#\{\s*(parallel|section|sections|master|single|critical)\(\s*\)[^\n]*' ...
        '(\n|\n#[^\n]+)+([ \t]+)' re_parregion '#\}\s*(\2)\(\s*\)[^\n]*'];
    while ~isempty(regexp(cfile_str, parregion, 'once'))
        [matchedstr,toks] = regexp(cfile_str, parregion, 'match', 'tokens');
        for i=1:length(toks)
            if ~isempty(strfind(toks{i}{5}, 'omp_get_thread_num')) && (isequal(toks{i}{2}, 'parallel') || isequal(toks{i}{2}, 'section'))
                fprintf(2,['It seems that you have private varilables in an OpenMP %s region:\n %s', ...
                    'Please make sure the region is contained in a function with coder.inline(''never'').\n'], ...
                    toks{i}{2}, [toks{i}{4},toks{i}{5}]);
            end
            if ~isempty(strfind(toks{i}{5}, 'emxEnsureCapacity')) && (isequal(toks{i}{2}, 'parallel') || isequal(toks{i}{2}, 'section'))
                fprintf(2,['It seems that you have memory allocation in an OpenMP %s region:\n %s', ...
                    'If you allocated a local buffer, make sure you call m2c_rref(buf) before OMP_begin_%s.\n'], ...
                    toks{i}{2}, [toks{i}{4},toks{i}{5}], toks{i}{2});
            end

            cfile_str = strrep(cfile_str, matchedstr{i}, ...
                [newline toks{i}{4} '{' ...
                strrep(toks{i}{3}, [newline newline], newline), ...
                toks{i}{4} '  ' ...
                regexprep(strrep(toks{i}{5}, [newline '  '], [newline '    ']), '\n\n$', '\n') ...
                toks{i}{4} '}' newline]);
        end
    end

    %% Process CUDA regions
    cudaregion = ['(\n+)#\{\s*(cuda)\(\w+\)[^\n]*(\n|\n#[^\n]+)+([ \t]+)' ...
        re_parregion '#\}\s*(cuda)\(\s*\)[^\n]*'];
    while ~isempty(regexp(cfile_str, cudaregion, 'once'))
        [matchedstr,toks] = regexp(cfile_str, cudaregion, 'match', 'tokens');
        for i=1:length(toks)
            if strfind(toks{i}{5}, 'emxEnsureCapacity')
                fprintf(2,['It seems that you have memory allocation in a CUDA parallel region:\n %s', ...
                    'If you allocated a local buffer, make sure you call m2c_rref(buf) before CU_begin_parallle.\n'], ...
                    [toks{i}{4},toks{i}{5}]);
            end
            
            cfile_str = strrep(cfile_str, matchedstr{i}, ...
                [newline toks{i}{4} '{' ...
                strrep(toks{i}{3}, [newline newline], newline), ...
                toks{i}{4} '  ' ...
                regexprep(strrep(toks{i}{5}, [newline '  '], [newline '    ']), '\n\n$', '\n') ...
                toks{i}{4} '}' newline]);
        end
    end

    % Replace "#pragma momp ..." by "#pragma omp ..." 
    cfile_str = regexprep(cfile_str, '(\n+)(\s*#pragma) momp ([^\n]+)', ...
        '$1$2 omp $3');

    % Check mismatched regions
    marks = '(\n)#(\{|\})\s*(\w+)\(\s*\)[^\n]*\n';
    if ~isempty(regexp(cfile_str, marks, 'once'))
        warning('m2c:MismatchRegions', ...
            'Found mis-matched begin and end labels. Look for "#error Mismatched" in C code.\n');
        
        cfile_str = regexprep(cfile_str, '(\n)#\{\s*(\w+)\(\s*\)[^\n]*\n', ...
            '\n#error Mismatched begin region for $2\n');
        cfile_str = regexprep(cfile_str, '(\n)#\}\s*(\w+)\(\s*\)[^\n]*\n', ...
            '\n#error Mismatched end region for $2\n');
    end
else
    % Remove all m2c pragmas
    cfile_str = regexprep(cfile_str, '\n#\+\+[^\n]*\n', '');
    cfile_str = regexprep(cfile_str, '\n#\{[\w\s]*\(\s*\)[^\n]*\n', '');
    cfile_str = regexprep(cfile_str, '\n#\}[\w\s]*\(\s*\)[^\n]*\n', '');
    cfile_str = regexprep(cfile_str, '\n\s*#pragma momp [^\n]+\n', '');
end

if m2c_opts.withOMP && (contains(cfile_str, 'omp_get_thread_num') || ...
        ~isempty(regexp(cfile_str, '#pragma\s+omp', 'once')))
    if ~isempty(regexp(cfile_str, '#pragma\s+omp\s+parallel', 'once'))
        parmode = 'omp';
    else
        parmode = 'omp-kernel';
    end
end

end

function [cfile_str, hfile_str] = replace_cuda_kernel(cfile_str, hfile_str, m2c_opts)
%% Find kernel functions

synced = ~isempty(regexp(cfile_str, '\s+__syncthreads\(', 'once'));

[~, func, ~] = fileparts(m2c_opts.funcName{1});
altapis = [func, strtrim(strrep(regexp(m2c_opts.codegenArgs, ...
    '(\w+)\s+-args', 'match'), ' -args', ''))];
if length(altapis)>1
    error('m2c:MultipeCudaEntry', 'There can be only one CUDA global functions.');
end

funcname = altapis{1};
[kernel, prototype] = regexp(cfile_str, re_funcdef(funcname), 'match', 'tokens', 'once');
funcdecl = regexp(hfile_str, ['\nextern\s+\w+\s+' funcname '\s*\([^\)]*\);'], 'match', 'once');

%% Change the prototype of function
newfuncdecl = sprintf('%s\n', '', ...
    '#ifdef __NVCC__', ...
    '__global__', ...
    funcdecl(2:end), ...
    '#endif');
newfunc = sprintf('%s\n', '', ...
    '__global__', kernel);

[wrapper_decls, wrapper_defs] = write_cuda_wrapper(funcname, prototype{1}(2:end-1), synced, m2c_opts);
newfunc = [newfunc wrapper_defs];

hfile_str = strrep(hfile_str, funcdecl, [newfuncdecl, wrapper_decls]);
cfile_str = strrep(cfile_str, kernel, newfunc);

end

function [decls, defs] = write_cuda_wrapper(func, args, synced, m2c_opts)
toks = regexp(args, '(?:const\s+)?\w+\s+(?:\*)?\s*(\w+)', 'tokens');

vars = toks{1}{1};
for i=2:length(toks)
    vars = sprintf('%s, %s', vars, toks{i}{1});
end

if nargin<3
    synced = false;
end

decls = sprintf('%s\n', '', ...
    ['extern void ' func '_cuda0(' args ');'], ...
    ['extern void ' func '_cuda1(' args ', int _nthreads);'], ...
    ['extern void ' func '_cuda2(' args ', int _nthreads, int _threadsPB);']);

if synced
    % Note: If inter-thread synchronization is used, then nblocks will be set
    % to 1 automatically
    if m2c_opts.debugInfo
        msg = '  M2C_printf("Launching CUDA with 1 block and %d threads per block\n", _threadsPB);';
    else
        msg = '';
    end

    defs = sprintf('%s\n', '', ...
        ['void ' func '_cuda0(' args ')'], ...
        '{', ...
        '  int _threadsPB, _minGridSize;', ...
        ['  cudaOccupancyMaxPotentialBlockSize(&_minGridSize, &_threadsPB, ' func ', 0, 0);'], msg, ...
        ['  ' func '<<<1, _threadsPB>>>(' vars ');'], ...
        '}');
    
    defs = sprintf('%s\n', defs, '', ...
        ['void ' func '_cuda1(' args ', int _nthreads)'], ...
        '{', ...
        '  int _threadsPB, _minGridSize;', ...
        ['  cudaOccupancyMaxPotentialBlockSize(&_minGridSize, &_threadsPB, ' func ', 0, 0);'], ...
        '  if (_nthreads > 0 && _nthreads<_threadsPB)', ...
        '    _threadsPB = _nthreads;', msg, ...
        ['  ' func '<<<1, _threadsPB>>>(' vars ');'], ...
        '}');
    
    defs = sprintf('%s\n', defs, '', ...
        ['void ' func '_cuda2(' args ', int _nthreads, int _threadsPB)'], ...
        '{', ...
        '  if (_threadsPB <= 0) {', ...
        '      int _minGridSize;', ...
        ['    cudaOccupancyMaxPotentialBlockSize(&_minGridSize, &_threadsPB, ' func ', 0, 0);'], ...
        '  }', ...
        '  if (_nthreads > 0 && _nthreads<_threadsPB)', ...
        '    _threadsPB = _nthreads;', msg, ...
        ['  ' func '<<<1, _threadsPB>>>(' vars ');'], ...
        '}');
else
    if m2c_opts.debugInfo
        msg = '  M2C_printf("Launching CUDA with %d blocks and %d threads per block\n", _nblocks, _threadsPB);';
    else
        msg = '';
    end
    
    defs = sprintf('%s\n', '', ...
        ['void ' func '_cuda0(' args ')'], ...
        '{', ...
        '  int _threadsPB, _nblocks;', ...
        '  struct cudaDeviceProp _prop;', ...
        '  cudaGetDevice(&_nblocks);', ...
        '  cudaGetDeviceProperties(&_prop, _nblocks);', ...
        ['  cudaOccupancyMaxPotentialBlockSize(&_nblocks, &_threadsPB, ' func ', 0, 0);'], ...
        ['  cudaOccupancyMaxActiveBlocksPerMultiprocessor(&_nblocks, ' func ', _threadsPB, 0);'], ...
        '  _nblocks *= _prop.multiProcessorCount;', msg, ...
        ['  ' func '<<<_nblocks, _threadsPB>>>(' vars ');'], ...
        '}');
    
    defs = sprintf('%s\n', defs, '', ...
        ['void ' func '_cuda1(' args ', int _nthreads)'], ...
        '{', ...
        '  int _threadsPB, _nblocks;', ...
        ['  cudaOccupancyMaxPotentialBlockSize(&_nblocks, &_threadsPB, ' func ', 0, 0);'], ...
        '  if (_nthreads <= 0) {', ...
        '    struct cudaDeviceProp _prop;', ...
        '    cudaGetDevice(&_nblocks);', ...
        '    cudaGetDeviceProperties(&_prop, _nblocks);', ...
        ['    cudaOccupancyMaxActiveBlocksPerMultiprocessor(&_nblocks, ' func ', _threadsPB, 0);'], ...
        '    _nblocks *= _prop.multiProcessorCount;', ...
        '  } else if (_nthreads < _threadsPB) {', ...
        '    _nblocks = 1; _threadsPB = _nthreads;', ...
        '  } else', ...
        '    _nblocks = (_nthreads + _threadsPB - 1) / _threadsPB;', msg, ...
        ['  ' func '<<<_nblocks, _threadsPB>>>(' vars ');'], ...
        '}');
    
    defs = sprintf('%s\n', defs, '', ...
        ['void ' func '_cuda2(' args ', int _nthreads, int _threadsPB)'], ...
        '{', ...
        '  int _nblocks;', ...
        '  if (_threadsPB <= 0)', ...
        ['    cudaOccupancyMaxPotentialBlockSize(&_nblocks, &_threadsPB, ' func ', 0, 0);'], ...
        '  if (_nthreads <= 0) {', ...
        '    struct cudaDeviceProp _prop;', ...
        '    cudaGetDevice(&_nblocks);', ...
        '    cudaGetDeviceProperties(&_prop, _nblocks);', ...
        ['    cudaOccupancyMaxActiveBlocksPerMultiprocessor(&_nblocks, ' func ', _threadsPB, 0);'], ...
        '    _nblocks *= _prop.multiProcessorCount;', ...
        '  } else if (_nthreads < _threadsPB) {', ...
        '    _nblocks = 1; _threadsPB = _nthreads;', ...
        '  } else', ...
        '    _nblocks = (_nthreads + _threadsPB - 1) / _threadsPB;', msg, ...
        ['  ' func '<<<_nblocks, _threadsPB>>>(' vars ');'], ...
        '}');
end
end

function expr = re_parregion
% The code fragment between begin_parallel/section/sections and 
% end_parallel/section/sections
expr = '((\n|#pragma [^{}][^\n]+\n|\s*[^#][^\n]+\n)+?)';
end

