function z = vecAdd_Bound_small(x, y, z, m)
% Example function for adding two vectors.

%#codegen -args {m2c_vec(100, 1), m2c_vec(100, 1), m2c_vec(100, 1), int32(0)}

[istart, iend] = m2c_local_chunk(m);

for i=istart:iend
    z(i) = x(i) + y(i);
end

%!test
%! m2c -force -O3 -mex tests/vecAdd_Bound_small
%! z = vecAdd_Bound_small(ones(100,1), ones(100,1), rand(100,1), int32(100));
%! assert(all(z==2));

%!test
%! m2c -force -remove-emx -O3 -mex tests/vecAdd_Bound_small
%! z = vecAdd_Bound_small(ones(100,1), ones(100,1), rand(100,1), int32(100));
%! assert(all(z==2));

%!test
%! m2c -remove-emx -omp -force -O3 -mex tests/vecAdd_Bound_small
%! z = vecAdd_Bound_small(ones(100,1), ones(100,1), rand(100,1), int32(100));
%! assert(all(z==2));

%!test
%! m2c -nvcc -force -O3 -mex tests/vecAdd_Bound_small
%! z = vecAdd_Bound_small(ones(100,1), ones(100,1), rand(100,1), int32(100));
%! assert(all(z==2));

%!test
%! m2c -remove-emx -nvcc -force -O3 -mex tests/vecAdd_Bound_small
%! z = vecAdd_Bound_small(ones(100,1), ones(100,1), rand(100,1), int32(100));
%! assert(all(z==2));
