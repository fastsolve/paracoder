function [op, info, toplevel] = mpi_Op_create(func, commute)
%mpi_Op_create  Creates a user-defined combination function handle
%
%  [op, info] = mpi_Op_create(func, commute)
%
% Input arguments:
%  func      A user defined function (MPI_User_function)
%  commute   true if commutative;  false otherwise (int32)
% Output arguments:
%  op        A new operation (MPI_Op)
%  info      return code (int32)
%
% SEE ALSO mpi_Op_free
%
% C interface:
% int MPI_Op_create(MPI_User_function *function, int commute, MPI_Op *op)
% http://mpi.deino.net/mpi_functions/MPI_Op_create.html

%#codegen -args {MPI_User_function_ptr, int32(0)}

info = int32(0); %#ok<NASGU>


t_op = coder.opaque('MPI_Op');
t_func = MPI_User_function_ptr(func);
info = coder.ceval('MPI_Op_create', t_func, commute, coder.wref(t_op));

toplevel = nargout>2;
op = MPI_Request(t_op, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Op_create failed with error message %s\n', mpi_Error_string(info))
end
