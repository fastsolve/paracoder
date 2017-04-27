function ret = MPI_ARGV_NULL
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('char **', 'MPI_ARGV_NULL');
else
    ret = mpi_get_const('MPI_ARGV_NULL');
end
