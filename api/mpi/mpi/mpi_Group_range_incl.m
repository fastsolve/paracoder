function [newgroup, info, toplevel] = mpi_Group_range_incl(group, n, ranges)
%mpi_Group_range_incl   Creates a new group from ranges of ranks in an existing group
%
%  [newgroup, info] = mpi_Group_range_incl(group, n, ranges)
%
%  group     Opaque MPI_Group object.
%  n         number of integer triplets in array ranges
%  ranges    a one-dimensional array of integer triplets, of the form
%            (first rank, last rank, stride) indicating ranks in group
%            or processes to be included in newgroup.
%  newgroup  new group derived from above, preserving the order in group
%  info (int) return code
%
% SEE ALSO   mpi_Group_range_incl
%
% C interface:
% int MPI_Group_range_incl(MPI_Group group, int n, int *ranges, MPI_Group *newgroup)
% http://mpi.deino.net/mpi_functions/MPI_Group_range_incl.html

%#codegen -args {MPI_Group, int32(0), coder.typeof(int32(0), [inf,1])}

coder.cinclude('mmpi.h');
    
info = int32(0); %#ok<NASGU>
newgroup0 = coder.opaque('MPI_Group');

if length(ranges) < 3*n
    m2c_error('mpi_Group_range_incl:OutOfBound', 'ranges array is too small.');
end

info = coder.ceval('MPI_Group_range_incl', MPI_Group(group), ...
    n, m2c_opaque_ptr_const(ranges, 'int32_triple *'), coder.wref(newgroup0));

toplevel = nargout>2;
newgroup = MPI_Group(newgroup0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Group_range_incl failed with error message %s\n', mpi_Error_string(info))
end
