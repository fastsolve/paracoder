function [extent, info, toplevel] = mpi_Type_extent(datatype)
%mpi_Type_extent   Returns the size in bytes of the specified data type.
%
%  [extent, info] = mpi_Type_extent(datatype)
%
%Input argument:
%  datatype  Opaque MPI_Datatype object (see MPI_Datatype).
%
%Output argument:
%  extent       datatype extent (MPI_Aint)
%  info         return code (int32)
%
% NOTE: The MPI-2 standard deprecated this routine. The replacement
%       for this routine is MPI_Type_get_extent
%
% C interface:
% int MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent);
% http://mpi.deino.net/mpi_functions/MPI_Type_extent.html

%#codegen -args {MPI_Datatype}

info = int32(0);
extent0 = coder.opaque('MPI_Aint');
info = coder.ceval('MPI_Type_extent', MPI_Datatype(datatype), coder.wref(extent0));

toplevel = nargout>2;
extent = MPI_Aint(extent0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Type_extent returned error code %d\n', info)
end
