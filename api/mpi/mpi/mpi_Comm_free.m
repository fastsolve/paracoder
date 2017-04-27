function [comm, info, toplevel] = mpi_Comm_free(comm)
%mpi_Comm_free  Marks the communicator object for deallocation
%
%  [comm, info] = mpi_Comm_free (comm)
%
%  comm   (INOUT) Communicator to be destroyed. It is marked for deallocation,
%      and is set to MPI_COMM_NULL at output.
%
%  info (int) return code
%
%  SEE ALSO: mpi_Comm_create
%
% C interface:
%   int MPI_Comm_free(MPI_Comm *comm)
% http://mpi.deino.net/mpi_functions/MPI_Comm_free.html
% http://www.mpi-forum.org/docs/mpi-11-html/node103.html

%#codegen -args {MPI_Comm}


info = int32(0); %#ok<NASGU>
t_comm = MPI_Comm(comm);
info = coder.ceval('MPI_Comm_free', coder.ref(t_comm));

toplevel = nargout>2;
comm = MPI_Comm(t_comm, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Comm_free failed with error message %s\n', mpi_Error_string(info))
end
