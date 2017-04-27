function obj = mpi_get_const(name)
%mpi_get_const Obtain a constant as an opaque object.
%   obj = mpi_get_const(name)
%
% The supported MPI_Datatype contants include:
%   MPI_DOUBLE, MPI_FLOAT, MPI_INT, MPI_UNSIGNED, MPI_SHORT, MPI_UNSIGNED_SHORT,
%   MPI_CHAR, MPI_UNSIGNED_CHAR (or MPI_BYTE), MPI_PACKED, and MPI_DATATYPE_NULL.
%   MPI_2INT,
% The supported MPI_Comm and MPI_Group constants include:
%   MPI_COMM_WORLD, MPI_COMM_SELF, and MPI_COMM_NULL
% The supported MPI_Op constants include:
%    MPI_SUM, MPI_PROD, MPI_MIN, MPI_MAX, MPI_BOR, MPI_BAND, MPI_BXOR,
%    MPI_LOR, MPI_LAND, MPI_LXOR, MPI_MAXLOC, MPI_MINLOC, and MPI_OP_NULL.
% Other constants include
%    MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_IN_PLACE, MPI_REQUEST_NULL, MPI_GROUP_NULL,
%    MPI_GROUP_EMPTY, MPI_STATUS_IGNORE, MPI_INFO_NULL, MPI_ERRCODES_IGNORE, MPI_ARGV_NULL,
%    MPI_IDENT, MPI_CONGRUENT, MPI_SIMILAR, MPI_UNEQUAL, MPI_MAX_PROCESSOR_NAME

%#codegen -args {coder.typeof(char(0),[1,inf])}

coder.cinclude('mpi.h');

assert(isequal(name(1:4), 'MPI_'));

%% MPI_Datatype
if isequal(name(5:end), 'FLOAT')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_FLOAT'), true);
elseif isequal(name(5:end), 'DOUBLE')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_DOUBLE'), true);
elseif isequal(name(5:end), 'LONG_DOUBLE')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_LONG_DOUBLE'), true);
elseif isequal(name(5:end), 'INT')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_INT'), true);
elseif isequal(name(5:end), 'UNSIGNED')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_UNSIGNED'), true);
elseif isequal(name(5:end), 'LONG')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_LONG'), true);
elseif isequal(name(5:end), 'UNSIGNED_LONG')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_UNSIGNED_LONG'), true);
elseif isequal(name(5:end), 'LONG_LONG')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_LONG_LONG'), true);
elseif isequal(name(5:end), 'LONG_LONG_INT')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_LONG_LONG_INT'), true);
elseif isequal(name(5:end), 'UNSIGNED_LONG_LONG')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_UNSIGNED_LONG_LONG'), true);
elseif isequal(name(5:end), 'SHORT')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_SHORT'), true);
elseif isequal(name(5:end), 'UNSIGNED_SHORT')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_UNSIGNED_SHORT'), true);
elseif isequal(name(5:end), 'CHAR')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_CHAR'), true);
elseif isequal(name(5:end), 'UNSIGNED_CHAR')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_UNSIGNED_CHAR'), true);
elseif isequal(name(5:end), 'BYTE')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_BYTE'), true);
elseif isequal(name(5:end), '2INT')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_2INT'), true);
elseif isequal(name(5:end), 'SHORT_INT')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_SHORT_INT'), true);
elseif isequal(name(5:end), 'FLOAT_INT')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_FLOAT_INT'), true);
elseif isequal(name(5:end), 'DOUBLE_INT')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_DOUBLE_INT'), true);
elseif isequal(name(5:end), 'PACKED')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_PACKED'), true);
elseif isequal(name(5:end), 'DATATYPE_NULL')
    obj = m2c_opaque_obj('MPI_Datatype', coder.opaque('MPI_Datatype',  'MPI_DATATYPE_NULL'), true);
elseif isequal(name(5:end), 'COMM_WORLD')
    obj = m2c_opaque_obj('MPI_Comm', coder.opaque('MPI_Comm',  'MPI_COMM_WORLD'), true);
elseif isequal(name(5:end), 'COMM_SELF')
    obj = m2c_opaque_obj('MPI_Comm', coder.opaque('MPI_Comm',  'MPI_COMM_SELF'), true);
elseif isequal(name(5:end), 'COMM_NULL')
    obj = m2c_opaque_obj('MPI_Comm', coder.opaque('MPI_Comm',  'MPI_COMM_NULL'), true);
elseif isequal(name(5:end), 'SUM')
    obj = m2c_opaque_obj('MPI_Op', coder.opaque('MPI_Op',  'MPI_SUM'), true);
elseif isequal(name(5:end), 'PROD')
    obj = m2c_opaque_obj('MPI_Op', coder.opaque('MPI_Op',  'MPI_PROD'), true);
elseif isequal(name(5:end), 'MIN')
    obj = m2c_opaque_obj('MPI_Op', coder.opaque('MPI_Op',  'MPI_MIN'), true);
elseif isequal(name(5:end), 'MAX')
    obj = m2c_opaque_obj('MPI_Op', coder.opaque('MPI_Op',  'MPI_MAX'), true);
elseif isequal(name(5:end), 'BOR')
    obj = m2c_opaque_obj('MPI_Op', coder.opaque('MPI_Op',  'MPI_BOR'), true);
elseif isequal(name(5:end), 'BAND')
    obj = m2c_opaque_obj('MPI_Op', coder.opaque('MPI_Op',  'MPI_BAND'), true);
