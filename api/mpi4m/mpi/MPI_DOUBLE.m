function ret = MPI_DOUBLE
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_DOUBLE');
else
    ret = mpi_get_const('MPI_DOUBLE');
end
