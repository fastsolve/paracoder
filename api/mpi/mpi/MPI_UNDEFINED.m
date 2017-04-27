function flag = MPI_UNDEFINED
coder.inline('always');

if ~isempty(coder.target)
    flag = int32(0);
    flag = coder.ceval(' ', coder.opaque('int', 'MPI_UNDEFINED'));
else
    flag = m2c_opaque2struct(mpi_get_const('MPI_UNDEFINED'), int32(0));
end
