function A = ccs_createFromAIJ(rows, cols, vs, varargin)
%ccs_createFromAIJ  Create a sparse matrix in CCS-format from AIJ (ijv) format
%
%    A = ccs_createFromAIJ(rows, cols, vs [, ni, nj]);
% A is a struct with fields col_ptr, row_ind, val, nrows, and ncols.
%
% See also ccs_matrix, ccs_createFromSparse

%#codegen -args {coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(int32(0), [inf,1]), coder.typeof(0, [inf,1])}
%#codegen ccs_create1 -args {coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(int32(0), [inf,1]), coder.typeof(0, [inf,1]), int32(0), int32(0)}

if nargin<4
    nrows = max(rows);
else
    nrows = int32(varargin{1});
end
if nargin<5
    ncols = max(cols);
else
    ncols = int32(varargin{2});
end

A = struct('col_ptr', zeros(ncols+1,1,'int32'), ...
    'row_ind',zeros(size(rows),'int32'), ...
    'val',zeros(size(rows), class(vs)), ...
    'nrows', nrows, 'ncols', ncols);

%% Construct A.col_ptr
for i=1:int32(length(cols))
    A.col_ptr(cols(i)+1) = A.col_ptr(cols(i)+1) + 1;
end

A.col_ptr(1) = 1;
for i=1:ncols
    A.col_ptr(i+1) = A.col_ptr(i) + A.col_ptr(i+1);
end

%% Construct A.row_ind and A.val
% Check whether column indices are in ascending order
ascend = true;
for i=2:length(cols)
    if cols(i)<cols(i-1)
        ascend = false;
        break;
    end
end

if ascend
    % if column indices are already in ascending order, simply
    % return rows as A.row_ind and vs as A.val.
    A.row_ind = int32(rows);
    A.val = vs;
else
    % Construct A.row_ind and A.val
    A.row_ind = coder.nullcopy(zeros(length(rows),1,'int32'));
    A.val = coder.nullcopy(zeros(length(rows),1, class(vs)));

    for i=1:length(cols)
        j = A.col_ptr(cols(i));
        A.val(j) = vs(i);
        A.row_ind(j) = rows(i);
        A.col_ptr(cols(i)) = A.col_ptr(cols(i)) + 1;
    end

    % Recover A.col_ptr
    for i=length(A.col_ptr):-1:2
        A.col_ptr(i) = A.col_ptr(i-1);
    end
    A.col_ptr(1)=1;
end

%% Sort row_ind
[A.row_ind, A.val] = ccs_sort(A.col_ptr, A.row_ind, A.val);
end

function [row_ind, val] = ccs_sort(col_ptr, row_ind, val)
% Same as crs_sort
[row_ind, val] = crs_sort(col_ptr, row_ind, val);
end
