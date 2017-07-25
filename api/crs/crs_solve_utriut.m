function b = crs_solve_utriut(U, b, varargin)
% crs_solve_utriut Solves U.'\b, where U is unit upper triangular
%     b = crs_solve_utriut(U, b) solves U'\b, where U stores the strict 
%     upper triangular part of U. The right-hand side vector will be 
%     overwritten by U.'\b at output.
%
%     b = crs_solve_utriut(U, b, offset) uses b(offset+1:offset+n) 
%     instead of b for the rhs and solution vector, where n=size(U,1).
% See also crs_solve_tril, crs_solve_triut

%#codegen -args {crs_matrix, coder.typeof(0, [inf, 1])}
%#codegen crs_solve_utriut_3args -args {crs_matrix, m2c_vec, int32(0)}

coder.inline('always');

if nargin < 3
    offset = int32(0);
else
    offset = int32(varargin{1});
end
n = int32(length(U.row_ptr) - 1);

for i = 1:n
    for k = U.row_ptr(i):(U.row_ptr(i+1) - 1)
        j = U.col_ind(k);
        % This can be done concurrently
        b(j+offset) = b(j+offset) - U.val(k) * b(i+offset);
    end
end

function test %#ok<DEFNU>
%!test
%! for k=1:100
%!     T = triu(rand(10,10), 1); b = rand(10, 1);
%!     U = crs_createFromSparse(sparse(T));
%!     us = crs_solve_utriut(U, b);
%!     assert(norm((T + speye(10))' * us - b) <= 1.e-10);
%! end
