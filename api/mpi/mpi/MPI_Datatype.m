function datatype = MPI_Datatype(varargin) %#codegen
%Map an opaque object into an MPI_Datatype object
%
%  MPI_Datatype() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  MPI_Datatype(obj) or MPI_Datatype(obj, false)
%  converts obj into an MPI_Datatype object.
%
%  MPI_Datatype(obj, 'wrap') or MPI_Datatype(obj, true) wraps the obj into 
%  an opaque object. This should be used if the opaque object needs
%  to be returned to MATLAB.
%
% Supported data types include:
%   double, single, int32, uint32, int16, uint16, char (int8), uint8,
% Their corresponding MPI datatypes are: MPI_LONG_DOUBLE, MPI_DOUBLE, MPI_FLOAT, 
%   MPI_INT, MPI_UNSIGNED, MPI_LONG, MPI_UNSIGNED_LONG, MPI_SHORT, 
%   MPI_UNSIGNED_SHORT, MPI_CHAR, MPI_UNSIGNED_CHAR (or MPI_BYTE),
%   MPI_LONG_LONG, MPI_UNSIGNED_LONG_LONG, MPI_C_FLOAT_COMPLEX, 
%   MPI_C_DOUBLE_COMPLEX, MPI_C_LONG_DOUBLE_COMPLEX
%
% The following datatypes are defined, but cannot be mapped from MATLAB
% objects automatically:
%   MPI_DOUBLE_INT, MPI_FLOAT_INT, MPI_2INT, MPI_SHORT_INT

coder.inline('always');
coder.cinclude('mpi.h');

if nargin==1 && isnumeric(varargin{1})
    switch class(varargin{1})
        case 'longdouble'
            datatype = MPI_LONG_DOUBLE;
        case 'double'
            datatype = MPI_DOUBLE;
        case 'single'
            datatype = MPI_FLOAT;
       case 'int64'
            datatype = MPI_LONG_LONG;
        case 'uint64'
            datatype = MPI_UNSIGNED_LONG_LONG;
        case 'int32'
            datatype = MPI_INT;
        case 'uint32'
            datatype = MPI_UNSIGNED;
        case 'int16'
            datatype = MPI_SHORT;
        case 'uint16'
            datatype = MPI_UNSIGNED_SHORT;
        case 'int8'
            datatype = MPI_CHAR;
        case 'uint8'
            datatype = MPI_UNSIGNED_CHAR;
        otherwise
            datatype = MPI_DATATYPE_NULL;
            m2c_error('MPI_Datatype:UnsupportedType', 'Unsupported data type');
    end    
else
    datatype = m2c_opaque_obj('MPI_Datatype', varargin{:});
end
