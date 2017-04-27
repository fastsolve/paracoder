function obj = MPI_Group(varargin) %#codegen
%Map an opaque object into an MPI_Group object
%
%  MPI_Group() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  MPI_Group(obj) or MPI_Group(obj, false)
%  converts obj into an MPI_Group object.
%
%  MPI_Group(obj, 'wrap') or MPI_Group(obj, true) wraps the obj
%  into an opaque object. This should be used if the opaque object
%  needs to be returned to MATLAB.

coder.inline('always');
coder.cinclude('mpi.h');

obj = m2c_opaque_obj('MPI_Group', varargin{:});
