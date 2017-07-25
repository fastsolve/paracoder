function b = ccs_solve_tril(L, b)
% ccs_solve_tril Solves L\b, where L is lower triangular
%     b = ccs_solve_tril(L, b)
%  The matrix is assumed to be lower triangular. The right-hand side vector
%  will be overwritten by L\b at output
%
% See also ccs_solve_triu, ccs_solve_trilt

%#codegen -args {ccs_matrix, coder.typeof(0, [inf, 1])}

coder.inline('always');

for j = 1:int32(length(L.col_ptr)) - 1
    start = L.col_ptr(j);
    assert(L.row_ind(start) == j && L.val(start) ~= 0);

    b(j) = b(j) / L.val(start);

    for k = (start + 1):(L.col_ptr(j+1) - 1)
        i = L.row_ind(k);
        % This can be done concurrently
        b(i) = b(i) - L.val(k) * b(j);
    end
end

function test %#ok<DEFNU>
%!test
%! for k=1:100
%!     T = tril(rand(10,10)); b = rand(10, 1);
%!     if condest(T) < 1.e5
%!         L = ccs_createFromSparse(sparse(T));
%!         us = ccs_solve_tril(L, b);
%!         assert(norm(T * us - b) <= 1.e-10);
%!     end
%! end
