function [ub, info, toplevel] = mpi_Type_ub(datatype)
%mpi_Type_ub   Returns the upper bound of a datatype
%
%  [ub, info] = mpi_Type_ub(datatype)
%
%Input argument:
%  datatype     opaque datatype object (see MPI_Datatype).
%
%Output argument:
%  ub           displacement of upper bound from origin, in bytes (MPI_Aint)
%  info         return code (int32)
%
% NOTE: The MPI-2 standard deprecated this routine. The replacement 
%       for this routine is MPI_Type_get_extent.
%
% C interface:
% int MPI_Type_ub(MPI_Datatype datatype, MPI_Aint *ub);
% http://mpi.deino.net/mpi_functions/MPI_Type_ub.html

%#codegen -args {MPI_Datatype}

info = int32(0); %#ok<NASGU>
ub0 = coder.opaque('MPI_Aint');
info = coder.ceval('MPI_Type_ub', MPI_Datatype(datatype), coder.wref(ub0));

toplevel = nargout>2;
ub = MPI_Aint(ub0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Type_ub returned error code %d\n', info)
end
