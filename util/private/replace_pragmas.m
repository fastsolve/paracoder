function [cfile_str, hfile_str, changed] = replace_pragmas(cfile_str, hfile_str, m2c_opts)
%replace_pragmas
%  This is a plugin for post_codegen.

strin = cfile_str;

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
    bbegin = '\n#{[\w\s]*\(\s*\)[^\n]*';
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
bbegin = '\n#{[\w\s]*\(\s*\)[^\n]*';
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
cfile_str = regexprep(cfile_str, {'(\n)#{for\(\s*\);','(\n)#}for\(\s*\);'}, {'',''});
cfile_str = regexprep(cfile_str, {'(\n)#{parfor\(\s*\);','(\n)#}parfor\(\s*\);'}, {'',''});

% Move emxFree and *emxInit_*_T after "#}(parallel)"
pat = '(\n+[ \t]+(emxFree_|[a-z]?_?emxInit_)\w+\([&\w\s,]+\);)\s*(\n#}parallel\(\s*\);)';
while ~isempty(regexp(cfile_str, pat, 'once'))
    cfile_str = regexprep(cfile_str, pat, '$2$1');
end

%% Process kernel functions
if ~isempty(regexp(cfile_str, '\n#mcuda_kernel', 'match', 'once'))
    [cfile_str, hfile_str]= optimize_cuda_kernel(cfile_str, hfile_str, m2c_opts);
    % Remove rtwtypes from header file
    if ~m2c_opts.typeRep
        hfile_str = regexprep(hfile_str, '\n#include "rtwtypes.h"', '');
    end
end

%% Process begin_region and end_region
cfile_str = regexprep(cfile_str, '#{[^\n]+\n#}[^\n]+', '  {}');

if m2c_opts.enableInline
    parregion = ['(\n)#{(parallel|section|sections)\(\s*\)[^\n]*(\n|\n#[^\n]+)+([ \t]+)' ...
        '((\n|#pragma [^{}][^\n]+\n|\s*[^#][^\n]+\n)+)' ...
        '#}(parallel|section|sections)\(\s*\)[^\n]*'];
    while ~isempty(regexp(cfile_str, parregion, 'once'))
        [~,toks] = regexp(cfile_str, parregion, 'match', 'tokens');
        for i=1:length(toks)
            if strfind(toks{i}{5}, 'omp_get_thread_num')
                fprintf(2,['It seems that you have private varilables in an OpenMP %s region:\n %s', ...
                    'Please make sure the region is contained in a function with coder.inline(''never'').\n'], ...
                    toks{i}{2}, [toks{i}{4},toks{i}{5}]);
            end
            if strfind(toks{i}{5}, 'emxEnsureCapacity')
                fprintf(2,['It seems that you have memory allocation in an OpenMP %s region:\n %s', ...
                    'If you allocated a local buffer, make sure you call m2c_sync(buf) before OMP_begin_%s.\n'], ...
                    toks{i}{2}, [toks{i}{4},toks{i}{5}], toks{i}{2});
            end
            if ~isequal(toks{i}{2}, toks{i}{6})
                fprintf(2, 'A %s region is marked with end_%s. Potential coding error:\n %s', ...
                    toks{i}{2}, toks{i}{6}, [toks{i}{4},toks{i}{5}]);
            end
        end

        cfile_str = regexprep(cfile_str, parregion, ...
            '$1$4M2C_BEGIN_REGION(/*$2*/)$3$4$5$4M2C_END_REGION(/*$6*/)$1');
    end

    % Add ifdef around "#pragma momp ..."
    cfile_str = regexprep(cfile_str, '(\n+)(\s*#pragma) momp ([^\n]+)', ...
        '$1#if defined(M2C_OPENMP)\n$2 omp $3\n#endif');

    %% Process CUDA regions
    cudaregion = ['(\n)#{(cuda)\(\w+\)[^\n]*(\n|\n#[^\n]+)+([ \t]+)' ...
        '((\n|#pragma [^{}][^\n]+\n|\s*[^#][^\n]+\n)+)' ...
        '#}(cuda)\(\s*\)[^\n]*'];
    async_region = ['(\n)#{(cuda)\(async\)[^\n]*(\n|\n#[^\n]+)+([ \t]+)' ...
        '((\n|#pragma [^{}][^\n]+\n|\s*[^#][^\n]+\n)+)' ...
        '#}(cuda)\(\s*\)[^\n]*'];
    sync_region = ['(\n)#{(cuda)\(sync\)[^\n]*(\n|\n#[^\n]+)+([ \t]+)' ...
        '((\n|#pragma [^{}][^\n]+\n|\s*[^#][^\n]+\n)+)' ...
        '#}(cuda)\(\s*\)[^\n]*'];
    while ~isempty(regexp(cfile_str, cudaregion, 'once'))
        [~,toks] = regexp(cfile_str, cudaregion, 'match', 'tokens');
        for i=1:length(toks)
            if strfind(toks{i}{5}, 'emxEnsureCapacity')
                fprintf(2,['It seems that you have memory allocation in a CUDA parallel region:\n %s', ...
                    'If you allocated a local buffer, make sure you call m2c_sync(buf) before MCU_begin_parallle.\n'], ...
                    [toks{i}{4},toks{i}{5}]);
            end
        end

        cfile_str = regexprep(cfile_str, async_region, ...
            '$1$4M2C_BEGIN_REGION(/*$2*/)$3$4$5$4M2C_END_REGION(/*$6*/)$1');
        cfile_str = regexprep(cfile_str, sync_region, ...
            '$1$4M2C_BEGIN_REGION(/*$2*/)$3$4$5$4cudaThreadSynchronize();\n$4M2C_END_REGION(/*$6*/)$1');
    end

    % Add ifdef around "#pragma momp ..."
    cfile_str = regexprep(cfile_str, '(\n+)(\s*#pragma) momp ([^\n]+)', ...
        '$1#if defined(M2C_OPENMP)\n$2 omp $3\n#endif');

    % Check mismatched regions
    marks = '(\n)#({|})(\w+)\(\s*\)[^\n]*\n';
    if ~isempty(regexp(cfile_str, marks, 'once'))
        warning('m2c:MismatchRegions', ...
            'Found mis-matched begin and end labels. Look for REGION_MISMATCH in the C code.\n');
        
        cfile_str = regexprep(cfile_str, '(\n)#{(\w+)\(\s*\)[^\n]*\n', ...
            '\nM2C_BEGIN_REGION_MISMATCH(/*$2*/)\n');
        cfile_str = regexprep(cfile_str, '(\n)#}(\w+)\(\s*\)[^\n]*\n', ...
            '\nM2C_END_REGION_MISMATCH(/*$2*/)\n');
    end
