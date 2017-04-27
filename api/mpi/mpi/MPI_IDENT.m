function flag = MPI_IDENT
coder.inline('always');

if ~isempty(coder.target)
    flag = int32(0);
    flag = coder.ceval(' ', coder.opaque('int', 'MPI_IDENT'));
else
    flag = m2c_opaque2struct(mpi_get_const('MPI_IDENT'), int32(0));
end
