function [source, dest, info, toplevel] = mpi_Cart_shift(comm, direction, displ)
%mpi_Cart_shift   Returns the shifted source and destination ranks
%                  given a shift direction and amount
%
%  [source, dest, info] = mpi_Cart_shift(comm, direction, displ)
%
%Input arguments:
%  comm       a communicator object (MPI_Comm)
%  direction  coordinate dimension of shift
%  displ      displacement (> 0: upwards shift, < 0: downwards shift)          
%Output arguments:
%  source     rank of source process
%  dest       rank of destination process
%  info       return code
%
% SEE ALSO mpi_Cart_coords
%
% C interface:
% int MPI_Cart_shift(MPI_Comm comm, int direction, int displ, int *source, int *dest)
% http://mpi.deino.net/mpi_functions/MPI_Cart_shift.html

%#codegen -args {MPI_Comm, int32(0), int32(0)}


info = int32(0); %#ok<NASGU>
source = int32(0);
dest = int32(0);

info = coder.ceval('MPI_Cart_shift', MPI_Comm(comm), ...
    direction, displ, coder.wref(source), coder.wref(dest));

toplevel = nargout>3;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Cart_shift failed with error message %s\n', mpi_Error_string(info))
end
