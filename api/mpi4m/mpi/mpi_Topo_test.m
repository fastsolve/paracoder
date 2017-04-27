function [topo_type, info, toplevel] = mpi_Topo_test(comm)
%mpi_Topo_test  Determines the type of topology (if any) associated with a communicator
%
%  [topo_type, info] =  mpi_Topo_test (comm)
%
%  comm       Opaque MPI_Comm object.
%
% Output arguments: 
%  topo_type  - topology type of communicator comm (int32)
%  info       - return code (int32)
%
%  SEE ALSO: mpi_Cart_create, mpi_Graph_create
%
% C interface:
% int mpi_Topo_test(MPI_Comm comm, int *topo_type ) 
% http://mpi.deino.net/mpi_functions/MPI_Topo_test.html

%#codegen -args {MPI_Comm}

 
info = int32(0); %#ok<NASGU>
topo_type = int32(0);

info = coder.ceval('MPI_Topo_test', MPI_Comm(comm), coder.wref(topo_type));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Topo_test failed with error message %s\n', mpi_Error_string(info))
end
