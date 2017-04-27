function ret = MPI_PROD
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Op', 'MPI_PROD');
else
    ret = mpi_get_const('MPI_PROD');
end
