function [y, z] = structCopy(x, y)
% Example function for adding two vectors.

%#codegen -args {coder.typeof(struct('a', m2c_intvec, 'b', m2c_mat, 'c', m2c_string)),
%#codegen coder.typeof(struct('a', m2c_intvec, 'b', m2c_mat, 'c', m2c_string)),}

z.a = x.a;
z.b = y.b;
z.c = y.c;

%!shared x, y
%!test
%! x= struct('a', int32(1:100)', 'b', ones(100,1), 'c', 'abc');
%! y= struct('a', int32(1:100)', 'b', ones(100,1), 'c', 'def');
%!
%! m2c -force -O3 -exe tests/spVecAdd
%! [y, z] = structCopy(x, y);
%! assert(isequal(z.a, x.a) && isequal(z.b, y.b) && isequal(z.c, y.c));
