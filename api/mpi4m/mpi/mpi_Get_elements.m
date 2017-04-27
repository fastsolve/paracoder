function [elems, info, toplevel] = mpi_Get_elements(stat, datatype)
%mpi_Get_elements  Gets the number of basic elements received
%
%  [elems, info] = mpi_Get_elements(stat, datatype)
%
%  stat: MPI_Status object
%
%  elems (int): the number of received elements (integer)
%  info (int): return code
%
%  SEE ALSO: MPI_Status, mpi_Get_count
%
% C interface:
%   int MPI_Get_elements, MPI_Status *status, MPI_Datatype datatype, int *elems);
% http://mpi.deino.net/mpi_functions/MPI_Get_elements.html

%#codegen -args {MPI_Status, MPI_Datatype}

elems = int32(0);
info = int32(0); %#ok<NASGU>

t_stat = MPI_Status(stat);
info = coder.ceval('MPI_Get_elements', coder.ref(t_stat), ...
    MPI_Datatype(datatype), coder.wref(elems));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Get_elements failed with error message %s\n', mpi_Error_string(info))
end
