function [size, info, toplevel] = mpi_Type_size(datatype)
%mpi_Type_size	 Return the number of bytes occupied by entries in the datatype
%
%  [size, info] = mpi_Type_size(datatype)
%
%Input argument:
%  datatype  Opaque MPI_Datatype object (see MPI_Datatype).
%
%Output argument:
%  size         datatype size (int32)
%  info         return code (int32)
%
% C interface:
% int MPI_Type_size(MPI_Datatype datatype, int *size);
% http://mpi.deino.net/mpi_functions/MPI_Type_size.html

%#codegen -args {MPI_Datatype}

info = int32(0);
size = int32(0);

if isempty(coder.target)
    arg = MPI_Datatype(datatype);
    if strcmp(char(arg(1).data(5:end)), 'DOUBLE')
        size = int32(8);
    elseif strcmp(char(arg(1).data(5:end)), 'FLOAT') || ...
        strcmp(char(arg(1).data(5:end)), 'INT') || ...
        strcmp(char(arg(1).data(5:end)), 'UNSIGNED')
        size = int32(4);
    elseif strcmp(char(arg(1).data(5:end)), 'SHORT') || ...
        strcmp(char(arg(1).data(5:end)), 'UNSIGNED_SHORT')
        size = int32(2);
    elseif strcmp(char(arg(1).data(5:end)), 'CHAR') || ...
        strcmp(char(arg(1).data(5:end)), 'UNSIGNED_CHAR')
        size = int32(1);
    else
        error('Unsupported data type');
    end
else
    info = coder.ceval('MPI_Type_size', MPI_Datatype(datatype), ...
                       coder.wref(size));
end
    
toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Type_size failed with error message %s\n', mpi_Error_string(info))
end
    

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! assert(mpi_Type_size(MPI_DOUBLE) == 8);
%! assert(mpi_Type_size(MPI_FLOAT) == 4);
%! assert(mpi_Type_size(MPI_INT) == 4);
%! assert(mpi_Type_size(MPI_SHORT) == 2);
%! assert(mpi_Type_size(MPI_UNSIGNED_SHORT) == 2);
%! assert(mpi_Type_size(MPI_CHAR) == 1);
%! assert(mpi_Type_size(MPI_UNSIGNED_CHAR) == 1);
