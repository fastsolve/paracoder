function [flag, stat, info, toplevel] = mpi_Iprobe(source, tag, comm )
%mpi_Iprobe    Non-blocking test for a message
%
%  [flag, stat, info] = MPI_Iprobe (source, tag, comm)
%
%  source is source rank or MPI_ANY_SOURCE
%  tag is tag value or MPI_ANY_TAG (integer)
%  comm is an opaque MPI_Comm object
%
% flag True if a message with the specified source, tag, and communicator is available (logical)
%  stat is an MPI_Status object
%  info (int) return code
%
%  SEE ALSO: mpi_Wait, mpi_Test
%
% C interface:
%   int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag, 
%           MPI_Status *status)
% http://mpi.deino.net/mpi_functions/MPI_Iprobe.html

%#codegen -args {int32(0), int32(0), MPI_Comm}


flag = int32(1);
info = int32(0); %#ok<NASGU>

stat0 = coder.opaque('MPI_Status');

if nargout>1
    info = coder.ceval('MPI_Iprobe', int32(source), int32(tag), ...
        MPI_Comm(comm), coder.wref(flag), coder.wref(stat0));
else
    info = coder.ceval('MPI_Iprobe', int32(source), int32(tag), ...
        MPI_Comm(comm), coder.wref(flag), coder.opaque('MPI_Status *', 'MPI_STATUS_IGNORE'));
end

if nargout>1
    toplevel = nargout>3;
    stat = MPI_Status(stat0, toplevel);
    
    if info && (toplevel || m2c_debug)
        m2c_error('MPI:RuntimeError', 'MPI_Iprobe failed with error message %s\n', mpi_Error_string(info))
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
%! [req0, info] = mpi_Isend(m2c_opaque_ptr_const(var1), count, MPI_DOUBLE, ...
%!      int32(0), int32(1), comm);  assert(info==0);
%! [flag, stat, info] = mpi_Iprobe(int32(0), int32(1), comm);
%! assert (flag==1 && info==0);
%! [req1, info] = mpi_Irecv(m2c_opaque_ptr(var2), count, MPI_DOUBLE, ...
%!     int32(0), int32(1), comm);  assert(info==0);

%! % Wait for the completion of
%! mpi_Wait(req0);
%! [~,req1,info] = mpi_Wait(req1);
%! assert (info==0);
