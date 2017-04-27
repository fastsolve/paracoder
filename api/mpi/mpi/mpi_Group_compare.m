function [result, info, toplevel] = mpi_Group_compare(group1, group2)
%mpi_Group_compare  Compares two groups
%
%  [result, info] = mpi_Group_compare(group1, group2)
%
%  group1    A group
%  group2    Another group
%  result     integer which is MPI_IDENT if the order and members of the
%            two groups are the same, MPI_SIMILAR if only the members
%            are the same, and MPI_UNEQUAL otherwise
%
% C interface:
% int MPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result)
% http://mpi.deino.net/mpi_functions/MPI_Group_compare.html

%#codegen -args {MPI_Group, MPI_Group}

    
info = int32(0); %#ok<NASGU>
result = int32(0);
info = coder.ceval('MPI_Group_compare', MPI_Group(group1), MPI_Group(group2), ...
    coder.wref(result));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Group_compare failed with error message %s\n', mpi_Error_string(info))
end
