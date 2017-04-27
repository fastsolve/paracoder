function ret = MPI_BOR
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Op', 'MPI_BOR');
else
    ret = mpi_get_const('MPI_BOR');
end
