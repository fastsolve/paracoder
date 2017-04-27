function info = barrier(comm ) %#codegen
%barrier Blocks until all processes in the communicator have reached this routine.
%   info = barrier(comm )

coder.inline('always');

if ~isempty(comm) && mpi_Comm_size(comm)>1
    info = mpi_Barrier(MPI_Comm(comm));
else
    info = int32(0);
end
