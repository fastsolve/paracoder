function str=dbopts

if exist('octave_config_info', 'builtin')
    str = '-Wno-unused-function -Wno-strict-aliasing';
else
    str = '-O -g';
end
