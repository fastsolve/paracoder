function type = mcuType(mType, isreal)
% Convert from a mType string to MCUDA type.

coder.inline('always');

switch mType
    case 'double'
        if isreal
            type = MCU_DOUBLE;
        else
            type = MCU_DOUBLE_COMPLEX;
        end
    case 'single'
        if isreal
            type = MCU_SINGLE;
        else
            type = MCU_COMPLEX;
        end
    case 'int8'
        type = MCU_INT8;
    case 'uint8'
        type = MCU_UINT8;
    case 'int16'
        type = MCU_INT16;
    case 'uint16'
        type = MCU_UINT16;
    case 'int32'
        type = MCU_INT32;
    case 'uint32'
        type = MCU_UINT32;
    case 'int64'
        type = MCU_INT64;
    case 'uint64'
        type = MCU_UINT64;
    otherwise
        m2c_error('mcuType:WrongType', ['Unknow supported data type ' mType '.\n']);
end
end
