function retval = mexext_matlab
% Return the extension of mex files for MATLAB

if ~isoctave
    retval = mexext
elseif contains(computer, 'linux')
    retval = 'mexa64'
elseif contains(computer, 'darwin')
    retval = 'mexmaci64'
else
    retval = 'mexw64'
end
