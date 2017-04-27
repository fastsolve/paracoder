function [newcomm, info, toplevel] = mpi_Intercomm_merge(intercomm, high)
%mpi_Intercomm_merge  Creates an intracommuncator from an intercommunicator
%
%  [newcomm, info] = mpi_Intercomm_merge(intercomm)
%
%  intercomm interc-ommunicator
%  high      Used to order the groups within comm (logical) when creating
%            the new communicator. This is a boolean value; the group
%            that sets high true has its processes ordered after the
%            group that sets this value to false. If all processes in
%            the intercommunicator provide the same value, the choice
%            of which group is ordered first is arbitrary.
%  newcomm   reated intracommunicato
%  info      return code
%
% SEE ALSO mpi_Intercomm_create, mpi_Comm_free
%
% C interface:
% int MPI_Intercomm_merge(MPI_Comm comm, int high, MPI_Comm *newcomm)
% http://mpi.deino.net/mpi_functions/MPI_Intercomm_merge.html

%#codegen -args {MPI_Comm, int32(0)}


info = int32(0); %#ok<NASGU>
newcomm0 = coder.opaque('MPI_Comm');
info = coder.ceval('MPI_Intercomm_merge', MPI_Comm(intercomm), high, ...
    coder.wref(newcomm0));

toplevel = nargout>2;
newcomm = MPI_Comm(newcomm0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Intercomm_merge failed with error message %s\n', mpi_Error_string(info))
end
