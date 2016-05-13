function argout = csize_t(argin) %#codegen
%CSIZE_T An integer type corresponding to size_t in C.

coder.inline('always');
if isempty(coder.target)
    if ~isempty(strfind(computer,'64')); argout = uint64(argin);
    else argout = uint32(argin); end
else
    argout = coder.opaque('size_t', argin);
end

end
