function [info,toplevel] = mpi_Allgather(sptr, scount, stype, rptr, rcount, rtype, comm)
%mpi_Allgather	Gathers data from all tasks and distribute the combined data to all tasks
%
%  info = mpi_Allgather(sptr, scount, stype, rptr, rount, rtype, comm)
%
%  Input Parameters
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
%  SEE ALSO: mpi_Barrier, mpi_Bcast, mpi_Scatter, mpi_Gather, mpi_Reduce
%
%  MPI_Allgather is a collective operation on comm (all ranks must call it)
%
% C interface:
%    int MPI_Allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
%                      void *recvbuf, int recvcount, MPI_Datatype recvtype,
%                      MPI_Comm comm)
% http://mpi.deino.net/mpi_functions/MPI_Allgather.html

%#codegen -args {m2c_opaque_ptr_const, int32(0), MPI_Datatype,
%#codegen m2c_opaque_ptr, int32(0), MPI_Datatype, MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(sptr) && coder.ismatlabthread
    if (sptr.nbytes-sptr.offset < scount*mpi_Type_size(stype) || ...
            rptr.nbytes-rptr.offset < rcount*mpi_Type_size(rtype))
        m2c_error('mpi_Allgather:OutOfBound','Message size is larger than variable size.');
    end
end

info = coder.ceval('MPI_Allgather', m2c_opaque_ptr_const(sptr), int32(scount), MPI_Datatype(stype), ...
    m2c_opaque_ptr(rptr), int32(rcount), MPI_Datatype(rtype), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Allgather failed with error message %s\n', mpi_Error_string(info))
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
%! info = mpi_Allgather(m2c_opaque_ptr_const(svar), count, MPI_DOUBLE, ...
%!        m2c_opaque_ptr(rvar), count, MPI_DOUBLE, comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));
