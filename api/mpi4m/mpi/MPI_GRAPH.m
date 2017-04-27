function flag = MPI_GRAPH
coder.inline('always');

if ~isempty(coder.target)
    flag = int32(0);
    flag = coder.ceval(' ', coder.opaque('int', 'MPI_GRAPH'));
else
    flag = m2c_opaque2struct(mpi_get_const('MPI_GRAPH'), int32(0));
end
