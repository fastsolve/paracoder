function writeMexFile(funcname, mpath, cpath, m2c_opts)

% TODO: Implement support for varargin, varargout, cell arrays, complex
%       numbers, global variables, and function pointers.

altapis = [funcname, strtrim(strrep(regexp(m2c_opts.codegenArgs, '(\w+)\s+-args', 'match'), ' -args', ''))];

% Write out _mex file
outCfile = [cpath funcname '_mex.' m2c_opts.suf];

[~, signature] = ckSignature(m2c_opts, 'codegen');

if cpath(1) == '/' || cpath(1) == '\'
    filestr = [funcname '_mex.' m2c_opts.suf];
else
    filestr = outCfile;
end

filestr = sprintf('%s\n', ...
    '/*', [' * ' filestr], ' *', ...
    [' * Auxiliary code for mexFunction of ' funcname], ' *', ...
    ' * C source code generated by m2c.', ...
    [' * ' signature], ...
    ' *', ' */', '', ...
    '#ifdef MATLAB_MEX_FILE', ...
    '#include "mex.h"',  ...
    '#else',  ...
    '#include "matrix.h"',  ...
    '#endif',  ...
    '/* Include the C file generated by codegen in lib mode */', ...
    ['#include "' funcname '.h"'], ...
    '#include "m2c.c"', ...
    '/* Include declaration of some helper functions. */', ...
    '#include "lib2mex_helper.c"', '');

% Parse input arguments from C files.
alt_nlhs = zeros(length(altapis),1);
alt_nrhs = zeros(length(altapis),1);
for i=1:length(altapis)
    % Parse input arguments from C files.
    [vars, ret, nlhs, nrhs, SDindex, pruned_vars] = parse_cgfiles(funcname, altapis{i}, mpath);
    if ~isempty(SDindex)
        fprintf(2, ['m2c Info: Codegen generated a StackData object "%s" of type "%s". ' ...
            'This probably indicates that you have some large, fixed-size local buffers in some subroutines ' ...
            'that Codegen grouped into an object. See "%scodegen/lib/%s/%s_types.h" for the definition and content of the object.\n'], ...
            vars(SDindex).name, vars(SDindex).type, mpath, funcname, funcname);
    end
    filestr = sprintf('%s', filestr, printApiFunction(funcname, altapis{i}, ...
        nlhs, nrhs, vars, ret, SDindex, pruned_vars, m2c_opts.timing));
    alt_nlhs(i) = nlhs; alt_nrhs(i) = nrhs;
end

filestr = sprintf('%s', filestr, printMexFunction(altapis, alt_nlhs, alt_nrhs));

writeFile(outCfile, filestr);
end

function str = printApiFunction(funcname, altname, nlhs, nrhs, vars, ret, SDindex, pruned_vars, timing)
% Print into a string an API function for the function with the given
% numbers of input and output arguments.

if ~isempty(ret)
    retval = [ret.name ' = '];
else
    retval = '';
end

vars_ret = [vars; ret];
if isempty(SDindex)
    SDname = '';
else
    SDname = ['&' vars(SDindex).name];
end

%TODO: Improve computation of sub_mx_level_in and sub_mx_level_out
[marshallin_substr, sub_mx_level_in] = marshallin(altname, vars_ret, nlhs, nrhs, SDindex);
[marshallout_substr, sub_mx_level_out] = marshallout(vars_ret, nlhs, pruned_vars);
sub_mx_level = max(sub_mx_level_in, sub_mx_level_out);

str = sprintf('%s\n', ...
    ['void ' altname '_api(const mxArray ** prhs, const mxArray **plhs) {'], ...
    var_declr(vars, ret, sub_mx_level, timing), ...
    marshallin_substr, '', '    /* Invoke the target function */', ...
    ['    ' funcname '_initialize(' SDname ');']);

if ~isempty(timing)
    str = sprintf('%s\n', str, '    _timestamp = M2C_wtime();');
end

str = sprintf('%s\n', str, ...
    ['    ' retval altname '(' listargs(vars) ');']);

if ~isempty(timing)
    str = sprintf('%s\n', str, ...
        '    _timestamp = M2C_wtime() - _timestamp;', ...
        ['    printf("Function ' funcname ' completed in %g seconds.\n", _timestamp);']);
end

str = sprintf('%s\n', str, ...
    ['    ' funcname '_terminate();'], '', ...
    marshallout_substr, '', var_free(vars_ret), '}');

% Remove two consecutive empty lines
while ~isempty(regexp(str, '\n\n\n', 'once'))
    str = regexprep(str, '(\n\n)\n', '$1');
end

end

function str = printMexFunction(altapis, alt_nlhs, alt_nrhs)
% Print into a string a mexFunction for the function with the given
% numbers of input and output arguments.

