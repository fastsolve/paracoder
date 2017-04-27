function [size,info, toplevel] = mpi_Pack_size(count, datatype, comm)
%mpi_Pack_size	Returns upper bound on amount of space needed to pack a msg
%
%  [size,info] = mpi_Pack_size(count, datatype, comm)
%
%  count      number of data items
%  datatype   an opaque MPI_Datatype object (see MPI_Datatype)
%  comm       MPI_Comm object (see MPI_Comm)
%
%  size (int) upper bound on size of packed message, in bytes
%  info (int) return code
%
%  SEE ALSO: mpi_Pack, mpi_Unpack
%
% C interface:
%   int MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm,
%                     int *size)
% http://mpi.deino.net/mpi_functions/MPI_Pack_size.html

%#codegen -args {int32(0), MPI_Datatype, MPI_Comm}

info = int32(0); %#ok<NASGU>

size = int32(0);
info = coder.ceval('MPI_Pack_size', ...
    int32(count), MPI_Datatype(datatype), MPI_Comm(comm), coder.wref(size));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Pack_size failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! [size,info] = mpi_Pack_size(int32(100), MPI_DOUBLE, comm);
%! assert(info==0);
