function isn = m2c_isnull(obj)
% Determine whether a given object is a null opointer of a particular type.
%
%    isn = m2c_isnull(obj)

if ischar(obj)
    isn = isempty(obj);
elseif ~isstruct(obj)
    isn = int32(0); %#ok<NASGU>
    isn = coder.ceval('!', obj);
else
    isn = ~any(obj.data);
end
end

