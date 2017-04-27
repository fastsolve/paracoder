function flag = MPI_CART
coder.inline('always');

if ~isempty(coder.target)
    flag = int32(0);
    flag = coder.ceval(' ', coder.opaque('int', 'MPI_CART'));
else
    flag = m2c_opaque2struct(mpi_get_const('MPI_CART'), int32(0));
end
