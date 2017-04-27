function ret = MPI_LONG_LONG
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_LONG_LONG');
else
    ret = mpi_get_const('MPI_LONG_LONG');
end
