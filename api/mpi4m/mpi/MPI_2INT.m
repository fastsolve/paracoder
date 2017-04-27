function ret = MPI_2INT
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Datatype', 'MPI_2INT');
else
    ret = mpi_get_const('MPI_2INT');
end
