function obj = MPI_Errhandler(varargin) %#codegen
%Map an opaque object into an MPI_Errhandler object
%
%  MPI_Errhandler() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  MPI_Errhandler(obj) or MPI_Errhandler(obj, false)
%  converts obj into an MPI_Errhandler object.
%
%  MPI_Errhandler(obj, 'wrap') or MPI_Errhandler(obj, true) wraps
%  the obj into an opaque object. This should be used if the opaque
%  object needs to be returned to MATLAB.

coder.inline('always');
coder.cinclude('mpi.h');

obj = m2c_opaque_obj('MPI_Errhandler', varargin{:});
