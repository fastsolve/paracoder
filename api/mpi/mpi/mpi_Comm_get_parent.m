function [comm, info, toplevel] = mpi_Comm_get_parent
%mpi_Comm_get_parent  Return the parent communicator for this process
%
%  [comm, info] = mpi_Comm_get_parent
%
%  comm       Opaque MPI_Comm object.
%  info (int) return code
%
% C interface:
% int MPI_Comm_get_parent(MPI_Comm *parent)
% http://mpi.deino.net/mpi_functions/MPI_Comm_get_parent.html

%#codegen -args {}

info = int32(0); %#ok<NASGU>
comm0 = coder.opaque('MPI_Comm');
info = coder.ceval('MPI_Comm_get_parent', coder.wref(comm0));

toplevel = nargout>2;
comm = MPI_Comm(comm0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Comm_get_parent failed with error message %s\n', mpi_Error_string(info))
end

function test %#ok<DEFNU>
%!test
%! assert(isequal(mpi_Comm_get_parent, MPI_COMM_NULL))
