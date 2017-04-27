function req = MPI_Request(varargin) %#codegen
%Map an opaque object into an MPI_Request object
%
%  MPI_Request() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  MPI_Request(obj) converts obj into an MPI_Request object.
%
%  MPI_Request(obj, 'wrap') wraps the obj into an opaque object. This should be
%  used if the opaque object needs to be returned to MATLAB.

coder.inline('always');
coder.cinclude('mpi.h');

req = m2c_opaque_obj('MPI_Request', varargin{:});
