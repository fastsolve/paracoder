function [ranks2, info, toplevel] = mpi_Group_translate_ranks(group1, n, ranks1, group2)
%mpi_Group_translate_ranks  Translates the ranks of processes in one group to those in another group
%
%  [ranks2, info] = mpi_Group_translate_ranks(group1, n, ranks1, group2)
%
%  group1    first group
%  n         number of ranks in ranks1 and ranks2 arrays
%  ranks1    array of zero or more valid ranks in group1
%  group2    second group
%  ranks2    array of corresponding ranks in group2, MPI_UNDEFINED when no correspondence exists.
%
%  SEE ALSO  mpi_Group_free
%
% C interface:
% int MPI_Group_translate_ranks(MPI_Group group1, int n, int *ranks1, 
%                               MPI_Group group2, int *ranks2)
% http://mpi.deino.net/mpi_functions/MPI_Group_translate_ranks.html

%#codegen -args {MPI_Group, int32(0), coder.typeof(int32(0), [inf,1]), MPI_Group}

    
info = int32(0); %#ok<NASGU>
if length(ranks1) < n
    m2c_error('MPI_Group_translate_ranks:OutOfBound', 'ranks1 array is too small.');
end

ranks2 = zeros(n, 1, 'int32');

info = coder.ceval('MPI_Group_translate_ranks', MPI_Group(group1), ...
    n, ranks1, MPI_Group(group2), ranks2);


toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Group_translate_ranks failed with error message %s\n', mpi_Error_string(info))
end
