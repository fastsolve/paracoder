function ret = MPI_SUM
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Op', 'MPI_SUM');
else
    ret = mpi_get_const('MPI_SUM');
end
