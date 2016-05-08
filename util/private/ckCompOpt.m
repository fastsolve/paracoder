function [OK, str] = ckCompOpt(m2c_opts, stage, file)

OK = nargin<3 || nargin==3 && exist(file, 'file');

if nargin==3 && OK || nargout==2
    str = createSignature(m2c_opts, stage);
end
if nargin==3 && OK
    str2 = extractSignature(file);
    OK = isequal(str, str2);
end

end

function str = createSignature(m2c_opts, stage)
str = '';

switch stage
    case 'codegen'
        fields = {'codegenArgs', 'api', 'debugInfo', 'enableInline', 'enableInf', ...
            'timing', 'lapackLibs', 'mpiLibs', 'ompLibs', 'accLibs'};
    case 'mex'
        fields = {'debugInfo', 'optLevel', 'lapackLibs', ...
            'cc', 'cflags', 'libs', 'mexflags', ...
            'mpiLibs', 'ompLibs', 'accLibs', 'petscLibs'};
    case 'exe'
        fields = {'debugInfo', 'optLevel', 'lapackLibs', ...
            'cc', 'cflags', 'libs', ...
            'mpiLibs', 'ompLibs', 'accLibs', 'petscLibs', ...
            'ddd', 'valgrind', 'gprof', 'gcov', 'efence'};
    otherwise
        error('m2c:checking', 'Unknown stage %s\n', stage);
end

for i=1:length(fields)
    if isnumeric(m2c_opts.(fields{i})) || islogical(m2c_opts.(fields{i}))
        if m2c_opts.(fields{i})
            str = [str ' ' fields{i} '=' num2str(m2c_opts.(fields{i}))]; %#ok<*AGROW>
        end
    elseif ischar(m2c_opts.(fields{i}))
        if ~isempty(m2c_opts.(fields{i}))
            str = [str ' ' fields{i} '=' m2c_opts.(fields{i})];
        end
    elseif iscell(m2c_opts.(fields{i}))
        if ~isempty(m2c_opts.(fields{i})) && ~isempty(m2c_opts.(fields{i}){1})
            str = [str ' ' fields{i} '={' ...
                strtrim(sprintf('%s ', m2c_opts.(fields{i}){:})), '}'];
        elseif ~isempty(m2c_opts.(fields{i})) && isempty(m2c_opts.(fields{i}){1})
            str = [str ' ' fields{i} '={''''}'];
        end
    else
        error('Unsupported argument data type');
    end
end

str = ['%#m2c options:' str];

end


function str = extractSignature(fame)

file = readFile(fame);

line = regexp(file, '%#m2c options:([^\n])*\n', 'match');

if ~isempty(line)
    str = line{1}(1:end-1);
else
    str = '';
end

end
