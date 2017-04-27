function ret = MPI_FLOAT
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_FLOAT');
else
    ret = mpi_get_const('MPI_FLOAT');
end
