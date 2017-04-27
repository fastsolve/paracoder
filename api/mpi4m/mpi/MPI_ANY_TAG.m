function n = MPI_ANY_TAG
coder.inline('always');

if ~isempty(coder.target)
    n = int32(0);
    n = coder.ceval(' ', coder.opaque('int', 'MPI_ANY_TAG'));
else
    n = m2c_opaque2struct(mpi_get_const('MPI_ANY_TAG'), int32(0));
end
