function flag = is64 %codegen
%IS64 Whether the platform is 64-bit

coder.inline('always');

if isempty(coder.target)
    flag = int32(~isempty( strfind(computer,'64')));
else
    sizeptr = int32(0);
    sizeptr = coder.ceval('sizeof', coder.rref(sizeptr));
    flag = int32(sizeptr==8);
end

end
