function ret = MPI_LXOR
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Op', 'MPI_LXOR');
else
    ret = mpi_get_const('MPI_LXOR');
end
