function [datatype, info] = free_type(datatype) %#codegen
%FREE_TYPE  Mark the datatype for deallocation
%
% [datatype, info] = free_type(datatype)
%
%  datatype   (INOUT) Type to be destroyed. It is marked for deallocation,
%      and is set to MPI_DATATYPE_NULL at output.
%
% See also create_type

coder.inline('always');

[datatype, info] = mpi_Type_free(datatype);
