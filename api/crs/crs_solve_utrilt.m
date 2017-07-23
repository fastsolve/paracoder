function b = crs_solve_utrilt(A, b)
% crs_solve_utrilt Solves A.'\b, where A is unit lower triangular
%     b = crs_solve_utrilt(A, b)
%  Matrix A stores only the strictly lower triangular part. The right-hand 
%  will be overwritten by A.'\b at output
%
% See also crs_solve_tril, crs_solve_triut

%#codegen -args {crs_matrix, coder.typeof(0, [inf,1])}

coder.inline('always');

n = int32(length(A.row_ptr) - 1);

for i = n:-1:1
    for k = A.row_ptr(i):(A.row_ptr(i+1) - 1)
        j = A.col_ind(k);
        % This can be done concurrently
        b(j) = b(j) - A.val(k) * b(i);
    end
end

function test %#ok<DEFNU>
%!test
%! for k=1:100
%!     L = tril(rand(10,10), -1); b = rand(10, 1);
%!     if condest(L) < 1.e5
%!         A = crs_createFromSparse(sparse(L));
%!         us = crs_solve_trilt(A, b);
%!         assert(norm((L + spdiag(10))' * us - b) <= 1.e-10);
%!     end
%! end
