function ret = MPI_MIN
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Op', 'MPI_MIN');
else
    ret = mpi_get_const('MPI_MIN');
end
