function ret = MPI_ERRCODES_IGNORE
coder.inline('always');

if ~isempty(coder.target)
    ret = coder.opaque('int *', 'MPI_ERRCODES_IGNORE');
else
    ret = mpi_get_const('MPI_ERRCODES_IGNORE');
end
