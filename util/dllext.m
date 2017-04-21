function ext = dllext
% Obtain the extension of the DLL

if exist('OCTAVE_VERSION','builtin')
    ext = octave_config_info('SHLEXT');
elseif ispc
    ext = 'dll';
elseif ismac
    ext = 'dylib';
else
    ext = 'so';
end
