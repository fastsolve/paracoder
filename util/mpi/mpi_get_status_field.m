function output = mpi_get_status_field(stat, field)
%Obtains a particular field of in MPI_Status
%   output = mpi_get_status_field(status, field)
%
% The supported fields include MPI_SOURCE, MPI_TAG, or MPI_ERROR

%#codegen -args {MPI_Status, coder.typeof(char(0), [1, inf])}
coder.cinclude('mpi.h');

t_stat = MPI_Status(stat);
stat_ptr = coder.opaque('const MPI_Status *'); %#ok<NASGU>
stat_ptr = coder.ceval(' ', coder.rref(t_stat));

if strcmp(field, 'source') || strcmp(field, 'MPI_SOURCE')
    output = m2c_get_cstruct_field(stat_ptr, 'MPI_SOURCE', 'int32');
elseif strcmp(field, 'tag') || strcmp(field, 'MPI_TAG')
    output = m2c_get_cstruct_field(stat_ptr, 'MPI_TAG', 'int32');
elseif strcmp(field, 'error') || strcmp(field, 'MPI_ERROR')
    output = m2c_get_cstruct_field(stat_ptr, 'MPI_ERROR', 'int32');
else
    m2c_error('mpi_get_status_field:UnknownField', ...
        'Unknown field name %s\n', [field, char(0)]);
    output = int32(-1);
end
m2c_rref(t_stat);
