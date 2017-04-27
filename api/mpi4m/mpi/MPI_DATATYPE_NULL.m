function ret = MPI_DATATYPE_NULL
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_DATATYPE_NULL');
else
    ret = mpi_get_const('MPI_DATATYPE_NULL');
end
