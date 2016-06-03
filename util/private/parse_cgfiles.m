function [vars, ret, nlhs, nrhs, SDindex, pruned_vars] = parse_cgfiles(funcname, altfunc, mpath)
% Parse C files generated by codegen with the lib option

% Check existence of the files
mfile = [mpath altfunc '.m'];
if ~exist(mfile, 'file') && exist([mpath 'codegen/' altfunc '.m'], 'file')
    mfile = [mpath 'codegen/' altfunc '.m'];
end

hfile = [mpath 'codegen/lib/' funcname '/' funcname '.h'];
tyfile = [mpath 'codegen/lib/' funcname '/' funcname '_types.h'];
htmlfile = get_htmlfile(mpath, funcname, altfunc);

if isempty(mfile)
    error('m2c:parse_cgfile', 'Cannot find MATLAB file %s', funcname);
end

if ~exist(hfile, 'file') ||  ~exist(tyfile, 'file')
    error('m2c:parse_cgfile', 'Could not locate header file %s.\n', hfile);
elseif ~exist(htmlfile, 'file')
    error('m2c:parse_cgfile', ['Cannot locate codegen report for function %s.' ...
        'Probably function name was misspelled in the M file.'], ...
        funcname);
end

%% Read in M-file
[fid, msg] = fopen(mfile , 'r', 'n', 'US-ASCII');
if fid<0; error('m2c:OpenFileFiled', '%s', msg); end

mfile = fread(fid, inf, '*char')';
mfile = regexprep(mfile, '\r\n', '\n'); % Change Windows format to UNIX format.
fclose(fid);

mfile = regexprep(mfile, '%[^\n]*\n', '\n');
mfile = regexprep(mfile, '\.\.\.\s+', '');

toks = regexp(mfile, '^\s*function\s*(\[[\w\s,]+\]|\s+\w+)?\s*=?\s*\w+\s*(\([\w\s,]*\))?\s*\n', 'tokens');
assert(~isempty(toks), 'Cannot parse MATLAB file.');
clear mfile;

if isempty(toks{1}{1})
    m_args.output = {};
elseif  toks{1}{1}(1)~='['
    m_args.output = strtrim(textscan(toks{1}{1}, '%s', 'Delimiter', ','));
    m_args.output = m_args.output{1};
else
    m_args.output = strtrim(textscan(toks{1}{1}(2:end-1), '%s', 'Delimiter', ','));
    m_args.output = m_args.output{1};
end

if isempty(toks{1}{2}) || isequal(toks{1}{2}, '()')
    m_args.input = {};
elseif  toks{1}{2}(1)~='('
    m_args.input = strtrim(textscan(toks{1}{2}, '%s', 'Delimiter', ','));
    m_args.input = m_args.input{1};
else
    m_args.input = strtrim(textscan(toks{1}{2}(2:end-1), '%s', 'Delimiter', ','));
    m_args.input = m_args.input{1};
end

if ~isempty(m_args.input) && strcmp(m_args.input{end},'varargin')
    m_args.input = m_args.input(1:end-1);
end

%% Read in C declarations
[fid, msg] = fopen(hfile, 'r', 'n', 'US-ASCII');
if fid<0; error('m2c:OpenFileFiled', '%s', msg); end

hfile = fread(fid, inf, '*char')';
hfile = regexprep(hfile, '\r\n', '\n');
hfile = regexprep(hfile, '\n', ' ');
fclose(fid);

% Extract function definition from the header file
toks = regexp(hfile, ['\sextern\s+(unsigned\s+)?(\w+)\s+' altfunc '\s*\(([^)]*)\)'], 'tokens');
clear hfile;
cdecl.rettype = map_basetype(toks{1}{1}, toks{1}{2});
cdecl.args = toks{1}{3};

%% Read in type declarations
[fid, msg] = fopen(tyfile , 'r', 'n', 'US-ASCII');
if fid<0; error('m2c:OpenFileFiled', '%s', msg); end

% Read file into memory
typedecl = fread(fid, inf, '*char')';
typedecl = regexprep(typedecl, '\r\n', '\n');
fclose(fid);

