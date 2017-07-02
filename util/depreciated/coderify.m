function coderify(varargin)
% Make M-file compatible with MATLAB coder. 
%    coderify(file1, file2, ...)
%    coderify(dir)
% This function adds %#codegen and coder.extrisinc for fprintf, warning, and disp.
% If the M file is modified, the original file is backed-up to a file 
% with ".bak" suffix. It does not check whether the function is truly 
% compatible with MATLAB Coder. It is advisable to run 
% "Code Analyzer Report" for basic screening.

if nargin==1
    if exist(varargin{1}, 'dir')
        fnames=fuf([varargin{1} '/*.m'],'detail');
    else
        fnames=varargin;
    end
else
    fnames=varargin;
end

for nf = 1:length(fnames)
    filename = fnames{ nf};
    str = read_file(filename);
    
    if isempty(regexp(str, '(^|\n)[\s]*function\s', 'once'))
        continue;
    end
    
    if str(end)~=char(10); str=[str char(10)]; end %#ok<AGROW>
    
    str0 = str;
    str = regexprep(str, '([=:]\s*)size\s*\((\s*\w+\s*,\s*\w+\s*)\)', '$1int32(size($2))');
    changed = length(str)>length(str0);
    
    extfuncs = {'fprintf', 'warning', 'disp'};
    addfunc = '';    
    
    for i=1:length(extfuncs)
        if ~isempty(regexp(str, ['(^|\n)[^%\n]*[^a-zA-Z_0-9%]' extfuncs{i} '[ \t]*\('], 'once'))&&...
                isempty(regexp(str, ['(^|\n)[^%\n]*coder\s*\.extrinsic\s*\([^)]*''' extfuncs{i} ''''],'once'))
            if isempty(addfunc)
                addfunc = [ '''', extfuncs{i}, ''''];
            else
                addfunc = sprintf('%s, ''%s''', addfunc, extfuncs{i});
            end
        end
    end
    
    addcg = isempty(regexp(str, '(^|\n)[^%]*%#codegen[\W]', 'once'));
    if addcg || ~isempty(addfunc)
        str0 = str;
        str = add_derivatives(str, addcg, addfunc);
        
        if length(str)>length(str0); changed = true; end
    end
    
    if changed 
        % Back up original file and write out the modified file.
        copyfile(filename, [filename '.bak']);
        write_file(filename, str);
    end
end

end

function str = read_file(filename)
fid = fopen(filename, 'rt');
if fid>=0
    str = fread(fid,'*char')';
    fclose(fid);
else
    warning('CODERIFY:CannotOpenFile', 'Could not open file %s\n', filename);
    str = '';
end
end

function str = add_derivatives(str, addcg, funcs)
    
lines=regexp(str, '[^\n]*\n', 'match');
for i=1:length(lines)
    if ~isempty(regexp(lines{i}, '^[\s]*function\s', 'once'))
        j = i;
        s = regexprep(lines{i}, '^([^%)]+)\)(.*$)', '$1) %#codegen $2', 'once');
        succeeded = length(s)>length(lines{j});

        while ~succeeded && ~isempty(regexp(lines{j}, '\.\.\.\s*$', 'once')) && j<length(lines)
            j = j + 1;
            s = regexprep(lines{j}, '^([^%)]+)\)(.*$)', '$1) %#codegen $2', 'once');
            
            succeeded = length(s)>length(lines{j});
        end
            
        if ~succeeded
            s = regexprep(lines{j}, '^([^%]*)%(.*)$', '$1%#codegen $2', 'once');
            if length(s)==length(lines{j})
                s = [lines{j}(1:end-1) ' %#codegen' lines{j}(end)];
            end
        end
        
        if addcg; lines{j} = s; end
        
        if ~isempty(funcs)
            % search for first line that is not blank
            succeeded = false;
            for k=j+1:length(lines)
                if ~isempty(regexp(lines{k}, '^[\s]*[^%\s].*$','once'))
                    lines{k} = sprintf('coder.extrinsic(%s);\n\n%s', funcs, lines{k});
                    succeeded = true;
                    break;
                end
            end
            
            if ~succeeded
                lines{end} = [lines{end} 'coder.extrinsic(' funcs ');' char(10)];
            end
        end
        
        break;
    end
end

str = cell2mat(lines);

end

function write_file(filename, str)
fid = fopen(filename, 'wt');
if fid>=0
    fwrite(fid, uint8(str'));
    fclose(fid);
end
end

