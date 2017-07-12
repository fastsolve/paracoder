function varargout = crs_createFromSparse(sp, m)
%crs_createFromSparse  Convert built-in sparse format to CRS
%
%    A = crs_createFromAIJ(sp [, nrows]);
%    [row_ptr, col_ind, val] = crs_createFromAIJ(sp[, nrows]);
%
% A is a struct with fields row_ptr, col_ind, val, nrows, and ncols.
%
% See also crs_matrix, crs_createFromAIJ

[is, js, vs] = find(sp);

A = crs_createFromAIJ(int32(is), int32(js), vs, ...
    int32(size(sp, 1)), int32(size(sp, 2)));

if nargin > 1 && m + 1 > length(A.row_ptr)
    A.row_ptr = [A.row_ptr; repmat(A.row_ptr(end), m+1-length(A.row_ptr), 1)];
end

if nargout <= 1
    varargout{1} = A;
else
    varargout{1} = A.row_ptr;
    varargout{2} = A.col_ind;
    varargout{3} = A.val;
end
