function [name, info, toplevel] = mpi_Get_processor_name
%mpi_Get_processor_name  Gets the name of the processor
%
% [name, info] = mpi_Get_processor_name
%
% C interface:
% int mpi_Get_processor_name(char *name, int *resultlen) 
% http://mpi.deino.net/mpi_functions/MPI_Get_processor_name.html

%#codegen -args {}


coder.inline('always');

name0 = zeros(1, MPI_MAX_PROCESSOR_NAME, 'uint8');
resultlen = MPI_MAX_PROCESSOR_NAME;

ptr = coder.opaque('char *'); %#ok<NASGU>
ptr = coder.ceval('(char *)', coder.ref(name0));

info = int32(0); %#ok<NASGU>
info = coder.ceval('MPI_Get_processor_name', ptr, coder.ref(resultlen));

name = char(name0(1:resultlen));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Get_processor_name failed with error message %s\n', mpi_Error_string(info))
end
