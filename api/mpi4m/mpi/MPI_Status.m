function output = MPI_Status(varargin) %#codegen
%Manipulates the MPI_Status structure.
%
%  MPI_Status() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  MPI_Status(obj) or MPI_Status(obj, false) converts obj into
%  an MPI_Status object.
%
%  MPI_Status(obj, 'wrap') or MPI_Status(obj, true) wraps the obj into
%  an opaque object. This should be used if the opaque object needs to
%  be returned to MATLAB.
%
%  val = MPI_Status(obj, '.', field) obtains the field of the MPI_Status
%  struct, where the field can be 'MPI_SOURCE' (or 'source',
% 'MPI_TAG' (or 'tag'), or 'MPI_ERROR' (or 'error').

coder.inline('always');
coder.cinclude('mpi.h');

if nargin<=1 || ~ischar(varargin{2}) || isequal(varargin{2}, 'wrap')
    % MPI_Status(obj) or MPI_Status(obj, 'wrap'|true|false)
    output = m2c_opaque_obj('MPI_Status', varargin{:});
elseif isequal(varargin{2}, 'get')
    % MPI_Status(obj, field)
    output = mpi_get_status_field(varargin{1}, varargin{3});
else
    m2c_error('MPI_Status:WrongInput', 'Unsupported input options.\n');
end