str = 'void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {';

if max(alt_nlhs)>1
    str = sprintf('\n%s', ...
        str, '    /* Temporary copy for mex outputs. */', ...
        ['    mxArray *outputs[' int2str(max(alt_nlhs)) '];'], ...
        '    int i;', ...
        '    int nOutputs = (nlhs < 1 ? 1 : nlhs);', '');
end

haselse = '';
for i=1:length(altapis)
    funcname = altapis{i}; nlhs = alt_nlhs(i); nrhs = alt_nrhs(i);
    str = sprintf('\n%s', str, ...
        ['    ' haselse 'if (nrhs == ' int2str(nrhs) ') {'], ...
        ['        if (nlhs > ' int2str(nlhs) ')'], ...
        ['            mexErrMsgIdAndTxt("' funcname ':TooManyOutputArguments",' ...
        '"Too many output arguments for entry-point ' funcname '.");']);
    if max(alt_nlhs)<=1
        str = sprintf('\n%s', str, ...
            '        /* Call the API function. */', ...
            ['        ' funcname '_api(prhs, (const mxArray**)plhs);'], '    }');
    else
        str = sprintf('\n%s', str, ...
            '        /* Call the API function. */', ...
            ['        ' funcname '_api(prhs, (const mxArray**)outputs);'], '    }');
    end
    
    haselse = 'else ';
end

str = sprintf('\n%s', ...
    str, '    else', ...
    ['        mexErrMsgIdAndTxt("' altapis{1} ':WrongNumberOfInputs","' ...
    'Incorrect number of input variables for entry-point ' altapis{1} '.");']);

if max(alt_nlhs)>1
    str = sprintf('\n%s', ...
        str, '', '    /* Copy over outputs to the caller. */', ...
        '    for (i = 0; i < nOutputs; ++i) {', ...
        '        plhs[i] = outputs[i];', ...
        '    }');
end

str = sprintf('\n%s', str, '}');

% Remove two consecutive empty lines
while ~isempty(regexp(str, '^\n\n', 'once'))
    str = regexprep(str, '^(\n)\n', '$1');
end
while ~isempty(regexp(str, '\n\n\n', 'once'))
    str = regexprep(str, '(\n\n)\n', '$1');
end

end

function str = var_declr(vars, ret, sub_mx_level, timing)
% Produce variable declarations
decl_emx = '';
decl_basic = '';
decl_struct = '';
has_struct_arr = false;

for i=1:length(vars)
    if vars(i).isemx
        % declare a varialbe of type emxArray
        if ~isempty(vars(i).subfields)
            has_struct_arr=true;
        end
        decl_emx = sprintf('%s\n    %-20s %s;', decl_emx, ...
            vars(i).type, vars(i).name);
    elseif ~isempty(vars(i).subfields)
        if prod(vars(i).size)>1
            has_struct_arr=true;
        end
        
        % declare a variable of a struct type
        if prod(vars(i).size)==1
            decl_struct = sprintf('%s\n    %-20s %s;', decl_struct, ...
                vars(i).type, vars(i).name);
        else
            decl_struct = sprintf('%s\n    %-20s %s[%d];', decl_struct, ...
                vars(i).type, vars(i).name, prod(vars(i).size));
        end
        [~,b] = check_struct_levels(vars(i).subfields);
        
        has_struct_arr = has_struct_arr || b;
    elseif isequal(vars(i).type, 'char_T')
        % declare a varialbe of primitive type
        decl_basic = sprintf('%s\n    %-20s %s[%d];', decl_basic, ...
            'char', vars(i).name, prod(vars(i).size));
    elseif prod(vars(i).size)>1 && ~any(vars(i).vardim)
        % declare a varialbe of primitive type
        decl_basic = sprintf('%s\n    %-20s %s[%d];', decl_basic, ...
            vars(i).type, vars(i).name, prod(vars(i).size));
    else
        % declare a varialbe of primitive type
        decl_basic = sprintf('%s\n    %-20s %s%s;', decl_basic, ...
            vars(i).type, vars(i).modifier, vars(i).name);
    end
end

if ~isempty(ret)
    decl_basic = sprintf('%s\n    %-20s %s%s;', decl_basic, ...
        ret.type, ret.modifier, ret.name);
end

if sub_mx_level
    % declare a variable of a struct type
    if sub_mx_level>1; vstr = sprintf(', *_sub_mx%d', 2:sub_mx_level);
    else vstr = ''; end
    decl_struct = sprintf('%s\n    %-20s %s%s;', decl_struct, 'mxArray', '*_sub_mx1', vstr);
end

if has_struct_arr
    % declare variables for index
    decl_struct = sprintf('%s\n    %-20s _sub_k;', decl_struct, 'int32_T');
