function ret = MPI_GROUP_EMPTY
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Group', 'MPI_GROUP_EMPTY');
else
    ret = mpi_get_const('MPI_GROUP_EMPTY');
end
