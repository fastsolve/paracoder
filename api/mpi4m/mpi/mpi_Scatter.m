function [info, toplevel] = mpi_Scatter(sptr, scount, stype, rptr, rcount, rtype, root, comm)
%mpi_Allgather	Sends data from one process to all other processes in a communicator
%
%  info = mpi_Scatter(sptr, scount, stype, rptr, rcount, rtype, root, comm)
%
%  Input Parameters
%  sptr       An m2c_opaque_ptr_const to MATLAB variable to be sent
%  scount     number of elements sent to each process (integer, significant only at root)
%  stype      data type of send buffer elements (significant only at root) (handle)
%  rptr       An m2c_opaque_ptr to MATLAB variable to be received
%  rcount     number of elements in receive buffer (integer)
%  rtype      data type of receive buffer elements (handle)
%  root       rank of sending process (integer)
%  comm       communicator (handle)
%
%  Output Parameters
%  info       return code
%
%  SEE ALSO: mpi_Barrier, mpi_Bcast, mpi_Scatter, mpi_Reduce
%
%  mpi_Scatter is a collective operation on comm (all processes must call it)
%
% C interface:
%    int MPI_Scatter(void *sendbuf, int sendcount, MPI_Datatype sendtype,
%                    void *recvbuf, int recvcount, MPI_Datatype recvtype,
%                    int root, MPI_Comm comm)
% http://mpi.deino.net/mpi_functions/MPI_Scatter.html

%#codegen -args {m2c_opaque_ptr_const, int32(0), MPI_Datatype,
%#codegen m2c_opaque_ptr, int32(0), MPI_Datatype, int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(sptr) && coder.target('MATLAB')
    if mpi_Comm_rank(comm)==root && ...
            sptr.nbytes-sptr.offset < scount*mpi_Type_size(stype)
        m2c_error('mpi_Scatter:OutOfBound','Message is larger than send buffer size.');
    end
    if rptr.nbytes-rptr.offset < rcount*mpi_Type_size(rtype)
        m2c_error('mpi_Scatter:OutOfBound','Message is larger than receive buffer.');
    end
end

info = coder.ceval('MPI_Scatter', m2c_opaque_ptr_const(sptr), int32(scount), ...
    MPI_Datatype(stype), m2c_opaque_ptr(rptr), int32(rcount), ...
    MPI_Datatype(rtype), int32(root), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Scatter error code %d\n', info)
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
%!
%! info = mpi_Scatter(m2c_opaque_ptr_const(svar), count, MPI_DOUBLE, ...
%!        m2c_opaque_ptr(rvar), count, MPI_DOUBLE, int32(0), comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));

% test checking on out of bound
%!test
%! info = int32(1);
%! rvar = zeros(size(svar));
%! try mpi_Scatter(m2c_opaque_ptr_const(svar), count+1, MPI_DOUBLE, ...
%!            m2c_opaque_ptr(rvar), count+1, MPI_DOUBLE, int32(0), comm);
%! catch; info=int32(0); end
%! assert(info==0);
