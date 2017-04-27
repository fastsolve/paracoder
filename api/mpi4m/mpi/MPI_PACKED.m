function ret = MPI_PACKED
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_PACKED');
else
    ret = mpi_get_const('MPI_PACKED');
end
