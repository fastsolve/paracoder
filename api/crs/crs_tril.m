function L = crs_tril(A, varargin)
% CRS_TRIL   Extract lower triangular part.
%   crs_tril(A) is the lower triangular part of A.
%   tril(A,K) is the elements on and below the K-th diagonal
%   of A.  K = 0 is the main diagonal, K > 0 is above the
%   main diagonal and K < 0 is below the main diagonal.
% 
%   See also crs_triu, crs_diag.

%#codegen -args {crs_matrix} crs_tril1 -args {crs_matrix, int32(1)}

if isempty(varargin); k = int32(0); 
else k = int32(varargin{1}); end

L = A;

[L.col_ind, L.val] = crs_sort(L.row_ptr, L.col_ind, L.val);

offset = int32(0);
start = int32(1);

for i=1:L.nrows
    for j=start : L.row_ptr(i+1)-1
        if L.col_ind(j)>i+k
            offset = offset+1;
        elseif offset
            L.col_ind(j-offset) = L.col_ind(j);
            L.val(j-offset) = L.val(j);
        end
    end
    
    start = L.row_ptr(i+1);
    L.row_ptr(i+1) = L.row_ptr(i+1) - offset;
end

if offset
    newlen = int32(length(L.col_ind))-offset;
    L.col_ind = sub_colvec(L.col_ind, 1, newlen);
    L.val = sub_colvec(L.val, 1, newlen);
end

function test %#ok<DEFNU>
%!test
%!shared A, sp_A
%! A = sprand(1000,1000,0.05);
%! sp_A = crs_matrix(A);

%! sp_L= crs_tril(sp_A);
%! assert(isequal(tril(A), crs_2sparse(sp_L)));

%!test
%! sp_L= crs_tril(sp_A, int32(1));
%! assert(isequal(tril(A,1), crs_2sparse(sp_L)));

%!test
%! sp_L= crs_tril(sp_A, int32(-1));
%! assert(isequal(tril(A,-1), crs_2sparse(sp_L)));