%% Read HTML file for further processing
[fid, msg] = fopen(htmlfile, 'r', 'n', 'US-ASCII');
if fid<0; error('m2c:OpenFileFiled', '%s', msg); end

% Read file into memory
htmlfile = fread(fid, inf, '*char')';
htmlfile = regexprep(htmlfile, '<[^>]+>', ' ');
htmlfile = strrep(htmlfile, '&nbsp;', '');

%htmlfile = textscan(fid, '%s', 'CommentStyle', {'<','>'}, 'Delimiter', '(<>)');
fclose(fid);

%% Parse variable declarations
if ~isempty(cdecl.args)
    carglist = textscan(cdecl.args, '%s', 'delimiter', ',');
    carglist = carglist{1};
    if strcmp(carglist, 'void'); carglist = ''; end
else
    carglist = '';
end
[vars,SDindex, pruned_vars] = parse_var_decl(carglist, typedecl, htmlfile, '', m_args);

[vars, ret, nlhs, nrhs] = sort_arguments(vars, cdecl.rettype, m_args, typedecl, htmlfile);

end

function [vars, SDindex, pruned_vars] = parse_var_decl(carglist, typedecl, htmlfile, prefix, m_args)
% Parse declaration of variables

SDindex = [];

% Determine the number of input and output arguments
ncarg = length(carglist);

% Try to parse the cdecl
vars = repmat(struct('name', '', 'type', '', 'basetype', '', ...
    'structname', '', 'modifier', '', 'isconst', false, 'subfields', [], ...
    'isemx', false, 'size', [], 'vardim', [], 'sizefield', [], ...
    'iindex', [], 'oindex', []), ncarg,1);

