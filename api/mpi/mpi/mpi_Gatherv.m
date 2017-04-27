function [info, toplevel] = mpi_Gatherv(sptr, scount, stype, rptr, rcounts, disps, rtype, root, comm)
%mpi_Gatherv  Gathers into specified locations from all processes in a group
%
%    info = mpi_Gatherv(sptr, scount, stype, rptr, rount, rtype, root, comm)
%
%  Input Parameters
%  sptr       An m2c_opaque_ptr_const to MATLAB variable to be sent
%  sendcount  number of elements in send buffer (integer)
%  sendtype   type of elements in send buffer (handle)
%  rptr       An m2c_opaque_ptr to MATLAB variable to be received
%  recvcount  number of elements in receive buffer (integer)
%  disps      i-th entry: C-style displacement in rvar at which to place the
%             incoming data from rank i (length commsize)
%  recvtype   type of elements in receive buffer (handle)
%  root       rank of the root processor
%  comm       communicator (handle)
%
%  Output Parameters
%  info       return code
%
%  SEE ALSO: mpi_Barrier, mpi_Bcast, mpi_Scatter, mpi_Gather, mpi_Reduce
%
%  mpi_Gatherv is a collective operation on comm (all ranks must call it)
%
% C interface:
%   int MPI_Gatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
%         void *recvbuf, int *recvcounts, int *displs, MPI_Datatype recvtype,
%         int root, MPI_Comm comm);
% http://mpi.deino.net/mpi_functions/MPI_Gatherv.html

%#codegen -args {m2c_opaque_ptr_const, int32(0), MPI_Datatype, m2c_opaque_ptr, coder.typeof(int32(0),[inf,inf]), ...
%#codegen coder.typeof(int32(0),[inf,inf]), MPI_Datatype, int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(sptr) && coder.ismatlabthread
    if (sptr.nbytes-sptr.offset < scount*mpi_Type_size(stype))
        m2c_error('mpi_Gatherv:OutOfBound','Message size is larger than variable size.');
    end
end

info = coder.ceval('MPI_Gatherv', m2c_opaque_ptr_const(sptr), int32(scount), MPI_Datatype(stype), ...
    m2c_opaque_ptr(rptr), coder.rref(rcounts), coder.rref(disps), MPI_Datatype(rtype), int32(root), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Gatherv failed with error message %s\n', mpi_Error_string(info))
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
%! info = mpi_Gatherv(m2c_opaque_ptr_const(svar), count, MPI_DOUBLE, ...
%!        m2c_opaque_ptr(rvar), rcounts, disps, MPI_DOUBLE, int32(0), comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));
