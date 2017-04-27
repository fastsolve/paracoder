function str=dbopts

if exist('OCTAVE_VERSION', 'builtin')
    str = '-Wno-unused-function -Wno-strict-aliasing';
else
    str = '-O';
end
