function [lb, extent, info, toplevel] = mpi_Type_get_extent(datatype)
%mpi_Type_get_extent   Get the lower bound and extent for a Datatype
%
%  [lb, extent, info] = mpi_Type_get_extent(datatype)
%
%Input argument:
%  datatype - Opaque MPI datatype object (see MPI_Datatype).
%
%Output argument:
%  lb       - lower bound of datatype (MPI_Aint)
%  extent   - datatype extent (MPI_Aint)
%  info     - return code (int32)
%
% C interface:
% int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb, MPI_Aint *extent);
% http://mpi.deino.net/mpi_functions/MPI_Type_get_extent.html

%#codegen -args {MPI_Datatype}

info = int32(0); %#ok<NASGU>
lb0 = coder.opaque('MPI_Aint');
extent0 = coder.opaque('MPI_Aint');
info = coder.ceval('MPI_Type_get_extent', MPI_Datatype(datatype), ...
    coder.wref(lb0), coder.wref(extent0));

toplevel = nargout>3;
extent = MPI_Aint(extent0, toplevel);
lb = MPI_Aint(lb0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Type_get_extent failed with error message %s\n', mpi_Error_string(info))
end
