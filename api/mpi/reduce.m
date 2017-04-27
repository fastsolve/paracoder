function [bglobal, info] = reduce(blocal, sz_in, op, comm, root) %#codegen
%REDUCE Perform a reduce operation to a root process.
%   [bglobal, info] = reduce(blocal, sz, op, comm [, root])
% Reduce to the root process for sz elements in blocal. If sz is empty, 
% it will be set to numel(blocal). The default root is 0.
%
%See also allreduce, bcast

if nargin>1 && isstruct(comm)
    coder.inline('never');
end

if nargin<=1 || isempty(comm) || mpi_Comm_size(comm)==1
    bglobal = blocal; info=int32(0); return;
end

if isempty(sz_in); sz=int32(numel(blocal)); 
else sz = int32(sz_in); assert(sz>=0 && sz<=numel(blocal)); end

if isempty(op); op = MPI_SUM; end

if nargin<5; root=int32(0); end

if mpi_Comm_rank(comm)==root
    bglobal = coder.nullcopy(zeros(size(blocal), class(blocal)));
else
    bglobal = zeros(0,1,class(blocal));
end

bglobal = m2c_unalias(bglobal); 
info = mpi_Reduce(m2c_opaque_ptr_const(blocal), m2c_opaque_ptr(bglobal), ...
    int32(sz), MPI_Datatype(blocal), op, int32(root), MPI_Comm(comm));

function test  %#ok<DEFNU>
%!test
%! comm = MPI_COMM_WORLD;
%! svar = rand(10,10);

%! [rvar, info] = reduce(svar, [], MPI_SUM, comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));
