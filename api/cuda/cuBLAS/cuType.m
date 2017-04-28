function type = cuType(mType, isreal)
% Convert from a mType string to MCUDA type.

coder.inline('always');

switch mType
    case 'double'
        if isreal
            type = CUB_DOUBLE;
        else
            type = CUB_DOUBLE_COMPLEX;
        end
    case 'single'
        if isreal
            type = CUB_SINGLE;
        else
            type = CUB_COMPLEX;
        end
    case 'int8'
        type = CUB_INT8;
    case 'uint8'
        type = CUB_UINT8;
    case 'int16'
        type = CUB_INT16;
    case 'uint16'
        type = CUB_UINT16;
    case 'int32'
        type = CUB_INT32;
    case 'uint32'
        type = CUB_UINT32;
    case 'int64'
        type = CUB_INT64;
    case 'uint64'
        type = CUB_UINT64;
    otherwise
        m2c_error('cuType:WrongType', ['Unknow supported data type ' mType '.\n']);
end
end
