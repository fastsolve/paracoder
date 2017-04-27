function obj = MPI_User_function_ptr(varargin) %#codegen
%Map an opaque object into a pointer to MPI_User_function
%
%  MPI_User_function_ptr() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  MPI_User_function_ptr(obj) or MPI_User_function_ptr(obj, false)
%  converts obj into an MPI_User_function object.
%
%  MPI_User_function_ptr(obj, 'wrap') or MPI_User_function_ptr(obj,
%  true) wraps the obj into an opaque object. This should be used
%  if the opaque object needs to be returned to MATLAB.
%

coder.inline('always');
coder.cinclude('mpi.h');

obj = m2c_opaque_obj('MPI_User_function *', varargin{:});
