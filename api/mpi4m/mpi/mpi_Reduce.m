function [info, toplevel] = mpi_Reduce(sptr, rptr, count, datatype, op, root, comm)
%mpi_Reduce    Reduces values on all processes to a single value
%
%  info = mpi_Reduce (sptr, rptr, count, datatype, op, root, comm)
%
%  sptr      Opaque pointer as buffer to be sent
%  rptr      Opaque pointer as buffer to be received
%  count     Number of items.
%  datatype  Opaque MPI_Datatype object (see MPI_Datatype).
%  op        Opaque MPI_Op object (see MPI_Op)
%  root  (int)  rank of root process (destination of reduce op)
%  comm      Opaque MPI_Comm object (see MPI_Comm)
%
%  info (int)   return code
%
%  SEE ALSO: mpi_Barrier, mpi_Bcast, mpi_Scatter, mpi_Gather
%
%  mpi_Reduce is a collective operation on comm (all ranks must call it)
%
% C interface:
% int MPI_Reduce(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
%                MPI_Op op, int root, MPI_Comm comm)
% http://mpi.deino.net/mpi_functions/MPI_Reduce.html

%#codegen -args {m2c_opaque_ptr_const, m2c_opaque_ptr, int32(0), MPI_Datatype,
%#codegen        MPI_Op, int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(sptr) && coder.target('MATLAB')
    if sptr.nbytes-sptr.offset < count*mpi_Type_size(datatype)
        m2c_error('mpi_Reduce:OutOfBound','Message is larger than send buffer size.');
    end
    if mpi_Comm_rank(comm)==root && ...
            rptr.nbytes-rptr.offset < count*mpi_Type_size(datatype)
        m2c_error('mpi_Reduce:OutOfBound','Message is larger than receive buffer.');
    end
end

info = coder.ceval('MPI_Reduce', m2c_opaque_ptr_const(sptr), m2c_opaque_ptr(rptr), ...
    int32(count), MPI_Datatype(datatype), MPI_Op(op), int32(root), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Reduce failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! svar = rand(10,10);
%! count = int32(numel(svar));
%! rvar = zeros(size(svar));
%!
%! info = mpi_Reduce(m2c_opaque_ptr_const(svar), m2c_opaque_ptr(rvar), ...
%!        count, MPI_DOUBLE, MPI_SUM, int32(0), comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));