for i=1:ncarg
    toks = regexp(carglist{i}, '^(const\s+)?((unsigned|signed)\s+)?(\w+)\s*(\*\s*)*(\w+)(\[\d*\])*$', 'tokens');
    
    % Set variable name
    assert(~isempty(toks{1}{5}));
    vars(i).name = toks{1}{5};
    
    % Set isconst
    if ~isempty(toks{1}{1})
        assert(isequal(deblank(toks{1}{1}),'const'));
        vars(i).isconst = true;
    end
    
    % Set type and base type
    assert(~isempty(toks{1}{3}));
    vars(i).type = map_basetype(strtrim(toks{1}{2}), toks{1}{3});
    
    if strncmp(vars(i).type, 'emxArray_', 9) && ...
            ~isempty(strfind(basetypes, [' ' vars(i).type(10:end) ' ']))
        vars(i).basetype = vars(i).type(10:end);
        vars(i).isemx = true;
        [vars(i).size, vars(i).vardim] = determine_type_size(htmlfile, [prefix vars(i).name], 0);
    elseif strncmp(vars(i).type, 'emxArray_', 9) % struct array
        % Determine basetype
        [~,b] = regexp(typedecl, ['\sstruct\s+' vars(i).type ...
            '\s*\{\s*(\w+)\s*\*data;\s'], 'match', 'tokens');
        if isempty(b)
            vars(i).isemx = true;
            [~,b] = regexp(vars(i).type, ['emxArray_(' basetypes('regexp') ')_'], ...
                'match', 'tokens', 'once');
            if ~isempty(b)
                vars(i).basetype = b{1};
            else
                % This is a static sized array.
                [~,b] = regexp(typedecl, ['\sstruct\s+' vars(i).type ...
                    '\s*\{\s*(\w+)\s*data\[\d+\];\s'], 'match', 'tokens', 'once');
                vars(i).basetype = b{1};
            end
            [vars(i).size, vars(i).vardim] = determine_type_size(htmlfile, [prefix vars(i).name], 0);
        else
            vars(i).isemx = true;
            vars(i).basetype = 'struct';
            vars(i).structname = b{1}{1};
            [vars(i).size, vars(i).vardim] = determine_type_size(htmlfile, [prefix vars(i).name], 0);
            
            [decl, sublist] = regexp(typedecl, ['\stypedef\s+struct\s+\w*\s*\{([^}][^\n]+\n)+\}\s+' ...
                vars(i).structname '\s*;'], 'match', 'tokens');
            
            if isempty(sublist)
                error('Cannot recognize datatype %s', vars(i).type);
            elseif ~isempty(strfind(sublist{1}{1}, '{'))
                error(['Nested structures is not supported for type %s. ' ...
                    'Its class definition generated by codegen is %s. ' ...
                    'You probably have a very large stack variable.'], ...
                    vars(i).type, decl{1});
            end
            sublist = textscan(sublist{1}{1}, '%s', 'delimiter', ';');
            
            % Parse type declaration
            [vars(i).subfields,SDindex] = parse_var_decl(sublist{1}, typedecl, htmlfile, [prefix vars(i).name '.']);
        end
    else
        if isempty(strfind(basetypes, [' ' vars(i).type ' ']))
            vars(i).basetype = 'struct';
            vars(i).structname = vars(i).type;
            
            if ~isempty(prefix) && ~isempty(regexp(prefix, 'SD.$', 'once')) && ncarg==1
                SDindex = 1;
            else
                [def, sublist0] = regexp(typedecl, ['\stypedef\s+struct(\s+\w+)?(\s*\{([^}][^\n]+\n)+\})?\s+' ...
                    vars(i).type '\s*;'], 'match', 'tokens');
                if ~isempty(sublist0) && isempty(sublist0{1}{2})
                    [~, sublist] = regexp(typedecl, ['\s+struct\s+' strtrim(sublist0{1}{1}) ...
                        '\s*\{([^}][^\n]+\n)+\}\s*;'], 'match', 'tokens');
                elseif ~isempty(sublist0) && ~isempty(sublist0{1}{2})
                    [~, sublist] = regexp(def{1}, '\{([^}][^\n]+\n)+\}', 'match', 'tokens');
                elseif isempty(sublist0)
                    error('Cannot recognize datatype %s', vars(i).type);
                end
                sublist = textscan(sublist{1}{1}, '%s', 'delimiter', ';');
                
                % Parse type declaration
                [vars(i).subfields,SDindex] = parse_var_decl(sublist{1}, typedecl, htmlfile, [prefix vars(i).name '.']);
                if ~isempty(SDindex); SDindex=i; end
            end
        else
            vars(i).basetype = vars(i).type;
        end
        
        vars(i).modifier = strtrim(toks{1}{4});
    end
    
    % Set modifier and size
    if ~isempty(toks{1}{6})
        toks = regexp(toks{1}{6}, '\[\s*(\d*)\s*\]\s*', 'tokens');
        if isempty(toks{1}{1})
            totallen = 0;
        else
            totallen = str2double(toks{1}{1});
        end
        
        [vars(i).size, vars(i).vardim] = determine_type_size(htmlfile, ...
            [prefix vars(i).name], totallen);
        vars(i).modifier = '*';
        
        if isempty(vars(i).size)
            if isequal(vars(i).name(1:end-4), vars(i-1).name(1:end-4)) && ...
                    isequal(vars(i).name(end-3:end), 'size') && ...
                    isequal(vars(i-1).name(end-3:end), 'data')
                % This is a size field of the previous argument
                vars(i-1).sizefield = i;
                vars(i).size = totallen;
                vars(i).vardim = false;
            else
                error('Could not determine the size of argument %s\n', vars(i).name);
            end
        end
    elseif ~isequal(vars(i).modifier,'*') && isempty(prefix) && ...
            ~isempty(strfind(basetypes, [' ' vars(i).type ' ']))
        vars(i).isconst = true;
    end
    
    % Set size for scalar
    if isempty(vars(i).size)
        [vars(i).size, vars(i).vardim] = determine_type_size(htmlfile, [prefix vars(i).name], 1);
    end
end

