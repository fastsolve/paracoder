function str=dbopts

if isoctave
    str = '-Wno-unused-function -Wno-strict-aliasing';
else
    str = '-O';
end
