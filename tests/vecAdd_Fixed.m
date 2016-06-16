function z = vecAdd_Fixed(x, y, z, m)
% Example function for adding two vectors.

%#codegen -args {m2c_vec(100000), m2c_vec(100000), m2c_vec(100000), m2c_const(int32(100000))}

[istart, iend] = m2c_local_chunk(m);

for i=istart:iend
    z(i) = x(i) + y(i);
end

%!test
%! m2c -force -O3 -exe tests/vecAdd_Fixed
%! z = run_vecAdd_Fixed_exe(ones(100000,1), ones(100000,1), rand(100000,1), int32(100000));
%! assert(all(z==2));

%!test 
%! m2c -force -remove-emx -O3 -exe tests/vecAdd_Fixed
%! z = run_vecAdd_Fixed_exe(ones(100000,1), ones(100000,1), rand(100000,1), int32(100000));
%! assert(all(z==2));

%!test
%! m2c -remove-emx -omp -force -O3 -exe tests/vecAdd_Fixed
%! z = run_vecAdd_Fixed_exe(ones(100000,1), ones(100000,1), rand(100000,1), int32(100000));
%! assert(all(z==2));

%!test
%! m2c -nvcc -force -O3 -exe tests/vecAdd_Fixed
%! z = run_vecAdd_Fixed_exe(ones(100000,1), ones(100000,1), rand(100000,1), int32(100000));
%! assert(all(z==2));

%!test
%! m2c -remove-emx -nvcc -force -O3 -exe tests/vecAdd_Fixed
%! z = run_vecAdd_Fixed_exe(ones(100000,1), ones(100000,1), rand(100000,1), int32(100000));
%! assert(all(z==2));