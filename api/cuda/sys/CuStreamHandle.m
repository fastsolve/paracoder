function hdl = CuStreamHandle(varargin) %#codegen
%Map an opaque object into a custream_t object
%
%  cuStreamHandle() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  cuStreamHandle(obj) or cuStreamHandle(false) converts obj into a custream_t object.
%
%  cuStreamHandle(obj, 'wrap') or cuStreamHandle(obj, true) wraps the obj into an opaque 
%  object. This should be used if the opaque object needs to be returned to MATLAB.

coder.inline('always');
coder.cinclude('mcuda.h');

hdl = m2c_opaque_obj('cudaStream_t', varargin{:});
