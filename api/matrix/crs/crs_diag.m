function D = crs_diag(A, varargin)
% CRS_DIAG    Extract diagonals of a matrix.
%   crs_diag(A, k) is a column vector formed from the elements 
%   of the K-th diagonal of X. K = 0 is the main diagonal, 
%   K > 0 is above the main diagonal and K < 0 is below the main diagonal. 
%   crs_diag(A) is the main diagonal of X.
% 
%   See also crs_tril, crs_triu.

%#codegen -args {crs_matrix} crs_diag1 -args {crs_matrix, int32(1)}

if isempty(varargin); k = int32(0); 
else k = int32(varargin{1}); end

D = zeros(A.nrows - int32(abs(k)), 1, class(A.val));

if k>=0
    for i=1:A.nrows
        for j=A.row_ptr(i) : A.row_ptr(i+1)-1
            if A.col_ind(j)==i+k
                D(i) = A.val(j);
                break;
            end
        end
    end
else
    for i=1:A.nrows
        for j=A.row_ptr(i) : A.row_ptr(i+1)-1
            if A.col_ind(j)==i+k
                D(i+k) = A.val(j);
                break;
            end
        end
    end
end

function test %#ok<DEFNU>
%!test
%!shared A, sp_A
%! A = sprand(1000,1000,0.05);
%! sp_A = crs_matrix(A);

%! D = crs_diag(sp_A);
%! assert(isequal(diag(A), D));

%!test
%! D = crs_diag(sp_A, int32(1));
%! assert(isequal(diag(A,1), D));

%!test
%! D = crs_diag(sp_A, int32(-1));
%! assert(isequal(diag(A,-1), D));
