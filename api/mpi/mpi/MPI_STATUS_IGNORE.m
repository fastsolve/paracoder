function ret = MPI_STATUS_IGNORE
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Status *', 'MPI_STATUS_IGNORE');
else
    ret = mpi_get_const('MPI_STATUS_IGNORE');
end
