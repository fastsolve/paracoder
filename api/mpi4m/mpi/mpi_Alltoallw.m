function [info, toplevel] = mpi_Alltoallw(sptr, scounts, sdisps, stypes, ...
    rptr, rcounts, rdisps, rtypes, comm)
%mpi_Alltoallw  Generalized all-to-all communication allowing different datatypes, counts, and displacements for each partner
%
%    info = mpi_Alltoallw(sptr, scounts, sdisps, stypes, rptr, rcounts, rdisps, rtypes, comm)
%
%  Input Parameters
%  sptr       An m2c_opaque_ptr_const to MATLAB variable to be sent
%  scounts    integer array equal to the group size specifying the number 
%             of elements to send to each processor
%  sdisps     integer array (of length group size). Entry j (C-style) 
%             specifies the displacement (relative to sendbuf from which 
%             to take the outgoing data destined for process j sendtype
%  stypes     data types of send buffer elements (MPI_Datatype_array)
%  rptr       An m2c_opaque_ptr to MATLAB variable to be received
%  rcounts    integer array equal to the group size specifying the maximum
%             number of elements that can be received from each processor
%  rdisps     nteger array (of length group size). Entry i (C-style) 
%             specifies the  displacement (relative to recvbuf at which to 
%             place the incoming data from process i
%  recvtypes  data type of receive buffer elements (MPI_Datatype_array)
%  comm       communicator (MPI_Comm)
%
%  Output Parameters
%  info       return code
%
%  SEE ALSO: mpi_Alltoall, mpi_Barrier, mpi_Bcast, mpi_Scatter, 
%            mpi_Gather, mpi_Reduce
%
%  MPI_Alltoallw is a collective operation on comm (all processes must call it)
%
%  C interface:
%   int MPI_Alltoallw (void *sendbuf, int *sendcounts, int *senddispls, MPI_Datatype *sendtype,
%         void *recvbuf, int *recvcounts, int *recvdispls, MPI_Datatype *recvtype,
%         MPI_Comm comm);
% http://mpi.deino.net/mpi_functions/MPI_Alltoallw.html

%#codegen -args {m2c_opaque_ptr_const, coder.typeof(int32(0),[inf,inf]), coder.typeof(int32(0),[inf,inf]), 
%#codegen MPI_Datatype_array, m2c_opaque_ptr, coder.typeof(int32(0),[inf,inf]),
%#codegen coder.typeof(int32(0),[inf,inf]), MPI_Datatype_array, MPI_Comm}


info = int32(0); %#ok<NASGU>

if isstruct(sptr) && coder.ismatlabthread
    if isequal(sptr.data,rptr.data)
        m2c_error('mpi_Alltoallw:NoInPlace','MPI_Alltoallw does not support in-place communication.');
    end
end

stypes0 = MPI_Datatype_array(stypes);
rtypes0 = MPI_Datatype_array(rtypes);

[stypes0,rtypes0] = m2c_unalias(stypes0,rtypes0);
info = coder.ceval('MPI_Alltoallw', m2c_opaque_ptr_const(sptr), coder.rref(scounts), coder.rref(sdisps), ...
    m2c_opaque_ptr_const(stypes0, 'MPI_Datatype *'), m2c_opaque_ptr(rptr), coder.rref(rcounts), ...
    coder.rref(rdisps), m2c_opaque_ptr_const(rtypes0, 'MPI_Datatype *'), MPI_Comm(comm));
m2c_rref(stypes0,rtypes0); %#ok<NASGU>

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Alltoallw failed with error message %s\n', mpi_Error_string(info))
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
%! stypes = MPI_Datatype_array(1);
%! stypes = MPI_Datatype_array(stypes, 'set', 1, MPI_DOUBLE);
%! rtypes = MPI_Datatype_array(1);
%! rtypes = MPI_Datatype_array(rtypes, 'set', 1, MPI_DOUBLE);
%! info = mpi_Alltoallw(m2c_opaque_ptr_const(svar), scounts, sdisps, stypes, ...
%!        m2c_opaque_ptr(rvar), rcounts, rdisps, rtypes, comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));
