% Build script for M2C.
% The script must be run in the M2C root directory.

if ~isnewer( ['./opaque_ptr.' mexext], './src/opaque_ptr.c')
    mex src/opaque_ptr.c
end
if ~isnewer( ['./opaque_ptr_const.' mexext], './src/opaque_ptr.c')
    mex -I. src/opaque_ptr_const.c
end
if ~isnewer( ['./bytes2num.' mexext], './src/bytes2num.c')
    mex src/bytes2num.c
end
