function n = mpi_get_sizeof(typename)
%mpi_get_sizeof Obtain the size of a given typename.
%   n = mpi_get_sizeof(typename)
%
% The supported typename include: MPI_DOUBLE, MPI_FLOAT, MPI_INT, MPI_UNSIGNED, 
%   MPI_SHORT, MPI_UNSIGNED_SHORT, MPI_CHAR, MPI_UNSIGNED_CHAR (or
%   MPI_BYTE), MPI_2INT, MPI_Comm, MPI_Request, MPI_Status,
%   MPI_Datatype, MPI_Op, and MPI_Aint.

%#codegen -args {coder.typeof(char(0),[1,inf])}
coder.cinclude('mpi.h');

assert(strncmp(typename, 'MPI_', 4));

n = int32(0);

%% MPI_Datatype
if strcmp(typename(5:end), 'Request')
    n = coder.ceval('sizeof', coder.opaque('MPI_Request',  'MPI_Request'));
    return;
end
if strcmp(typename(5:end), 'Status')
    n = coder.ceval('sizeof', coder.opaque('MPI_Status',  'MPI_Status'));
    return;
end
if strcmp(typename(5:end), 'Aint')
    n = coder.ceval('sizeof', coder.opaque('MPI_Aint',  'MPI_Aint'));
    return;
end
if strcmp(typename(5:end), 'Op')
    n = coder.ceval('sizeof', coder.opaque('MPI_Op',  'MPI_Op'));
    return;
end
if strcmp(typename(5:end), 'Datatype')
    n = coder.ceval('sizeof', coder.opaque('MPI_Datatype',  'MPI_Datatype'));
    return;
end

if strcmp(typename(5:end), 'DOUBLE') || strcmp(typename(5:end), '2INT')
    n = int32(8);
    return;
end
if strcmp(typename(5:end), 'FLOAT') || strcmp(typename(5:end), 'INT') || ...
        strcmp(typename(5:end), 'UNSIGNED')
    n = int32(4);
    return;
end
if strcmp(typename(5:end), 'SHORT') || strcmp(typename(5:end), 'UNSIGNED_SHORT')
    n = int32(2);
    return;
end
if strcmp(typename(5:end), 'CHAR') || strcmp(typename(5:end), 'UNSIGNED_CHAR') || ...
        strcmp(typename(5:end), 'BYTE')
    n = int32(1);
    return;
end

m2c_error('mpi_get_sizeof:UnknownType', 'Unknonw datatype %s.', [typename char(0)]);
