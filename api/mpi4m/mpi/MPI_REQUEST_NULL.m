function ret = MPI_REQUEST_NULL
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Requst', 'MPI_REQUEST_NULL');
else
    ret = mpi_get_const('MPI_REQUEST_NULL');
end
