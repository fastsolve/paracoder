function [ptr, size, info, toplevel] = mpi_Buffer_detach
%mpi_Buffer_detach	Removes an existing buffer (for use in MPI_Bsend etc)
%
%  [ptr, size, info] = mpi_Buffer_detach
%
%  info (int) return code
%
%  SEE ALSO: mpi_Buffer_attach, mpi_Bsend
%
% C interface:
%   int MPI_Buffer_detach(void *buffer, int *size)
% http://mpi.deino.net/mpi_functions/MPI_Buffer_detach.html

%#codegen -args {}


info = int32(0); %#ok<NASGU>
size = int32(0);

ptr0 = coder.opaque('void *');

info = coder.ceval('MPI_Buffer_detach', coder.wref(ptr0), coder.wref(size));

toplevel = nargout>3;
ptr = m2c_opaque_obj('void **', ptr0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Buffer_detach failed with error message %s\n', mpi_Error_string(info))
end
