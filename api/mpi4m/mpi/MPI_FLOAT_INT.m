function ret = MPI_FLOAT_INT
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_FLOAT_INT');
else
    ret = mpi_get_const('MPI_FLOAT_INT');
end
