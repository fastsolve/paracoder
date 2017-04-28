function sizepe = cuGetSizePerElement(type)
% Obtains the number of bypets for each data type.

coder.inline('always');

if type == CUB_DOUBLE || type == CUB_COMPLEX || type == CUB_INT64 || type == CUB_UINT64
    sizepe = int32(8);
elseif type == CUB_SINGLE || type == CUB_INT32 || type == CUB_UINT32
    sizepe = int32(4);
elseif type == CUB_INT16 || type == CUB_UINT16
    sizepe = int32(2);
elseif type == CUB_INT8 || type == CUB_UINT8
    sizepe = int32(1);
elseif type == CUB_DOUBLE_COMPLEX
    sizepe = int32(16);
else
    m2c_error('cuGetSizePerElement:WrongType', 'Unknow data type %d.\n', type);
    sizepe = int32(0);
end
