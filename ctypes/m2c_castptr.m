function obj = m2c_castptr(type, data) %#codegen
%CASTDATA  cast data into an opaque object
%    obj = castdata(type, data)

obj = coder.opaque(type);
obj = coder.ceval(['*(' type '*)'], coder.rref(data));
