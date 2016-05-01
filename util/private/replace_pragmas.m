function [str, changed] = replace_pragmas( str)
%replace_pragmas
%  This is a plugin for post_codegen.

strin = str;

%% Process pragma
prag = '\n#pragma[^\n]+';
statement = '(\n|\n[^#{}\n][^\n]*)';

% Remove empty brackets
pat = '(\n#[^#{}\n]+)\(\s*\)(;\n)';
while ~isempty( regexp( str, pat, 'once'))
    str = regexprep( str, pat, '$1$2');
end

% filter out .data and ->data in the declarations of shared variables
shared = regexp( str, '(\n#\+\+ shared\([^\)]+\))', 'tokens');
for i=1:length(shared)
    str = strrep( str, shared{i}{1}, regexprep( shared{i}{1}, '(\.|->)data\[0\]', ''));
end

% Process reduction operators
pat = '(\n#\+\+ reduction)([^\n]+:)\(([^\)]+\))';
while ~isempty( regexp( str, pat, 'once'))
    str = regexprep( str, pat, '$1($2$3');
end

% Process atomic directive
%(\s[\+\-\*\/])(\s([^;]+)
pat = '(\n#pragma omp atomic;\s+)([^;=]+\s)=(\s[^;=]+;)';
while ~isempty( regexp( str, pat, 'once'))
    [tokens, substr] = regexp( str, pat, 'tokens', 'match', 'once');
    lhs = regexprep( tokens{2}, '\s', '');
    substr1 = regexprep( [tokens{3}], '\s', '');
    
    n = length(lhs);
    if strncmp( substr1, lhs, n)
        substr1 = ['=' substr1(n+1:end)];
        substr1 = regexprep( substr1, '=(\+|\-|\*|\/|\&\&|\|\|\&|\|)', ' $1= ');
    end
    
    str = strrep( str, substr, [tokens{1} tokens{2} substr1]);
end

while true
    bbegin = '\n#{[\w\s]*\(\s*\)[^\n]*';
    pragcont = '\n#\+\+[^\n]*';
    changed = false;

    % Move statements between  #{ and "#pragma ++" to in front of #{
    pat = ['(' bbegin ';)(' statement ')+(' pragcont ')'];
    while ~isempty( regexp( str, pat, 'once'))
        str = regexprep( str, pat, '$2$1$3');
        changed = true;
    end

    % Switch statements #{ and "#++"
    pat = ['(' bbegin ')\s*(' pragcont ')'];
    while ~isempty( regexp( str, pat, 'once'))
        str = regexprep( str, pat, '$2$1');
        changed = true;
    end
    if ~changed; break; end
end

% Move statements between #pragma and #++ before #pragma
pat = ['(' prag ');(' statement ')+#\+\+\s*'];
while ~isempty( regexp( str, pat, 'once'))
    str = regexprep( str, pat, '$2$1 ');
end

% Remove default(none) if default(shared) is defined.
pat = ['(' prag ') default\(none\)([^\n]+default\(\w+\))'];
while ~isempty( regexp( str, pat, 'once'))
    str = regexprep( str, pat, '$1$2');
end

% Remove semicolon
pat = ['(' prag ');(\n)'];
while ~isempty( regexp( str, pat, 'once'))
    str = regexprep( str, pat, '$1$2');
end

pragmas = regexp( str, ['(' prag ')'], 'tokens');
% filter out & in the pragma
for i=1:length(pragmas)
    str = strrep( str, pragmas{i}{1}, regexprep( pragmas{i}{1}, '&', ''));
end

% Switch statements "#pragma omp for" and #{
pragfor = '\n#pragma omp\s+(parallel\s+)?for[^\n]*';
bbegin = '\n#{[\w\s]*\(\s*\)[^\n]*';
pat = ['(' pragfor ')\s*(' bbegin ')'];
while ~isempty( regexp( str, pat, 'once'))
    str = regexprep( str, pat, '$2$1 ');
end

% Switch simple statements between "#pragma omp [parallel] for" and "for"
simplestatements = '(\n|\n[^#{}\n][^\n{}]*)';
forbegin = '\n\s+for\s*\(';
pat = ['(' pragfor ')(' simplestatements ')+(' forbegin ')'];
while ~isempty( regexp( str, pat, 'once'))
    str = regexprep( str, pat, '$2$1$3');
end

% Fix the condition in for for-oops
var = '\s*\w+\s*';
part1 =  ['(' pragfor forbegin '[^;]+;' var ')'];
part2 = ['(' var ')'];
part3 = '(<=?)';
part4 = '\s*([^;\s]+)\s*';
str = regexprep( str, [part1 '\+' part2 part3 part4 ';'], '$1$3($4)-($2);');
str = regexprep( str, {'(\n)#{for\(\s*\);','(\n)#}for\(\s*\);'}, {'',''});
str = regexprep( str, {'(\n)#{parfor\(\s*\);','(\n)#}parfor\(\s*\);'}, {'',''});

% Move emxFree and *emxInit_*_T after "#}(parallel)"
pat = '(\n+[ \t]+(emxFree_|[a-z]?_?emxInit_)\w+\([&\w\s,]+\);)\s*(\n#}parallel\(\s*\);)';
while ~isempty( regexp( str, pat, 'once'))
    str = regexprep( str, pat, '$2$1');
end

% Process begin_region and end_region
str = regexprep( str, '#{[^\n]+\n#}[^\n]+', '  {}');

region = ['(\n)#{([\w\s]*)\(\s*\)[^\n]*(\n|\n#[^\n]+)+([ \t]+)' ...
    '((\n|#pragma [^{}][^\n]+\n|[^#\n]+\n)+)#}([\w\s]*)\(\s*\)[^\n]*'];
while ~isempty(regexp( str, region, 'once'))
    str = regexprep( str, region, ...
        '$1$4PLC_BEGIN_REGION(/*omp $2*/)$3$4$5$4PLC_END_REGION(/*omp $6*/)$1');
end

str = optimize_kernel_functions( str);

%% Change whether the file has changed
changed = ~isequal(strin, str);
end

function fb = kernel_funcbody
fb = '{(?:[^}][^\n]*\n)*\n#pragma kernel\n(?:[^}][^\n]*\n)*\n*}';
end

function expr = funccall(func)
expr = ['\n[^\n;]+[^\w]' func '\s*\([^\};]+\)\s*;'];
end

function str = optimize_kernel_functions( str)

%% Find kernel functions

kernel = ['\s+(\w+)\s*(\([^{}\)]+\))\s*' kernel_funcbody];
basictype = ['(boolean_T|char_T|int8_T|int16_T|int32_T|int64_T|uint8_T|' ...
    'uint16_T|uint32_T|uint64_T|real_T|real32_T|real64_T)'];

[kernels, prototype] = regexp( str, kernel, 'match', 'tokens');

for i=1:length(kernels)
    newfunc = regexprep( kernels{i}, '\n#pragma kernel', '');
    
    funcdecl = regexp( str, ['\s+static\s+\w+\s+' prototype{i}{1} '\s*\([^\)]*\);'], 'match', 'once');
    %% Process each kernel function
    if isempty( funcdecl)
        warning( 'palc:CannotProcessKernel', ['Function ' prototype{i}{1} ...
            ' is not a local function or it has a return value, so it cannot be converted into a kernel function.']);
    elseif ~isempty( strfind( kernels{i}, 'emxArray_Init'))
        warning( 'palc:CannotProcessKernel', ['Function ' prototype{i}{1} ...
            ' contains temporary emxArrays, so it cannot be converted into a kernel function.']);
    elseif ~isempty( regexp( kernels{i}, '->sizes', 'once'))
        warning( 'palc:CannotProcessKernel', ['Function ' prototype{i}{1} ...
            ' explicitly uses size information of arrays, so it cannot be converted into a kernel function.']);
    else
        %% Find emxArray arguments and change them to plain pointers
        newfuncdecl = funcdecl;
        newargs = prototype{i}{2};
        
        args = strtrim(textscan( strrep( newargs, sprintf('\n'), ' '), '%s', 'Delimiter', ','));
        args = args{1};
        append = false(length(args),1);
        for k=1:length(args)
            arg = regexp( args{k}, ['emxArray_(' basictype ')\s*\*\s*(\w+)'], 'tokens', 'once');
            
            if ~isempty( arg)
                newfuncdecl = regexprep( newfuncdecl, ...
                    ['emxArray_' arg{1} '\s*\*\s*' arg{2} '\s*([,\)])'], [arg{1} ' *' arg{2} '$1']);
                newargs = regexprep( newargs, ...
                    ['emxArray_' arg{1} '\s*\*\s*' arg{2} '\s*([,\)])'], [arg{1} ' *' arg{2} '$1']);
                newfunc = regexprep( newfunc, [arg{2} '->\s*data'], arg{2});
                
                append(k) = true;
            end
        end
        
        %% Change the prototype of function
        newfunc = strrep(newfunc, prototype{i}{2}, newargs);
        str = strrep(str, funcdecl, newfuncdecl);
        
        %% Find function calls to the kernel functions
        calls = regexp( str, funccall(prototype{i}{1}), 'match');
        for k=1:length(calls)
            if ~isempty(regexp(calls{k}, '\s+static\s+', 'once'))
                continue;
            end
            [call, newcall, args] = parsefunccall( calls{k}, prototype{i}{1});
            assert( length(args)==length(append));
            
            for j=1:length(args)
                if j>1
                    newcall = sprintf( '%s, ', newcall);
                end
                
                if append(j)
                    newcall = sprintf( '%s%s', newcall, [args{j} '->data']);
                else
                    newcall = sprintf( '%s%s', newcall, args{j});
                end
            end

            str = strrep(str, call, newcall);
        end
    end
    
    str = strrep( str, kernels{i}, newfunc);
end

end

function [call, prefix, args] = parsefunccall( call, func)

% Removed ');' at the end
call = regexprep( call, ')\s*;', '');
prefix = regexp(call, ['.*[^\w]' func '\s*\('], 'match'); 
prefix = prefix{1};

args = strtrim(textscan( strrep( call, sprintf('\n'), ' '), ...
    '%s', 'Delimiter', ','));
args = args{1};
% remove func( from args{1}{1}
args{1} = regexprep(args{1}, ['.*[^\w]?' func '\s*\((.+)'], '$1');

% check whether there are '(' in the args
i=1; 
while i<length(args)
    % Merge arguments if parentheses do not match
    if length( strfind( args{i}, '(')) < length( strfind( args{i}, ')'))
        args{i} = [args{i} ', ' args{i+1}];
        args = args{[1:i i+2:length(args)]};
    end
    i = i + 1;
end

end