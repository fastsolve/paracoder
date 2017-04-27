function ret = MPI_UNSIGNED_CHAR
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_UNSIGNED_CHAR');
else
    ret = mpi_get_const('MPI_UNSIGNED_CHAR');
end
