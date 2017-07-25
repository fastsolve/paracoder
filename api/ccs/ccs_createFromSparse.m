function varargout = ccs_createFromSparse(sp, m)
%ccs_createFromSparse  Convert MATLAB sparse matrix to compressed column sparse format
%
%    A = ccs_createFromAIJ(sp [, nrows]);
%    [col_ptr, row_ind, val] = ccs_createFromAIJ(sp[, nrows]);
%
% A is a struct with fields col_ptr, row_ind, val, nrows, and ncols.
%
% See also ccs_matrix, ccs_createFromAIJ

[is, js, vs] = find(sp);

if nargin > 1
    nrows = int32(m);
else
    nrows = int32(size(sp, 1));
end

% Note: In Octave, find returns row vectors instead of column vectors
A = ccs_createFromAIJ(int32(is(:)), int32(js(:)), vs(:), ...
    nrows, int32(size(sp, 2)));

if nargout <= 1
    varargout{1} = A;
else
    varargout{1} = A.col_ptr;
    varargout{2} = A.row_ind;
    varargout{3} = A.val;
end
