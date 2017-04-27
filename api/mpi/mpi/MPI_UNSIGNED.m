function ret = MPI_UNSIGNED
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_UNSIGNED');
else
    ret = mpi_get_const('MPI_UNSIGNED');
end
