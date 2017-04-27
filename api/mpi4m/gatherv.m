function [bglobal, info] = gatherv(blocal, m, n, comm, root_in) %#codegen
%GATHERV  Gathers subarrays from all tasks to the root process
%   [bglobal, info] = gatherv(blocal, m, n, comm)
% This function works for vectors and matrices. For a matrix, it can be
% either partitioned columnwise (size(blocal,1)==m) or
% rowwise (if size(blocal,2)==n), but the former is more efficient.
% If m is empty, it is set to size(blocal,1). Similarly, if n is empty,
% it is set to size(blocal,2).
%
% See also allgatherv, scatterv

if nargin>3 && isstruct(comm)
    coder.inline('never');
end

if nargin<3 || isempty(comm) || mpi_Comm_size(comm)==1
    bglobal = coder.nullcopy(zeros(m, n, class(blocal)));
    bglobal(:) = blocal(:);
    info = int32(0);
    return;
end

if nargin>4; root = int32(root_in);
else root = int32(0); end

len = int32(numel(blocal));
if isempty(m); m=int32(size(blocal,1)); end
if isempty(n); n=int32(size(blocal,2)); end

if m==1 || n==1
    % Gather a vector
    if mpi_Comm_rank(comm)==0
        bglobal = coder.nullcopy(zeros(m, n, class(blocal)));
        [counts, disps] = count_bufsizes(int32(numel(bglobal)), comm);
        assert(counts(1)==len);
        
        bglobal = m2c_unalias(bglobal);
        info = mpi_Gatherv(m2c_opaque_ptr_const(blocal), len, MPI_Datatype(blocal), ...
            m2c_opaque_ptr(bglobal), counts, disps, MPI_Datatype(bglobal), root, MPI_Comm(comm));
    else
        bglobal = zeros(0, 1, class(blocal));
        info = mpi_Gatherv(m2c_opaque_ptr_const(blocal), len, MPI_Datatype(blocal), ...
            m2c_opaque_ptr(bglobal), int32(0), int32(0), MPI_DATATYPE_NULL, root, MPI_Comm(comm));
    end
elseif size(blocal,1)==m
    % Gather a matrix partitioned in columns
    if mpi_Comm_rank(comm)==0
        bglobal = coder.nullcopy(zeros(m, n, class(blocal)));
        
        [counts, disps] = count_bufsizes(n, comm, m);
        assert(counts(1)==len);
        
        bglobal = m2c_unalias(bglobal);
        info = mpi_Gatherv(m2c_opaque_ptr_const(blocal), len, MPI_Datatype(blocal), ...
            m2c_opaque_ptr(bglobal), counts, disps, MPI_Datatype(bglobal), root, MPI_Comm(comm));
    else
        bglobal = zeros(0, 1, class(blocal));
        info = mpi_Gatherv(m2c_opaque_ptr_const(blocal), len, MPI_Datatype(blocal), ...
            m2c_opaque_ptr(bglobal), int32(0), int32(0), MPI_DATATYPE_NULL, root, MPI_Comm(comm));
    end
else
    % Gather a matrix partitioned in rows
    if size(blocal,2)~=n
        m2c_error('gatherv:partition', 'Matrix is partitioned incorrectly');
    end
    blt = blocal';
    
    if mpi_Comm_rank(comm)==0
        bgt = coder.nullcopy(zeros(n, m));
        [counts, disps] = count_bufsizes(m, comm, n);
        assert(counts(1)==len);

        [bgt,blt] = m2c_unalias(bgt,blt);
        info = mpi_Gatherv(m2c_opaque_ptr_const(blt), len, MPI_Datatype(blocal), ...
            m2c_opaque_ptr(bgt), counts, disps, MPI_Datatype(bgt), root, MPI_Comm(comm));
        
        % Transpose the matrix
        bglobal = bgt';
    else
        blt = m2c_unalias(blt);
        bglobal = zeros(0, 1, class(blocal));
        info = mpi_Gatherv(m2c_opaque_ptr_const(blt), len, MPI_Datatype(blocal), ...
            m2c_opaque_ptr(bglobal), int32(0), int32(0), MPI_DATATYPE_NULL, root, MPI_Comm(comm));
    end
end

function test  %#ok<DEFNU>
%!shared comm, svar
%!test
%! comm = MPI_COMM_WORLD;
%! svar = rand(10,10);

%!test
%! [rvar,info] = gatherv(svar, 10, 10, comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));

%!test
%! [rvar,info] = gatherv(svar, 100, 1, comm);
%! assert(info==0);
%! assert(isequal(svar(:), rvar(:)));
