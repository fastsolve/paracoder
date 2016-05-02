function b = haslapack( file)

fid = fopen(file, 'r', 'n', 'US-ASCII');
% Read file into memory
cfile = fread(fid, inf, '*char')';
fclose(fid);

b = ~isempty(regexp( cfile, '\n\s*#include\s*"lapacke.h"', 'match'));
end
