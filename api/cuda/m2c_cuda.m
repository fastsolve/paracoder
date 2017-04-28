function flag = m2c_cuda
%Flag indicating whether m2c_cuda is on.
%It is always false within MATLAB. For m2c, it can be turned on with the
%-cuda option. It can also be turned on or off by the compiler flag
%-DM2C_CUDA=1  DM2C_CUDA=0, respectively.

coder.inline('always');
coder.cinclude('cuda4m.h');

if isempty(coder.target)
    flag = false;
else
    flag = int32(1); %#ok<NASGU>
    flag = coder.ceval(' ', coder.opaque('int', 'M2C_CUDA'));
end
end
