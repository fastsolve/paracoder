function b = crs_solve_utril(A, b)
% crs_solve_utril Solves A\b, where A is unit lower triangular
%     b = crs_solve_utril(A, b)
%  Matrix A stores only the strictly lower triangular part. The right-hand 
%  side vector will be overwritten by A\b at output.

%#codegen -args {crs_matrix, coder.typeof(0, [inf,1])}

coder.inline('always');

n = int32(length(A.row_ptr) - 1);

for i = 1:n
    for k = A.row_ptr(i):A.row_ptr(i+1) - 1
        b(i) = b(i) - A.val(k) * b(A.col_ind(k));
    end
end

function test %#ok<DEFNU>
%!test
%! for k=1:100
%!     L = tril(rand(10,10), -1); b = rand(10,1);
%!     if condest(L) < 1.e5
%!         A = crs_createFromSparse(sparse(L));
%!         us = crs_solve_utril(A, b);
%!         assert(norm((L+speye(10)) * us - b) <= 1.e-10);
%!     end
%! end
