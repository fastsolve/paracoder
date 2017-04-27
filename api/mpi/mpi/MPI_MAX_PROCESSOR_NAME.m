function ret = MPI_MAX_PROCESSOR_NAME
coder.inline('always');

if ~isempty(coder.target)
    ret = int32(0);
    ret = coder.ceval(' ', coder.opaque('int', 'MPI_MAX_PROCESSOR_NAME'));
else
    ret = mpi_get_const('MPI_MAX_PROCESSOR_NAME');
end
