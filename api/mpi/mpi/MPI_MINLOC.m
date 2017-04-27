function ret = MPI_MINLOC
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Op', 'MPI_MINLOC');
else
    ret = mpi_get_const('MPI_MINLOC');
end
