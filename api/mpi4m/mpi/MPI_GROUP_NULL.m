function ret = MPI_GROUP_NULL
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Group', 'MPI_GROUP_NULL');
else
    ret = mpi_get_const('MPI_GROUP_NULL');
end
