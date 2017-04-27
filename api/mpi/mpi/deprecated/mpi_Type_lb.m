function [lb, info, toplevel] = mpi_Type_lb(datatype)
%mpi_Type_lb   Returns the lower bound of a datatype
%
%  [lb, info] = mpi_Type_lb(datatype)
%
%Input argument:
%  datatype  Opaque MPI_Datatype object (see MPI_Datatype).
%
%Output argument:
%  lb           displacement of lower bound from origin, in bytes (MPI_Aint)
%  info         return code (int32)
%
% NOTE: The MPI-2 standard deprecated this routine. The replacement
%       for this routine is MPI_Type_get_extent
%
% C interface:
% int MPI_Type_lb(MPI_Datatype datatype, MPI_Aint *lb);
% http://mpi.deino.net/mpi_functions/MPI_Type_lb.html

%#codegen -args {MPI_Datatype}

info = int32(0); %#ok<NASGU>
lb0 = coder.opaque('MPI_Aint');
info = coder.ceval('MPI_Type_lb', MPI_Datatype(datatype), coder.wref(lb0));

toplevel = nargout>2;
lb = MPI_Aint(lb0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Type_lb returned error code %d\n', info)
end
