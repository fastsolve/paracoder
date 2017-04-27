function [info,toplevel] = mpi_Allgatherv(sptr, scount, stype, rptr, rcounts, disps, rtype, comm)
%mpi_Allgatherv     Gathers data from all tasks and deliver it to all
%
%    info = mpi_Allgatherv(sptr, scount, stype, rptr, rount, rtype, comm)
%
%  Input Parameters
%  sptr       An m2c_opaque_ptr_const to MATLAB variable to be sent
%  sendcount  number of elements in send buffer (integer)
%  sendtype   type of elements in send buffer (handle)
%  rptr       An m2c_opaque_ptr to MATLAB variable to be received
%  recvcounts integer array (of length group size) containing the number
%             of elements that are to be received from each process
%  disps      integer array (of length group size). Entry i specifies the
%             displacement (in C style, relative to recvbuf ) at which
%             to place the incoming data from process i
%  recvtype   type of elements in receive buffer (handle)
%  comm       communicator (handle)
%
%  Output Parameters
%  info       return code
%
%  SEE ALSO: mpi_Barrier, mpi_Bcast, mpi_Scatter, mpi_Gather, mpi_Reduce
%
%  MPI_Allgatherv is a collective operation on comm (all ranks must call it)
%
% C interface:
%   int MPI_Allgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
%         void *recvbuf, int *recvcounts, int *displs, MPI_Datatype recvtype,
%         MPI_Comm comm);
% http://mpi.deino.net/mpi_functions/MPI_Allgatherv.html

%#codegen -args {m2c_opaque_ptr_const, int32(0), MPI_Datatype, m2c_opaque_ptr, ...
%#codegen coder.typeof(int32(0),[inf,inf]), coder.typeof(int32(0),[inf,inf]), MPI_Datatype, MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(sptr) && coder.ismatlabthread
    if (sptr.nbytes-sptr.offset < scount*mpi_Type_size(stype))
        m2c_error('mpi_Allgatherv:OutOfBound','Message size is larger than variable size.');
    end
end

info = coder.ceval('MPI_Allgatherv', m2c_opaque_ptr_const(sptr), int32(scount), MPI_Datatype(stype), ...
    m2c_opaque_ptr(rptr), coder.rref(rcounts), coder.rref(disps), MPI_Datatype(rtype), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Allgatherv failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! svar = rand(10,10);
%! count = int32(numel(svar));
%! rvar = zeros(size(svar));
%! rcounts = count; disps = int32(0);
%! info = mpi_Allgatherv(m2c_opaque_ptr_const(svar), count, MPI_DOUBLE, ...
%!        m2c_opaque_ptr(rvar), rcounts, disps, MPI_DOUBLE, comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));
