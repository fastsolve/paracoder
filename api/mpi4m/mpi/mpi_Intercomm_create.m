function [newcomm, info, toplevel] = mpi_Intercomm_create(local_comm, ...
    local_leader, peer_comm, remote_leader, tag)
%mpi_Intercomm_create  Creates a new communicator
%
%  [newcomm, info] = mpi_Intercomm_create(local_comm,
%                    local_leader, peer_comm, remote_leader, tag)
%
%  comm      A communicator object
%  group     A group, which is a subset of the group of comm
%  newcomm   A new commungroup, which is a subset of the group of comm
%  info      return code
%
% SEE ALSO mpi_Intercomm_merge, mpi_Comm_free
%
% C interface:
% int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
%      MPI_Comm peer_comm, int remote_leader, int tag, MPI_Comm *newintercomm);
% http://mpi.deino.net/mpi_functions/MPI_Intercomm_create.html

%#codegen -args {MPI_Comm, int32(0), MPI_Comm, int32(0), int32(0)}

info = int32(0); %#ok<NASGU>

    
newcomm0 = coder.opaque('MPI_Comm');
info = coder.ceval('MPI_Intercomm_create', MPI_Comm(local_comm), local_leader, ...
    MPI_Comm(peer_comm), remote_leader, tag, coder.wref(newcomm0));

toplevel = nargout>2;
newcomm = MPI_Comm(newcomm0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Intercomm_create failed with error message %s\n', mpi_Error_string(info))
end