if nargout>2
    pruned_vars = repmat(struct('name', '', 'type', '', 'size', [], 'oindex', []), 1,0);
    
    if nargin>4
        npruned = 0;
        % Loop through all the output arguments and see check whether any was skipped
        for i=1:length(m_args.output)
            % check to see whether the variable is in vars
            name = m_args.output{i};
            found = 0;
            for j=1:length(vars)
                if isequal(vars(j).name, name)
                    found = j;
                    break;
                end
            end
            if ~found
                pruned_vars = [pruned_vars, ...
                    struct('name', name, 'type', '', 'size', [], 'oindex', i)]; %#ok<AGROW>
                npruned = npruned + 1;
                [pruned_vars(npruned).size, pruned_vars(npruned).vardim, ...
                    pruned_vars(npruned).type] = determine_type_size(htmlfile, name, 0);
                if length(pruned_vars(npruned).size)==1
                    pruned_vars(npruned).size = [0 1];
                end
            end
        end
    end
end
end

function [vars, ret, nlhs, nrhs] = sort_arguments(vars, rettype, m_args, typedecl, htmlfile)
% Determine the order of the arguments in MATLAB

nlhs = length(m_args.output);
nrhs = length(m_args.input);

for i=1:nrhs
    found = false;
    % Parse input arguments
    for k=i:length(vars)
        if isequal(vars(k).name,m_args.input{i})
            vars(k).iindex = i;
            found = true;
            break;
        end
    end
    
    if ~found
        for k=i:length(vars)
            if isempty(vars(k).iindex) && ~isempty(regexp(vars(k).name,['^\w+_' m_args.input{i} '$'],'once'))
                vars(k).iindex = i;
                found = true;
                break;
            end
        end
    end
    
    if ~found
        if i==nrhs && isequal(m_args.input{i}, 'varargin')
            nrhs = nrhs-1;
        else
            fprintf(2, ['Error in processing input arguments %s. '...
                'The generated MATLAB wrapper function may be incorrect.'], m_args.input{i});
        end
    end
end

ret = [];
for i=1:nlhs
    % Parse output arguments
    for k=1:length(vars)
        if isequal(vars(k).name,m_args.output{i}) || ...
                ~isempty(vars(k).sizefield) && isequal(vars(k).name(1:end-5),m_args.output{i})
            vars(k).oindex = i;
            break;
        end
    end
    
    if ~isempty(vars) && ~isempty(vars(k).oindex)
        continue;
    elseif (i==nlhs && isequal(m_args.output{i}, 'varargout'))
        nlhs = nlhs - 1;
    elseif isequal(rettype, 'void')
        % Parse output arguments
        len = length(m_args.output{i});
        for k=1:length(vars)
            if ~isempty(strfind(vars(k).name, m_args.output{i})) && ...
                    isempty(vars(k).oindex) && ...
                    isequal(vars(k).name(end-len+1:end), m_args.output{i})
                vars(k).oindex = i;
                break;
            end
        end
    else
        assert(isempty(ret) && ~isequal(rettype, 'void'), 'Incorrect return variable');
        ret = struct('name', m_args.output{i}, 'type', rettype, 'basetype', rettype, ...
            'structname', '', 'modifier', '', 'isconst', false, 'subfields', [], ...
            'isemx', false, 'size', [], 'vardim', [], 'sizefield', [], ...
            'iindex', [], 'oindex', i);
        % Check return type
        if isempty(strfind(basetypes, [' ' rettype ' ']))
            ret.basetype = 'struct';
            [~, sublist] = regexp(typedecl, ['\stypedef\s+struct\s+\w*\s*\{([^}]+)\}\s+' ...
                ret.type '\s*;'], 'match', 'tokens');
            if isempty(sublist)
                error('Cannot recognize datatype %s', rettype);
            end
            sublist = textscan(sublist{1}{1}, '%s', 'delimiter', ';');
            
            % Parse type declaration
            ret.subfields = parse_var_decl(sublist{1}, typedecl, htmlfile, [ret.name '.']);
        end
    end
end

end

function [sz,vardim,basetype] = determine_type_size(htmlfile, varname, totalsize)
% Parse the HTML file to determine the size of a variable

% Determine the size of the variable
if isempty(strfind(varname,'.'))
    type = 'I\/O|Input|Output';
else
    type = 'Field';
end

