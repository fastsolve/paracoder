function [str2, same] = mergeStr_Bound_large(str0, str1)
% Example function for merging two strings and returning a scalar value.

%#codegen -args {m2c_string(100000, 1), m2c_string(100000, 1)}

same = strcmp(str0, str1);

str2 = [str0, str1];

%!test
%! m2c -force -O3 -exe tests/mergeStr_Bound_large
%! str0 = repmat('a', 1, 100000); str1 = repmat('b', 1, 100000);
%! [str2, same] = run_mergeStr_Bound_large_exe(str0, str1);
%! assert(isequal(str2, [str0 str1]) && ~same);