end

if ~isempty(timing);
    % declare variables for timing
    decl_timing = sprintf('\n    real64_T   _timestamp;');
else
    decl_timing = '';
end

str = sprintf('%s\n%s\n%s\n%s\n', decl_emx, decl_struct, decl_basic, decl_timing);

end

function [level,has_struct_arr] = check_struct_levels(vars, level)
% Check number of levels of a struct and whether it contains struct arrays
if nargin<2; level = 1; end

has_struct_arr = false;
for i=1:length(vars)
    if ~isempty(vars(i).subfields)
        [level,b] = check_struct_levels(vars(i).subfields, level+1);
        
        has_struct_arr = has_struct_arr || b || prod(vars(i).size)~=1;
    end
end
end

function [str, sub_mx_leve] = marshallin(funcname, vars, nlhs, nrhs, SDindex)
% Marshall function input arguments and preallocate output arguments.

invarsindex = zeros(nrhs, 1);
outvarsindex = zeros(nlhs, 1);

for i=1:length(vars)
    if ~isempty(vars(i).iindex)
        invarsindex(vars(i).iindex) = i;
    end
    if ~isempty(vars(i).oindex)
        outvarsindex(vars(i).oindex) = i;
    end
end

sub_mx_leve = 0;
str = '';
first = true;
for j=1:nrhs
    i = invarsindex(j); assert(i>0);
    var = vars(i);
    
    if first
        str = '    /* Marshall in function inputs */';
        first = false;
    end
    
    if ~isempty(var.oindex)
        str = sprintf('%s\n    plhs[%d] = mxDuplicateArray(prhs[%d]);', ...
            str, var.oindex-1, var.iindex-1);
        mx = ['plhs[' int2str(var.oindex-1) ']'];
    else
        mx = ['prhs[' int2str(var.iindex-1) ']'];
    end
    if ~isempty(var.subfields)
        [str, sub_mx_leve] = marshallin_struct(str, mx, var, funcname);
    else
        str = sprintf(['%s\n    if (mxGetNumberOfElements(%s) && mxGetClassID(%s) != %s)\n', ...
            '        mexErrMsgIdAndTxt("%s:WrongInputType",\n',...
            '            "Input argument %s has incorrect data type. %s is expected.");'], ...
            str, mx, mx, getMxClassID(var.basetype), ...
            funcname, var.name, getMatlabClass(var.basetype));
        
        if var.isemx
            for i=1:length(var.size)
                if ~var.vardim(i)
                    str = sprintf(['%s\n    if (mxGetNumberOfElements(%s) && mxGetDimensions(%s)[%d] != %d)\n', ...
                        '        mexErrMsgIdAndTxt("%s:WrongSizeOfInputArg",\n',...
                        '            "Dimension %d of %s should be equal to %d.");'], ...
                        str, mx, mx, i-1, var.size(i), funcname, i, var.name, var.size(i));
                elseif isfinite(var.size(i))
                    str = sprintf(['%s\n    if (mxGetDimensions(%s)[%d] > %d)\n', ...
                        '        mexErrMsgIdAndTxt("%s:WrongSizeOfInputArg",\n',...
                        '            "Dimension %d of %s should be no more than %d.");'], ...
                        str, mx, i-1, var.size(i), funcname, i, var.name, var.size(i));
                end
            end
            if any(isinf(var.size))
                str = sprintf('%s\n    alias_mxArray_to_emxArray(%s, (emxArray__common *)&%s, "%s", %d);', ...
                    str, mx, var.name, var.name, length(var.size));
            else
                str = sprintf('%s\n    copy_mxArray_to_emxArrayStatic(%s, %s.data, %s.size, %d, "%s", %d);', ...
                    str, mx, var.name, var.name, length(var.size), var.name, prod(var.size));
            end
        elseif prod(var.size)~=1
            assert(~any(var.vardim));
            for i=1:length(var.size)
                str = sprintf(['%s\n    if (mxGetDimensions(%s)[%d] != %d)\n', ...
                    '        mexErrMsgIdAndTxt("%s:WrongSizeOfInputArg",\n',...
                    '            "Dimension %d of %s should be equal to %d.");'], ...
                    str, mx, i-1, var.size(i), funcname, i, var.name, var.size(i));
            end
            assert(~isequal(var.type, 'char') && ~isequal(var.type, 'char_T'));
            str = sprintf('%s\n    copy_mxArray_to_array(%s, %s, %d);', ...
                str, mx, var.name, prod(var.size));
        else
            str = sprintf(['%s\n    if (mxGetNumberOfElements(%s) != 1)\n', ...
                '        mexErrMsgIdAndTxt("%s:WrongSizeOfInputArg",\n',...
                '            "Argument %s should be a scalar.");'], ...
                str, mx, funcname, var.name);
            if isempty(var.modifier)
                if isequal(var.type, 'char_T') || isequal(var.type, 'char')
                    str = sprintf('%s\n    %s = *(mxChar*)mxGetData(%s);', ...
                        str, var.name, mx);
                else
                    str = sprintf('%s\n    %s = *(%s*)mxGetData(%s);', ...
                        str, var.name, var.type, mx);
                end
            else
                str = sprintf('%s\n    %s = (%s*)mxGetData(%s);', ...
                    str, var.name, var.type, mx);
            end
        end
    end
