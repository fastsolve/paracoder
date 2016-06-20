function [y, z] = structCopy_Bound_large(x, y)
% Example function for adding two vectors.

%#codegen -args {coder.typeof(struct('a', m2c_intvec(100000,1), 'b', m2c_vec(100000,1), 'c', m2c_string(10000,1)), [100000,1], [1,0]),
%#codegen coder.typeof(struct('a', m2c_intvec(1000000,1), 'b', m2c_vec(100000,1), 'c', m2c_string(10000,1)))}

z = x;
y.c = x(1).c;

%!shared x, y
%!test
%! x= repmat(struct('a', int32(1:100)', 'b', ones(100,1), 'c','abc'), [3,1]);
%! y= struct('a', int32(1:100)', 'b', ones(100,1), 'c', 'def');
%!
%! m2c -force -O3 -exe tests/structCopy_Bound_large
%! [y, z] = run_structCopy_Bound_large_exe(x, y);
%! assert(isequal(z, x) && isequal(y.c, x(1).c));
