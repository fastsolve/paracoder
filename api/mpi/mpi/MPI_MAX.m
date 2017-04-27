function ret = MPI_MAX
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Op', 'MPI_MAX');
else
    ret = mpi_get_const('MPI_MAX');
end
