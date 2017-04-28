function output = CuVec(varargin) %#codegen
%Createa an opaque vector object on CUDA.
%
%  CuVec() simply returns a definition of a structure,
%  suitable in the argument specification for codegen.
%
%  CuVec(0) creates a null CuVec object.
%
%  CuVec(obj, type, n, 'wrap') wraps the given opaque pointer
%          into a CuVec object.
%
%  CuVec(obj, type) converts obj into a CUDA pointer of the given type,
%  where type is a constant string, such as 'double *'.
%
%  CuVec(obj, type, 'offset', k) returns a CUDA pointer but offset 
%  by k elements.
%
% See also cuVecCreate, CuMat

coder.inline('always');
coder.cinclude('cuda4m.h');
narginchk(0, 4);

if nargin==0
    % We assume 64-bit architecture for CUDA.
    output = coder.typeof(struct('data', uint64(0), ...
        'type', int32(0), 'dims', int32(0)));
elseif nargin==1 && isnumeric(varargin{1})
    output = struct('data', uint64(0), 'type', int32(0), 'dims', int32(0));
elseif nargin==4 && ischar(varargin{4})
    output = struct('data', uint64(0), 'type', int32(varargin{2}), ...
        'dims', int32(varargin{3}));
    
    obj = varargin{1};
    if ~isempty(obj)
        output.data = coder.ceval('*(uint64_T *)', coder.rref(obj));
    end
elseif nargin==2
    if isstruct(varargin{1}) && isfield(varargin{1}, 'data')
        output = m2c_castdata(varargin{2}, varargin{1}.data);
    else
        output = m2c_castdata(varargin{2}, varargin{1});
    end
elseif nargin==4 && ischar(varargin{3})
    % Compute pointer with offset
    if isstruct(varargin{1}) && isfield(varargin{1}, 'data')
        output = m2c_offset_ptr(m2c_castdata(varargin{2}, varargin{1}.data), varargin{4});
    else
        output = m2c_offset_ptr(m2c_castdata(varargin{2}, varargin{1}), varargin{4});
    end
else
    % Undefined.
end
