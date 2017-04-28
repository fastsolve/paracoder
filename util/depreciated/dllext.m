function ext = dllext
% Obtain the extension of the DLL

if isoctave
    if exist('__octave_config_info__', 'builtin')
      % octave_config_info is depreciated in 4.2.1
      octave_config_info = @__octave_config_info__;
    end

    ext = octave_config_info('SHLEXT');
elseif ispc
    ext = 'dll';
elseif ismac
    ext = 'dylib';
else
    ext = 'so';
end
