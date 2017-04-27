function [group, info, toplevel] = mpi_Group_free(group)
%mpi_Group_free  Marks the group for deallocation
%
%  [group, info] = mpi_Group_free (group)
%
%  group   (INOUT) Group to be destroyed. It is marked for deallocation,
%      and is set to MPI_GROUP_NULL at output.
%
%  info (int) return code
%
%  SEE ALSO: mpi_Comm_group, 
%
% C interface:
%   int MPI_Group_free(MPI_Group *group)
% http://mpi.deino.net/mpi_functions/MPI_Group_free.html
% http://www.mpi-forum.org/docs/mpi-11-html/node103.html

%#codegen -args {MPI_Group}


info = int32(0); %#ok<NASGU>
t_group = MPI_Group(group);
info = coder.ceval('MPI_Group_free', coder.ref(t_group));

toplevel = nargout>2;
group = MPI_Group(t_group, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Group_free failed with error message %s\n', mpi_Error_string(info))
end
