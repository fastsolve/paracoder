function [count, info, toplevel] = mpi_Get_count(stat, datatype)
%mpi_Get_count  Gets the number of "top level" elements
%
%  [count, info] = mpi_Get_count(stat, datatype)
%
%  stat: MPI_Status object
%
%  count (int): the number of received elements (integer)
%  info (int): return code
%
%  SEE ALSO: MPI_Status, mpi_Get_elements
%
% C interface:
%   int MPI_Get_count(MPI_Status *status, MPI_Datatype datatype, int *count);
% http://mpi.deino.net/mpi_functions/MPI_Get_count.html

%#codegen -args {MPI_Status, MPI_Datatype}

count = int32(0);
info = int32(0); %#ok<NASGU>

t_stat = MPI_Status(stat);
info = coder.ceval('MPI_Get_count', coder.ref(t_stat), ...
    MPI_Datatype(datatype), coder.wref(count));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Get_count failed with error message %s\n', mpi_Error_string(info))
end
