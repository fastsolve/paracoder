function [size,info] = comm_remote_size(comm ) %#codegen
%comm_remote_size Determines the size of the remote group associated with an inter-communictor
%   [size,info] = comm_remote_size(comm )
%
% See also comm_size, comm_rank

coder.inline('always');

[size,info] = mpi_Comm_remte_size(MPI_Comm(comm));
