function varargout = crs_matrix(varargin) %#codegen
%crs_matrix  Create a sparse matrix in CRS-format
%
%    A = crs_matrix(is, js, vs [, nrows, ncols])
%    [row_ptr, col_ind, val, nrows, ncols] = crs_matrix(...)
% In the first case, A is a struct with fields row_ptr, col_ind,
% val, nrows, and ncols.
%
%    A = crs_matrix(sp, [, nrows, ncols]) or
%    [row_ptr, col_ind, val, nrows, ncols] = crs_matrix(...) creates a
% matrix from the MATLAB sparse format. This mode is incompatible with
% MATLAB Coder. It is provided for convenience of writing test programs.
%
%    A = crs_matrix({row_ptr, col_ind, val} [, nrows, ncols])
% wraps the row_ptr, col_ind and val given in a cell array into a structure.
%
%    A = crs_matrix(m, n);
% Create an empty matrix with m rows and n colmns.
%
% See also crs_2sparse, crs_create
%
% Note: This function does not use multithreading. If there is no input,
%   this function creates a type declaration to be used with codegen.

if nargin==0
    varargout{1} = coder.typeof(struct('row_ptr', coder.typeof(int32(0), [inf,1]), ...
        'col_ind', coder.typeof(int32(0), [inf,1]), ...
        'val', coder.typeof(0, [inf,1]), 'nrows', int32(0), 'ncols', int32(0)));
    return;
elseif issparse(varargin{1})
    [is,js,vs] = find(varargin{1});

    A = crs_create(int32(is), int32(js), vs, ...
        int32(size(varargin{1},1)), int32(size(varargin{1},2)));
elseif iscell(varargin{1})
    A.row_ptr = int32(varargin{1}{1});
    A.col_ind = int32(varargin{1}{2});
    A.val = double(varargin{1}{3});

    if nargin > 1
        A.nrows = int32(varargin{2});
    else
        A.nrows = int32(length(A.row_ptr)-1);
    end
    if nargin > 2
        A.ncols = int32(varargin{3});
    else
        A.ncols = int32(max(A.col_ind));
    end
elseif nargin==2
    A = crs_create(int32(varargin{1}), int32(varargin{2}));
    coder.varsize('A.row_ptr', 'A.col_ind', 'A.val', [inf,1]);
else
    is = int32(varargin{1});
    js = int32(varargin{2});
    vs = varargin{3};

    A = crs_create(is, js, vs, varargin{4:end});
    coder.varsize('A.row_ptr', 'A.col_ind', 'A.val', [inf,1]);
end

if nargout<=1
    varargout{1} = A;
else
    varargout{1} = A.row_ptr;
    varargout{2} = A.col_ind;
    if nargout>2; varargout{3} = A.val; end
    if nargout>3; varargout{4} = A.nrows; end
    if nargout>4; varargout{5} = A.ncols; end
end