else
    % Remove all m2c pragmas
    cfile_str = regexprep(cfile_str, '\n#\+\+[^\n]*\n', '');
    cfile_str = regexprep(cfile_str, '\n#{[\w\s]*\(\s*\)[^\n]*\n', '');
    cfile_str = regexprep(cfile_str, '\n#}[\w\s]*\(\s*\)[^\n]*\n', '');
    cfile_str = regexprep(cfile_str, '\n\s*#pragma momp [^\n]+\n', '');
end

%% Change whether the file has changed
changed = ~isequal(strin, cfile_str);
end

function expr = cuda_kernel_funcbody
expr = '{(?:([^}\n][^\n]*)?\n)*\n#mcuda_kernel\n(?:([^}\n][^\n]*)?\n)*\n*}';
end

function expr = funccall(func)
expr = ['\n\s+[^\n;]+[^\w]' func '\s*\([^\};]+\)\s*;'];
end

function expr = basictype
expr = ['(boolean_T|char_T|int8_T|int16_T|int32_T|int64_T|uint8_T|' ...
    'uint16_T|uint32_T|uint64_T|real_T|real32_T|real64_T)'];
end

function expr = kernel
expr = ['\w+\s+(\w+)\s*(\([^{}\)]+\))\s*' cuda_kernel_funcbody];
end

function expr = set_threads_args 
expr = '#pragma mcuda set_threads\(([^,]+),\s*([^\)]+)\)[^\n]*\n';
end

function [cfile_str, hfile_str] = optimize_cuda_kernel(cfile_str, hfile_str, m2c_opts)
%% Find kernel functions

