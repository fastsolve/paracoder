function [info, toplevel] = mpi_Reduce_scatter(sptr, rptr, rcounts, datatype, op, comm)
%mpi_Reduce_scatter Combines values and scatters the results
%
%  info = mpi_Reduce_scatter(sptr, rptr, count, datatype, op, comm)
%
%  Input arguments
%  sptr        starting address of send buffer (m2c_opaque_ptr_const)
%  rptr        starting address of receive buffer (m2c_opaque_ptr)
%  rcounts     integer array specifying the number of elements
%              in result distributed to each process.
%              Array must be identical on all calling processes.
%  datatype    data type of elements of input buffer (MPI_Datatype handle)
%  op          operation (MPI_Op handle)
%  comm        communicator (MPI_Comm handle)
%
%  Output arguments
%  info (int)   return code
%
%  SEE ALSO: mpi_Barrier, mpi_Bcast, mpi_Scatter, mpi_Gather, mpi_Reduce
%
%  mpi_Reduce_scatter is a collective operation on comm (all processors must call it)
%
% C interface:
%    int MPI_Reduce_scatter(void *sendbuf, void *recvbuf, int *recvcnts,
%            MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
% http://mpi.deino.net/mpi_functions/MPI_Reduce_scatter.html

%#codegen -args {m2c_opaque_ptr_const, m2c_opaque_ptr, coder.typeof(int32(0),[inf,inf]),
%#codegen        MPI_Datatype, MPI_Op, MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(sptr) && coder.ismatlabthread
    count = sum(rcounts(:)); sizepe=mpi_Type_size(datatype);
    if (sptr.nbytes-sptr.offset < count*sizepe)
        m2c_error('mpi_Reduce_scatter:OutOfBound','Send buffer is too small.');
    elseif (rptr.nbytes-rptr.offset < rcounts(mpi_Comm_rank(comm)+1)*sizepe)
        m2c_error('mpi_Reduce_scatter:OutOfBound','Receive buffer is too small.');
    end
end

info = coder.ceval('MPI_Reduce_scatter', m2c_opaque_ptr_const(sptr), m2c_opaque_ptr(rptr), ...
    coder.rref(rcounts), MPI_Datatype(datatype), MPI_Op(op), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Reduce_scatter failed with error message %s\n', mpi_Error_string(info))
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
%! info = mpi_Reduce_scatter(m2c_opaque_ptr_const(svar), m2c_opaque_ptr(rvar), ...
%!        count, MPI_DOUBLE, MPI_SUM, comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));
