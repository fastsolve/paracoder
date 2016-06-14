function s = m2c_opaque2struct(obj, s)
%m2c_opaque2struct Convert an opaque object to a struct.
%   s = m2c_opaque2struct(obj, s)

if isstruct(s)
    names = fieldnames(s);
    
    if isscalar(s)
        s = repmat(s(1), obj.nitems, 1);
    end
    offset = 0;
    for j=1:obj.nitems
        for i=1:length(names)
            len = sizeof(s(j).(names{i}));
            s(j).(names{i}) = typecast(obj.data(offset+1:offset+len), ...
                class(s(j).(names{i})));
            offset = offset + len;
        end
    end
else
    s = typecast(obj.data, class(s));
end

function size = sizeof(val)
if isa(val, 'double') || ...
        isa(val, 'int64') || isa(val, 'uint64')
    size = int32(8) * numel(val);
elseif isa(val, 'float') || ...
        isa(val, 'int32') || isa(val, 'uint32')
    size = int32(4) * numel(val);
elseif isa(val, 'int16') || isa(val, 'uint16')
    size = int32(2) * numel(val);
elseif isa(val, 'int8') || isa(val, 'uint8')
    size = numel(val);
else
    m2c_error('Unsupported data type');
end
