function buildclib( libname, opts, inpfiles, libs, exports)
% Build a shared library using cc.
% builidlib(LIBNAME, OPTS, INPFILES, LIBS, EXPORTS)
% 
% LIBNAME should contain the directory and basename, but no suffix.
% OPTS should specify options for C preprocessor or compiler (such as -I.)
% LIBS should specify options for linker (such as -Ldir -lfoo)
% INPFILES is a string with a list of C files and/or OBJ files.
% EXPORTS must be given on PC. It should be an exports file containing 
%   the list of functions to be exported (e.g., libcgns.exports).

if nargin<4; libs=''; end

if exist('mbuild', 'file') && (ispc || nargin>4)
    % Use mbuild within MATLAB if is on a PC or exports is defined.
    if nargin<=4 || isempty(exports)
        error('The argument exports must be specified.');
    end
    command = ['mbuild -output ' libname ' ' exports ' ' ...
        opts ' ' inpfiles ' ' libs];

    disp(command);
    eval(command);
    return;
end

% If mbuild is not found or the exports file is not given, then use gcc to link
if ismac
    command = ['gcc -fno-common -fPIC -Wl,-flat_namespace -dynamiclib -undefined error ' ...
        opts ' -o ' libname '.dylib ' inpfiles ' ' libs];
else
    command = ['gcc -fno-common -shared ' ...
        opts ' -o ' libname '.' dllext ' ' inpfiles ' ' libs];
end

disp(command);
system(command);
