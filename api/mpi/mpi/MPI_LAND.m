function ret = MPI_LAND
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Op', 'MPI_LAND');
else
    ret = mpi_get_const('MPI_LAND');
end
