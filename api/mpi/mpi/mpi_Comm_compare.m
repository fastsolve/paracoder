function [result, info, toplevel] = mpi_Comm_compare(comm1, comm2)
%mpi_Comm_compare  Compares two communicators
%
%  [result, info] = mpi_Comm_compare(comm1, comm2)
%
%  comm1     first communicator object
%  comm2     second communicator object
%  result    integer, which is MPI_IDENT if the contexts and groups are
%            the same, MPI_CONGRUENT if different contexts but
%            identical groups, MPI_SIMILAR if different contexts but
%            similar groups, and MPI_UNEQUAL otherwise
%  info      return code
%
% C interface:
% int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result)
% http://mpi.deino.net/mpi_functions/MPI_Comm_compare.html

%#codegen -args {MPI_Comm, MPI_Comm}

    
info = int32(0); %#ok<NASGU>
result = int32(0);
info = coder.ceval('MPI_Comm_compare', MPI_Comm(comm1), MPI_Comm(comm2), ...
    coder.wref(result));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Comm_compare failed with error message %s\n', mpi_Error_string(info))
end
