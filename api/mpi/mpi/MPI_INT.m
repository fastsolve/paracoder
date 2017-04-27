function ret = MPI_INT
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_INT');
else
    ret = mpi_get_const('MPI_INT');
end
