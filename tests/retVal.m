function [m, n] = retVal(m)
% Example function for testing return value

%#codegen -args {int32(0)}

n = int32(m~=1);

%!test
%! m2c -force -O3 -mex tests/retVal
%! [m, n] = retVal(int32(10));
%! assert(m==10 && n==1);

%!test
%! [m, n] = retVal(int32(1));
%! assert(m==1 && n==0);