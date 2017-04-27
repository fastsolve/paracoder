function ret = MPI_MAXLOC
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Op', 'MPI_MAXLOC');
else
    ret = mpi_get_const('MPI_MAXLOC');
end
