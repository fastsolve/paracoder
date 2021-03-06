function flag = MPI_SIMILAR
coder.inline('always');

if ~isempty(coder.target)
    flag = int32(0);
    flag = coder.ceval(' ', coder.opaque('int', 'MPI_SIMILAR'));
else
    flag = m2c_opaque2struct(mpi_get_const('MPI_SIMILAR'), int32(0));
end
