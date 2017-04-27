function [newgroup, info, toplevel] = mpi_Group_excl(group, n, ranks)
%mpi_Group_excl   Produces a group by reordering an existing group and taking only unlisted members
%
%  [newgroup, info] = mpi_Group_excl(group, n, ranks)
%
%  group     Opaque MPI_Group object.
%  ranks     ranks of processes in group not to appear in newgroup (column vector)
%  newgroup  new group derived from above, in the order defined by ranks
%  info (int) return code
%
% SEE ALSO   mpi_Group_incl
%
% C interface:
% int MPI_Group_excl(MPI_Group group, int n, int *ranks, MPI_Group *newgroup)
% http://mpi.deino.net/mpi_functions/MPI_Group_excl.html

%#codegen -args {MPI_Group, int32(0), coder.typeof(int32(0), [inf,1])}

    
info = int32(0); %#ok<NASGU>
newgroup0 = coder.opaque('MPI_Group');

if length(ranks) < n
    m2c_error('mpi_Group_excl:OutOfBound', 'ranks array is too small.');
end

info = coder.ceval('MPI_Group_excl', MPI_Group(group), ...
    n, coder.rref(ranks), coder.wref(newgroup0));

toplevel = nargout>2;
newgroup = MPI_Group(newgroup0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Group_excl failed with error message %s\n', mpi_Error_string(info))
end
