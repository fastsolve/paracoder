function [istart, iend, rank] = m2c_local_chunk(m, comm, nprocs)
% Determines starting and ending indices of local chunk on a MPI process.
%
% [istart, iend, rank] = m2c_local_chunk(m) obtains the local chunk
% on the current MPI process in MPI_COMM_WORLD, where m is the total
% number of items.
%
% [istart, iend, rank] = m2c_local_chunk(m, comm) uses
% the given communicator, instead of MPI_COMM_WORLD.
%
% [istart, iend, rank] = m2c_local_chunk(m, comm, nprocs) assumes that
% there are n processes, instead of calling mpi_Comm_size to determine it.

coder.inline('always');

if nargin<2; comm = MPI_COMM_WORLD; end

if nargin<3; nprocs = mpi_Comm_size(comm); end

if nprocs==1
    istart = int32(1); iend = int32(m); rank = int32(0);
else
    rank =  mpi_Comm_rank(comm);
    
    chunk = m2c_intdiv(m, nprocs);
    remainder = m-nprocs*chunk;
    
    istart = rank*chunk+min(remainder,rank)+1;
    iend = istart+chunk+int32(rank<remainder)-1;
end