end

first = true;
% Preallocate output arguemnts that are arrays of fixed size
for j=1:nlhs
    if outvarsindex(j)==0
        continue;
    end
    
    var = vars(outvarsindex(j));
    if ~isempty(var.iindex); continue; end
    
    if first
        str = sprintf('%s\n\n%s', str, '    /* Preallocate output variables */');
        first = false;
    end
    
    if var.isemx && any(isinf(var.size))
        str = sprintf('%s\n    init_emxArray((emxArray__common*)&%s, %d);', ...
            str, var.name, length(var.size));
    elseif ~isempty(var.subfields)
        str = preallocate_struct(str, var.name, var);
    elseif ~isempty(var.modifier) && prod(var.size)>0 && ~isequal(var.type, 'char_T')
        str = sprintf(['%s\n    {mwSize l_size[] = {', ...
            regexprep(strtrim(sprintf('%d ', var.size)), ' ', ', '), '};\n', ...
            '    *(void **)&%s = prealloc_mxArray((mxArray**)&plhs[%d], %s, %d, l_size); }'], ...
            str, var.name, j-1, getMxClassID(var.basetype), length(var.size));
    end
end

% Preallocate StackData object
if ~isempty(SDindex)
    var = vars(SDindex);
    sf = vars(SDindex).subfields;
    str = sprintf('%s\n\n%s\n    %s.%s = (%s *)mxMalloc(sizeof(%s));', str, ...
        '    /* Allocate Stack Data */', var.name,sf.name, sf.type, sf.type);
end

end

function str = preallocate_struct(str, prefix, var, level)
% Pre-allocate output struct

if nargin<4; level=1; end
assert(~var.isemx);

substr = '';
indent = repmat('    ',1,level-1);
if prod(var.size)>1
    indent = repmat('    ',1,level);
end

for k=1:length(var.subfields)
    sf = var.subfields(k);
    if sf.isemx && any(isinf(sf.size))
        substr = sprintf(['%s\n%s    *(void **)&%s.%s = mxCalloc(1, sizeof(emxArray__common));', ...
            '%s    init_emxArray((emxArray__common*)%s.%s, %d);'], ...
            substr, indent, prefix, sf.name, indent, prefix, sf.name, length(sf.size));
    elseif ~isempty(sf.subfields)
        substr = preallocate_struct(substr, [prefix '.' sf.name], sf, level+1);
    end
end

if prod(var.size)>1 && ~isempty(substr)
    substr = sprintf('%s\n%s%s\n%s}', '', indent, ...
        'for (_sub_k=0; _sub_k<%d; ++_sub_k) {', substr, indent);
end

str = sprintf('%s%s', str, substr);
end

function [str, sub_mx_level] = marshallin_struct(str, mx, var, funcname, level, prefix)
if nargin<5; level=1; end
if nargin<6; prefix=''; end

indent = repmat('    ',1,level-1);

str = sprintf('%s\n', str);

% Check struct type and fields
str = sprintf(['%s\n%s    if (!mxIsStruct(%s))\n', ...
    '%s        mexErrMsgIdAndTxt("%s:WrongInputType",\n',...
    '%s            "Input argument %s has incorrect data type. struct is expected.");'], ...
    str, indent, mx, indent, funcname, indent, [prefix var.name]);
str = sprintf(['%s\n%s    if (mxGetNumberOfFields(%s)!=%d)\n', ...
    '%s        mexErrMsgIdAndTxt("%s:InputStructWrongFields",\n',...
    '%s            "Input argument %s has incorrect number of fields.");'], ...
    str, indent, mx, length(var.subfields), indent, funcname, indent, [prefix var.name]);
if all(isfinite(var.size)) && ~any(var.vardim)
    str = sprintf(['%s\n%s    if (mxGetNumberOfElements(%s) != %d)\n', ...
        '%s        mexErrMsgIdAndTxt("%s:WrongSizeOfInputArg",\n',...
        '%s            "Argument %s must contain %d items.");'], ...
        str, indent, mx, prod(var.size), indent, funcname, indent, var.name, prod(var.size));
end

