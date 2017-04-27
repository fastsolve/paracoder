function obj = MPI_Op(varargin) %#codegen
%Map an opaque object into an MPI_Op object
%
%  MPI_Op() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  MPI_Op(obj) or MPI_Op(obj, false)
%  converts obj into an MPI_Op object.
%
%  MPI_Op(obj, 'wrap') or MPI_Op(obj, true) wraps the obj into an
%  opaque object. This should be used if the opaque object needs to
%  be returned to MATLAB.
%
% Supported operators include
%    MPI_SUM, MPI_PROD, MPI_MIN, MPI_MAX, MPI_BOR, MPI_BAND, MPI_BXOR,
%    MPI_LOR, MPI_LAND, MPI_LXOR, MPI_MAXLOC and MPI_MINLOC.

coder.inline('always');
coder.cinclude('mpi.h');

obj = m2c_opaque_obj('MPI_Op', varargin{:});
