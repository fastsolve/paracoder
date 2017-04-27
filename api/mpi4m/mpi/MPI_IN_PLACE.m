function ptr = MPI_IN_PLACE
coder.inline('always');

if ~isempty(coder.target)
    ptr = coder.opaque('void *', 'MPI_IN_PLACE');
else
    obj = mpi_get_const('MPI_IN_PLACE');
    ptr = m2c_opaque_obj2ptr(obj);
end