if var.isemx && any(isinf(var.size))
    str = sprintf('%s\n%s    init_emxArray_from_mxArray(%s, (emxArray__common*)&%s, "%s", %d, sizeof(%s));', ...
        str, indent, mx, [prefix var.name], [prefix var.name], length(var.size), var.structname);
    indent = repmat('    ',1,level);
    index = '_sub_k'; p = [[prefix var.name] '.data[_sub_k]' ];
elseif prod(var.size)>1
    indent = repmat('    ',1,level);
    index = '_sub_k'; p = [[prefix var.name] '[_sub_k]' ];
else
    index = '0'; p = [prefix var.name];
end

submx = ['_sub_mx' int2str(level)];
substr = '';
sub_mx_level = 0;
local_sub_mx_level = ~isempty(var.subfields);
for k=1:length(var.subfields)
    sf = var.subfields(k);
    
    % Check fields
    substr = sprintf('%s\n%s    %s = mxGetField(%s, %s, "%s");', ...
        substr, indent, submx, mx, index, sf.name);
    substr = sprintf(['%s\n%s    if (%s==NULL)\n', ...
        '%s        mexErrMsgIdAndTxt("%s:WrongInputStruct",\n',...
        '%s            "Input argument %s does not have the field %s.");'], ...
        substr, indent, submx, indent, funcname, indent, [prefix var.name], sf.name);
    
    substr = sprintf(['%s\n%s    if (mxGetNumberOfElements(%s) && mxGetClassID(%s) != %s)\n', ...
        '%s        mexErrMsgIdAndTxt("%s:WrongInputType",\n',...
        '%s            "Input argument %s.%s has incorrect data type. %s is expected.");'], ...
        substr, indent, submx, submx, getMxClassID(sf.basetype), indent, funcname, ...
        indent, [prefix var.name], sf.name, getMatlabClass(sf.basetype));
    
    if sf.isemx
        for i=1:length(sf.size)
            if ~sf.vardim(i)
                substr = sprintf(['%s\n%s    if (mxGetNumberOfElements(%s) && mxGetDimensions(%s)[%d] != %d)\n', ...
                    '%s        mexErrMsgIdAndTxt("%s:WrongSizeOfInputArg",\n',...
                    '%s            "Dimension %d of %s.%s should be equal to %d.");'], ...
                    substr, indent, submx, submx, i-1, sf.size(i), indent, funcname, indent, ...
                    i, [prefix var.name], sf.name, sf.size(i));
            elseif isfinite(sf.size(i))
                substr = sprintf(['%s\n%s    if (mxGetDimensions(%s)[%d] > %d)\n', ...
                    '%s        mexErrMsgIdAndTxt("%s:WrongSizeOfInputArg",\n',...
                    '%s            "Dimension %d %s.%s should be equal to %d.");'], ...
                    substr, indent, submx, i-1, sf.size(i), indent, funcname, indent, ...
                    i, [prefix var.name], sf.name, sf.size(i));
            end
        end
        if any(isinf(sf.size))
            substr = sprintf('%s\n%s    *(void**)&%s.%s = mxCalloc(1, sizeof(emxArray__common));', ...
                substr, indent, p, var.subfields(k).name);
            substr = sprintf('%s\n%s    alias_mxArray_to_emxArray(%s, (emxArray__common*)%s.%s, "%s.%s", %d);', ...
                substr, indent, submx, p, sf.name, [prefix var.name], sf.name, length(sf.size));
        else
            substr = sprintf('%s\n%s    copy_mxArray_to_emxArrayStatic(%s, %s.%s.data, %s.%s.size, %d, "%s.%s", %d);', ...
                substr, indent, submx, p, sf.name, p, sf.name, length(sf.size), [prefix var.name], sf.name, prod(sf.size));
        end
    elseif ~isempty(var.subfields(k).subfields)
        [substr, sub_mx_level1] = marshallin_struct(substr, submx, var.subfields(k), ...
            funcname, level+1, [prefix var.name '.']);
        sub_mx_level = max(sub_mx_level, sub_mx_level1);
    elseif prod(sf.size)>1
        assert(~isequal(sf.type, 'char') && ~isequal(sf.type, 'char_T'));
        for i=1:length(sf.size)
            substr = sprintf(['%s\n%s    if (mxGetNumberOfElements(%s) && mxGetDimensions(%s)[%d] != %d)\n', ...
                '%s        mexErrMsgIdAndTxt("%s:WrongSizeOfInputArg",\n',...
                '%s            "Dimension %d of %s.%s should be equal to %d.");'], ...
                substr, indent, submx, submx, i-1, sf.size(i), indent, funcname, indent, ...
                i, [prefix var.name], sf.name, sf.size(i));
        end
        substr = sprintf('%s\n%s    copy_mxArray_to_array(%s, %s.%s, %d);', ...
            substr, indent, submx, p, sf.name, prod(sf.size));
    else
        substr = sprintf(['%s\n%s    if (mxGetNumberOfElements(%s) != 1)\n', ...
            '%s        mexErrMsgIdAndTxt("%s:WrongSizeOfInputArg",\n',...
            '%s            "Argument %s.%s should be a scalar.");'], ...
            substr, indent, submx, indent, funcname, indent, [prefix var.name], sf.name);
        substr = sprintf('%s\n%s    %s.%s = *(%s*)mxGetData(%s);', ...
            substr, indent, p, sf.name, sf.type, submx);
    end
