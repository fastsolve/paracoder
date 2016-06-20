function z = spVecAdd(x, y, z)
% Example function for adding two vectors.

%#codegen -args {coder.typeof(struct('is', m2c_intvec, 'vals', m2c_vec, 'len', int32(0))),
%#codegen coder.typeof(struct('is', m2c_intvec, 'vals', m2c_vec, 'len', int32(0))),
%#codegen coder.typeof(struct('is', m2c_intvec, 'vals', m2c_vec, 'len', int32(0)))}

[istart, iend] = m2c_local_chunk(x.len);

for i=istart:iend
    z.vals(z.is(i)) = x.vals(x.is(i)) + y.vals(y.is(i));
end

%!shared x, y, z
%!test
%! x= struct('is', int32(1:100)', 'vals', ones(100,1), 'len', int32(100));
%! y= struct('is', int32(1:100)', 'vals', ones(100,1), 'len', int32(100));
%! z= struct('is', int32(1:100)', 'vals', rand(100,1), 'len', int32(100));
%! 
%! m2c -force -O3 -mex tests/spVecAdd
%! z = spVecAdd(x, y, z);
%! assert(all(z.vals==2));

% %!test
% %! m2c -remove-emx -force -O3 -mex tests/spVecAdd
% %! z = spVecAdd(x, y, z);
% %! assert(all(z.vals==2));

%!test
%! m2c -omp -force -O3 -mex tests/spVecAdd
%! z = spVecAdd(x, y, z);
%! assert(all(z.vals==2));

% %!test
% %! m2c -nvcc -force -O3 -mex tests/spVecAdd
% %! z = spVecAdd(x, y, z);
% %! assert(all(z.vals==2));

% %!test
% %! m2c -remove-emx -nvcc -force -O3 -mex tests/spVecAdd
% %! z = spVecAdd(x, y, z);
% %! assert(all(z.vals==2));