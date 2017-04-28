function hdl = CuBlasHandle(varargin) %#codegen
%Map an opaque object into a cublasHandle_t object
%
%  CuBlasHandle() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  CuBlasHandle(obj) or CuBlasHandle(false) converts obj into a cublasHandle_t object.
%
%  CuBlasHandle(obj, 'wrap') or CuBlasHandle(obj, true) wraps the obj into an opaque 
%  object. This should be used if the opaque object needs to be returned to MATLAB.

coder.inline('always');
coder.cinclude('cuda4m.h');

hdl = m2c_opaque_obj('cublasHandle_t', varargin{:});
