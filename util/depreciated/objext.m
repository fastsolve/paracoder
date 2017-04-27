function ext = objext
% Obtain the extension of Object fils.

if ispc
    ext = 'obj';
else
    ext = 'o';
end
