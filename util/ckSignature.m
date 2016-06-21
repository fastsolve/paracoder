function [OK, str] = ckSignature(m2c_opts, stage, file)
% Check signature of the code generation options.

OK = nargin<3 || nargin==3 && exist(file, 'file');

if nargin==3 && OK || nargout==2
    str = createSignature(m2c_opts, stage);
end

if nargin==3 && OK
    [str2,isold] = extractSignature(file);
    % For compatability with older version, treat empty signature as OK.
    if isequal(stage, 'codegen')
        OK = isempty(str2) || isequal(str, str2);
    else
        OK = isequal(str, str2) && ~isold;
    end
end

end

function str = createSignature(m2c_opts, stage)
str = '';

switch stage
    case 'codegen'
        fields = {'codegenArgs', 'codegenConfig', 'api', 'debugInfo', ...
            'addpath', 'chkMem', 'enableInline', 'enableInf', 'presVars', ...
            'withOMP', 'withNvcc', 'dynMem', 'timing', 'withLapack', 'typeRep', 'remEmx'};
    case 'mex'
        fields = {'debugInfo', 'verbose', 'quiet', 'optimLevel', ...
            'cc', 'cppflags', 'cflags', 'ldflags', 'libs', 'mexflags', 'mexFile', ...
            'withOMP', 'ompLibs', 'mpiLibs', 'cudaDir', 'withNvcc', ...
            'lapackLibs', 'blasLibs', 'petscDir', 'mklDir'};
    case 'exe'
        fields = {'debugInfo', 'verbose', 'quiet', 'optimLevel', ...
            'cc', 'cppflags', 'cflags', 'ldflags', 'libs', 'exeFile', ...
            'withOMP', 'ompLibs', 'mpiLibs', 'cudaDir', 'withNvcc', ...
            'lapackLibs', 'blasLibs', 'petscDir', 'mklDir', ...
            'ddd', 'valgrind', 'gprof', 'gcov'};
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
        if ~isempty(m2c_opts.(fields{i}))
            str = [str ' ' fields{i} '={''' ...
                strtrim(sprintf('%s ', m2c_opts.(fields{i}){:})), '''}'];
        end
    else
        error('Unsupported argument data type');
    end
end

str = ['%#m2c options:' getMD5(str)];

end


function [str, isold] = extractSignature(fame)

file = readFile(fame);

line = regexp(file, '%#m2c options:[^\n]*\n', 'match');

if ~isempty(line)
    str = line{1}(1:end-1);
else
    str = '';
end

isold = ~isempty(strfind(file, 'opaque_obj'')'));

end

function md5hash = getMD5(str)
% Compute MD5 checksum

if exist('octave_config_info', 'builtin')
    md5hash = md5sum(str, true);
else
    md = java.security.MessageDigest.getInstance('MD5');
    md5hash = sprintf('%.2x', typecast(md.digest(uint8(str)), 'uint8'));
end

end