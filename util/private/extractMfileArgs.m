function m_args = extractMfileArgs(mfile)

[fid, msg] = fopen(mfile , 'r', 'n', 'US-ASCII');
if fid<0; error('m2c:OpenFileFiled', '%s', msg); end

mfile_str = fread(fid, inf, '*char')';
mfile_str = regexprep(mfile_str, '\r\n', '\n'); % Change Windows format to UNIX format.
fclose(fid);

mfile_str = regexprep(mfile_str, '%[^\n]*\n', '\n');
mfile_str = regexprep(mfile_str, '\.\.\.\s+', '');

toks = regexp(mfile_str, '^\s*function\s*(\[[\w\s,]+\]|\s+\w+)?\s*=?\s*\w+\s*(\([\w\s,]*\))?\s*\n', 'tokens');
assert(~isempty(toks), 'Cannot parse MATLAB file.');
clear mfile_str;

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