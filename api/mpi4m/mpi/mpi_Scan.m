function [info, toplevel] = mpi_Scan(sptr, rptr, count, datatype, op, comm)
%mpi_Scan  Computes the scan (partial reductions) of data on a collection of processes
%
%  info = mpi_Scan (sptr, rptr, count, datatype, op, comm)
%
%  sptr      Opaque pointer as buffer to be sent
%  rptr      Opaque pointer as buffer to be received
%  count     Number of items.
%  datatype  Opaque MPI_Datatype object (see MPI_Datatype).
%  op        Opaque MPI_Op object (see MPI_Op)
%  comm      Opaque MPI_Comm object (see MPI_Comm)
%
%  info (int)   return code
%
%  SEE ALSO: mpi_Barrier, mpi_Bcast, mpi_Reduce, mpi_Scatter, mpi_Gather
%
%  mpi_Scan is a collective operation on comm (all ranks must call it)
%
% C interface:
% int MPI_Scan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, 
%              MPI_Op op, MPI_Comm comm)
% http://mpi.deino.net/mpi_functions/MPI_Scan.html

%#codegen -args {m2c_opaque_ptr_const, m2c_opaque_ptr, int32(0), MPI_Datatype,
%#codegen        MPI_Op, MPI_Comm}


info = int32(0); %#ok<NASGU>

if isstruct(sptr) && coder.target('MATLAB')
    if sptr.nbytes-sptr.offset < count*mpi_Type_size(datatype)
        m2c_error('mpi_Scan:OutOfBound','Message is larger than send buffer size.');
    end
end

info = coder.ceval('MPI_Scan', m2c_opaque_ptr_const(sptr), m2c_opaque_ptr(rptr), ...
    int32(count), MPI_Datatype(datatype), MPI_Op(op), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Scan failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! comm = MPI_COMM_WORLD;
%! svar = rand(10,10);
%! count = int32(numel(svar));
%! rvar = zeros(size(svar));
%!
%! info = mpi_Scan(m2c_opaque_ptr_const(svar), m2c_opaque_ptr(rvar), ...
%!        count, MPI_DOUBLE, MPI_SUM, comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));
