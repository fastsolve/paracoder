function classid = getMatlabClass(str)
switch (str)
    case 'boolean_T'
        classid = 'logical';
    case 'char_T'
        classid = 'char';
    case {'real64_T', 'real_T'}
        classid = 'double';
    case 'real32_T'
        classid = 'single';
    case 'int8_T'
        classid = 'int8';
    case 'uint8_T'
        classid = 'uint8';
    case 'int16_T'
        classid = 'int16';
    case 'uint16_T'
        classid = 'uint16';
    case 'int32_T'
        classid = 'int32';
    case 'uint32_T'
        classid = 'uint32';
    case 'int64_T'
        classid = 'int64';
    case 'uint64_T'
        classid = 'uint64';
    case 'struct'
        classid = 'struct';
    otherwise
        error('Unknown type %s', str);
end
end
