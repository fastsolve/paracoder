function ret = MPI_BXOR
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Op', 'MPI_BXOR');
else
    ret = mpi_get_const('MPI_BXOR');
end
