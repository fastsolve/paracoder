function ret = MPI_OP_NULL
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Op', 'MPI_OP_NULL');
else
    ret = mpi_get_const('MPI_OP_NULL');
end
