function [str2, same] = mergeStr(str0, str1)
% Example function for merging two strings and returning a scalar value.

%#codegen -args {m2c_string, m2c_string}

same = strcmp(str0, str1);

str2 = [str0, str1];

%!test
%! m2c -force -O3 -mex tests/mergeStr
%! [str2, same] = mergeStr('abc', 'def');
%! assert(isequal(str2, 'abcdef') && ~same);
