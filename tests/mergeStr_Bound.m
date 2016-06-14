function [str2, same] = mergeStr_Bound(str0, str1)
% Example function for returning a scalar value.

%#codegen -args {m2c_string(32, 1), m2c_string(32, 1)}

same = strcmp(str0, str1);

str2 = [str0, str1];

%!test
%! m2c -force -O3 -exe tests/mergeStr_Bound
%! [str2, same] = run_mergeStr_Bound_exe('abc', 'def');
%! assert(isequal(str2, 'abcdef') && ~same);
