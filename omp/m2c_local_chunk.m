function varargout = m2c_local_chunk(varargin)
coder.inline('always');
[varargout{:}] = OMP_local_chunk(varargin{:});
