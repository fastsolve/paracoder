function [datatype, info, toplevel] = mpi_Type_commit(datatype)
%mpi_Type_commit  Commits the datatype
%
%  [datatype, info] = mpi_Type_commit (datatype)
%
%  datatype Datatype to be committed. 
%  info (int) return code
%
%  A datatype object has to be committed before it can be used in a
%  communication.
%
%  SEE ALSO: mpi_Type_free
%
% C interface:
%   int MPI_Type_commit(MPI_Datatype *datatype)
% http://mpi.deino.net/mpi_functions/MPI_Type_commit.html
% http://www.mpi-forum.org/docs/mpi-11-html/node158.html

%#codegen -args {MPI_Datatype}


info = int32(0); %#ok<NASGU>
t_datatype = MPI_Datatype(datatype);
info = coder.ceval('MPI_Type_commit', coder.ref(t_datatype));

toplevel = nargout>2;
datatype = MPI_Datatype(t_datatype, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Type_commit failed with error message %s\n', mpi_Error_string(info))
end
