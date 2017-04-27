function ret = MPI_BYTE
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_BYTE');
else
    ret = mpi_get_const('MPI_BYTE');
end