toks = regexp(htmlfile, ['\s+' varname '\s+(?:&gt;\s+\d+)?\s+(?:' type ')\s+ ([\dx\s:?\*]+)(\w+|-)'], 'tokens');
if isempty(toks)
    if strncmp(varname, 'varargin', 8)
        error('m2c:vararginUnsupported', ...
            ['M2C cannot determine input data type for varargin for top-level functions. ' ...
            'Please write a wrapper function to name ' ...
            'the optional argument "varargin" expliclty.']);
    elseif ~isempty(regexp(varname, '[a-z]+_data', 'once'))
        toks = regexp(htmlfile, ['\s+' varname(1:end-5) '\s+(?:&gt;\s+\d+)?\s+(?:' type ')\s+ ([\dx\s:?]+)(\w+|-)'], 'tokens');
    elseif ~isempty(regexp(varname, '[a-z]_', 'once'))
        toks = regexp(htmlfile, ['\s+' varname(3:end) '\s+(?:&gt;\s+\d+)?\s+(?:' type ')\s+ ([\dx\s:?]+)(\w+|-)'], 'tokens');
    else
        sz = [totalsize; 1]; return;
    end
end

if isempty(toks)
    sz = [];
    vardim = [];
    basetype = '';
else
    szlist = textscan(toks{1}{1}, '%s', 'delimiter', 'x*');
    sz = zeros(length(szlist{1}),1);
    vardim = false(length(szlist{1}),1);
    
    for j=1:length(sz)
        if szlist{1}{j}(1) == ':'
            vardim(j) = true;
            if ~isempty(regexp(szlist{1}{j}, ':\s*\d+', 'once'))
                sz(j) = str2double(szlist{1}{j}(2:end));
            else
                sz(j) = inf;
            end
        else
            vardim(j) = false;
            sz(j) = str2double(szlist{1}{j});
        end
    end
    
    basetype = toks{1}{2};
    
    % Trim high-dimensional arrays
    for j=length(sz):-1:1
        if sz(j) ~= 1 || vardim(j)
            sz(j+1:end) = [];
            vardim(j+1:end) = [];
            break;
        end
    end
    
    assert(totalsize==0 || totalsize == prod(sz), 'Size handling error.');
end

end

function str = basetypes(~)
% Obtain list of base datatypes
if nargin==0
    str = [' boolean_T char_T real_T real_T real64_T real32_T ' ...
        'int32_T uint32_T int8_T uint8_T int16_T uint16_T int64_T uint64_T '];
else
    str = ['(boolean_T|char_T|real_T|real64_T|real32_T|' ...
        'int32_T|uint32_T|int8_T|uint8_T|int16_T|uint16_T|int64_T|uint64_T)'];
end
end

function str = map_basetype(sign, type)

switch type
    case 'char'
        if isempty(sign)
            str = 'char_T';
        elseif isequal(sign, 'signed')
            str = 'int8_T';
        elseif isequal(sign, 'unsigned')
            str = 'uint8_T';
        end
    case 'short'
        if isempty(sign) || isequal(sign, 'signed')
            str = 'int16_T';
        elseif isequal(sign, 'unsigned')
            str = 'uint16_T';
        end
    case 'int'
        if isempty(sign) || isequal(sign, 'signed')
            str = 'int32_T';
        elseif isequal(sign, 'unsigned')
            str = 'uint32_T';
        end
    case 'long'
        if isempty(sign) || isequal(sign, 'signed')
            str = 'int64_T';
        elseif isequal(sign, 'unsigned')
            str = 'uint64_T';
        end
    case 'float'
        str = 'real32_T';
    case 'double'
        str = 'real64_T';
    otherwise
        str = type;
end
end

function htmlfile = get_htmlfile(mpath, funcname, altfunc)
% Locate HTML file for the given function name and alternative name.
htmlfile = [mpath 'codegen/lib/' funcname '/html/' altfunc '1_watch.html'];
if exist(htmlfile,'file')
    return;
end

listing = dir([mpath 'codegen/lib/' funcname '/html/' altfunc '*_watch.html']);
htmlfile = '';
for i=length(listing):-1:1
    if ~isempty(regexp(listing(i).name, [altfunc '\d+_watch.html'],'once'))
        htmlfile = [mpath 'codegen/lib/' funcname '/html/' listing(i).name];
        return;
    end
end
end