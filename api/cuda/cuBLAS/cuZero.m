function val = cuZero(type)
% Obtains zero of a particular type

coder.inline('always');

if type == CUB_DOUBLE
    val = 0;
elseif type == CUB_SINGLE
    val = single(0);
elseif type == CUB_INT32
    val = int32(0);
elseif type == CUB_UINT32
    val = uint32(0);
elseif type == CUB_INT8
    val = int8(0);
elseif type == CUB_UINT8
    val = uint8(0);
elseif type == CUB_INT16
    val = int16(0);
elseif type == CUB_UINT16
    val = uint16(0);
elseif type == CUB_INT64
    val = int64(0);
elseif type == CUB_UINT64
    val = uint64(0);
elseif type == CUB_COMPLEX
    val = complex(single(0));
elseif type == CUB_DOUBLE_COMPLEX
    val = complex(0);
else
    m2c_error('cuZero:WrongType', 'Unknow data type %d.\n', type)
end
