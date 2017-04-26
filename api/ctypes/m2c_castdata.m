function obj = m2c_castdata(type, data) %#codegen
%CASTDATA  cast data into an opaque object
%    obj = m2c_castdata(type, data)

obj = coder.opaque(type);
obj = coder.ceval(['*(' type '*)'], coder.rref(data));
