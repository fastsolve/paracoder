function [info, toplevel] = mpi_Bsend(ptr, count, datatype, dest, tag, comm)
%mpi_Bsend    Basic send with user-provided buffering
%
%  info = mpi_Bsend(ptr, count, datatype, dest, tag, comm)
%
%  ptr        an m2c_opaque_ptr_const to a variable.
%  count      number of data items
%  datatype   an opaque MPI_Datatype object (see MPI_Datatype)
%  src        rank of source
%  tag        message tag
%  comm       MPI_Comm object (see MPI_Comm)
%
%  info (int) return code
%
%  SEE ALSO: mpi_Buffer_attach, mpi_Buffer_detach, mpi_Ibsend, mpi_Bsend_init
%
% C interface:
%   int MPI_Bsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, 
%                 MPI_Comm comm)
% http://mpi.deino.net/mpi_functions/MPI_Bsend.html

%#codegen -args {m2c_opaque_ptr_const, int32(0), MPI_Datatype, int32(0), int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(ptr) && coder.target('MATLAB')
    if (ptr.nbytes-ptr.offset < count*mpi_Type_size(datatype))
        m2c_error('mpi_Bsend:OutOfBound','Message size is larger than variable size.');
    end
end

info = coder.ceval('MPI_Bsend', m2c_opaque_ptr_const(ptr), int32(count), ...
    MPI_Datatype(datatype), int32(dest), int32(tag), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Bsend failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! count = int32(numel(var1));
%! var2 = zeros(10,10);
%!
%! [req,info] = mpi_Irecv(m2c_opaque_ptr(var2), count, MPI_DOUBLE, int32(0), int32(1), comm);
%! assert(info==0);
%! sz = count*8+MPI_BSEND_OVERHEAD;
%! buf = zeros(sz,1,'uint8');
%! mpi_Buffer_attach(m2c_opaque_ptr(buf), sz);
%! info = mpi_Bsend(m2c_opaque_ptr_const(var1), count, MPI_DOUBLE, int32(0), int32(1), comm);
%! mpi_Wait(req);
%! assert(info==0);
%! assert(isequal(var1, var2));
%! mpi_Buffer_detach;
