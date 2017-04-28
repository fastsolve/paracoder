function varargout = m2c_local_chunk(varargin)
coder.inline('always');
[varargout{:}] = CU_local_chunk(varargin{:});