end

%
if ~isempty(substr)
    if var.isemx
        indent = repmat('    ',1,level);
        str = sprintf('%s\n%sfor (_sub_k=mxGetNumberOfElements(%s)-1; _sub_k>=0; --_sub_k) {%s\n%s}', ...
            str, indent, mx, substr, indent);
    elseif prod(var.size)>1
        indent = repmat('    ',1,level);
        str = sprintf('%s\n%sfor (_sub_k=0; _sub_k<%d; ++_sub_k) {%s\n%s}', ...
            str, indent, prod(var.size), substr, indent);
    else
        str = sprintf('%s\n%s', str, substr);
    end
end

sub_mx_level = sub_mx_level + local_sub_mx_level;

end

function str = listargs(vars)
% List the arguments for calling the function

str = '';
for i=1:length(vars)
    if vars(i).isemx
        str = sprintf('%s, &%s', str, vars(i).name);
    elseif ~isempty(vars(i).subfields)
        if ~isempty(vars(i).modifier) && prod(vars(i).size)==1
            modifier='&';
        else
            modifier='';
        end
        str = sprintf('%s, %s%s', str, modifier, vars(i).name);
    else
        str = sprintf('%s, %s', str, vars(i).name);
    end
end

str = str(3:end);
end

function [str,sub_mx_level] = marshallout(vars, nlhs, pruned_vars)
% Marshall function output arguments

if nlhs==0;
    str='';
    return;
else
    str = '    /* Marshall out function outputs */';
end

outvarsindex = zeros(nlhs, 1);
for i=1:length(vars)
    if ~isempty(vars(i).oindex)
        outvarsindex(vars(i).oindex) = i;
    end
end

sub_mx_level = 0;
for j=1:nlhs
    pruned = 0;
    if outvarsindex(j)==0
        for k=1:length(pruned_vars)
            if pruned_vars(k).oindex==j
                pruned = k;
                var = pruned_vars(k);
                break;
            end
        end
    else
        var = vars(outvarsindex(j));
    end
    
    if pruned
        str = sprintf('%s\n    /* Creating empty mxArray for pruned variable %s */', str, var.name);
        str = sprintf(['%s\n    {mwSize l_size[] = {', ...
            regexprep(strtrim(sprintf('%d ', var.size)), ' ', ', '), '};\n', ...
            '    prealloc_mxArray((mxArray**)&plhs[%d], %s, %d, l_size); }'], ...
            str, j-1, ['mx' upper(var.type) '_CLASS'], length(var.size));
    elseif ~isempty(var.subfields)
        [str,sub_mx_level1] = marshallout_struct(str, sprintf('plhs[%d]', j-1), var);
        sub_mx_level = max(sub_mx_level, sub_mx_level1);
    elseif ~isempty(var.iindex) && var.isemx && any(isinf(var.size))
        str = sprintf('%s\n    if (%s.canFreeData) plhs[%d] = move_emxArray_to_mxArray((emxArray__common*)&%s, %s);', ...
            str, var.name, j-1, var.name, getMxClassID(var.basetype));
    elseif var.isemx
        if all(isfinite(var.size)) && any(var.vardim)
            str = sprintf(['%s\n', ...
                '    plhs[%d] = copy_array_to_mxArray(%s.data, %s, %d, %s.size);'], ...
                str, j-1, var.name, getMxClassID(var.basetype), length(sz), var.name);
        elseif all(isfinite(var.size))
            sz = var.size;
            sz_str = sprintf(', %d', sz); sz_str = sz_str(3:end);
            
            str = sprintf(['%s\n    {int32_T l_size[] = {%s};\n' ...
                '    plhs[%d] = copy_array_to_mxArray(%s, %s, %d, l_size); }'], ...
                str, sz_str, j-1, var.name, getMxClassID(var.basetype), length(sz));
        else
            str = sprintf('%s\n    plhs[%d] = move_emxArray_to_mxArray((emxArray__common*)&%s, %s);', ...
                str, j-1, var.name, getMxClassID(var.basetype));
        end
    elseif isempty(var.modifier)
        str = sprintf('%s\n    plhs[%d] = copy_scalar_to_mxArray(&%s, %s);', ...
            str, j-1, var.name, getMxClassID(var.basetype));
    elseif isequal(var.type, 'char_T')
        if ~isempty(var.sizefield)
            str = sprintf(['%s\n', ...
                '    plhs[%d] = copy_array_to_mxArray(%s, %s, %d, %s);'], ...
                str, j-1, var.name, getMxClassID(var.basetype), vars(var.sizefield).size, vars(var.sizefield).name);
        else
            str = sprintf(['%s\n    {int32_T l_size[] = {', ...
                regexprep(strtrim(sprintf('%d ', var.size)), ' ', ', '), '};\n', ...
                '    plhs[%d] = copy_array_to_mxArray(%s, %s, %d, l_size); }'], ...
                str, j-1, var.name, getMxClassID(var.basetype), length(var.size));
        end
    elseif ~isempty(var.sizefield)
        % Need to resize a preallocated varilable-length array
        str = sprintf(['%s\n', '    resize_mxArray(plhs[%d], %d, %s);'], ...
            str, j-1, vars(var.sizefield).size, vars(var.sizefield).name);
    else
        str = sprintf('%s\n    /* Nothing to do for plhs[%d] */', str, j-1);
    end
