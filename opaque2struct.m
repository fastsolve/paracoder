function s = opaque2struct( obj, s)
%opaque2struct Convert an opaque object to a struct
%   s = opaque2struct( obj, s)

if isstruct(s)
    names = fieldnames( s);
    
    if isscalar(s)
        s = repmat( s(1), obj.nitems, 1);
    end
    offset = 0;
    for j=1:obj.nitems
        for i=1:length(names)
            [s(j).(names{i}),len] = bytes2num( obj.data, offset, s(j).(names{i}));
            offset = offset + len;
        end
    end
else
    if isscalar(s)
        s = repmat( s(1), obj.nitems, 1);
    end
    
    offset = 0;
    for j=1:obj.nitems
        [s(j),len] = bytes2num( obj.data, offset, s(j));
        offset = offset + len;
    end
end