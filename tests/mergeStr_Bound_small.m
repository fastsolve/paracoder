function [str2, same] = mergeStr_Bound_small(str0, str1)
% Example function for merging two strings and returning a scalar value.

%#codegen -args {m2c_string(32, 1), m2c_string(32, 1)}

same = strcmp(str0, str1);

str2 = [str0, str1];

%!test
%! m2c -force -O3 -mex tests/mergeStr_Bound_small
%! [str2, same] = mergeStr_Bound_small('abc', 'def');
%! assert(isequal(str2, 'abcdef') && ~same);