elseif isequal(name(5:end), 'BXOR')
    obj = m2c_opaque_obj('MPI_Op', coder.opaque('MPI_Op',  'MPI_BXOR'), true);
elseif isequal(name(5:end), 'LOR')
    obj = m2c_opaque_obj('MPI_Op', coder.opaque('MPI_Op',  'MPI_LOR'), true);
elseif isequal(name(5:end), 'LAND')
    obj = m2c_opaque_obj('MPI_Op', coder.opaque('MPI_Op',  'MPI_LAND'), true);
elseif isequal(name(5:end), 'LXOR')
    obj = m2c_opaque_obj('MPI_Op', coder.opaque('MPI_Op',  'MPI_LXOR'), true);
elseif isequal(name(5:end), 'MAXLOC')
    obj = m2c_opaque_obj('MPI_Op', coder.opaque('MPI_Op',  'MPI_MAXLOC'), true);
elseif isequal(name(5:end), 'MINLOC')
    obj = m2c_opaque_obj('MPI_Op', coder.opaque('MPI_Op',  'MPI_MINLOC'), true);
elseif isequal(name(5:end), 'OP_NULL')
    obj = m2c_opaque_obj('MPI_Op', coder.opaque('MPI_Op',  'MPI_OP_NULL'), true);
elseif isequal(name(5:end), 'ANY_SOURCE')
    obj = m2c_opaque_obj('int', coder.opaque('int',  'MPI_ANY_SOURCE'), true);
elseif isequal(name(5:end), 'ANY_TAG')
    obj = m2c_opaque_obj('int', coder.opaque('int',  'MPI_ANY_TAG'), true);
elseif isequal(name(5:end), 'IN_PLACE')
    obj = m2c_opaque_obj('void *', coder.opaque('void *',  'MPI_IN_PLACE'), true);
elseif isequal(name(5:end), 'ERRORS_ARE_FATAL')
    obj = m2c_opaque_obj('MPI_Errhandler', coder.opaque('MPI_Errhandler',  'MPI_ERRORS_ARE_FATAL'), true);
elseif isequal(name(5:end), 'ERRORS_RETURN')
    obj = m2c_opaque_obj('MPI_Errhandler', coder.opaque('MPI_Errhandler',  'MPI_ERRORS_RETURN'), true);
elseif isequal(name(5:end), 'BSEND_OVERHEAD')
    obj = m2c_opaque_obj('int', coder.opaque('int',  'MPI_BSEND_OVERHEAD'), true);
elseif isequal(name(5:end), 'UNDEFINED')
    obj = m2c_opaque_obj('int', coder.opaque('int',  'MPI_UNDEFINED'), true);
elseif isequal(name(5:end), 'IDENT')
    obj = m2c_opaque_obj('int', coder.opaque('int',  'MPI_IDENT'), true);
elseif isequal(name(5:end), 'CONGRUENT')
    obj = m2c_opaque_obj('int', coder.opaque('int',  'MPI_CONGRUENT'), true);
elseif isequal(name(5:end), 'SIMILAR')
    obj = m2c_opaque_obj('int', coder.opaque('int',  'MPI_SIMILAR'), true);
elseif isequal(name(5:end), 'UNEQUAL')
    obj = m2c_opaque_obj('int', coder.opaque('int',  'MPI_UNEQUAL'), true);
elseif isequal(name(5:end), 'MAX_PROCESSOR_NAME')
    obj = m2c_opaque_obj('int', coder.opaque('int',  'MPI_MAX_PROCESSOR_NAME'), true);
elseif isequal(name(5:end), 'GRAPH')
    obj = m2c_opaque_obj('int', coder.opaque('int',  'MPI_GRAPH'), true);
elseif isequal(name(5:end), 'CART')
    obj = m2c_opaque_obj('int', coder.opaque('int',  'MPI_CART'), true);
elseif isequal(name(5:end), 'REQUEST_NULL')
    obj = m2c_opaque_obj('MPI_Request', coder.opaque('MPI_Request',  'MPI_REQUEST_NULL'), true);
elseif isequal(name(5:end), 'GROUP_NULL')
    obj = m2c_opaque_obj('MPI_Group', coder.opaque('MPI_Group',  'MPI_GROUP_NULL'), true);
elseif isequal(name(5:end), 'GROUP_EMPTY')
    obj = m2c_opaque_obj('MPI_Group', coder.opaque('MPI_Group',  'MPI_GROUP_EMPTY'), true);
elseif isequal(name(5:end), 'STATUS_IGNORE')
    obj = m2c_opaque_obj('MPI_Status *', coder.opaque('MPI_Status *',  'MPI_STATUS_IGNORE'), true);
elseif isequal(name(5:end), 'INFO_NULL')
    obj = m2c_opaque_obj('MPI_Info', coder.opaque('MPI_Info',  'MPI_INFO_NULL'), true);
elseif isequal(name(5:end), 'ARGV_NULL')
    obj = m2c_opaque_obj('char **', coder.opaque('char **',  'MPI_ARGV_NULL'), true);
elseif isequal(name(5:end), 'ERRCODES_IGNORE')
    obj = m2c_opaque_obj('int *', coder.opaque('int *',  'MPI_ERRCODES_IGNORE'), true);
else
    obj = m2c_opaque_obj('void *', coder.opaque('void *',  'NULL'), true);
    m2c_error('mpi_get_const:UnknownConstant', 'Unknonw constant %s.', [name char(0)]);
end
