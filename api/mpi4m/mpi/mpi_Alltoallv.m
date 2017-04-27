function [info, toplevel] = mpi_Alltoallv(sptr, scounts, sdisps, stype, rptr, rcounts, rdisps, rtype, comm)
%mpi_Alltoallv   Gathers data from all tasks and deliver it to all
%
%    info = mpi_Alltoallv(sptr, scounts, sdisps, stype, rptr, rcounts, rdisps, rtype, comm)
%
%  Input Parameters
%  sptr       An m2c_opaque_ptr_const to MATLAB variable to be sent
%  scounts    integer array equal to the group size specifying the number 
%             of elements to send to each processor
%  sdisps     integer array (of length group size). Entry j (C-style) 
%             specifies the displacement (relative to sendbuf from which 
%             to take the outgoing data destined for process j sendtype
%  stype      data type of send buffer elements (handle)
%  rptr       An m2c_opaque_ptr to MATLAB variable to be received
%  rcounts    integer array equal to the group size specifying the maximum
%             number of elements that can be received from each processor
%  rdisps     nteger array (of length group size). Entry i (C-style) 
%             specifies the  displacement (relative to recvbuf at which to 
%             place the incoming data from process i
%  recvtype   data type of receive buffer elements (handle)
%  comm       communicator (handle)
%
%  Output Parameters
%  info       return code
%
%  SEE ALSO: mpi_Alltoall, mpi_Alltoallw, mpi_Barrier, mpi_Bcast, mpi_Scatter, 
%            mpi_Gather, mpi_Reduce
%
%  MPI_Alltoallv is a collective operation on comm (all processes must call it)
%
%  C interface:
%   int MPI_Alltoallv (void *sendbuf, int *sendcounts, int *senddispls, MPI_Datatype sendtype,
%         void *recvbuf, int *recvcounts, int *recvdispls, MPI_Datatype recvtype,
%         MPI_Comm comm);
% http://mpi.deino.net/mpi_functions/MPI_Alltoallv.html

%#codegen -args {m2c_opaque_ptr_const, coder.typeof(int32(0),[inf,inf]), coder.typeof(int32(0),[inf,inf]), MPI_Datatype, m2c_opaque_ptr, ...
%#codegen coder.typeof(int32(0),[inf,inf]), coder.typeof(int32(0),[inf,inf]), MPI_Datatype, MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(sptr) && coder.ismatlabthread
    if isequal(sptr.data,rptr.data)
        m2c_error('mpi_Alltoallv:NoInPlace','MPI_Alltoallv does not support in-place communication.');
    end
end

info = coder.ceval('MPI_Alltoallv', m2c_opaque_ptr_const(sptr), coder.rref(scounts), coder.rref(sdisps), MPI_Datatype(stype), ...
    m2c_opaque_ptr(rptr), coder.rref(rcounts), coder.rref(rdisps), MPI_Datatype(rtype), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Alltoallv failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>

%!shared comm, svar, scounts, sdisps, rcounts, rdisps
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! svar = rand(10,10);
%! scounts = int32(numel(svar)); sdisps = int32(0);
%! rvar = zeros(size(svar));
%! rcounts = scounts; rdisps = int32(0); 
%! 
%! info = mpi_Alltoallv(m2c_opaque_ptr_const(svar), scounts, sdisps, MPI_DOUBLE, ...
%!        m2c_opaque_ptr(rvar), rcounts, rdisps, MPI_DOUBLE, comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));

%!test
%! info = int32(1);
%! % test checking on in-place communication
%! try mpi_Alltoallv(m2c_opaque_ptr_const(svar), scounts, sdisps, MPI_DOUBLE, ...
%!        m2c_opaque_ptr(svar), rcounts, rdisps, MPI_DOUBLE, comm);
%! catch; info=int32(0); end
%! assert(info==0);
