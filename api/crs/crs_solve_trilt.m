function b = crs_solve_trilt(A, b)
% crs_solve_trilt Solves A.'\b, where A is lower triangular
%     b = crs_solve_trilt(A, b)
%  The matrix is assumed to be lower triangular. The right-hand side vector
%  will be overwritten by A.'\b at output
%
% See also crs_solve_tril, crs_solve_triut

%#codegen -args {crs_matrix, coder.typeof(0, [inf,1])}

for i = int32(length(A.row_ptr)) - 1:-1:1
    cend = A.row_ptr(i+1) - 1;
    assert(A.col_ind(cend) == i && A.val(cend) ~= 0);

    b(i) = b(i) / A.val(cend);

    for k = A.row_ptr(i):(cend - 1)
        j = A.col_ind(k);
        % This can be done concurrently
        b(j) = b(j) - A.val(k) * b(i);
    end
end

function test %#ok<DEFNU>
%!test
%! for k=1:100
%!     L = tril(rand(10,10)); b = rand(10, 1);
%!     if condest(L) < 1.e5
%!         A = crs_createFromSparse(sparse(L));
%!         us = crs_solve_trilt(A, b);
%!         assert(norm(L' * us - b) <= 1.e-10);
%!     end
%! end
