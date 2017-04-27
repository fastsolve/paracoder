function obj = MPI_Info(varargin) %#codegen
%Map an opaque object into an MPI_Info object
%
%  MPI_Info() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  MPI_Info(obj) or MPI_Info(obj, false)
%  converts obj into an MPI_Info object.
%
%  MPI_Info(obj, 'wrap') or MPI_Info(obj, true) wraps the obj into
%  an opaque object. This should be used if the opaque object needs
%  to be returned to MATLAB.

coder.inline('always');

obj = m2c_opaque_obj('MPI_Info', varargin{:});
