function ptr = m2c_opaque_obj2ptr(obj, offset) %#codegen
%Converts m2c_opaque_obj to m2c_opaque_ptr.
%
%  m2c_opaque_obj2ptr(obj) simply returns a m2c_opaque_ptr_type
%  object from a m2c_opaque_type object. In the generated C code,
%
%  m2c_opaque_obj2ptr(obj, offset) assumes the obj is a m2c_opaque_array,
%  and it retrieves the pointer obj(1+offset) (in MATLAB indexing convention).
%
% See also m2c_opaque_array, m2c_opaque_ptr

coder.inline('always');

narginchk(1,2);

if nargin<2; offset = int32(0); end

ptr = struct('data', uint64(0), 'type', obj.type, ...
    'nbytes', int32(0), 'offset', int32(offset));

if isempty(coder.target)
    ptr.data = typecast(obj.data, class(uint64(0)));
else
    ptr.data = m2c_castdata('size_t', obj.data);
end
