function [dup, info, toplevel] = mpi_Comm_dup(comm)
%mpi_Comm_dup  Duplicates an existing communicator with all its cached information
%
%  [dup, info] = mpi_Comm_dup(comm)
%
%  comm  Communicator to be duplicated 
%  dup   A new communicator over the same group as comm but with a new context.
%  info (int) return code
%
% C interface:
% int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *dup)
% http://mpi.deino.net/mpi_functions/MPI_Comm_dup.html

%#codegen -args {MPI_Comm}

info = int32(0); %#ok<NASGU>

    
dup0 = coder.opaque('MPI_Comm');
info = coder.ceval('MPI_Comm_dup', MPI_Comm(comm), coder.wref(dup0));
    
toplevel = nargout>2;
dup = MPI_Comm(dup0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Comm_dup failed with error message %s\n', mpi_Error_string(info))
end
