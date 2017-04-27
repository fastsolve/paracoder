function ret = MPI_BAND
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Op', 'MPI_BAND');
else
    ret = mpi_get_const('MPI_BAND');
end
