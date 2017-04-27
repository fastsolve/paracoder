function build_examples(varargin)

lines = grep_pattern('*.m', '\n%#codegen -args');
files = regexp(lines, '(\w+.m):', 'tokens');

for j=1:length(files)
    file = files{j}{1};
    compile('-noinf', file, varargin{:});
end
end
