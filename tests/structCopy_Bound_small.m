function [y, z] = structCopy_Bound_small(x, y)
% Example function for copying structures and arrays of structures.

%#codegen -args {coder.typeof(struct('a', m2c_intvec(100,1), 'b', m2c_vec(100,1),'c', m2c_string(10,1)), [3,1], [1,0]),
%#codegen coder.typeof(struct('a', m2c_intvec(100,1), 'b', m2c_vec(100,1), 'c', m2c_string(10,1)))}

z = x;
y.c = x(1).c;

%!test
%! x= repmat(struct('a', int32(1:100)', 'b', ones(100,1), 'c', 'abc'), 3,1);
%! y= struct('a', int32(1:100)', 'b', ones(100,1), 'c', 'def');
%!
%! m2c -force -O3 -mex tests/structCopy_Bound_small
%! [y, z] = structCopy_Bound_small(x, y);
%! assert(isequal(z, x) && isequal(y.c, x(1).c));
