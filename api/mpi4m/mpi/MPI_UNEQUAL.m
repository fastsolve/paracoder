function flag = MPI_UNEQUAL
coder.inline('always');

if ~isempty(coder.target)
    flag = int32(0);
    flag = coder.ceval(' ', coder.opaque('int', 'MPI_UNEQUAL'));
else
    flag = m2c_opaque2struct(mpi_get_const('MPI_UNEQUAL'), int32(0));
end