end
end

function [str,sub_mx_level] = marshallout_struct(str, mx, var, level, prefix)
% sub_mx_level is needed for determining the levels of _sub_mx

if nargin<4; level=1; end
if nargin<5; prefix=''; end

indent = repmat('    ',1,level-1);

str = sprintf('%s\n%s    {const char *_fields[] = { %s ""};', ...
    str, indent, sprintf('"%s", ', var.subfields.name));

if var.isemx
    str = sprintf('%s\n%s    %s = create_struct_mxArray(%s.numDimensions, %s.size, %d, _fields);}', ...
        str, indent, mx, [prefix var.name], [prefix var.name], length(var.subfields));
    indent = repmat('    ',1,level); index='_sub_k'; sub='.data[_sub_k]';
elseif prod(var.size)>1
    sz_str = sprintf(', %d', var.size); sz_str = sz_str(3:end);
    
    str = sprintf(['%s\n%s    int32_T l_size[] = {%s};' ...
        '\n%s    %s = create_struct_mxArray(%d, l_size, %d, _fields);}'], ...
        str, indent, sz_str, indent, mx, length(var.size), length(var.subfields));
    indent = repmat('    ',1,level); index='_sub_k'; sub='[_sub_k]';
else
    str = sprintf('%s\n%s    int32_T _one=1;\n%s    %s = create_struct_mxArray(1, &_one, %d, _fields);}', ...
        str, indent, indent, mx, length(var.subfields));
    index='0';  sub='';
end

sub_mx_level = 0;
local_sub_mx_level = ~isempty(var.subfields);
substr = '';
for k=1:length(var.subfields)
    sf = var.subfields(k);
    sfname = sf.name;
    if ~isempty(sf.subfields)
        [substr,sub_mx_level1] = marshallout_struct(substr, ['_sub_mx' int2str(level)], sf, level+1, [prefix var.name sub '.']);
        substr = sprintf('%s\n%s    mxSetFieldByNumber((mxArray*)(%s), %s, %d, _sub_mx%d);', ...
            substr, indent, mx, index, k-1, level);
        sub_mx_level = max(sub_mx_level, sub_mx_level1);
    elseif sf.isemx
        if all(isfinite(sf.size)) && any(sf.vardim)
            substr = sprintf(['%s\n' ...
                '    mxSetFieldByNumber((mxArray*)(%s), %s, %d, ' ...
                'copy_array_to_mxArray(%s%s.%s.data, %s, %d, %s%s.%s.size));'], ...
                substr, mx, index, k-1, [prefix var.name], sub, sfname, ...
                getMxClassID(sf.basetype), length(sf.size), ...
                [prefix var.name], sub, sfname);
        elseif all(isfinite(sf.size))
            sz = sf.size;
            sz_str = sprintf(', %d', sz); sz_str = sz_str(3:end);
            
            substr = sprintf(['%s\n%s    {int32_T l_size[] = {%s};\n' ...
                '%s    mxSetFieldByNumber((mxArray*)(%s), %s, %d, ' ...
                'copy_array_to_mxArray(%s%s.%s.data, %s, %d, l_size)); }'], ...
                substr, indent, sz_str, indent, mx, index, k-1, ...
                [prefix var.name], sub, sfname, getMxClassID(sf.basetype), length(sz));
        else
            substr = sprintf(['%s\n%s    mxSetFieldByNumber((mxArray*)(%s), %s, %d, ' ...
                'move_emxArray_to_mxArray((emxArray__common*)%s%s.%s, %s));'], ...
                substr, indent, mx, index, k-1, [prefix var.name], sub, ...
                sfname, getMxClassID(sf.basetype));
        end
    elseif prod(sf.size)==1
        substr = sprintf(['%s\n%s    mxSetFieldByNumber((mxArray*)(%s), %s, %d, ' ...
            'copy_scalar_to_mxArray(&%s%s.%s, %s));'], ...
            substr, indent, mx, index, k-1, [prefix var.name], sub, sfname, getMxClassID(sf.basetype));
    elseif ~isempty(sf.sizefield)
        % Not yet debugged
        substr = sprintf(['%s\n' ...
            '%s    mxSetFieldByNumber((mxArray*)(%s), %s, %d, ' ...
            'copy_array_to_mxArray(%s%s.%s, %s, %d, %s%s.%s));'], ...
            substr, indent, mx, index, k-1, [prefix var.name], ...
            sub, sfname, getMxClassID(sf.basetype), ...
            var.subfields(sf.sizefield).size, ...
            [prefix var.name], sub, var.subfields(sf.sizefield).name);
    else
        sz = sf.size;
        sz_str = sprintf(', %d', sz); sz_str = sz_str(3:end);
        
        substr = sprintf(['%s\n%s    {int32_T l_size[] = {%s};\n' ...
            '%s    mxSetFieldByNumber((mxArray*)(%s), %s, %d, ' ...
            'copy_array_to_mxArray(%s%s.%s, %s, %d, l_size)); }'], ...
            substr, indent, sz_str, indent, mx, index, k-1, [prefix var.name], ...
            sub, sfname, getMxClassID(sf.basetype), length(sz));
    end
