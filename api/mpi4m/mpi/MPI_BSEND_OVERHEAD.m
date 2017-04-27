function n = MPI_BSEND_OVERHEAD
coder.inline('always');

if ~isempty(coder.target)
    n = int32(0);
    n = coder.ceval(' ', coder.opaque('int', 'MPI_BSEND_OVERHEAD'));
else
    n = m2c_opaque2struct(mpi_get_const('MPI_BSEND_OVERHEAD'), int32(0));
end
