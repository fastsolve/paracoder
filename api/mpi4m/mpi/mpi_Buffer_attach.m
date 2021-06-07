function [info, toplevel] = mpi_Buffer_attach (ptr, size)
%mpi_Buffer_attach  Attaches a user-provided buffer for sending
%
%  info = mpi_Buffer_attach (ptr, size)
%
%  buf user-provided MATLAB variable to be used as message buffer.
%	The size given should be the sum of the sizes of all outstanding Bsends
%	that you intend to have, plus a few bytes for each  Bsend that you do.
%	Compute size using MPI_Pack_size(1st)+...+(nth)+ n*MPI_BSEND_OVERHEAD
%
%  info (int) return code
%
%  SEE ALSO: mpi_Buffer_detach, mpi_Bsend
%
% C interface:
%   int MPI_Buffer_attach(void *buf, int size)
% http://mpi.deino.net/mpi_functions/MPI_Buffer_attach.html

%#codegen -args {m2c_opaque_ptr, int32(0)}

info = int32(0); %#ok<NASGU>

if isstruct(ptr) && coder.target('MATLAB')
    if (ptr.nbytes-ptr.offset < size)
        m2c_error('mpi_Buffer_attach:OutOfBound','Message size is larger than variable size.');
    end
end

info = coder.ceval('MPI_Buffer_attach', m2c_opaque_ptr(ptr), int32(size));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Buffer_attach failed with error message %s\n', mpi_Error_string(info))
end
