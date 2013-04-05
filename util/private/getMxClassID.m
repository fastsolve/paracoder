function classid = getMxClassID( str)
switch ( str)
    case 'boolean_T'
        classid = 'mxLOGICAL_CLASS';
    case 'char_T'
        classid = 'mxCHAR_CLASS';
    case {'real64_T', 'real_T'}
        classid = 'mxDOUBLE_CLASS';
    case 'real32_T'
        classid = 'mxSINGLE_CLASS';
    case 'int8_T'
        classid = 'mxINT8_CLASS';
    case 'uint8_T'
        classid = 'mxUINT8_CLASS';
    case 'int16_T'
        classid = 'mxINT16_CLASS';
    case 'uint16_T'
        classid = 'mxUINT16_CLASS';
    case 'int32_T'
        classid = 'mxINT32_CLASS';
    case 'uint32_T'
        classid = 'mxUINT32_CLASS';
    case 'int64_T'
        classid = 'mxINT64_CLASS';
    case 'uint64_T'
        classid = 'mxUINT64_CLASS';
    case 'struct'
        classid = 'mxSTRUCT_CLASS';
    otherwise
        error('Unknown type %s', str);
end
end
