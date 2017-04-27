function ret = MPI_ERRORS_ARE_FATAL
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('MPI_Errhandler', 'MPI_ERRORS_ARE_FATAL');
else
    ret = mpi_get_const('MPI_ERRORS_ARE_FATAL');
end
