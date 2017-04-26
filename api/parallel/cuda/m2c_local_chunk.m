function varargout = m2c_local_chunk(varargin)
coder.inline('always');
[varargout{:}] = MCU_local_chunk(varargin{:});
