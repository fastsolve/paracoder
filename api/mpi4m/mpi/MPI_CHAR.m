function ret = MPI_CHAR
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_CHAR');
else
    ret = mpi_get_const('MPI_CHAR');
end
