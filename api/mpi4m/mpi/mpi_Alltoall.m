function [info, toplevel] = mpi_Alltoall(sptr, scount, stype, rptr, rcount, rtype, comm)
%mpi_Alltoall    Sends data from all to all processes
%
%  info = mpi_Alltoall(sptr, scount, stype, rptr, rount, rtype, comm)
%
%  sptr       An m2c_opaque_ptr_const to MATLAB variable to be sent
%  scount     number of elements in send buffer (integer)
%  stype      type of elements in send buffer (handle)
%  rptr       An m2c_opaque_ptr to MATLAB variable to be received
%  rcount     number of elements in receive buffer (integer)
%  rtype      type of elements in receive buffer (handle)
%  comm       communicator (handle)
%
%  Output Parameters
%  info       return code
%
%  SEE ALSO: mpi_Alltoallv, mpi_Alltoallw, mpi_Barrier, mpi_Bcast,
%      mpi_Scatter, mpi_Gather, mpi_Reduce
%
%  mpi_Alltoall is a collective operation on comm (all ranks must call it)
%
% C interface:
%    int MPI_Alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
%                     void *recvbuf, int recvcount, MPI_Datatype recvtype,
%                     MPI_Comm comm)
% http://mpi.deino.net/mpi_functions/MPI_Alltoall.html

%#codegen -args {m2c_opaque_ptr_const, int32(0), MPI_Datatype,
%#codegen m2c_opaque_ptr, int32(0), MPI_Datatype, MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(sptr) && coder.ismatlabthread
    nprocs = mpi_Comm_size(comm);
    if (sptr.nbytes-sptr.offset < scount*nprocs *mpi_Type_size(stype) || ...
            rptr.nbytes-rptr.offset < rcount*nprocs *mpi_Type_size(rtype))
        m2c_error('mpi_Alltoall:OutOfBound','Message size is larger than variable size.');
    end
    if isequal(sptr.data,rptr.data)
        m2c_error('mpi_Alltoall:NoInPlace','MPI_Alltoall does not support in-place communication.');
    end
end

info = coder.ceval('MPI_Alltoall', m2c_opaque_ptr_const(sptr), int32(scount), MPI_Datatype(stype), ...
    m2c_opaque_ptr(rptr), int32(rcount), MPI_Datatype(rtype), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Alltoall failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>

%!shared comm, svar, count
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! svar = rand(10,10);
%! count = int32(numel(svar));
%! rvar = zeros(size(svar));
%! info = mpi_Alltoall(m2c_opaque_ptr_const(svar), count, MPI_DOUBLE, ...
%!        m2c_opaque_ptr(rvar), count, MPI_DOUBLE, comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));

%!test
%! info = int32(1);
%! rvar = zeros(size(svar));
%! % test checking on buffer overflow
%! try mpi_Alltoall(m2c_opaque_ptr_const(svar), count+1, MPI_DOUBLE, ...
%!            m2c_opaque_ptr(rvar), count+1, MPI_DOUBLE, comm);
%! catch; info=int32(0); end
%! assert(info==0);

%!test
%! info = int32(1);
%! rvar = zeros(size(svar));
%! % test checking on in-place communication
%! try mpi_Alltoall(m2c_opaque_ptr_const(svar), count, MPI_DOUBLE, ...
%!            m2c_opaque_ptr(svar), count, MPI_DOUBLE, comm);
%! catch; info=int32(0); end
%! assert(info==0);
