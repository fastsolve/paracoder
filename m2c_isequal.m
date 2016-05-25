function b = m2c_isequal(arg1, arg2) %#codegen
%Compares two input arguments and check whether they are equal
%   b = m2c_isequal(arg1, argw)
%
% In general, arg1 must not be opaque. If arg2 is opaque, then it
% the comparison will be converted into C.

coder.inline('always');

if isnumeric(arg1)
    if isnumeric(arg2) || isempty(coder.target)
        b = arg1 == arg2;
    else
        b = false;
        b = coder.ceval('M2C_ISEQUAL_NUM', arg1, arg2);
    end
elseif islogical(arg1)
    if islogical(arg2) || isempty(coder.target)
        b = arg1 == (arg2~=0);
    else
        b = false;
        b = coder.ceval('M2C_ISEQUAL_BOOL', arg1, arg2);
    end
elseif ischar(arg1)
    if ischar(arg2) || isempty(coder.target)
        b = isequal(arg1, arg2);
    else
        m2c_error('Comparison of MATLAB string with opaque C string is not supported.');
    end
elseif isstruct(arg1)
    if isstruct(arg2) || isempty(coder.target)
        b = isequal(arg1, arg2);
    else
        m2c_error('Comparison of MATLAB struct with non-struct is not supported.');
    end
else
    m2c_error('All the input variables must also be output variables.');
end
