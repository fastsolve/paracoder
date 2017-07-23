function b = crs_solve_triut(A, b)
% crs_solve_triut Solves A.'\b, where A is upper triangular
%     b = crs_solve_triut(A, b)
%  The matrix is assumed to be upper triangular. The right-hand side vector
%  will be overwritten by A.'\b at output
%
% See also crs_solve_tril, crs_solve_triut

%#codegen -args {crs_matrix, coder.typeof(0, [inf, 1])}

coder.inline('always');

for i = 1:int32(length(A.row_ptr)) - 1
    cstart = A.row_ptr(i);
    assert(A.col_ind(cstart) == i && A.val(cstart) ~= 0);

    b(i) = b(i) / A.val(cstart);

    for k = (cstart + 1):(A.row_ptr(i+1) - 1)
        j = A.col_ind(k);
        % This can be done concurrently
        b(j) = b(j) - A.val(k) * b(i);
    end
end

function test %#ok<DEFNU>
%!test
%! for k=1:100
%!     R = triu(rand(10,10)); b = rand(10, 1);
%!     if condest(R) < 1.e5
%!         A = crs_createFromSparse(sparse(R));
%!         us = crs_solve_triut(A, b);
%!         assert(norm(R' * us - b) <= 1.e-10);
%!     end
%! end
