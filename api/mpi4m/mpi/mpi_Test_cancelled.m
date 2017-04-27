function [flag, info, toplevel] = mpi_Test_cancelled(stat)
%mpi_Test_cancelled  Tests to see if a request was cancelled
%
%  [flag, info] = mpi_Test_cancelled(stat)
%
%  stat: MPI_Status object 
%
%  flag (int): true if the request was cancelled, false otherwise
%  info (int): return code
%
%  SEE ALSO: mpi_Cancel, mpi_Test, mpi_Testall, mpi_Testany,
%      mpi_Testsome, mpi_Wait, mpi_Waitall, mpi_Waitany, mpi_Waitsome
%
% C interface:
%   int MPI_Test_cancelled(MPI_Status *status, int *flag)
% http://mpi.deino.net/mpi_functions/MPI_Test_cancelled.html

%#codegen -args {MPI_Status}

flag = int32(0);
info = int32(0); %#ok<NASGU>

t_stat = MPI_Status(stat);
info = coder.ceval('MPI_Test_cancelled', coder.ref(t_stat), coder.wref(flag));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Test_cancelled failed with error message %s\n', mpi_Error_string(info))
end
