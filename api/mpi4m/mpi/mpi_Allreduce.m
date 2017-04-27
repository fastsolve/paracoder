function [info, toplevel] = mpi_Allreduce(sptr, rptr, count, datatype, op, comm)
%mpi_Allreduce	Combines values from all processes and distributes the result back to all processes
%
%  info = MPI_Allreduce (sptr, rptr, count, datatype, op, comm)
%
%  sptr      An m2c_opaque_ptr_const to MATLAB variable to be sent, Set
%            sptr to MPI_IN_PLACE if sptr==rptr.
%  rptr      An m2c_opaque_ptr to MATLAB variable to be received
%  count     Number of items.
%  datatype  Opaque MPI_Datatype object (see MPI_Datatype)
%  op        Opaque MPI_Op object (see MPI_Op)
%  comm      Opaque MPI_Comm object (see MPI_Comm)
%
%  info (int) return code
%
%  SEE ALSO: mpi_Barrier, mpi_Bcast, mpi_Scatter, mpi_Gather, mpi_Reduce
%
%  MPI_Allreduce is a collective operation on comm (all processes must call it)
%
% C interface:
% int MPI_Allreduce(void *sendbuf, void *recvbuf, int count,
%                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm )
% http://mpi.deino.net/mpi_functions/MPI_Allreduce.html

%#codegen -args {m2c_opaque_ptr_const, m2c_opaque_ptr, int32(0), MPI_Datatype, MPI_Op, MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(sptr) && coder.ismatlabthread
    if (sptr.nbytes && sptr.nbytes-sptr.offset < count*mpi_Type_size(datatype) || ...
            rptr.nbytes && rptr.nbytes-rptr.offset < count*mpi_Type_size(datatype))
        m2c_error('mpi_Allreduce:OutOfBound','Message size is larger than variable size.');
    end
end

info = coder.ceval('MPI_Allreduce', m2c_opaque_ptr_const(sptr), m2c_opaque_ptr(rptr), ...
    int32(count), MPI_Datatype(datatype), MPI_Op(op), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Allreduce failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! svar = rand(10,10);
%! rvar = zeros(size(svar));
%!
%! info = mpi_Allreduce(m2c_opaque_ptr_const(svar), m2c_opaque_ptr(rvar), ...
%!        int32(numel(rvar)), MPI_Datatype(rvar), MPI_SUM, comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));
%!
%! info = mpi_Allreduce(MPI_IN_PLACE, m2c_opaque_ptr(rvar), ...
%!        int32(numel(rvar)), MPI_Datatype(rvar), MPI_SUM, comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));
