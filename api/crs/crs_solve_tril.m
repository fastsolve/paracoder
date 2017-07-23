function b = crs_solve_tril(A, b)
% crs_solve_tril Solves A\b, where A is lower triangular
%     b = crs_solve_tril(A, b)
%  The matrix is assumed to be lower triangular. The right-hand side vector
%  will be overwritten by A\b at output.

%#codegen -args {crs_matrix, coder.typeof(0, [inf,1])}

coder.inline('always');

n = int32(length(A.row_ptr) - 1);

for i = 1:n
    cend = A.row_ptr(i+1) - 1;
    assert(A.col_ind(cend) == i && A.val(cend) ~= 0);

    for k = A.row_ptr(i):(cend - 1)
        j = A.col_ind(k);
        b(i) = b(i) - A.val(k) * b(j);
    end

    b(i) = b(i) / A.val(cend);
end

function test %#ok<DEFNU>
%!test
%! for k=1:100
%!     L = tril(rand(10,10)); b = rand(10,1);
%!     if condest(L) < 1.e5
%!         A = crs_createFromSparse(sparse(L));
%!         us = crs_solve_tril(A, b);
%!         assert(norm(L * us - b) <= 1.e-10);
%!     end
%! end
