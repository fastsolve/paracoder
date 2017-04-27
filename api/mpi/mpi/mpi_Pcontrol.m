function [info, toplevel] = mpi_Pcontrol(level)
%mpi_Pcontrol  Controls profiling
%
%  info =  mpi_Pcontrol(level)
%
%  level - Profiling level
%  info  - return code
%
% C interface:
% int mpi_Pcontrol(int level) 
% http://mpi.deino.net/mpi_functions/MPI_Pcontrol.html

%#codegen -args {int32(0)}

 
info = int32(0); %#ok<NASGU>

info = coder.ceval('MPI_Pcontrol', level);

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Pcontrol failed with error message %s\n', mpi_Error_string(info))
end
