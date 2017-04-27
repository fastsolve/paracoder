function [version, subversion, info, toplevel] = mpi_Get_version
%mpi_Get_version  Gets the name of the processor
%
%    [version, subversion, info] = mpi_Get_version
%
% C interface:
% int MPI_Get_version(int *version, int *subversion)
% http://mpi.deino.net/mpi_functions/MPI_Get_version.html

%#codegen -args {}


coder.inline('always');

version = int32(0);
subversion = int32(0);
info = int32(0); %#ok<NASGU>
info = coder.ceval('MPI_Get_version', coder.wref(version), coder.ref(subversion));

toplevel = nargout>3;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Get_version failed with error message %s\n', mpi_Error_string(info))
end
