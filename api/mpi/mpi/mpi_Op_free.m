function [op, info, toplevel] = mpi_Op_free(op)
%mpi_Op_free    Frees a user-defined combination function handle
%
%  [op, info] = mpi_Op_free(op)
%
% Input argument:
%  op 	    operation (MPI_Op). 
%
% Output argument:
%  op 	    operation (MPI_Op). 
%  info     return code (int32)
%
%  SEE ALSO: mpi_Op_create
%
% C interface:
%   int MPI_Op_free(MPI_Op *op)
% http://mpi.deino.net/mpi_functions/MPI_Op_free.html

%#codegen -args {MPI_Op}


info = int32(0); %#ok<NASGU>
t_op = MPI_Op(op);
info = coder.ceval('MPI_Op_free', coder.ref(t_op));

toplevel = nargout>2;
op = MPI_Request(t_op, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Op_free failed with error message %s\n', mpi_Error_string(info))
end
