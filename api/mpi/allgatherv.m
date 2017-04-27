function [bglobal,info] = allgatherv(blocal, m, n, comm) %#codegen
%ALLGATHERV  Gathers subarrays from all tasks and deliver it to all
%   bglobal = allgatherv(blocal, m, n, comm)
% This function works for vectors and matrices. For a matrix, it can be
% either partitioned columnwise (size(blocal,1)==m) or
% rowwise (if size(blocal,2)==n), but the former is more efficient.
% If m is empty, it is set to size(blocal,1). Similarly, if n is empty,
% it is set to size(blocal,2).
%
% See also gatherv, scatterv

if nargin>3 && isstruct(comm)
    coder.inline('never');
end

if nargin<3 || isempty(comm) || mpi_Comm_size(comm)==1
    bglobal = coder.nullcopy(zeros(m, n, class(blocal)));
    bglobal(:) = blocal(:);
    info = int32(0);
    return;
end

len = int32(numel(blocal));
if isempty(m); m=int32(size(blocal,1)); end
if isempty(n); n=int32(size(blocal,2)); end

if m==1 || n==1
    % Gather a vector
    bglobal = coder.nullcopy(zeros(m, n, class(blocal)));
    [counts, disps] = count_bufsizes(int32(numel(bglobal)), comm);
    assert(len==counts(mpi_Comm_rank(comm)+1));
    
    bglobal = m2c_unalias(bglobal);
    info = mpi_Allgatherv(m2c_opaque_ptr_const(blocal), len, MPI_Datatype(blocal), ...
        m2c_opaque_ptr(bglobal), counts, disps, MPI_Datatype(blocal), MPI_Comm(comm));
elseif size(blocal,1)==m
    % Gather a matrix partitioned in columns
    bglobal = coder.nullcopy(zeros(m, n, class(blocal)));
    [counts, disps] = count_bufsizes(n, comm, m);
    assert(len==counts(mpi_Comm_rank(comm)+1));
    
    bglobal = m2c_unalias(bglobal);
    info = mpi_Allgatherv(m2c_opaque_ptr_const(blocal), len, MPI_Datatype(blocal), ...
        m2c_opaque_ptr(bglobal), counts, disps, MPI_Datatype(blocal), MPI_Comm(comm));
else
    % Gather a matrix partitioned in rows
    if size(blocal,2)~=n
        m2c_error('allgatherv:partition', 'Matrix is partitioned incorrectly');
    end
    
    blt = blocal'; bgt = coder.nullcopy(zeros(n, m));
    [counts, disps] = count_bufsizes(m, comm, n);
    assert(len==counts(mpi_Comm_rank(comm)+1));
    [blt,bgt] = m2c_unalias(blt,bgt);
    info = mpi_Allgatherv(m2c_opaque_ptr_const(blt), len, MPI_Datatype(blocal), ...
        m2c_opaque_ptr(bgt), counts, disps, MPI_Datatype(blocal), MPI_Comm(comm));
    
    % Transform the matrix
    bglobal = bgt';
end

function test  %#ok<DEFNU>
%!shared comm, svar
%!test
%! comm = MPI_COMM_WORLD;
%! svar = rand(10,10);

%!test
%! [rvar,info] = allgatherv(svar, 10, 10, comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));

%!test
%! [rvar,info] = allgatherv(svar, 100, 1, comm);
%! assert(info==0);
%! assert(isequal(svar(:), rvar(:)));
