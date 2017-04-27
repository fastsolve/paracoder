function output = MPI_Aint(varargin) %#codegen
%Map an opaque object into an MPI_Aint object
%
%  MPI_Aint() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  MPI_Aint(obj) or MPI_Aint(obj, false)
%  converts obj into an MPI_Aint object.
%
%  MPI_Aint(obj, 'wrap') or MPI_Aint(obj, true) wraps the obj into 
%  an opaque object. This should be used if the opaque object needs
%  to be returned to MATLAB.

coder.inline('always');
coder.cinclude('mpi.h');
 
if nargin==1 && isempty(coder.target)
    arg = varargin{1};
    if isstruct(arg)
        output = arg;
    elseif mpi_get_sizeof('MPI_Aint')==8
        output = m2c_opaque_obj('MPI_Aint', int64(arg), 'wrap');
    else
        output = m2c_opaque_obj('MPI_Aint', int32(arg), 'wrap');
    end
else
    output = m2c_opaque_obj('MPI_Aint', varargin{:});
end
