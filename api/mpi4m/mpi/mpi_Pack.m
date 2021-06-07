function [position,info, toplevel] = mpi_Pack(inbuf, incount, datatype, outbuf, outcount, position, comm)
%mpi_Pack   Packs a datatype into contiguous memory
%
%  [position,info] = mpi_Pack(inbuf, incount, datatype, outbuf, outcount, position, comm)
%
%  Input arguments
%      inbuf      input buffer (m2c_opaque_ptr_const)
%      incount    input count
%      datatype   datatype (opaque MPI_Comm object)
%      outbuf     output buffer (m2c_opaque_ptr)
%      outcount   output count
%      position   starting position for message
%      comm       communicator (opaque MPI_Comm object)
%
%  Output arguments
%      position   new position
%      info (int) return code
%
%  SEE ALSO: mpi_Unpack, mpi_Pack_size
%
% C interface:
%   int MPI_Pack(void *inbuf, int incount, MPI_Datatype datatype,
%           void *outbuf, int outcount, int *position, MPI_Comm comm)
% http://mpi.deino.net/mpi_functions/MPI_Pack.html

%#codegen -args {m2c_opaque_ptr_const, int32(0), MPI_Datatype, m2c_opaque_ptr,
%#codegen int32(0), int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(inbuf) && coder.target('MATLAB')
    if (inbuf.nbytes-inbuf.offset < incount*mpi_Type_size(datatype))
        m2c_error('mpi_Send:OutOfBound','Input buffer is too small.');
    end
    if (outbuf.nbytes-outbuf.offset < outcount)
        m2c_error('mpi_Send:OutOfBound','Output buffer is too small.');
    end
end

info = coder.ceval('MPI_Pack', m2c_opaque_ptr_const(inbuf), int32(incount), MPI_Datatype(datatype), ...
    m2c_opaque_ptr(outbuf), int32(outcount), coder.ref(position), MPI_Comm(comm));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Pack failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! var2 = single(rand(10,10));
%!
%! outcount = mpi_Pack_size(int32(numel(var1)), MPI_DOUBLE,comm) + ...
%!            mpi_Pack_size(int32(numel(var2)), MPI_FLOAT, comm);
%! outbuf = zeros(outcount,1,'uint8');
%! pos = int32(0);
%! [pos,info] = mpi_Pack(m2c_opaque_ptr_const(var1), int32(numel(var1)), ...
%!              MPI_DOUBLE, m2c_opaque_ptr(outbuf), outcount, pos, comm);
%! [pos,info] = mpi_Pack(m2c_opaque_ptr_const(var2), int32(numel(var2)), ...
%!              MPI_FLOAT, m2c_opaque_ptr(outbuf), outcount, pos, comm);
%!
%! assert(info==0 && pos == outcount);
