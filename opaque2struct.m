function s = opaque2struct(obj, s)
%opaque2struct Convert an opaque object to a struct.
%   s = opaque2struct(obj, s)

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

function size = sizeof(val) %#codegen

if strcmp(class(val), 'double') || ...
        strcmp(class(val), 'int64') || strcmp(class(val), 'uint64')
    size = int32(8) * numel(val);
elseif strcmp(class(val), 'float') || ...
        strcmp(class(val), 'int32') || strcmp(class(val), 'uint32')
    size = int32(4) * numel(val);
elseif strcmp(class(val), 'int16') || strcmp(class(val), 'uint16')
    size = int32(2) * numel(val);
elseif strcmp(class(val), 'int8') || strcmp(class(val), 'uint8')
    size = numel(val);
else
    msg_error('Unsupported data type');
end
