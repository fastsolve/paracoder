function [newgroup, info, toplevel] = mpi_Group_intersection(group1, group2)
%mpi_Group_intersection  Makes a group from the intersection of two groups
%
%  [newgroup, info] = mpi_Group_intersection(group1, group2)
%
%  group1    first group
%  group2    second group
%  newgroup  intersection group
%
%  SEE ALSO  mpi_Group_free
%
% C interface:
% int MPI_Group_intersection(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
% http://mpi.deino.net/mpi_functions/MPI_Group_intersection.html

%#codegen -args {MPI_Group, MPI_Group}

    
info = int32(0); %#ok<NASGU>
newgroup0 = coder.opaque('MPI_Group');

info = coder.ceval('MPI_Group_intersection', MPI_Group(group1), MPI_Group(group2), ...
    coder.wref(newgroup0));

toplevel = nargout>2;
newgroup = MPI_Group(newgroup0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Group_intersection failed with error message %s\n', mpi_Error_string(info))
end
