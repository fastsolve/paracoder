function [group, info, toplevel] = mpi_Comm_remote_group(comm)
%mpi_Comm_remote_group Accesses the remote group associated with the given inter-communicator
%
%  [group, info] = mpi_Comm_remote_group(comm)
%
%  comm  Opaque MPI_Comm object.
%  group  Opaque MPI_Group object.
%  info (int) return code
%
% C interface:
% int MPI_Comm_remote_group(MPI_Comm comm, MPI_Comm *group)
% http://mpi.deino.net/mpi_functions/MPI_Comm_remote_group.html

%#codegen -args {MPI_Comm}

info = int32(0); %#ok<NASGU>
group0 = coder.opaque('MPI_Group');
info = coder.ceval('MPI_Comm_remote_group', MPI_Comm(comm), coder.wref(group0));

toplevel = nargout>2;
group = MPI_Group(group0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Comm_remote_group failed with error message %s\n', mpi_Error_string(info))
end