end

if ~isempty(substr)
    if var.isemx
        str = sprintf('%s\n%sfor (_sub_k=mxGetNumberOfElements(%s)-1; _sub_k>=0; --_sub_k) {%s\n%s}', ...
            str, indent, mx, substr, indent);
    elseif prod(var.size)>1
        str = sprintf('%s\n%sfor (_sub_k=0; _sub_k<%d; ++_sub_k) {%s\n%s}', ...
            str, indent, prod(var.size), substr, indent);
    else
        str = sprintf('%s%s', str, substr);
    end
end

sub_mx_level = sub_mx_level + local_sub_mx_level;
end

function str = var_free(vars)
% Print out free_emxArray for given variable

has_emxArray = false;

fvstr = '';
for i=1:length(vars)
    if ~isempty(vars(i).subfields)
        [fvstr,hasa] = deallocate_struct(fvstr, '', vars(i));
        has_emxArray = has_emxArray || hasa;
    elseif strncmp(vars(i).type, 'emxArray_', 9) && any(isinf(vars(i).size))
        fvstr = sprintf('%s\n    free_emxArray((emxArray__common*)&%s);', ...
            fvstr, vars(i).name);
        has_emxArray = true;
    end
end

if has_emxArray;
    str = sprintf('    /* Free temporary variables */%s', fvstr);
else
    str = '';
end
end

function [str, has_emxArray] = deallocate_struct(str, prefix, var, level)
% Deallocate output struct

if nargin<4; level=1; end
indent = repmat('    ', 1, level-1);

substr = '';

if strncmp(var.type, 'emxArray_', 9)
    has_emxArray = true;
    varname = [prefix var.name '.data[_sub_k].'];
    indent = repmat('    ', 1, level);
else
    has_emxArray = false;
    if prod(var.size)>1
        varname = [prefix var.name '[_sub_k].'];
        indent = repmat('    ', 1, level);
    else
        varname = [prefix var.name '.'];
    end
end

for k=1:length(var.subfields)
    sf = var.subfields(k);
    if sf.isemx && any(isinf(sf.size))
        substr = sprintf('%s    free_emxArray((emxArray__common*)%s%s); mxFree(%s%s);\n%s', ...
            indent, varname, sf.name, varname, sf.name, substr);
        has_emxArray = true;
    elseif ~isempty(sf.subfields)
        [substr, has_subemx] = deallocate_struct(substr, varname, sf, level+1);
        has_emxArray = has_emxArray || has_subemx;
    end
end

if isempty(substr); return; end

if strncmp(var.type, 'emxArray_', 9)
    str = sprintf('%s\n%sfor (_sub_k=nelems_emxArray((emxArray__common*)&%s)-1; _sub_k>=0; --_sub_k) {\n%s\n%s}', ...
        str, indent, [prefix var.name], substr, indent);
elseif prod(var.size)>1
    str = sprintf('%s\n%sfor (_sub_k=0; _sub_k<%d; ++_sub_k) {\n%s\n%s}', ...
        str, indent, prod(var.size), substr, indent);
else
    str = sprintf('%s\n%s', str, substr);
end
end
