function classid = getMxClassID(str)
switch (str)
    case 'boolean_T'
        classid = 'mxLOGICAL_CLASS';
    case {'char_T', 'char'}
        classid = 'mxCHAR_CLASS';
    case {'real64_T', 'real_T', 'double'}
        classid = 'mxDOUBLE_CLASS';
    case {'real32_T', 'float'}
        classid = 'mxSINGLE_CLASS';
    case {'int8_T', 'signed char'}
        classid = 'mxINT8_CLASS';
    case {'uint8_T', 'unsigned char'}
        classid = 'mxUINT8_CLASS';
    case {'int16_T', 'short', 'signed short'}
        classid = 'mxINT16_CLASS';
    case {'uint16_T', 'unsigned short'}
        classid = 'mxUINT16_CLASS';
    case {'int32_T', 'int', 'signed int'}
        classid = 'mxINT32_CLASS';
    case {'uint32_T', 'unsigned int'}
        classid = 'mxUINT32_CLASS';
    case {'int64_T', 'long', 'signed long'}
        classid = 'mxINT64_CLASS';
    case {'uint64_T', 'unsigned long'}
        classid = 'mxUINT64_CLASS';
    case 'struct'
        classid = 'mxSTRUCT_CLASS';
    otherwise
        error('Unknown type %s', str);
end
end
