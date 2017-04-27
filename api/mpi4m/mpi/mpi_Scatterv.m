function [info, toplevel] = mpi_Scatterv(sptr, scounts, disps, stype, rptr, rcount, rtype, root, comm)
%mpi_Scatterv  Scatters a buffer in parts to all processes in a communicator
%
%    info = mpi_Scatterv(sptr, scounts, disps, stype, rptr, rcounts, rtype, root, comm)
%
%  Input Parameters
%  sptr       An m2c_opaque_ptr_const to MATLAB variable to be sent
%  scounts    integer array (of length group size) specifying the number 
%             of elements to send to each processor
%  disps      integer array (of length group size). Entry i (C-style) 
%             specifies the displacement (relative to sendbuf from which 
%             to take the outgoing data to process i
%  stype      type of elements in send buffer (handle)
%  rptr       An m2c_opaque_ptr to MATLAB variable to be received
%  rcount     number of elements in receive buffer (integer)
%  rtype      data type of receive buffer elements (handle)
%  root       rank of sending process (integer)
%  comm       communicator (handle)
%
%  Output Parameters
%  info       return code
%
%  SEE ALSO: mpi_Scatter, mpi_Barrier, mpi_Bcast, mpi_Gather, mpi_Reduce
%
%  mpi_Scatterv is a collective operation on comm (all processes must call it)
%
% C interface:
%   int MPI_Scatterv(void *sendbuf, int *sendcounts, int *displs, MPI_Datatype sendtype,
%         void *recvbuf, int recvcount, MPI_Datatype recvtype,
%         int root, MPI_Comm comm);
% http://mpi.deino.net/mpi_functions/MPI_Scatterv.html

%#codegen -args {m2c_opaque_ptr_const, coder.typeof(int32(0),[inf,inf]), 
%#codegen coder.typeof(int32(0),[inf,inf]), MPI_Datatype, 
%#codegen m2c_opaque_ptr, int32(0), MPI_Datatype, int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(sptr) && coder.ismatlabthread
    if (rptr.nbytes-rptr.offset < rcount*mpi_Type_size(rtype))
        m2c_error('mpi_Scatterv:OutOfBound','Message size is larger than variable size.');
    end
end

info = coder.ceval('MPI_Scatterv', m2c_opaque_ptr_const(sptr), ...
    coder.rref(scounts), coder.rref(disps), MPI_Datatype(stype), ...
    m2c_opaque_ptr(rptr), int32(rcount), MPI_Datatype(rtype), ...
    int32(root), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Scatterv error code %d\n', info)
end

function test  %#ok<DEFNU>
%!shared comm, svar, count
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! svar = rand(10,10);
%! count = int32(numel(svar));
%!
%! rvar = zeros(size(svar));
%! 
%! scounts = count;  rcount = count; disps = int32(0); 
%! info = mpi_Scatterv(m2c_opaque_ptr_const(svar), scounts, disps, MPI_DOUBLE, ...
%!        m2c_opaque_ptr(rvar), rcount, MPI_DOUBLE, int32(0), comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));

% test checking on out of bound
%!test
%! info = int32(1);
%! rvar = zeros(size(svar));
%! try mpi_Scatterv(m2c_opaque_ptr_const(svar), scounts, MPI_DOUBLE, ...
%!            m2c_opaque_ptr(rvar), count+1, MPI_DOUBLE, int32(0), comm);
%! catch; info=int32(0); end
%! assert(info==0);
