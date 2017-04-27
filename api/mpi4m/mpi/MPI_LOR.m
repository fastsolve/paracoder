function ret = MPI_LOR
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Op', 'MPI_LOR');
else
    ret = mpi_get_const('MPI_LOR');
end
