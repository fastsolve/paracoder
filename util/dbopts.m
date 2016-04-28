function str=dbopts

if exist('octave_config_info', 'builtin')
    str = '-Wno-unused-function -Wno-strict-aliasing -g';
else
    str = '-O2 -DNDEBUG -g';
end
