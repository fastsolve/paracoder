function [newcomm, info, toplevel] = mpi_Comm_create(comm, group)
%mpi_Comm_create  Creates a new communicator
%
%  [newcomm, info] = mpi_Comm_create(comm, group)
%
%  comm      A communicator object
%  group     A group, which is a subset of the group of comm
%  newcomm   A new commungroup, which is a subset of the group of comm
%  info      return code
%
% SEE ALSO mpi_Comm_free
%
% C interface:
% int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm)
% http://mpi.deino.net/mpi_functions/MPI_Comm_create.html

%#codegen -args {MPI_Comm, MPI_Group}

info = int32(0); %#ok<NASGU>

    
newcomm0 = coder.opaque('MPI_Comm');
info = coder.ceval('MPI_Comm_create', MPI_Comm(comm), MPI_Group(group), ...
    coder.wref(newcomm0));
    
toplevel = nargout>2;
newcomm = MPI_Comm(newcomm0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Comm_create failed with error message %s\n', mpi_Error_string(info))
end
