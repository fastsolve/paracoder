function [counts, disps] = count_bufsizes(m, comm, nrows) %#codegen
%count_bufsizes   Obtain the counts and disps for gather or scatter.
%    [counts, disps] = count_bufsizes(m, comm, nrows)
%
% count is a column vector of size comm_size, containing the number
%       of items for each process.
% disps is a column vector of size comm_size+1, containing the offset
%       of indices for each process. The last entry is equal to m.

nprocs = mpi_Comm_size(comm);
chunk = int32(fix(double(m)/double(nprocs)));
remainder = m-nprocs*chunk;

if nargin>=3; chunk = chunk * nrows;
else nrows = int32(1); end

counts = coder.nullcopy(zeros(nprocs, 1, 'int32'));
disps = coder.nullcopy(zeros(nprocs+1, 1, 'int32'));

% Process first processes
disps(1) = 0;
for i=1:remainder
    counts(i) = chunk+nrows;
    disps(i+1) = disps(i) + counts(i);
end

for i=remainder+1:nprocs
    counts(i) = chunk;
    disps(i+1) = disps(i) + chunk;
end
assert(disps(nprocs+1)==m*nrows);
