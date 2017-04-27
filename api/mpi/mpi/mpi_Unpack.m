function [position,info, toplevel] = mpi_Unpack(inbuf, incount, position, ...
                                       outbuf, packsize, datatype, comm)
%mpi_Unpack  Unpack a buffer according to a datatype into contiguous memory
%
%  [position,info] = mpi_Unpack(inbuf, incount, position, outbuf, packsize, datatype, comm)
%
%  Input arguments
%      inbuf      input buffer (m2c_opaque_ptr_const)
%      incount    input count
%      position   starting position for message
%      outbuf     output buffer (m2c_opaque_ptr)
%      packsize   output count
%      datatype   datatype (opaque MPI_Comm object)
%      comm       communicator (opaque MPI_Comm object)
%
%  Output arguments
%      position   new position
%      info (int) return code
%
%  SEE ALSO: mpi_Pack, mpi_Pack_size
%
% C interface:
%   int MPI_Unpack(void *inbuf, int incount, int *position, 
%           void *outbuf, int packsize, MPI_Datatype datatype,MPI_Comm comm)
% http://mpi.deino.net/mpi_functions/MPI_Pack.html

%#codegen -args {m2c_opaque_ptr_const, int32(0), int32(0), m2c_opaque_ptr, 
%#codegen int32(0), MPI_Datatype, MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(inbuf) && coder.ismatlabthread
    if (inbuf.nbytes-inbuf.offset < incount)
        m2c_error('mpi_Send:OutOfBound','Input buffer is too small.');
    end
    if (outbuf.nbytes-outbuf.offset < packsize*mpi_Type_size(datatype))
        m2c_error('mpi_Send:OutOfBound','Output buffer is too small.');
    end
end

info = coder.ceval('MPI_Unpack', m2c_opaque_ptr_const(inbuf), int32(incount), coder.ref(position), ...
    m2c_opaque_ptr(outbuf), int32(packsize), MPI_Datatype(datatype), MPI_Comm(comm));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Unpack failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! var2 = single(rand(10,10));
%! 
%! packsize = mpi_Pack_size(int32(numel(var1)), MPI_DOUBLE,comm) + ...
%!            mpi_Pack_size(int32(numel(var2)), MPI_FLOAT, comm);
%! packbuf = zeros(packsize,1,'uint8');
%! pos = int32(0);
%! [pos,info] = mpi_Pack(m2c_opaque_ptr_const(var1), int32(numel(var1)), ...
%!              MPI_DOUBLE, m2c_opaque_ptr(packbuf), packsize, pos, comm);
%! [pos,info] = mpi_Pack(m2c_opaque_ptr_const(var2), int32(numel(var2)), ...
%!              MPI_FLOAT, m2c_opaque_ptr(packbuf), packsize, pos, comm);
%!
%! assert(info==0 && pos == packsize);

%! packsize = mpi_Pack_size(int32(numel(var1)), MPI_DOUBLE,comm) + ...
%!            mpi_Pack_size(int32(numel(var2)), MPI_FLOAT, comm);
%! packbuf = zeros(packsize,1,'uint8');
%! pos = int32(0);
%! [pos,info] = mpi_Unpack(m2c_opaque_ptr_const(packbuf), packsize, pos, ...
%!              m2c_opaque_ptr(var1), int32(numel(var1)), MPI_DOUBLE, comm);
%! assert(info==0 && pos == mpi_Pack_size(int32(numel(var1)), MPI_DOUBLE,comm));
%! [pos,info] = mpi_Unpack(m2c_opaque_ptr_const(packbuf), packsize, pos, ...
%!              m2c_opaque_ptr(var2), int32(numel(var2)), MPI_FLOAT, comm);
%! assert(info==0 && pos == packsize);
