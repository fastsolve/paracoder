function [cfile_str, hfile_str, ctypes_str, success] = remove_emxArrays ...
    (cfile_str, hfile_str, ctypes_str, m2c_opts)
%Attempt to remove all references to emxArrays.
%The emxArrays can be removed if there are no references to emxInit,
%emxFree, emxEnsureCapacity, and size information.

success = false;

[~, func, ~] = fileparts(m2c_opts.funcName{1});
altapis = [func, strtrim(strrep(regexp(m2c_opts.codegenArgs, ...
    '(\w+)\s+-args', 'match'), ' -args', ''))];
funcname = altapis{1};

if ~isempty(strfind(cfile_str, 'emxArray_Init'))
    warning('m2c:CannotProcessKernel', ['Function ' funcname ...
        ' contains temporary emxArrays, so emxArray cannot be removed.']);
    return;
elseif ~isempty(strfind(cfile_str, '->size'))
    warning('m2c:CannotProcessKernel', ['Function ' funcname ...
        ' explicitly uses size information of arrays, so emxArray cannot be removed.']);
    return;
end

%Check whether there are still calls to size.

% Remove declaration of emxCreate_basictype, emxCreateND_basictype,
% and emxCreateWrapperND_basictype, emxDestroyArray_basictype
hfile_str = regexprep(hfile_str, ['extern emxArray_\w+\s+\*emxCreate_' re_basictype ...
    '\([^,\)]+,[^,\)]+\);\n'], '');
hfile_str = regexprep(hfile_str, ['extern emxArray_\w+\s+\*emxCreateND_' re_basictype ...
    '\([^,\)]+,[^,\)]+\);\n'], '');
hfile_str = regexprep(hfile_str, ['extern emxArray_\w+\s+\*emxCreateWrapper_' re_basictype ...
    '\([^,\)]+,[^,\)]+,[^,\)]+\);\n'], '');
hfile_str = regexprep(hfile_str, ['extern emxArray_\w+\s+\*emxCreateWrapperND_' re_basictype ...
    '\([^,\)]+,[^,\)]+,[^,\)]+\);\n'], '');
hfile_str = regexprep(hfile_str, ['extern void\s+emxDestroyArray_' re_basictype ...
    '\([^,\)]+\);\n'], '');

% Also remove emxInitArray_
cfile_str = regexprep(cfile_str, ['void\s+emxInitArray_' re_basictype ...
    '\([^,\)]+,[^,\)]+\)\s*' re_funcbody], '');
hfile_str = regexprep(hfile_str, ['extern void\s+emxInitArray_' re_basictype ...
    '\([^,\)]+,[^,\)]+\);\n'], '');

% Remove definition of emxArray__*
ctypes_str = regexprep(ctypes_str, ['#ifndef\s+struct_emxArray_\w+\s+'...
    '#define\s+struct_emxArray_\w+\s+struct\s+emxArray_\w+\s+{[^}]+};\s+' ...
    '#endif\s+#ifndef\s+typedef_emxArray_\w+\s+#define\s+typedef_emxArray_\w+\s+' ...
    'typedef\s+struct\s+emxArray_\w+\s+' ...
    'emxArray_\w+;\s+#endif\n'], '');

% Remove #include _types.h
hfile_str = regexprep(hfile_str, '#include "\w+_types.h"\n', '');

% Remove empty _initialize and _terminate routines
cfile_str = regexprep(cfile_str, ['void\s+\w+(_initialize|_terminate)' ...
    '\(void\)\s*' re_funcbody], '');
hfile_str = regexprep(hfile_str, ['extern void\s+\w+(_initialize|_terminate)' ...
    '\(void\);\n'], '');
hfile_str = regexprep(hfile_str, '#include "\w+_types.h"\n', '');

[cfile_str, hfile_str] = optimize_kernels(funcname, cfile_str, hfile_str, m2c_opts);

% Remove rtwtypes from header file
if ~m2c_opts.typeRep
    hfile_str = regexprep(hfile_str, '\n#include "rtwtypes.h"', '');
end

success = true;

end

function [cfile_str, hfile_str] = optimize_kernels(funcname, cfile_str, hfile_str, m2c_opts)
%% Find kernel functions

[kernel, prototype] = regexp(cfile_str, re_funcdef(funcname), 'match', 'tokens', 'once');
funcdecl = regexp(hfile_str, ['\nextern\s+\w+\s+' funcname '\s*\([^\)]*\);'], 'match', 'once');


%% Find emxArray arguments and change them to plain pointers
newfuncdecl = funcdecl;
newfunc = kernel;
newargs = prototype{1};

args = strtrim(textscan(strrep(newargs, sprintf('\n'), ' '), '%s', 'Delimiter', ','));
args = args{1};
append = false(length(args),1);
for k=1:length(args)
    arg = regexp(args{k}, ['emxArray_(' re_basictype ')\s*\*\s*(\w+)'], 'tokens', 'once');
    
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

newfunc = strrep(newfunc, prototype{1}, newargs);

%% Find function calls to the kernel functions
while true
    [calls,pos] = regexp(cfile_str, re_funccall(funcname), 'match', 'once');
    if isempty(calls)
        break;
    end
    if ~isempty(regexp(calls, '\s+static\s+', 'once'))
        continue;
    end
    [call, newcall, args] = parsefunccall(calls, funcname);
    assert(length(args)==length(append));
    
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

hfile_str = strrep(hfile_str, funcdecl, newfuncdecl);
cfile_str = strrep(cfile_str, kernel, newfunc);

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