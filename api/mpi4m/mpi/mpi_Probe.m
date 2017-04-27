function [stat, info, toplevel] = mpi_Probe(source, tag, comm )
%mpi_Probe    Blocking test for a message
%
%  [stat, info] = MPI_Probe (source, tag, comm)
%
%  source is source rank or MPI_ANY_SOURCE
%  tag is tag value or MPI_ANY_TAG (integer)
%  comm is an opaque MPI_Comm object
%
%  stat is an MPI_Status object
%  info (int) return code
%
%  SEE ALSO: mpi_Wait, mpi_Test
%
% C interface:
%   int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status)
% http://mpi.deino.net/mpi_functions/MPI_Probe.html

%#codegen -args {int32(0), int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

stat0 = coder.opaque('MPI_Status');

if nargout>1
    info = coder.ceval('MPI_Probe', int32(source), int32(tag), ...
        MPI_Comm(comm), coder.wref(stat0));
else
    info = coder.ceval('MPI_Probe', int32(source), int32(tag), ...
        MPI_Comm(comm), coder.opaque('MPI_Status *', 'MPI_STATUS_IGNORE'));
end


if nargout>1
    toplevel = nargout>2;
    stat = MPI_Status(stat0, toplevel);
    
    if info && (toplevel || m2c_debug)
        m2c_error('MPI:RuntimeError', 'MPI_Probe failed with error message %s\n', mpi_Error_string(info))
    end
end

function test %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! count = int32(numel(var1));
%! var2 = zeros(10,10);
%!
%! [req0,info] = mpi_Isend(m2c_opaque_ptr_const(var1), count, MPI_DOUBLE, ...
%!      int32(0), int32(1), comm);  assert(info==0);
%! [stat, info] = mpi_Probe(int32(0), int32(1), comm);
%! [req1, info] = mpi_Irecv(m2c_opaque_ptr(var2), count, MPI_DOUBLE, ...
%!     int32(0), int32(1), comm);  assert(info==0);
%!
%! % Wait for the completion of
%! [~,req1,info] = mpi_Wait(req1);
%! mpi_Wait(req0);
%! assert (info==0);
