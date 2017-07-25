function b = ccs_solve_trilt(L, b)
% ccs_solve_trilt Solves L.'\b, where L is lower triangular
%     b = ccs_solve_trilt(L, b)
%  The matrix is assumed to be lower triangular. The right-hand side vector
%  will be overwritten by L.'\b at output
%
% See also ccs_solve_tril, ccs_solve_triut

%#codegen -args {ccs_matrix, coder.typeof(0, [inf,1])}

coder.inline('always');

n = int32(length(L.col_ptr) - 1);

for j = n:-1:1
    rstart = L.col_ptr(j);
    assert(L.row_ind(rstart) == j && L.val(rstart) ~= 0);

    for i = (rstart + 1):(L.col_ptr(j+1) - 1)
        k = L.row_ind(i);
        b(j) = b(j) - L.val(i) * b(k);
    end

    b(j) = b(j) / L.val(rstart);
end


function test %#ok<DEFNU>
%!test
%! for k=1:100
%!     R = triu(rand(10,10)); b = rand(10,1);
%!     if condest(R) < 1.e5
%!         L = ccs_createFromSparse(sparse(R));
%!         us = ccs_solve_trilt(L, b);
%!         assert(norm(R * us - b) <= 1.e-10);
%!     end
%! end