while true
    [kernels, prototype] = regexp(cfile_str, kernel, 'match', 'tokens', 'once');
    if isempty(kernels); break; end
    
    newfunc = regexprep(kernels, '\n#mcuda_kernel', '');    
    funcdecl = regexp(cfile_str, ['\nstatic\s+\w+\s+' prototype{1} '\s*\([^\)]*\);'], 'match', 'once');
    %% Process each kernel function
    if isempty(funcdecl)
        inheader = true;
        funcdecl = regexp(hfile_str, ['\nextern\s+\w+\s+' prototype{1} '\s*\([^\)]*\);'], 'match', 'once');
    else
        inheader = false;        
    end
    if ~isempty(strfind(kernels, 'emxArray_Init'))
        warning('m2c:CannotProcessKernel', ['Function ' prototype{1} ...
            ' contains temporary emxArrays, so it cannot be converted into a kernel function.']);
    elseif ~isempty(regexp(kernels, '->sizes', 'once'))
        warning('m2c:CannotProcessKernel', ['Function ' prototype{1} ...
            ' explicitly uses size information of arrays, so it cannot be converted into a kernel function.']);
    else
        %% Find emxArray arguments and change them to plain pointers
        newfuncdecl = funcdecl;
        newargs = prototype{2};
        
        args = strtrim(textscan(strrep(newargs, sprintf('\n'), ' '), '%s', 'Delimiter', ','));
        args = args{1};
        append = false(length(args),1);
        for k=1:length(args)
            arg = regexp(args{k}, ['emxArray_(' basictype ')\s*\*\s*(\w+)'], 'tokens', 'once');
            
            if ~isempty(arg)
                newfuncdecl = regexprep(newfuncdecl, ...
                    ['emxArray_' arg{1} '\s*\*\s*' arg{2} '\s*([,\)])'], ...
                    [get_ctypename(arg{1}, m2c_opts.typeRep) ' *' [arg{2} '_data'] '$1']);
                newargs = regexprep(newargs, ...
                    ['emxArray_' arg{1} '\s*\*\s*' arg{2} '\s*([,\)])'], ...
                    [get_ctypename(arg{1}, m2c_opts.typeRep)  ' *' [arg{2} '_data'] '$1']);
                newfunc = regexprep(newfunc, [arg{2} '->\s*data'], [arg{2} '_data']);
                
                append(k) = true;
            end
        end
        
        newfunc = strrep(newfunc, prototype{2}, newargs);

        %% Change the prototype of function
        isglobal = ~isempty(strfind(newfunc, '#pragma mcuda global'));
        if isglobal
            newfuncdecl = sprintf('%s\n', '', ...
                '__global__', newfuncdecl(2:end));
            newfunc = sprintf('%s\n', '', ...
                '__global__', newfunc);
        end
        
        if inheader
            hfile_str = strrep(hfile_str, funcdecl, newfuncdecl);
        else
            cfile_str = strrep(cfile_str, funcdecl, newfuncdecl);
        end
        
        %% Find function calls to the kernel functions
        while true
            [calls,pos] = regexp(cfile_str, funccall(prototype{1}), 'match', 'once');
            if isempty(calls)
                break;
            end
            if ~isempty(regexp(calls, '\s+static\s+', 'once'))
                continue;
            end
            [call, newcall, args] = parsefunccall(calls, prototype{1});
            assert(length(args)==length(append));

            if isglobal
                set_threads = regexp(cfile_str(1:pos), set_threads_args, 'tokens');
                if ~isempty(set_threads)
                    newcall = [newcall(1:end-1) '<<<' ...
                        set_threads{end}{1}, ', ', set_threads{end}{2}, '>>>('];
                end
            end

            for j=1:length(args)
                if j>1
                    newcall = sprintf('%s, ', newcall);
                end
                
                if append(j)
                    newcall = sprintf('%s%s', newcall, [args{j} '->data']);
                else
                    newcall = sprintf('%s%s', newcall, args{j});
                end
            end
            
            cfile_str = [cfile_str(1:pos-1) newcall cfile_str(pos+length(call):end)];
        end
    end
    
    if isglobal
        newfunc = regexprep(newfunc, '\n#pragma mcuda global', '');
    end
    
    cfile_str = strrep(cfile_str, kernels, newfunc);
end

% Remove set_threads
cfile_str = regexprep(cfile_str, set_threads_args, '');

end

function [call, prefix, args] = parsefunccall(call, func)

% Removed ');' at the end
call = regexprep(call, ')\s*;', '');
prefix = regexp(call, ['.*[^\w]' func '\s*\('], 'match');
prefix = prefix{1};

args = strtrim(textscan(strrep(call, sprintf('\n'), ' '), ...
    '%s', 'Delimiter', ','));
args = args{1};
% remove func(from args{1}{1}
args{1} = regexprep(args{1}, ['.*[^\w]?' func '\s*\((.+)'], '$1');

% check whether there are '(' in the args
i=1;
while i<length(args)
    % Merge arguments if parentheses do not match
    if length(strfind(args{i}, '(')) < length(strfind(args{i}, ')'))
        args{i} = [args{i} ', ' args{i+1}];
        args = args{[1:i i+2:length(args)]};
    end
    i = i + 1;
end

end

function ctype = get_ctypename(basetype, nochange)
if nochange
    ctype = basetype;
    return; 
end
switch basetype
    case 'boolean_T'
        ctype = 'boolean_T';
    case 'char_T'
        ctype = 'char';
    case 'int8_T'
        ctype = 'signed char';
    case 'uint8_T'
        ctype = 'unsigned char';
    case 'int16_T'
        ctype = 'short';
    case 'uint16_T'
        ctype = 'unsigned short';
    case 'int32_T'
        ctype = 'int';
    case 'uint32_T'
        ctype = 'unsigned int';
    case 'int64_T'
        ctype = 'signed long';
    case 'uint64_T'
        ctype = 'unsigned long';
    case {'real_T', 'real64_T'}
        ctype = 'double';
    case 'real32_T'
        ctype = 'float';
end
end