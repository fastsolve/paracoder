function [datatype, info, toplevel] = mpi_Type_free(datatype)
%mpi_Type_free  Marks the datatype for deallocation
%
%  [datatype, info] = mpi_Type_free (datatype)
%
%  datatype   (INOUT) Type to be destroyed. It is marked for deallocation,
%      and is set to MPI_DATATYPE_NULL at output.
%
%  info (int) return code
%
%  SEE ALSO: mpi_Type_cotiguous
%
% C interface:
%   int MPI_Type_free(MPI_Datatype *datatype)
% http://mpi.deino.net/mpi_functions/MPI_Type_free.html
% http://www.mpi-forum.org/docs/mpi-11-html/node158.html

%#codegen -args {MPI_Datatype}


info = int32(0); %#ok<NASGU>
t_datatype = MPI_Datatype(datatype);
info = coder.ceval('MPI_Type_free', coder.ref(t_datatype));

toplevel = nargout>2;
datatype = MPI_Datatype(t_datatype, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Type_free failed with error message %s\n', mpi_Error_string(info))
end
