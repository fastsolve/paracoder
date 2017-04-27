function flag = MPI_CONGRUENT
coder.inline('always');

if ~isempty(coder.target)
    flag = int32(0);
    flag = coder.ceval(' ', coder.opaque('int', 'MPI_CONGRUENT'));
else
    flag = m2c_opaque2struct(mpi_get_const('MPI_CONGRUENT'), int32(0));
end
