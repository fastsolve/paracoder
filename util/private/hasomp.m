function b = hasomp( file)

fid = fopen(file, 'r', 'n', 'US-ASCII');
% Read file into memory
cfile = fread(fid, 1000, '*char')';
fclose(fid);

b = ~isempty(regexp( cfile, '\n\s*#include\s*"omp.h"', 'match'));
end
