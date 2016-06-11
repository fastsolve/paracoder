function [cfile_str, hfile_str, ctypes_str, success] = remove_emxArrays ...
    (cfile_str, hfile_str, ctypes_str)
%Attempt to remove all references to emxArrays.
%The emxArrays can be removed if there are no references to emxInit,
%emxFree, emxEnsureCapacity, and size information.

% TODO: Implement this function based on replace_pragmas

success = false;

%Check whether there are still calls to emxInit and emxFree
if ~isempty(regexp(cfile_str, ['(\s+(emxInit_|emxFree_)' re_basictype ')\('], 'once'))
    return;
end

%Check whether there are still calls to size.

end

