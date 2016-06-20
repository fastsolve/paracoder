function z = vecAdd_Bound_large(x, y, z, m)
% Example function for adding two vectors.

%#codegen -args {m2c_vec(1000000, 1), m2c_vec(1000000, 1), m2c_vec(1000000, 1), int32(0)}

[istart, iend] = m2c_local_chunk(m);

for i=istart:iend
    z(i) = x(i) + y(i);
end

%!test
%! m2c -force -O3 -mex tests/vecAdd_Bound_large
%! z = vecAdd_Bound_large(ones(1000000,1), ones(1000000,1), rand(1000000,1), int32(1000000));
%! assert(all(z==2));

%!test
%! m2c -force -remove-emx -O3 -mex tests/vecAdd_Bound_large
%! z = vecAdd_Bound_large(ones(1000000,1), ones(1000000,1), rand(1000000,1), int32(1000000));
%! assert(all(z==2));

%!test
%! m2c -remove-emx -omp -force -O3 -mex tests/vecAdd_Bound_large
%! z = vecAdd_Bound_large(ones(1000000,1), ones(1000000,1), rand(1000000,1), int32(1000000));
%! assert(all(z==2));

%!test
%! m2c -nvcc -force -O3 -mex tests/vecAdd_Bound_large
%! z = vecAdd_Bound_large(ones(100000,1), ones(100000,1), rand(100000,1), int32(100000));
%! assert(all(z==2));

%!test
%! m2c -remove-emx -nvcc -force -O3 -mex tests/vecAdd_Bound_large
%! z = vecAdd_Bound_large(ones(100000,1), ones(100000,1), rand(100000,1), int32(100000));
%! assert(all(z==2));