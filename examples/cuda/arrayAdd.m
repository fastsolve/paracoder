function z = arrayAdd(x, y, z, m)
% Example function for adding two arrays.

%#codegen -args {m2c_vec, m2c_vec, m2c_vec, int32(0)}

[istart, iend] = m2c_local_chunk(m);

for i=istart:iend
    z(i) = x(i) + y(i);
end
