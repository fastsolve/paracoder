function z = vecAdd_Bound(x, y, z, m)
% Example function for adding two vectors.

%#codegen -args {m2c_vec(100, 1), m2c_vec(100, 1), m2c_vec(100, 1), int32(0)}

[istart, iend] = m2c_local_chunk(m);

for i=istart:iend
    z(i) = x(i) + y(i);
end

%!test
%! m2c -force -O3 -exe tests/vecAdd_Bound
%! z = run_vecAdd_Bound_exe(ones(100,1), ones(100,1), rand(100,1), int32(100));
%! assert(all(z==2));
