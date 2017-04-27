function ret = MPI_SHORT_INT
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_SHORT_INT');
else
    ret = mpi_get_const('MPI_SHORT_INT');
end
