function ret = MPI_INFO_NULL
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Info', 'MPI_INFO_NULL');
else
    ret = mpi_get_const('MPI_INFO_NULL');
end
