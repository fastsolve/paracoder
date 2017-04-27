function [blocal, info] = scatterv(bglobal, ml, nl, comm, root_in) %#codegen
%SCATTERV  Scatters a vector or array to all processes in a communicator.
%   blocal = scatterv(bglobal, ml, nl, comm, [root])
% This function works for vectors and matrices. For a matrix, it can be
% either partitioned columnwise (if size(bglobal,1)==ml) or
% rowwise (if size(bglobal,2)==nw), but the former is more efficient.
%
% If ml is empty, it is set to size(bglobal,1). Similarly, if nl is empty,
% it is set to size(bglobal,2).
%
% See also gatherv, allgatherv

if nargin>3 && isstruct(comm)
    coder.inline('never');
end

if isempty(ml); ml=int32(size(bglobal,1)); end
if isempty(nl); nl=int32(size(bglobal,2)); end

blocal = coder.nullcopy(zeros(ml, nl, class(bglobal)));

if nargin<3 || isempty(comm) || mpi_Comm_size(comm)==1
    blocal(:) = bglobal(:); info = int32(0);
    return;
end

if nargin>4; root = int32(root_in);
else root = int32(0); end

len = int32(numel(blocal));

m = max(int32(size(bglobal,1)), ml);
n = max(int32(size(bglobal,2)), nl);

if m==1 || n==1
    % Scatter a vector
    if mpi_Comm_rank(comm)==0
        [counts, disps] = count_bufsizes(int32(numel(bglobal)), comm);
        assert(counts(1) == len);
        
        blocal = m2c_unalias(blocal);
        info = mpi_Scatterv(m2c_opaque_ptr_const(bglobal), counts, disps, MPI_Datatype(bglobal), ...
            m2c_opaque_ptr(blocal), len, MPI_Datatype(blocal), root, MPI_Comm(comm));
    else
        info = mpi_Scatterv(m2c_opaque_ptr_const(bglobal), int32(0), int32(0), MPI_DATATYPE_NULL, ...
            m2c_opaque_ptr(blocal), len, MPI_Datatype(blocal), root, MPI_Comm(comm));
    end
elseif m==ml
    % Scatter a matrix partitioned in columns
    if mpi_Comm_rank(comm)==0
        [counts, disps] = count_bufsizes(n, comm, m);
        assert(counts(1) == len);
        
        blocal = m2c_unalias(blocal);
        info = mpi_Scatterv(m2c_opaque_ptr_const(bglobal), counts, disps, MPI_Datatype(bglobal), ...
            m2c_opaque_ptr(blocal), len, MPI_Datatype(blocal), root, MPI_Comm(comm));
    else
        blocal = m2c_unalias(blocal);
        info = mpi_Scatterv(m2c_opaque_ptr_const(bglobal), int32(0), int32(0), MPI_DATATYPE_NULL, ...
            m2c_opaque_ptr(blocal), len, MPI_Datatype(blocal), root, MPI_Comm(comm));
    end
else
    % Gather a matrix partitioned in rows
    if nl~=n
        m2c_error('scatterv:partition', 'Matrix is partitioned incorrectly');
    end
    
    blt = coder.nullcopy(zeros(nl, ml, class(bglobal)));
    
    if mpi_Comm_rank(comm)==0
        bgt = bglobal';
        [counts, disps] = count_bufsizes(m, comm, n);
        assert(counts(1) == len);
        
        blt = m2c_unalias(blt);
        info = mpi_Scatterv(m2c_opaque_ptr_const(bgt), counts, disps, MPI_Datatype(bglobal), ...
            m2c_opaque_ptr(blt), len, MPI_Datatype(blt), root, MPI_Comm(comm));
    else
        blt = m2c_unalias(blt);
        info = mpi_Scatterv(m2c_opaque_ptr_const(bglobal), int32(0), int32(0), MPI_DATATYPE_NULL, ...
            m2c_opaque_ptr(blt), len, MPI_Datatype(blt), root, MPI_Comm(comm));
    end
    blocal = blt';
end


function test  %#ok<DEFNU>
%!shared comm, svar
%!test
%! comm = MPI_COMM_WORLD;
%! svar = rand(10,10);

%!test
%! [rvar,info] = scatterv(svar, 10, 10, comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));

%!test
%! [rvar,info] = scatterv(svar, 100, 1, comm);
%! assert(info==0);
%! assert(isequal(svar(:), rvar(:)));
