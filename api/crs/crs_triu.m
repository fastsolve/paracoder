function U = crs_triu(A, varargin)
% CRS_TRIL   Extract upper triangular part.
%   crs_triu(A) is the upper triangular part of A.
%   triu(A,K) is the elements on and above the K-th diagonal
%   of A.  K = 0 is the main diagonal, K > 0 is above the
%   main diagonal and K < 0 is below the main diagonal.
% 
%   See also crs_tril, crs_diag.

%#codegen -args {crs_matrix} crs_triu1 -args {crs_matrix, int32(1)}

if isempty(varargin); k = int32(0); 
else k = int32(varargin{1}); end

U = A;

[U.col_ind, U.val] = crs_sort(U.row_ptr, U.col_ind, U.val);

offset = int32(0);
start = int32(1);

for i=1:U.nrows
    for j=start : U.row_ptr(i+1)-1
        if U.col_ind(j)<i+k
            offset = offset+1;
        elseif offset
            U.col_ind(j-offset) = U.col_ind(j);
            U.val(j-offset) = U.val(j);
        end
    end
    
    start = U.row_ptr(i+1);
    U.row_ptr(i+1) = U.row_ptr(i+1) - offset;
end

if offset
    newlen = int32(length(U.col_ind))-offset;
    U.col_ind = sub_colvec(U.col_ind, 1, newlen);
    U.val = sub_colvec(U.val, 1, newlen);
end

function test %#ok<DEFNU>
%!test
%!shared A, sp_A
%! A = sprand(1000,1000,0.05);
%! sp_A = crs_matrix(A);

%! sp_U= crs_triu(sp_A);
%! assert(isequal(triu(A), crs_2sparse(sp_U)));

%!test
%! sp_U= crs_triu(sp_A, int32(1));
%! assert(isequal(triu(A,1), crs_2sparse(sp_U)));

%!test
%! sp_U= crs_triu(sp_A, int32(-1));
%! assert(isequal(triu(A,-1), crs_2sparse(sp_U)));
