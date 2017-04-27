function ret = MPI_ERRORS_RETURN
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Errhandler', 'MPI_ERRORS_RETURN');
else
    ret = mpi_get_const('MPI_ERRORS_RETURN');
end
