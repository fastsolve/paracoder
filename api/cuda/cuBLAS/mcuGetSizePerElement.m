function sizepe = cuGetSizePerElement(type)
% Obtains the number of bypets for each data type.

coder.inline('always');

if type == MCU_DOUBLE || type == MCU_COMPLEX || type == MCU_INT64 || type == MCU_UINT64
    sizepe = int32(8);
elseif type == MCU_SINGLE || type == MCU_INT32 || type == MCU_UINT32
    sizepe = int32(4);
elseif type == MCU_INT16 || type == MCU_UINT16
    sizepe = int32(2);
elseif type == MCU_INT8 || type == MCU_UINT8
    sizepe = int32(1);
elseif type == MCU_DOUBLE_COMPLEX
    sizepe = int32(16);
else
    m2c_error('cuGetSizePerElement:WrongType', 'Unknow data type %d.\n', type);
    sizepe = int32(0);
end
