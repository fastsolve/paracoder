function ret = MPI_COMM_SELF
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Comm', 'MPI_COMM_SELF');
else
    ret = mpi_get_const('MPI_COMM_SELF');
end
