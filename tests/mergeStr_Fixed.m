function [str2, same] = mergeStr_Fixed(str0, str1)
% Example function for returning a scalar value.

%#codegen -args {m2c_string(3), m2c_string(1)}

if strcmp(str0, str1)
    same = '1';
else
    same = '0';
end

str2 = [str0, str1];

%!test
%! m2c -force -O3 -exe tests/mergeStr_Fixed
%! [str2, same] = run_mergeStr_Fixed_exe('abc', 'd');
%! assert(isequal(str2, 'abcd') && same=='0');
