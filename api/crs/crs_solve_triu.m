function b = crs_solve_triu(A, b)
% crs_solve_triu Solves A\b, where A is upper triangular
%     b = crs_solve_triu(A, b)
%  The matrix is assumed to be upper triangular. The right-hand side vector
%  will be overwritten by A\b at output
%
% See also crs_solve_tril, crs_solve_trilt

%#codegen -args {crs_matrix, coder.typeof(0, [inf,1])}

for i = int32(length(A.row_ptr)) - 1:-1:1
    rstart = A.row_ptr(i);
    assert(A.col_ind(rstart) == i && A.val(rstart) ~= 0);

    for cind = (rstart + 1):(A.row_ptr(i+1) - 1)
        k = A.col_ind(cind);
        b(i) = b(i) - A.val(cind) * b(k);
    end

    b(i) = b(i) / A.val(rstart);
end


function test %#ok<DEFNU>
%!test
%! for k=1:100
%!     R = triu(rand(10,10)); b = rand(10,1);
%!     if condest(R) < 1.e5
%!         A = crs_createFromSparse(sparse(R));
%!         us = crs_solve_triu(A, b);
%!         assert(norm(R * us - b) <= 1.e-10);
%!     end
%! end
