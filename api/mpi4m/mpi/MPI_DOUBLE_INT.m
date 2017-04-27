function ret = MPI_DOUBLE_INT
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_DOUBLE_INT');
else
    ret = mpi_get_const('MPI_DOUBLE_INT');
end
