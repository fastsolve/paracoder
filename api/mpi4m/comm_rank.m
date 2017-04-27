function [rank,info] = comm_rank(comm ) %#codegen
%COMM_RANK Determines the rank of the calling process in the communicator
%   [rank,info] = comm_rank([comm])
%
% By default, comm_rank is MPI_COMM_WORLD
%
% See also comm_size

coder.inline('always');

if nargin
    [rank,info] = mpi_Comm_rank(MPI_Comm(comm));
else
    [rank,info] = mpi_Comm_rank(MPI_COMM_WORLD);
end
