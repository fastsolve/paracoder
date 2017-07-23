function b = crs_solve_utriu(A, b)
% crs_solve_utriu Solves A\b, where A is unit upper triangular
%     b = crs_solve_utriu(A, b)
%  Matrix A stores only the strictly upper triangular part. The right-hand 
%  side vector will be overwritten by A\b at output
%
% See also crs_solve_tril, crs_solve_trilt

%#codegen -args {crs_matrix, coder.typeof(0, [inf,1])}

n = int32(length(A.row_ptr) - 1);

for i = n:-1:1
    for cind = A.row_ptr(i):(A.row_ptr(i+1) - 1)
        b(i) = b(i) - A.val(cind) * b(A.col_ind(cind));
    end
end


function test %#ok<DEFNU>
%!test
%! for k=1:100
%!     R = triu(rand(10,10), 1); b = rand(10,1);
%!     if condest(R) < 1.e5
%!         A = crs_createFromSparse(sparse(R));
%!         us = crs_solve_triu(A, b);
%!         assert(norm((R + speye(10)) * us - b) <= 1.e-10);
%!     end
%! end
