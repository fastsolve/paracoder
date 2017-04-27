function ret = MPI_SHORT
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_SHORT');
else
    ret = mpi_get_const('MPI_SHORT');
end
