function [size,info] = comm_size(comm ) %#codegen
%comm_size Determines size of group associated with a communicator
%   [size,info] = comm_size([comm] )
%
% By default, comm_rank is MPI_COMM_WORLD
%
% See also comm_rank

coder.inline('always');

if nargin
    [size,info] = mpi_Comm_size(MPI_Comm(comm));
else
    [size,info] = mpi_Comm_size(MPI_COMM_WORLD);
end
