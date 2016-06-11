function ctype = get_ctypename(basetype, nochange)
% Obtain the built-in C type name from a typedef in rtwtypes.
if nochange
    ctype = basetype;
    return; 
end
switch basetype
    case 'boolean_T'
        ctype = 'boolean_T';
    case 'char_T'
        ctype = 'char';
    case 'int8_T'
        ctype = 'signed char';
    case 'uint8_T'
        ctype = 'unsigned char';
    case 'int16_T'
        ctype = 'short';
    case 'uint16_T'
        ctype = 'unsigned short';
    case 'int32_T'
        ctype = 'int';
    case 'uint32_T'
        ctype = 'unsigned int';
    case 'int64_T'
        ctype = 'signed long';
    case 'uint64_T'
        ctype = 'unsigned long';
    case {'real_T', 'real64_T'}
        ctype = 'double';
    case 'real32_T'
        ctype = 'float';
end
end
