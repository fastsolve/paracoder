function [y, z] = structCopy_Fixed(x, y)
% Example function for copying structures and arrays of structures.

%#codegen -args {coder.typeof(struct('a', m2c_intvec(100), 'b', m2c_vec(100), 'c', m2c_string(3)), [3,1]),
%#codegen coder.typeof(struct('a', m2c_intvec(100), 'b', m2c_vec(100), 'c', m2c_string(3)))}

z = x;
y.c = x(1).c;

%!test
%! x= repmat(struct('a', int32(1:100)', 'b', ones(100,1), 'c','abc'), [3,1]);
%! y= struct('a', int32(1:100)', 'b', ones(100,1), 'c', 'def');
%!
%! m2c -force -O3 -mex tests/structCopy_Fixed
%! [y, z] = structCopy_Fixed(x, y);
%! assert(isequal(z, x) && isequal(y.c, x(1).c));
