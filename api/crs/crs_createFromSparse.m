function A = crs_createFromSparse(sp)
%crs_createFromSparse  Convert built-in sparse format to CRS
%
%    A = crs_createFromAIJ(sp);
% A is a struct with fields row_ptr, col_ind, val, nrows, and ncols.
%
% See also crs_matrix, crs_createFromAIJ

[is,js,vs] = find(sp);

A = crs_createFromAIJ(int32(is), int32(js), vs, ...
    int32(size(sp,1)), int32(size(sp,2)));
