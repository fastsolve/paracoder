function ptr = M2C_offset_ptr( ptr, offset ) %#codegen
%M2C_offset_ptr Offset a pointer by offset bytes
%   ptr = M2C_OFFSET_PTR( ptr, offset )

coder.inline('always');

ptr = coder.ceval( 'M2C_OFFSET_PTR', ptr, int32(offset));
end
