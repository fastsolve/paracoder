function [newcomm, info, toplevel] = mpi_Comm_split(comm, color, key)
%mpi_Comm_split  Creates new communicators based on colors and keys
%
%  [newcomm, info] = mpi_Comm_split(comm, color, key)
%
%  comm      communicator object
%  color     control of subset assignment (nonnegative integer). 
%            Processes with the same color are in the same new communicator.
%  key       control of rank assigment (integer)
%  newcomm   A new commungroup, which is a subset of the group of comm
%  info      return code
%
% SEE ALSO mpi_Comm_create, mpi_Comm_free
%
% C interface:
% int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm)
% http://mpi.deino.net/mpi_functions/MPI_Comm_split.html

%#codegen -args {MPI_Comm, int32(0), int32(0)}

info = int32(0); %#ok<NASGU>

    
newcomm0 = coder.opaque('MPI_Comm');
info = coder.ceval('MPI_Comm_split', MPI_Comm(comm), color, key, ...
    coder.wref(newcomm0));
    
toplevel = nargout>2;
newcomm = MPI_Comm(newcomm0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Comm_split failed with error message %s\n', mpi_Error_string(info))
end
